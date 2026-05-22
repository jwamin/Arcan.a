//
// Arcana Drive Program
// Created by Joss Manger on 7/18/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <arcana.h>
int main(int argc, const char *argv[]){

    printf("\n~ A R C A N . A ~\nThe cards await...\n\n");

    //process arguments
    // -i will do getChar Interactive mode - no arg will simply print whole reading
    ArcanaConfig config = getConfig(argc,argv);

    Card myCard;
    myCard.index = 32;
    myCard.inverted = 0;

    printf("Your significator:\n");
    identifyCard(&myCard);

    Card *deckTop = deal(&myCard);

    if (!deckTop) {
        fprintf(stderr, "The deck could not be conjured. Something is amiss.\n");
        exit(EXIT_FAILURE);
    }

    Reading *thisReading = NULL;
    if (config.interactive) {
        unsigned char count = config.threeCard ? DEAL_THREE : DEAL;
        thisReading = startReading(&myCard, deckTop, count);
        getchar();
        unsigned char isReading = continueReading(thisReading);
        while(1){
            getchar();
            isReading = continueReading(thisReading);
            if(!isReading){
                break;
            }
        }
        printf("\nMay the cards light your way.\n");
    } else if (config.threeCard) {
        readThreeCard(deckTop);
    } else {
        readMyTarot(deckTop);
    }
    free(deckTop);
    free(thisReading);
    return 0;
}