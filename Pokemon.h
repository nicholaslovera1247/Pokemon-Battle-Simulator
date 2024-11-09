//
// Created by Nick Lovera on 9/7/24.
//

#ifndef M1OEP_NLOVERA_POKEMON_H
#define M1OEP_NLOVERA_POKEMON_H
#include <string>
#include <vector>
#include "attackMoves.h"
using namespace std;

class Pokemon{

private:
    // Fields
    string pokemonName;
    string pokemonElement;
    string pokemonIndex;
    int pokemonHP;
    int XP;
    vector<attackMoves> pokemonMoveset;
public:
    // Default constructor
    Pokemon();

    // Parameterized Constructor
    explicit Pokemon(string name);

    // Getters
    string getName() const;

    string getElementType() const;

    vector<attackMoves> getMoveset() const;

    int getHP() const;

    int getXP() const;

    string getIndexNum() const;

    //Setters
    void setName(string name);

    void setElementType(string element);

    void setMoveset(vector<attackMoves> moveset);

    void setHP(int hp);

    virtual void setXP(int xp);

    void setIndexNum(int index);


    // Custom methods

    void teachMove();

    void addMove();

    void deleteMove(attackMoves move);

    void clearMoveset();

    //Overloaded operator for == (Should have done this last module lol)
    bool operator==(const Pokemon& other) const;



};




#endif //M1OEP_NLOVERA_POKEMON_H
