#include "arcana.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef _HAS_ARC4RANDOM
#warning "_HAS_ARC4RANDOM unset will try to link bsd"
#include <bsd/bsd.h>
#endif



struct Card* deal(Card* myCard){

    if (!validateCard(myCard) || !isCourtCard(myCard)){
        printf("IF you don't pick a court card, i'm not reading your tarot\n");
        return NULL;
    }

    Card* cards = calloc(SHUFFLE_COUNT, sizeof(Card));
    Card* currentCard;

    //initialize deck
    for (int i = 0; i < CARD_COUNT; ++i) {
        if (i == myCard->index) {
            continue;
        }
        currentCard = &cards[i];
        currentCard->inverted = arc4random_uniform(2);
        currentCard->index = i;
    }

    shuffle(cards);

    //return the newly created and shuffled deck
    return cards;

}

unsigned char validateCard(Card* card){
    if (card == NULL){
        return 0;
    }
    return 1;
}

void readMyTarot(Card* deck){

    if (!validateCard(deck)){
        printf("I failed to read your tarot - This is a VERY bad omen.\n");
        return;
    }

    printf("Your %d-card tarot reading:\n",DEAL);
    for (int i = 0; i < DEAL; ++i) {
        printf("Card %d: ",i+1);
        identifyCard(&deck[i]);
    }
    printf("Best o' luck!\n");
}

Reading *startReading(Card *myCard, Card *deck) {

    Reading *reading = malloc(sizeof(Reading));
    reading->courtCardForQuerant = myCard;
    reading->current = 0;
    reading->deck = deck;

    return reading;

}

unsigned char continueReading(Reading *reading) {
    unsigned char i = reading->current;

    if (i < DEAL) {
        printf("Card %d: ", i + 1);
        identifyCard(&reading->deck[i]);
        i++;
        reading->current = i;
        return (i == DEAL) ? 0 : 1;
    } else {
        return 0;
    }
}

// Basic F-Y Shuffle
struct Card* shuffle(Card *deck){

    unsigned int swapIndex;
    Card* swap;

    for (unsigned int current = 0; current < CARD_COUNT; ++current) {
        swapIndex = current + arc4random_uniform(CARD_COUNT - current);
        if (swapIndex != current){
            //printf("%d will swap %d with %d\n",current,deck[current].index,deck[swapIndex].index);
            //assign swap to current index
            swap = &deck[current];
            //make current the randomly selected index
            deck[current] = deck[swapIndex];
            //make random index the currentIndex
            deck[swapIndex] = *swap;
            if (current == 0){
                deck = swap;
            }
        }
    }

    return deck;

}

void identifyCard(Card* card) {
    unsigned int index = card->index;

    if (index < 22) {
        // MAJOR ARCANA
        const char* majorString = getMajorString(card->index);
        printf("Key %d is in the MAJOR ARCANA: %s, isInverted: %d\n", card->index, majorString, card->inverted);
    } else {
        //MINOR ARCANA
        unsigned int minor_index = index - 22;
        unsigned int suitIndex = minor_index / 14;
        unsigned int cardNumber = minor_index % 14;

        const char* suitString = getSuit(suitIndex);
        const char* str = getMinorString(cardNumber+1);

        printf("Key %d is in the Minor Arcana: The %s of %s, isInverted: %d\n", index, str, suitString, card->inverted);
    }

}



unsigned char isCourtCard(Card* card){

    int minor_index = card->index - (MAJOR_ARCANA_COUNT - 1);
    unsigned char suitIndex = minor_index / 14;

    if (minor_index <= 0){
        //major arcana
        return 0;
    }

    if (minor_index > 10) {
        return 1;
    }

    return 0;

}

const char* getMajorString(unsigned int cardNumber) {
        switch (cardNumber) {
            case FOOL:
                return "0: THE FOOL";
            case MAGICIAN:
                return "I: THE MAGICIAN";
            case HIGH_PRIESTESS:
                return "II: THE HIGH PRIESTESS";
            case EMPRESS:
                return "III: THE EMPRESS";
            case EMPEROR:
                return "IV: THE EMPEROR";
            case HIEROPHANT:
                return "V: THE HIEROPHANT";
            case LOVERS:
                return "VI: THE LOVERS";
            case CHARIOT:
                return "VII: THE CHARIOT";
            case STRENGTH:
                return "VIII: STRENGTH";
            case HERMIT:
                return "IX: THE HERMIT";
            case WHEEL_OF_FORTUNE:
                return "X: WHEEL OF FORTUNE";
            case JUSTICE:
                return "XI: JUSTICE";
            case HANGED_MAN:
                return "XII: THE HANGED MAN";
            case DEATH:
                // Remember, there's only meant to be one in each pack...
                return "XIII: DEATH";
            case TEMPERANCE:
                return "XIV: TEMPERENCE";
            case DEVIL:
                return "XV: THE DEVIL";
            case TOWER:
                return "XVI: THE TOWER";
            case STAR:
                return "XVII: THE STAR";
            case MOON:
                return "XVIII: THE MOON";
            case SUN:
                return "XIX: THE SUN";
            case JUDGEMENT:
                return "XX: JUDGEMENT";
            case WORLD:
                return "XXI: THE WORLD";
            default:
                printf("major arcana card out of index <0 / >22");
                exit(EXIT_FAILURE);
        }
}

const char* getMinorString(unsigned int suitIndex) {

    // Is a court card or ace
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
                printf("this shouldn't happen");
                exit(EXIT_FAILURE);
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

Card *getMyCard(unsigned char suitIndex, unsigned char minorIndex) {

    Card *myCard = makeCard(suitIndex,minorIndex);
    identifyCard(myCard);
    if (isCourtCard(myCard)) {
        printf("got a court card\n");
        return myCard;
    }
    printf("not a court card\n");
    return NULL;

}

unsigned char getIndex(unsigned char suitIndex, unsigned char minorIndex) {
    return minorIndex + (suitIndex * MINOR_ARCANA_COUNT) + (MAJOR_ARCANA_COUNT - 1);
}

ArcanaConfig getConfig(int argc, const char *argv[]) {
    ArcanaConfig result;
    char c;
    while(--argc > 0 && (*++argv)[0] == '-'){

        printf("%c\n",c);
        while (c = *++argv[0]){
            switch(c){
                case 'i':
                    result.interactive = 1;
                    break;
                //case more arguments
                default:
                    result.interactive = 0;
                    break;
            }
        }
    }

    return result;
}

Card *makeCard(unsigned char suitIndex, unsigned char minorIndex) {
    Card *myCard = (Card*) malloc(sizeof(Card));
    myCard->index = getIndex(suitIndex,minorIndex);
    myCard->inverted = 0;

    if (validateCard(myCard)){
        return myCard;
    }

    return NULL;
}


