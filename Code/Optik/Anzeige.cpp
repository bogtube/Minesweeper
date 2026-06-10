#include <iostream>
#include <sys/ioctl.h> // Wird benötigt, um die Terminalgröße unter Linux/macOS auszulesen
#include <unistd.h>    // Für STDOUT_FILENO
#include "Anzeige.h"

using namespace std;

void Anzeige::clearScreen(){
  cout << "\033[2J\033[1;1H";
}

void Anzeige::zeichneMenu(){
  bool imMenu = true;
  int auswahl = 0;
}

// Hilfsfunktion, um die aktuelle Terminalbreite zu ermitteln
int getTerminalWidth() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
    return 80; // Standard-Fallback, falls die Erkennung fehlschlägt
}

void Anzeige::zeichneSpielfeld(Spielfeld& feld){
  clearScreen();
  
  int h = feld.getHoehe();
  int b = feld.getBreite();

  // 3. Zentrierung berechnen
  // Ein Feld "[ X ]  " ist genau 7 Zeichen breit.
  int feldBreiteInZeichen = b * 7; 
  int terminalBreite = getTerminalWidth();
  int padding = (terminalBreite - feldBreiteInZeichen) / 2;
  if (padding < 0) padding = 0; // Verhindern von negativen Abständen bei kleinen Fenstern

  // ANSI-Farbcodes definieren
  string reset = "\033[0m";
  string rot = "\033[91m";      // 1
  string gruen = "\033[92m";    // 2
  string blau = "\033[94m";     // 3
  string magenta = "\033[95m";  // 4
  string cyan = "\033[96m";     // 5
  string gelb = "\033[93m";     // 6 oder Flagge

  for(int i = 0; i < h; i++){
    // Vor jeder Zeile das berechnete Padding für die Zentrierung ausgeben
    for(int p = 0; p < padding; p++) {
        cout << " ";
    }

    for(int j = 0; j < b; j++){
      if(feld.istSichtbar(i, j)){ 
        char zeichen = feld.getFeld()[i][j];

        // 2. Freie Felder (0) leer anzeigen
        if(zeichen == '0') {
            cout << "[   ]  "; // Drei Leerzeichen für die leere Optik
        } 
        // 1. Zahlen in verschiedenen Farben anzeigen
        else {
            cout << "[ ";
            if(zeichen == '1')      cout << rot << zeichen << reset;
            else if(zeichen == '2') cout << gruen << zeichen << reset;
            else if(zeichen == '3') cout << blau << zeichen << reset;
            else if(zeichen == '4') cout << magenta << zeichen << reset;
            else if(zeichen == '5' || zeichen == '6') cout << cyan << zeichen << reset;
            else cout << zeichen; // Falls es eine Mine ('X') o.ä. ist
            cout << " ]  ";
        }

      } else if (feld.hatFlagge(i, j)){
          // Flagge z.B. in Gelb anzeigen
          cout << "[ " << gelb << "F" << reset << " ]  ";
      } else {
          cout << "[ # ]  "; // Zeigt ein verdecktes Feld an
      }
    }
    cout << "\n\n";
  }
}
