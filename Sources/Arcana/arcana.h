#ifndef ARCAN_A_ARCANA_H
#define ARCAN_A_ARCANA_H

#define CARD_COUNT 78
#define SHUFFLE_COUNT CARD_COUNT-1
#define DEAL 10
#define MAJOR_ARCANA_COUNT 22
#define MINOR_ARCANA_COUNT 14
#define TOTAL (MAJOR_ARCANA_COUNT+(MINOR_ARCANA_COUNT*4))

/*structs*/

typedef enum Major_Arcana {
    FOOL = 0,
    MAGICIAN,
    HIGH_PRIESTESS,
    EMPRESS,
    EMPEROR,
    HIEROPHANT,
    LOVERS,
    CHARIOT,
    STRENGTH,
    HERMIT,
    WHEEL_OF_FORTUNE,
    JUSTICE,
    HANGED_MAN,
    DEATH,
    TEMPERANCE,
    DEVIL,
    TOWER,
    STAR,
    MOON,
    SUN,
    JUDGEMENT,
    WORLD
} Major_Arcana;

typedef enum Suit {
    WANDS = 0,
    CUPS,
    SWORDS,
    PENTACLES
} Suit;

typedef enum CourtCard {
    ACE = 1,
    PAIGE = 11,
    KNIGHT = 12,
    QUEEN = 13,
    KING = 14
} CourtCard;

typedef struct Card {
    unsigned char index;
    unsigned char inverted;
} Card;

typedef struct Deal {
    struct Card* deck;
    struct Card* courtCardForQuerant;
} Deal;

Card* getMyCard(unsigned char suitIndex, unsigned char minorIndex);

unsigned char getIndex(unsigned char suitIndex, unsigned char minorIndex);

Card* deal(Card *myCard);

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
