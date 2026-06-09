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

bool checkNiederlage(int x, int y, Spielfeld& spielfeld){
  return spielfeld.getFeld()[x][y] == 'M';
}

bool checkSieg(int x, int y, Spielfeld& spielfeld){
  // TODO einfach nur gucken wie viele Felder noch frei sind
  return false;
}

void feldAufdecken(int x, int y, Spielfeld& spielfeld){
  spielfeld.setSichtbar(x, y);
  cout << "Feld [" << x << "][" << y << "] wurde entblößt: " << spielfeld.getFeld()[x][y] << "\n";
}

int main(){
  Spielfeld spielfeld;
  Anzeige anzeige;

  int eingabeHoehe, eingabeBreite, schwierigkeit;

  // --- STARTMENÜ ---
  cout << "=== MINESWEEPER ===\n";
  cout << "Hoehe: ";
  cin >> eingabeHoehe;
  cout << "Breite: ";
  cin >> eingabeBreite;
  cout << "Schwierigkeit in Prozent (1-99, z.B. 15): ";
  cin >> schwierigkeit;

  spielfeld.initialisierungSpielfeld(eingabeHoehe, eingabeBreite); 
  placeMines(eingabeHoehe, eingabeBreite, schwierigkeit, spielfeld);
  countMines(eingabeHoehe, eingabeBreite, spielfeld);

  bool gameOver = false;
  char aktion;
  int x, y;

  // --- GAME LOOP ---
  while(!gameOver){
    cout << "\033[2J\033[1;1H"; 

    anzeige.zeichneSpielfeld(spielfeld);

    cout << "\nEingabe (Format: [a/f] [X] [Y] -> z.B. 'a 2 4'): ";                              // weil ich zu faul war mich mit der TUI oder Cursor ausseinander zu setzten, deswegen 3 inputs in 1--> damit schnell
    cin >> aktion >> x >> y;

    if (x < 0 || x >= eingabeBreite || y < 0 || y >= eingabeHoehe) {                            // Safty first oder so 
        cout << "Koordinaten ausserhalb des Spielfelds! Versuch es nochmal.\n";
        continue; 
    }

    if(aktion == 'a'){
      if(checkNiederlage(x, y, spielfeld)){
        cout << "\n Bamm! bist auf eine Mine drauf. GAME OVER! \n";
        gameOver = true;
      }else{
        FillEmptySpace(y, x, spielfeld);
        if(checkSieg(y, x, spielfeld)){
          cout << "Gewonnen!! Uhu, gut gemacht.\n";
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
