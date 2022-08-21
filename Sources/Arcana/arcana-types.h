//
// Created by Joss Manger on 8/4/22.
//

#ifndef ARCANA_TYPES_H
#define ARCANA_TYPES_H

#define CARD_COUNT 78
#define SHUFFLE_COUNT CARD_COUNT-1
#define DEAL 10
#define MAJOR_ARCANA_COUNT 22
#define MINOR_ARCANA_COUNT 14
#define TOTAL (MAJOR_ARCANA_COUNT+(MINOR_ARCANA_COUNT*4))

/*structs*/

typedef struct ArcanaConfig {
    unsigned char interactive;
} ArcanaConfig;

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

typedef struct Reading {
    struct Card* deck;
    struct Card* courtCardForQuerant;
    unsigned char current;
} Reading;

#endif //ARCANA_TYPES_H
