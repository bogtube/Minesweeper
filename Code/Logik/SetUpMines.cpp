#include <random>
#include "SetUpMines.h"
#include "Spielfeld.h"

using namespace std;


void placeMines(int SizeX, int SizeY, int difficulty, Spielfeld& field){

    int fieldSpaces = SizeX * SizeY;

    int MineAmount = (fieldSpaces * difficulty) / 100;

    for(int i = 0; i < MineAmount; i++){
        randomPlacement(SizeX,SizeY,field);
    }
}

void randomPlacement(int SizeX, int SizeY, Spielfeld& field){
    char** myField = field.getFeld();
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distX(0,SizeX - 1);
    uniform_int_distribution<> distY(0,SizeY - 1);

    while(true){
        int PosX = distX(gen);
        int PosY = distY(gen);

        if(!isMine(PosX,PosY,field)){
            myField[PosX][PosY] = 'M';
            break;
        }
    }
}
