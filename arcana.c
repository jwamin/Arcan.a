#include "arcana.h"
#include <stdlib.h>
#include <stdio.h>

struct Card* deal(){

    struct Card* cards = malloc(sizeof(struct Card) * CARD_COUNT);
    Card* currentCard;

    //initialize deck
    for (int i = 0; i < CARD_COUNT; ++i) {
        currentCard = &cards[i];
        currentCard->inverted = arc4random_uniform(2);
        currentCard->index = i;
    }

    //TODO: Shuffle deck

    //return the newly created deck
    return cards;

}

void identifyCard(Card* card) {
    unsigned int index = card->index;



    if (index < 22) {
        // MAJOR ARCANA
        printf("card %d is MAJOR ARCANA, isInverted: %d\n",card->index,card->inverted);
        switch (card->index) {
            case FOOL:
                printf("it's the fool\n");
                break;
                //TODO: add additional cases
            default:
                break;
        }
    } else {
        //MINOR ARCANA
        unsigned int minor_index = index - 22;
        unsigned int suitIndex = minor_index / 14;
        const char* suitString = getSuit(suitIndex);
        unsigned int cardNumber = minor_index - ((suitIndex * 14));

        const char* str = getMinorString(cardNumber+1);

        printf("card %d is Minor Arcana: The %s of %s, isInverted: %d, cardNumber:%d\n",index,str,suitString,card->inverted,cardNumber);
    }

}

const char* getMinorString(unsigned int suitIndex) {
    if (suitIndex > 10 || suitIndex == 1) {
        switch (suitIndex) {
            case ACE:
                return "Ace";
            case PAIGE:
                return "Paige";
            case KNIGHT:
                return "Knight";
            case QUEEN:
                return "Queen";
            case KING:
                return "King";
            default:
                return "";
        }
    } else {
        char *out = malloc(sizeof(char)*10);
        sprintf(out,"%d",suitIndex);
        return out;
    }
}

const char* getSuit(unsigned int suitIndex){
    switch(suitIndex){
        case WANDS:
            return "Wands";
        case CUPS:
            return "Cups";
        case SWORDS:
            return "Swords";
        case PENTACLES:
            return "Pentacles";
        default:
            return "";
    }
}