#include <iostream>
#include "Anzeige.h"

using namespace std;

void Anzeige::clearScreen(){
  cout << "\033[2J\033[1;1H";
};

void Anzeige::zeichneMenu(){
  bool imMenu = true;
  int auswahl = 0;
};


void Anzeige::zeichneSpielfeld(Spielfeld& feld){
  clearScreen();
  
  int h = feld.getHoehe();
  int b = feld.getBreite();
  char** meinArray = feld.getFeld();

  for(int i = 0; i < h; i++){
    for(int j = 0; j < b; j++){
      if(feld.istSichtbar(i, j)){ 
        cout << "[ " << feld.getFeld()[i][j] << " ]  ";
        }else if (feld.hatFlagge(i, j)){
          cout << "[ F ]  ";
        }else{
          cout << "[ # ]  "; // Zeigt ein verdecktes Feld an
        }
    }
    cout << "\n\n";
}
};
