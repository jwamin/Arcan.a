//
// Arcana Drive Program
// Created by Joss Manger on 7/18/21.
//
#include <stdio.h>
#include <arcana.h>
int main(int argc, const char *argv[]){

    printf("Welcome to Arcan.a\n");

    //process arguments
    // -i will do getChar Interactive mode - no arg will simply print whole reading
    ArcanaConfig config = getConfig(argc,argv);

    Card myCard;
    myCard.index = 32;
    myCard.inverted = 0;

    printf("Your card is: \n");
    identifyCard(&myCard);

    Card *deckTop = deal(&myCard);

    if (config.interactive) {
        Reading *thisReading = startReading(&myCard,deckTop);
        getchar();
        unsigned char isReading = continueReading(thisReading);
        while(1){
            getchar();
            isReading = continueReading(thisReading);
            if(!isReading){
                break;
            }
        }
        printf("Best o' luck!\n");
    } else {
        readMyTarot(deckTop);
    }

    return 0;
}