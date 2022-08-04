//
// Created by Joss Manger on 8/4/22.
//

import Foundation


func main(){

    #if canImport(Arcana)
    print("arcana importable")
    #else
    print("unable to import Arcana")
    #endif

}

main()