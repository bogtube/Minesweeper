#ifndef SPIELFELD_H
#define SPIELFELD_H

class Spielfeld {
private:
    int hoehe = 0;
    int breite = 0;
    int radius = 0;
    int anzahlBomben = 0;

    bool** sichtbar;
    bool** flagge;

    char** feld = nullptr;

public:
    ~Spielfeld();

    void setHoehe(int h);
    void setBreite(int b);
    void setRadius(int r);
    void inFeld(int h, int b);
    void setSichtbar(int x, int y);
    void bauDonutSpielfeld(int radius);
    void bauSpielfeld(int hoehe, int breite);
    void initialisierungSpielfeld(int h, int b);

    void toggleFlagge(int x, int y);
    bool hatFlagge(int x, int y);

    bool istSichtbar(int x, int y);
    
    int getHoehe();
    int getBreite();
    int getRadius();

    char** getFeld();
   
   };

#endif
