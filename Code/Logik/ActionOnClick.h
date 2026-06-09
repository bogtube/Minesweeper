#ifndef ACTIONONCLICK_H
#define ACTIONONCLICK_H
#include "Spielfeld.h"

void FillEmptySpace(int PosX, int PosY, Spielfeld& spielfeld);
void FillEmptySpaceRecursion(int PosX, int PosY, Spielfeld& spielfeld);           // Spielfeld vereint die Objekte eh, müssen nicht beide Sichtbar und nichtSichtbar als input nehmen 

#endif
