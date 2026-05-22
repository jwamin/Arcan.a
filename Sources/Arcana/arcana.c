#include "arcana.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef _HAS_ARC4RANDOM
#warning "_HAS_ARC4RANDOM unset will try to link bsd"
#include <bsd/bsd.h>
#endif



struct Card* deal(Card* myCard){

    if (!validateCard(myCard) || !isCourtCard(myCard)){
        printf("Choose a court card as your significator — the cards will not speak otherwise.\n");
        return NULL;
    }

    Card* cards = calloc(SHUFFLE_COUNT, sizeof(Card));
    if (!cards) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
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
        printf("The cards lie in darkness, unreadable. A heavy omen.\n");
        return;
    }

    printf("The spread is laid. Your %d-card reading:\n\n",DEAL);
    for (int i = 0; i < DEAL; ++i) {
        printf("  Card %d — ",i+1);
        identifyCard(&deck[i]);
    }
    printf("\nMay the cards light your way.\n");
}

void readThreeCard(Card* deck) {
    if (!validateCard(deck)) {
        printf("The cards lie in darkness, unreadable. A heavy omen.\n");
        return;
    }
    const char* positions[DEAL_THREE] = {"Past", "Present", "Future"};
    printf("Three cards rise from the dark:\n\n");
    for (int i = 0; i < DEAL_THREE; ++i) {
        printf("  %s — ", positions[i]);
        identifyCard(&deck[i]);
    }
    printf("\nMay the cards light your way.\n");
}

Reading *startReading(Card *myCard, Card *deck, unsigned char count) {

    Reading *reading = malloc(sizeof(Reading));
    if (!reading) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    reading->courtCardForQuerant = myCard;
    reading->current = 0;
    reading->deck = deck;
    reading->count = count;

    return reading;

}

unsigned char continueReading(Reading *reading) {
    unsigned char i = reading->current;

    if (i < reading->count) {
        if (reading->count == DEAL_THREE) {
            const char* positions[DEAL_THREE] = {"Past", "Present", "Future"};
            printf("  %s — ", positions[i]);
        } else {
            printf("  Card %d — ", i + 1);
        }
        identifyCard(&reading->deck[i]);
        i++;
        reading->current = i;
        return (i == reading->count) ? 0 : 1;
    } else {
        return 0;
    }
}

// Basic F-Y Shuffle
struct Card* shuffle(Card *deck){

    unsigned int swapIndex;
    Card* swap;

    for (unsigned int current = 0; current < SHUFFLE_COUNT; ++current) {
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
    const char* orientation = card->inverted ? "Reversed" : "Upright";

    if (index < 22) {
        const char* majorString = getMajorString(card->index);
        printf("%s  (%s)\n", majorString, orientation);
    } else {
        unsigned int minor_index = index - 22;
        unsigned int suitIndex = minor_index / 14;
        unsigned int cardNumber = minor_index % 14;

        const char* suitString = getSuit(suitIndex);
        const char* str = getMinorString(cardNumber+1);

        printf("The %s of %s  (%s)\n", str, suitString, orientation);
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
                return "0 — THE FOOL";
            case MAGICIAN:
                return "I — THE MAGICIAN";
            case HIGH_PRIESTESS:
                return "II — THE HIGH PRIESTESS";
            case EMPRESS:
                return "III — THE EMPRESS";
            case EMPEROR:
                return "IV — THE EMPEROR";
            case HIEROPHANT:
                return "V — THE HIEROPHANT";
            case LOVERS:
                return "VI — THE LOVERS";
            case CHARIOT:
                return "VII — THE CHARIOT";
            case STRENGTH:
                return "VIII — STRENGTH";
            case HERMIT:
                return "IX — THE HERMIT";
            case WHEEL_OF_FORTUNE:
                return "X — WHEEL OF FORTUNE";
            case JUSTICE:
                return "XI — JUSTICE";
            case HANGED_MAN:
                return "XII — THE HANGED MAN";
            case DEATH:
                // Remember, there's only meant to be one in each pack...
                return "XIII — DEATH";
            case TEMPERANCE:
                return "XIV — TEMPERANCE";
            case DEVIL:
                return "XV — THE DEVIL";
            case TOWER:
                return "XVI — THE TOWER";
            case STAR:
                return "XVII — THE STAR";
            case MOON:
                return "XVIII — THE MOON";
            case SUN:
                return "XIX — THE SUN";
            case JUDGEMENT:
                return "XX — JUDGEMENT";
            case WORLD:
                return "XXI — THE WORLD";
            default:
                fprintf(stderr, "major arcana index out of range\n");
                exit(EXIT_FAILURE);
        }
}

static const char* toRoman(unsigned int n) {
    switch (n) {
        case 2:  return "II";
        case 3:  return "III";
        case 4:  return "IV";
        case 5:  return "V";
        case 6:  return "VI";
        case 7:  return "VII";
        case 8:  return "VIII";
        case 9:  return "IX";
        case 10: return "X";
        default: return "";
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
                fprintf(stderr, "minor arcana index out of range\n");
                exit(EXIT_FAILURE);
        }
    } else {
        return toRoman(suitIndex);
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
        return myCard;
    }
    return NULL;

}

unsigned char getIndex(unsigned char suitIndex, unsigned char minorIndex) {
    return minorIndex + (suitIndex * MINOR_ARCANA_COUNT) + (MAJOR_ARCANA_COUNT - 1);
}

ArcanaConfig getConfig(int argc, const char *argv[]) {
    ArcanaConfig result = {0};
    char c = '\0';
    while(--argc > 0 && (*++argv)[0] == '-'){

        while (c = *++argv[0]){
            switch(c){
                case 'i':
                    result.interactive = 1;
                    break;
                case '3':
                    result.threeCard = 1;
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
    if (!myCard) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    myCard->index = getIndex(suitIndex,minorIndex);
    myCard->inverted = 0;

    if (validateCard(myCard)){
        return myCard;
    }

    return NULL;
}


