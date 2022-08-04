//
// Created by Joss Manger on 8/4/22.
//

import Foundation
import Arcana

func main(){

    #if canImport(Arcana)
    print("arcana importable")

    var deck: UnsafeMutablePointer<Card>! = deal()

    deck = deal()
    readMyTarot(deck)
    free(deck)

    #else
    print("unable to import Arcana")
    #endif

}

main()