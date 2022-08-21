#ifndef ARCAN_A_ARCANA_H
#define ARCAN_A_ARCANA_H
#include "arcana-types.h"

ArcanaConfig getConfig(int argc, const char *argv[]);

Card* getMyCard(unsigned char suitIndex, unsigned char minorIndex);

unsigned char getIndex(unsigned char suitIndex, unsigned char minorIndex);

Card* deal(Card *myCard);

Reading *startReading(Card *myCard, Card *deck);
unsigned char continueReading(Reading *reading);

void readMyTarot(Card* deck);

struct Card* shuffle(Card* deck); //or boogie?

void identifyCard(Card* card);
unsigned char isCourtCard(Card* card);

const char* getSuit(unsigned int suitIndex);

//Get String for Major Arcana Card
const char* getMajorString(unsigned int cardNumber);

//Get Court or Ace string
const char* getMinorString(unsigned int suitIndex);

unsigned char validateCard(Card* card);

#endif //ARCAN_A_ARCANA_H
