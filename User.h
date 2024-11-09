//
// Created by Nick Lovera on 10/5/24.
//

#ifndef M1OEP_NLOVERA_USER_H
#define M1OEP_NLOVERA_USER_H
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

// User has a Pokemon
class User{
private:
    // Fields
    vector<Pokemon> userPokemon;
public:
    User();

    void string_return();

    void addPokemon(Pokemon pokemon);

    void removePokemon(Pokemon pokemon);

    vector<Pokemon> getPokemonVector();


};


#endif //M1OEP_NLOVERA_USER_H
