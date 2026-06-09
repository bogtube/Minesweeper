#include "Spielfeld.h"
#include "ActionOnClick.h"


void FillEmptySpace(int PosX, int PosY, Spielfeld& spielfeld){
  
    if(PosX < 0 || PosX >= spielfeld.getHoehe() || PosY < 0 || PosY >= spielfeld.getBreite()){          // Weil du Maxi kein Clean Code Produzierst muss ich hier dafür sorgen das gescheite Werte in deine Funktion kommen WOW!!
        return;
    }

    if(spielfeld.istSichtbar(PosX, PosY)){
        return;
    }
    
    spielfeld.setSichtbar(PosX, PosY);                                                                  // ich meine das hast du vergessen Maxi 

    char** meinSpielfeld = spielfeld.getFeld();
    if(meinSpielfeld[PosX][PosY] == '0'){
        FillEmptySpaceRecursion(PosX,PosY,spielfeld);
    }
}

void FillEmptySpaceRecursion(int PosX, int PosY, Spielfeld& spielfeld){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){                                                       // kann man besser schreiben 
                continue;
            }
            FillEmptySpace(PosX+i,PosY+j,spielfeld);
        }
    }
}
