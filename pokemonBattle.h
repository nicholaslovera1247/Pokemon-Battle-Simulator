//
// Created by Nick Lovera on 10/5/24.
//

#ifndef M1OEP_NLOVERA_POKEMONBATTLE_H
#define M1OEP_NLOVERA_POKEMONBATTLE_H
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Opponent.h"
#include "User.h"
using namespace std;

class pokemonBattle{
private:
    User player;
    Opponent opp;
public:
    pokemonBattle(User player);

    int get_int_from_user();

};










#endif //M1OEP_NLOVERA_POKEMONBATTLE_H
