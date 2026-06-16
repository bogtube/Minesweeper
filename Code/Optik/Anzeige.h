#ifndef ANZEIGE_H
#define ANZEIGE_H
#include "../Logik/Spielfeld.h"

class Anzeige{
  public:
    void clearScreen();
    void zeichneSpielfeld(Spielfeld& feld, int score);
    void zeichneMenu(int& hoehe, int& breite, int& schwierigkeit);
    void zeigeEinzug(int breite);
};
#endif
