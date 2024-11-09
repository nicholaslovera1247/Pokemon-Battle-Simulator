//
// Created by Nick Lovera on 10/5/24.
//
#include "User.h"
#include <iostream>

// Default Constructor
User::User(): userPokemon() {}


// Returns a string of all the Pokemon the user has
void User::string_return() {
    int i = 1;
    cout << "Here your current Pokemon!" << endl;
    cout << "-------------------------------" << endl;
    for(Pokemon pokemon : userPokemon){
        cout << "Pokemon " + to_string(i) << endl;
        cout << "-------------------------------" << endl;
        cout << "Name: " + pokemon.getName() << endl;
        cout << "Element: " + pokemon.getElementType() << endl;
        cout << "HP: " + to_string(pokemon.getHP()) << endl;
        cout << "XP: " + to_string(pokemon.getXP()) << endl;
        cout << "-------------------------------" << endl;
        for (attackMoves move : pokemon.getMoveset()) {
            cout << "Move Name: " << move.getMoveName() << endl;
            cout << "Move Element: " << move.getMoveElement() << endl;
            cout << "Move Damage: " << move.getMoveDamage() << endl;
            cout << "-------------------------------" << endl;
        }
        i++;
    }
}

// Returns the vector of Pokemon
vector<Pokemon> User::getPokemonVector() {
    return userPokemon;
}

// Adds a Pokemon to the vector if it is not equal to size 5, if so issues an error message
void User::addPokemon(Pokemon pokemon) {
    if(userPokemon.size() != 5){
        userPokemon.push_back(pokemon);
    }
    else{
        cout << "Max Pokemon exceeded! Please remove a Pokemon!" << endl;
    }
}

// Removes a Pokemon if the vector is not zero and if it exists in the vector
void User::removePokemon(Pokemon pokemon) {
    auto first = userPokemon.begin();
    auto last = userPokemon.end();
    auto it = find(first,last,pokemon);
    if (userPokemon.size() == 0){
        cout << "You do not have any Pokemon" << endl;
    }
    else if (it != userPokemon.end()){
        userPokemon.erase(it);
    }
    else{
        cout << "Pokemon not found" << endl;
    }
}
