//
// Arcana Drive Program
// Created by Joss Manger on 7/18/21.
//
#include <stdio.h>
#include <arcana.h>
int main(){
    printf("Welcome to Arcan.a\n");
    Card myCard;
    myCard.index = 21;
    myCard.inverted = 0;
    printf("Your card is: \n");
    identifyCard(&myCard);
    Card *deckTop = deal(&myCard);
    readMyTarot(deckTop);

    return 0;
}