//
// Arcana Drive Program
// Created by Joss Manger on 7/18/21.
//
#include <stdio.h>
#include <arcana.h>
int main(){
    printf("Welcome to Arcan.a\n");
    Card *deckTop = deal();
    readMyTarot(deckTop);

    return 0;
}