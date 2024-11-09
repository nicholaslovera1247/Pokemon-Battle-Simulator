#include "Opponent.h"


/* Opponent default constructor is a Pokemon, and in this case the
 * we use the overriden Opponent setXP method to give the opponent their
 * special xp
 */
Opponent::Opponent() : Pokemon() {
    setXP(getHP());
}

/*
 * Parameterized constructor calling the same method as the
 * default
 */
Opponent::Opponent(string name) : Pokemon(name) {
    setXP(getHP());
}

// Overridden function for Opponent class, sets Opponents XP to half of their HP
void Opponent::setXP(int xp) {
    int halfHP = xp / 2;
    Pokemon::setXP(halfHP);
}

/*
 * A function to be used after the battle is finished and the User has won.
 * This will return the XP of an opponent pokemon and set the User's pokemon's
 * XP to said value.
 */
int Opponent::giveXP() {
    return getXP();
}

// Has the computer pick a random attack to hit the User with
attackMoves Opponent::pickRandomAttack(){
    vector<attackMoves> moveset = this->getMoveset();
    int randomIndex = rand() % moveset.size();
    attackMoves chosenMove = moveset[randomIndex];
    return chosenMove;
}
