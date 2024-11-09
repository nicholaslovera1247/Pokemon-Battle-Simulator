//
// Created by Nick Lovera on 9/12/24.
//

#include "attackMoves.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

/* Attack Moves Class */
attackMoves::attackMoves() : moveName("None"), moveDamage(0), moveElement("None") {}
attackMoves::attackMoves(string name,string element,int dmg): moveName(name),moveElement(element),moveDamage(dmg){}

vector<attackMoves> attackMoves::loadMovesFromFile() {
    vector<attackMoves> moves;

    fstream fin;

    fin.open("../pokemonMoves.csv", ios::in);

    if (!fin.is_open()) {
        cout << "Error in creating move!" << endl;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string tempName, tempElement, tempIndex;
        int tempDMG;

        getline(ss, tempIndex, ',');
        getline(ss, tempName, ',');
        getline(ss, tempElement, ',');
        ss >> tempDMG;

        attackMoves move(tempName,tempElement,tempDMG);
        moves.push_back(move);

    }
    fin.close();
    return moves;
}


// Returns the attack move's name
string attackMoves::getMoveName() const {
    return moveName;
}


// Returns the atack move's damage infliction (how much damage it does)
int attackMoves::getMoveDamage() const {
    return moveDamage;
}

/* Returns the attack move's element, this will be used in a later iteration of the program
 * when we start to have battles between Pokemon and have to deal with which elements
 * are super/not very effective against each other
 */
string attackMoves::getMoveElement() const {
    return moveElement;
}


// Sets the attack move's name
void attackMoves::setMoveName(std::string name) {
    moveName = name;
}

// Sets the attack move's damage value
void attackMoves::setMoveDamage(int damage) {
    moveDamage = damage;
}

// Sets the attack move's element
void attackMoves::setMoveElement(std::string element) {
    moveElement = element;
}

// Overloaded operator for ==
bool attackMoves::operator==(const attackMoves &other) const {
    return this->moveName == other.moveName &&
           this->moveDamage == other.moveDamage &&
           this->moveElement == other.moveElement;
}