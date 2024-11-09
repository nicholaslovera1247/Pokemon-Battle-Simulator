//
// Created by Nick Lovera on 9/30/24.
//

#ifndef M1OEP_NLOVERA_OPPONENT_H
#define M1OEP_NLOVERA_OPPONENT_H
#include "Pokemon.h"


// The opponent is a Pokemon
class Opponent : public Pokemon{
public:
        Opponent();

        explicit Opponent(string name);

        void setXP(int xp) override;

        int giveXP();

        attackMoves pickRandomAttack();

};






#endif //M1OEP_NLOVERA_OPPONENT_H
