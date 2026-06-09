#include "Spielfeld.h"
#include "CountMinesEx.h"
#include <stdexcept>


int countMinesAroundTarget(int posX, int posY, Spielfeld& field){
    int amountOfMines = 0;
    char** myField = field.getFeld(); 
    for(int i = posX - 1; i < posX + 2; i++){
        for(int j = posY - 1; j < posY + 2; j++){
            try{
                if(isMine(i,j,field)){
                    amountOfMines++;
                }
            }
            catch(...){}
        }
    }
    return amountOfMines;
}

void countMines(int SizeX, int SizeY, Spielfeld& field){
    char** myField = field.getFeld();
    for(int i = 0; i < SizeX; i++){
        for(int j = 0; j < SizeY; j++){
            if(!isMine(i,j,field)){
                myField[i][j] = countMinesAroundTarget(i,j,field) + '0';
            }
        }
    }
}

bool isMine(int posX, int posY, Spielfeld& field){
  if(posX < 0 || posX >= field.getHoehe() || posY < 0 || posY >= field.getBreite()) {
    return false;
  }
  char** myField = field.getFeld();
  return myField[posX][posY] == 'M';
}
