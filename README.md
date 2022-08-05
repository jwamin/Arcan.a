# Arcan.a

## C Static Library for the Tarot

```
Welcome to Arcan.a
Your 10-card tarot reading:
Card 1: Key 60 is in the Minor Arcana: The Paige of Swords, isInverted: 0
Card 2: Key 45 is in the Minor Arcana: The 10 of Cups, isInverted: 1
Card 3: Key 43 is in the Minor Arcana: The 8 of Cups, isInverted: 0
Card 4: Key 9 is in the MAJOR ARCANA: IX: THE HERMIT, isInverted: 1
Card 5: Key 71 is in the Minor Arcana: The 8 of Pentacles, isInverted: 1
Card 6: Key 41 is in the Minor Arcana: The 6 of Cups, isInverted: 1
Card 7: Key 74 is in the Minor Arcana: The Paige of Pentacles, isInverted: 1
Card 8: Key 41 is in the Minor Arcana: The 6 of Cups, isInverted: 1
Card 9: Key 65 is in the Minor Arcana: The 2 of Pentacles, isInverted: 1
Card 10: Key 68 is in the Minor Arcana: The 5 of Pentacles, isInverted: 0
Best of luck!

Process finished with exit code 0
```

### Features 

#### Cards

* Generate Deck

* Shuffle Deck with Fisher-Yeates

* Identify card from index 0-77

* Randomly assign inversion for card

#### Dealing

* Extract chosen court card
  * Shuffle remaining deck
* Deal top 10 cards

#### API

* Swift Package - simply hit this repo with Xcode / swiftpm
  * `swift build` 
  * `swift run ArcanaDriver`

* Cmake Project for WSL/Linux imports `arc4random_uniform` from `bsd.h`

#### TODO

* C Source cleanup

* Interactive CLI

* Refine Swift Interface
  * Wrapper to be used in GUI 
  * Tweak swift package to build against `bsd.h`

* Analyse reading (primarily suits / major arcana etc)
