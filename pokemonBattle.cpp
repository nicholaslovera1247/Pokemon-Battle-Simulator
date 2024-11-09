//
// Created by Nick Lovera on 10/6/24.
//
#include "pokemonBattle.h"
#include <iostream>
#include <sstream>
#include <string>

// Pokemon Battle Constructor, sets up the entire game.
pokemonBattle::pokemonBattle(User userP):player(userP),opp(Opponent()) {
    cout << "Battle Beginning!" << endl;
    cout << "Here is your opponent!" << endl;
    cout << opp.getName() + " | HP: " + to_string(opp.getHP())<< endl;

    cout << "Choose your Pokemon!" << endl;
    for(Pokemon pokemon : player.getPokemonVector()){
        cout << pokemon.getName() << endl;
    }
    int i = get_int_from_user();
    Pokemon battlePoke("?");
    if(!(i > player.getPokemonVector().size()) && !(i <= 0)){
        battlePoke = player.getPokemonVector()[i-1];
    }
    else{
         battlePoke = player.getPokemonVector()[0];
    }
    cout << "You chose: " + battlePoke.getName() << endl;
    while(true){
        cout << "Your turn!" << endl;
        cout << "Choose an attack to perform!" << endl;
        for(attackMoves moves : battlePoke.getMoveset()){
            cout << moves.getMoveName() << "| DMG: " + to_string(moves.getMoveDamage()) << endl;
        }
        int j = get_int_from_user();
        attackMoves performedMove = battlePoke.getMoveset()[j - 1];

        cout << battlePoke.getName() + " used " + performedMove.getMoveName() + " for " +
        to_string(performedMove.getMoveDamage()) + " damage! " << endl;

        opp.setHP(opp.getHP() - performedMove.getMoveDamage());
        cout << "Opponent's HP: " + to_string(opp.getHP()) << endl;

        if(opp.getHP() <= 0){
            break;
        }
        cout << "Opponent's Turn!" << endl;
        attackMoves oppAttack = opp.pickRandomAttack();
        cout << opp.getName() + " used " + oppAttack.getMoveName() + " for " + to_string(oppAttack.getMoveDamage()) +
        " damage!" << endl;
        battlePoke.setHP(battlePoke.getHP() - oppAttack.getMoveDamage());
        cout << "Your HP: " + to_string(battlePoke.getHP()) << endl;
        if(battlePoke.getHP() <= 0){
            break;
        }
    }
    if(opp.getHP() < 0){
        cout << "YOU DEFEATED " + opp.getName() << endl;
        for(Pokemon poke : player.getPokemonVector()){
            if(battlePoke.getName() == poke.getName()){
                poke.setXP(poke.getXP() + opp.getXP());
                break;
            }
        }
        cout << battlePoke.getName() + " gained " + to_string(opp.getXP()) + " XP" << endl;
    }

    if(battlePoke.getHP() < 0){
        cout << "YOU LOST TO " + opp.getName() << endl;
        cout << "Play again?" << endl;
    }


}

// Validation method for the Pokemon Battle Constructor
int pokemonBattle::get_int_from_user(){
    string input;
    bool validation = true;
    int num;
    cout << "Please 1, 2, or 3: " << endl;
    while (validation) {
        getline(cin,input);

        stringstream ss(input);

        bool isAllWhtSpce = false;
        for (char c:input){
            if(!isspace(c)){
                isAllWhtSpce = false;
                break;
            }
            else{
                isAllWhtSpce = true;
            }
        }

        if((ss >> num) && ss.eof() && (num == 1 || num == 2 || num == 3)){
            validation = false;
            return num;
        }
        else if (isAllWhtSpce || input.length() == 0){
            cout << "No input. Please enter a number: " << endl;
        }
        else{
            cout << "Invalid. Please enter a number: " << endl;
        }
    }
}
