//
// Created by Joss Manger on 7/18/21.
//

#include "Sources/Arcana/include/arcana.h"
#include <stdio.h>
int main(){
    printf("Welcome to Arcan.a\n");
    Card* deckTop = deal();
    readMyTarot(deckTop);

    return 0;
}