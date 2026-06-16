#include <iostream>
#include <sys/ioctl.h> 
#include <unistd.h>    
#include "Anzeige.h"

using namespace std;

void Anzeige::clearScreen(){
  cout << "\033[2J\033[1;1H";
}

int getTerminalWidth() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
    return 80; 
}

void Anzeige::zeichneMenu(int& hoehe, int& breite, int& schwierigkeit){
  clearScreen();
  
  int menuBreite = 54; 
  int terminalBreite = getTerminalWidth();
  int padding = (terminalBreite - menuBreite) / 2;
  if (padding < 0) padding = 0; 

  string einzug(padding, ' ');

  cout << "\n\n";
  cout << einzug << "╔════════════════════════════════════════════════════╗\n";
  cout << einzug << "║                                                    ║\n";
  cout << einzug << "║                 M I N E S W E E P E R              ║\n";
  cout << einzug << "║                                                    ║\n";
  cout << einzug << "╠════════════════════════════════════════════════════╣\n";
  cout << einzug << "║                                                    ║\n";
  cout << einzug << "║                                                    ║\n";
  cout << einzug << "║                             (Ps. bin verschwunden) ║\n";
  cout << einzug << "╚════════════════════════════════════════════════════╝\n";
  
  cout << "\n" << einzug << "▶ Spielfeld Hoehe  (z.B. 10): ";
  cin >> hoehe;
  cout << einzug << "▶ Spielfeld Breite (z.B. 10): ";
  cin >> breite;
  cout << einzug << "▶ Schwierigkeit %  (z.B. 15): ";
  cin >> schwierigkeit;
}

// NEU: Berechnet denselben Abstand wie das Feld, damit Texte exakt bündig darunter stehen
void Anzeige::zeigeEinzug(int b) {
    int feldBreiteInZeichen = b * 7 + 4; 
    int terminalBreite = getTerminalWidth();
    int padding = (terminalBreite - feldBreiteInZeichen) / 2;
    if (padding < 0) padding = 0; 
    string einzug(padding, ' ');
    cout << einzug;
}

void Anzeige::zeichneSpielfeld(Spielfeld& feld, int score){
  clearScreen();
  
  int h = feld.getHoehe();
  int b = feld.getBreite();

  int feldBreiteInZeichen = b * 7 + 4; 
  int terminalBreite = getTerminalWidth();
  int padding = (terminalBreite - feldBreiteInZeichen) / 2;
  if (padding < 0) padding = 0; 

  string einzug(padding, ' ');

  string reset = "\033[0m";
  string rot = "\033[91m";      
  string gruen = "\033[92m";    
  string blau = "\033[94m";     
  string magenta = "\033[95m";  
  string cyan = "\033[96m";     
  string gelb = "\033[93m";     
  string gold = "\033[33;1m";

  // Score anzeigen
  cout << einzug << gold << "SCORE: " << score << reset << "\n\n";

  // X-Koordinaten (Spalten) oberhalb des Feldes rendern
  cout << einzug << "    "; 
  for(int j = 0; j < b; j++){
      if(j < 10) cout << "  " << j << "    ";
      else       cout << " " << j << "    ";
  }
  cout << "\n\n";

  for(int i = 0; i < h; i++){
    cout << einzug;

    // Y-Koordinaten (Zeilen) links vom Spielfeld anzeigen
    if (i < 10) cout << " " << i << "  ";
    else cout << i << "  ";

    for(int j = 0; j < b; j++){
      if(feld.istSichtbar(i, j)){ 
        char zeichen = feld.getFeld()[i][j];

        if(zeichen == '0') {
            cout << "[   ]  "; 
        } 
        else {
            cout << "[ ";
            if(zeichen == '1')      cout << rot << zeichen << reset;
            else if(zeichen == '2') cout << gruen << zeichen << reset;
            else if(zeichen == '3') cout << blau << zeichen << reset;
            else if(zeichen == '4') cout << magenta << zeichen << reset;
            else if(zeichen == '5' || zeichen == '6') cout << cyan << zeichen << reset;
            else cout << zeichen; 
            cout << " ]  ";
        }

      } else if (feld.hatFlagge(i, j)){
          cout << "[ " << gelb << "F" << reset << " ]  ";
      } else {
          cout << "[ # ]  "; 
      }
    }
    cout << "\n\n";
  }
}
