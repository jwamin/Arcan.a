//
// Created by Joss Manger on 7/18/21.
//

#include "arcana.h"
#include <stdio.h>
int main(){
    printf("Welcome to Arcan.a\n");
    Card* deckTop = deal();
    read(deckTop);

    return 0;
}