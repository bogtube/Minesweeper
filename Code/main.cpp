#include <iostream>
#include <cmath>
#include "Spielfeld.h"
#include "SetUpMines.h"
#include "ActionOnClick.h"
#include "Anzeige.h"
#include "CountMinesEx.h"

using namespace std; 

int checkNachbarn(int x, int y, Spielfeld& spielfeld){
  char** feld = spielfeld.getFeld();
  char wert = feld[x][y];
  if(wert == 'M') return -1;
  return wert - '0';
}

bool checkNiederlage(int y, int x, Spielfeld& spielfeld){
  return spielfeld.getFeld()[y][x] == 'M';
}

bool checkSieg(Spielfeld& spielfeld){
  int h = spielfeld.getHoehe();
  int b = spielfeld.getBreite();
  char** feld = spielfeld.getFeld();
  
  for(int i = 0; i < h; i++){
    for(int j = 0; j < b; j++){
      if(feld[i][j] != 'M' && !spielfeld.istSichtbar(i, j)){
        return false; 
      }
    }
  }
  return true; 
}

int berechneScore(Spielfeld& spielfeld) {
    int score = 0;
    int h = spielfeld.getHoehe();
    int b = spielfeld.getBreite();
    char** feld = spielfeld.getFeld();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < b; j++) {
            if(spielfeld.istSichtbar(i, j) && feld[i][j] != 'M') {
                score += 10;
                if(feld[i][j] >= '1' && feld[i][j] <= '8') {
                    score += (feld[i][j] - '0') * 5; 
                }
            }
        }
    }
    return score;
}

void feldAufdecken(int x, int y, Spielfeld& spielfeld){
  spielfeld.setSichtbar(x, y);
  cout << "Feld [" << x << "][" << y << "] wurde entbloesst: " << spielfeld.getFeld()[x][y] << "\n";
}

int main(){
  Spielfeld spielfeld;
  Anzeige anzeige;

  int eingabeHoehe, eingabeBreite, schwierigkeit;

  // --- STARTMENÜ ---
  anzeige.zeichneMenu(eingabeHoehe, eingabeBreite, schwierigkeit);

  spielfeld.initialisierungSpielfeld(eingabeHoehe, eingabeBreite); 
  placeMines(eingabeHoehe, eingabeBreite, schwierigkeit, spielfeld);
  countMines(eingabeHoehe, eingabeBreite, spielfeld);

  bool gameOver = false;
  char aktion;
  int x, y;

  // --- GAME LOOP ---
  while(!gameOver){
    
    int aktuellerScore = berechneScore(spielfeld);
    anzeige.zeichneSpielfeld(spielfeld, aktuellerScore);

    anzeige.zeigeEinzug(eingabeBreite);
    cout << "Eingabe (Format: [a/f] [Spalte/X] [Zeile/Y] -> z.B. 'a 2 4'): ";                              
    cin >> aktion >> x >> y;

    if (x < 0 || x >= eingabeBreite || y < 0 || y >= eingabeHoehe) {                            
        cout << "\033[91mKoordinaten ausserhalb des Spielfelds! Versuch es nochmal.\033[0m\n";
        continue; 
    }

    if(aktion == 'a'){
      if(checkNiederlage(y, x, spielfeld)){
        spielfeld.setSichtbar(y, x);
        anzeige.zeichneSpielfeld(spielfeld, aktuellerScore);
        cout << "\n \033[91mBamm! Bist auf eine Mine getreten. GAME OVER!\033[0m \n";
        gameOver = true;
      }else{
        FillEmptySpace(y, x, spielfeld);
        if(checkSieg(spielfeld)){
          anzeige.zeichneSpielfeld(spielfeld, berechneScore(spielfeld));
          cout << "\n \033[92mGewonnen!! Uhu, gut gemacht.\033[0m\n";
          gameOver = true;
        }
      }
    }else if(aktion == 'f'){
      spielfeld.toggleFlagge(y, x);
    }else{
      cout << "Gib was richtiges ein du kek. ('a' oder 'f' als erstes Zeichen)\n";
    }
  }

  return 0;
}
