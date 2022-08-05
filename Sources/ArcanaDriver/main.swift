//
// Created by Joss Manger on 8/4/22.
//

import Foundation
import Arcana

func swiftPrint(_ str:String...){
    print("Swift",terminator:"");
    print(str)
}

func main(){

    #if canImport(Arcana)
    print("arcana importable")

    let card: UnsafeMutablePointer<Card>! = getMyCard(0,11);
    swiftPrint("hello world")
    let deck = deal(card)
    swiftPrint("dealt")
    readMyTarot(deck)
    free(deck)

    #else
    print("unable to import Arcana")
    #endif

}

main()