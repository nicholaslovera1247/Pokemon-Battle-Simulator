//
// Created by Nick Lovera on 9/12/24.
//

#include "Pokemon.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

/* Pokemon Class */


// Get a random pokemon!
Pokemon::Pokemon(): pokemonName("None"), pokemonElement("None"), pokemonHP(0), pokemonIndex("0"), XP(0), pokemonMoveset(){
    int random_int = rand() % 151 + 1;
    string random_int_string = to_string(random_int);

    fstream fin;

    fin.open("../pokemon.csv",ios::in);

    if(!fin.is_open()){
        cout << "Error in creating Pokemon!" << endl;
    }

    string line;
    while(getline(fin,line)){
        stringstream ss(line);
        string tempName,tempElement,tempIndex;
        int tempHP;

        getline(ss,tempIndex,',');
        getline(ss,tempName,',');
        getline(ss,tempElement,',');
        ss >> tempHP;

        if(random_int_string == tempIndex){
            this->pokemonIndex = tempIndex;
            this->pokemonName = tempName;
            this->pokemonElement = tempElement;
            this->pokemonHP = tempHP;
            teachMove();
            this->XP = 0;
            break;
        }
    }
    fin.close();
}

// Select a Pokemon
Pokemon::Pokemon(std::string name): pokemonName("?"), pokemonElement("?"), pokemonHP(0), XP(0), pokemonIndex("0"),pokemonMoveset() {
    fstream fin;

    fin.open("../pokemon.csv",ios::in);

    if(!fin.is_open()){
        cout << "Error in creating Pokemon!" << endl;
    }

    string line;
    while(getline(fin,line)){
        stringstream ss(line);
        string tempName, tempElement, tempIndex;
        int tempHP;

        getline(ss,tempIndex,',');
        getline(ss, tempName,',');
        getline(ss,tempElement,',');
        ss >> tempHP;

        if (name == tempName){
            this->pokemonIndex = tempIndex;
            this->pokemonName = tempName;
            this->pokemonElement = tempElement;
            this->pokemonHP = tempHP;
            teachMove();
            this->XP = 0;
            break;
        }
    }
    fin.close();

}

// Returns a Pokemon's name
string Pokemon::getName() const {
    return pokemonName;
}

// Returns a Pokemon's element
string Pokemon::getElementType() const {
    return pokemonElement;
}

// Ruturns a Pokemon's HP
int Pokemon::getHP() const {
    return pokemonHP;
}

// Returns a Pokemon's Index Number as a sting
string Pokemon::getIndexNum() const {
    return pokemonIndex;
}

// Returns a Pokemon's XP count (once it reaches 100 they evolve)
int Pokemon::getXP() const {
    return XP;
}

// Returns a Pokemon's moveset
vector<attackMoves> Pokemon::getMoveset() const {
    return pokemonMoveset;
}

// Sets the Pokemon's name
void Pokemon::setName(std::string name) {
    pokemonName = name;
}

// Sets the Pokemon's element type
void Pokemon::setElementType(std::string element) {
    pokemonElement = element;
}

// Sets Pokemon's HP
void Pokemon::setHP(int hp) {
    pokemonHP = hp;
}

void Pokemon::setIndexNum(int index) {
    pokemonIndex = to_string(index);
}

// Virtual function that sets a Pokemons XP
void Pokemon::setXP(int xp) {
    XP = xp;
}

// Sets a Pokemon's moveset
void Pokemon::setMoveset(vector<attackMoves> moveset) {
    pokemonMoveset = moveset;
}


/*
 * This method is used to initially give a Pokemon 3 moves when it is created. In later
 * versions we will make another method that allows you to pick a new ability
 */

void Pokemon::teachMove() {
    attackMoves move;
    vector<attackMoves> moveVec = move.loadMovesFromFile();
    while(this->pokemonMoveset.size() < 3){
        int randInt = rand() % moveVec.size();
        attackMoves attackMove = moveVec[randInt];
        auto first = this->pokemonMoveset.begin();
        auto last = this->pokemonMoveset.end();
        auto it = find(first,last,attackMove);
        if(attackMove.getMoveElement() == pokemonElement && it == last){
            this->pokemonMoveset.push_back(attackMove);
        }
    }
}

/*
 * This method allows the user to add 1 random move to their moveset, given
 * their moveset is less than 3. We return a true boolean if the move was
 * successfully added, and a false boolean if their moveset is full along
 * with an error message stating that they need to delete a move first to add
 * another one. Has a 1 in 100 chance to add a move that does not have the Pokemon's
 * element type
 */
void Pokemon::addMove() {
    int luckyInt = rand() % 100 + 1;
    if (this->pokemonMoveset.size() != 3){
        bool validation = true;
        while(validation) {
            attackMoves move;
            vector<attackMoves> moveVec = move.loadMovesFromFile();
            int randInt = rand() % moveVec.size();
            attackMoves attackMove = moveVec[randInt];
            auto first = this->pokemonMoveset.begin();
            auto last = this->pokemonMoveset.end();
            auto it = find(first,last,attackMove);
            if (luckyInt == 100){
                if(attackMove.getMoveElement() != this->pokemonElement && it == last) {
                    cout << "LUCKY PULL! This move does not have the Pokemon's element!" << endl;
                    this->pokemonMoveset.push_back(attackMove);
                    validation = false;
                }
            }
            else if (attackMove.getMoveElement() == this->pokemonElement and it == last) {
                this->pokemonMoveset.push_back(attackMove);
                validation = false;
            }
        }
    }
    else{
        cout << "Moveset full! Please delete a move to get a new random one" << endl;
    }
}


/*
 * This method is used to have a Pokemon forget a specific move to make room for them
 * to learn another one. If they have not learned any moves, we issue an error message to the
 * user to avoid a compiler error in the form of an index error, and urge them to teach their
 * Pokemon some moves. We also return a boolean of true or false, true if a move was deleted
 * and false if either the vector has no moves or if the move is not found
 */
void Pokemon::deleteMove(attackMoves move) {
    if (pokemonMoveset.size() > 0){
        auto first = pokemonMoveset.begin();
        auto last = pokemonMoveset.end();
        auto it = find(first,last,move);
        if (it != pokemonMoveset.end()){
            pokemonMoveset.erase(it);
        }
        else{
            cout << "Move not found in moveset" << endl;
        }
    }
    else{
        cout << "Your Pokemon has not learned any moves! Teach it some!" << endl;
    }
}

// Clears out a Pokemon moveset
void Pokemon::clearMoveset() {
    auto first = pokemonMoveset.begin();
    auto last = pokemonMoveset.end();
    pokemonMoveset.erase(first,last);
}



// Overloaded operator for ==
bool Pokemon::operator==(const Pokemon &other) const {
    return this->pokemonName == other.pokemonName &&
           this->pokemonElement == other.pokemonElement &&
           this->pokemonHP == other.pokemonHP &&
           this->pokemonIndex == other.pokemonIndex;
}


