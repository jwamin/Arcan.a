//
// Created by Joss Manger on 7/18/21.
//

#include "arcana.h"

int main(){

    Card* deckTop = deal();
    for (int i = 0; i < CARD_COUNT; ++i) {
        identifyCard(&deckTop[i]);
    }

}