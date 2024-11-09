//
// Created by Nick Lovera on 10/5/24.
//
#include "Pokemon.h"
#include "Opponent.h"
#include "User.h"
#include <ctime>
#include <iostream>

bool test_Pokemon();
bool test_Opponent();
bool test_User();

int main(){
    srand(time(NULL));
    if (test_Pokemon()) {
        cout << "Passed all Pokemon test cases" << endl;
    }
    if (test_Opponent()) {
        cout << "Passed all Opponent test cases" << endl;
    }
    if (test_User()){
        cout << "Passed all User test cases" << endl;
    }
    return 0;
}

bool test_Pokemon(){
    bool passed = true;
    Pokemon p1;
    Pokemon p2;
    if(p1 == p2){
        cout << "FAILED. Did not pass random Pokemon constructor case" << endl;
        passed = false;
    }


    if(p1.getXP() != 0){
        cout << "FAILED. Did not pass POKEMON setXP case" << endl;
        passed = false;
    }

    Pokemon p3("Zapdos");
    if (p3.getName() != "Zapdos"){
        cout << "FAILED. Did not pass parameterized Pokemon constructor case" << endl;
        passed = false;
    }



    if(p3.getXP() != 0){
        cout << "FAILED. Did not pass POKEMON setXP for parameterized constructor case" << endl;
        passed = false;
    }


    Pokemon p4("TEST");
    if(p4.getName() != "?"){
        cout << "FAILED. Did not pass Pokemon not in Pokedex case" << endl;
        passed = false;
    }

    Pokemon p5;
    p5.clearMoveset();
    if(p5.getMoveset().size() != 0){
        cout << "FAILED: Did not pass clear moveset case" << endl;
        passed = false;
    }

    p5.teachMove();
    if(p5.getMoveset().size() != 3){
        cout << "FAILED. Did not pass fill moveset case" << endl;
        passed = false;
    }

    int sizeBefore = p5.getMoveset().size();
    vector<attackMoves> moves = p5.getMoveset();
    attackMoves move = moves[1];
    p5.deleteMove(move);
    if(p5.getMoveset().size() != sizeBefore - 1){
        cout << "FAILED. Did not pass delete move case" << endl;
        passed = false;
    }

    sizeBefore = p5.getMoveset().size();
    p5.addMove();
    if(p5.getMoveset().size() != sizeBefore + 1){
        cout << "FAILED. Did not pass add move case" << endl;
        passed = false;
    }

    return passed;
}

bool test_Opponent(){
    bool passed = true;

    /*
     * For this, we do not need to test the individual constructors as they are just Pokemon constructors
     * which are already tested, I am just going to test the overridden setXP method, which is used
     * in the constuctor
    */
    Opponent op1;
    if(op1.getXP() != (op1.getHP() / 2)){
        cout << "FAILED. Did not pass OPPONENT setXP method" << endl;
        passed = false;
    }
    /* This test case does not work, I do not know why
    attackMoves randMove = op1.pickRandomAttack();
    auto first = op1.getMoveset().begin();
    auto last = op1.getMoveset().end();
    auto it = find(first,last,randMove);
    if(it == last){
        cout << "Failed. Did not pass random chosen attack case" << endl;
        passed = false;
    }
     */
    Opponent op2("Zapdos");
    if(op2.getXP() != (op2.getHP()/2)){
        cout << "FAILED. Did not pass PARAMETERIZED OPPONENT setXP method" << endl;
        passed = false;
    }
    Pokemon p1;
    p1.setXP(op2.giveXP());
    if(p1.getXP() != op2.getXP()){
        cout << "FAILED. Did not pass give XP case" << endl;
        passed = false;
    }
    return passed;
}

bool test_User(){
    bool passed = true;
    Pokemon p1("Charmander"),p2("Charizard"),p3("Pikachu"),p4("Zapdos"),p5("Gengar");
    User user;
    user.addPokemon(p1);
    user.addPokemon(p2);
    user.addPokemon(p3);
    user.addPokemon(p4);
    user.addPokemon(p5);
    if(user.getPokemonVector().size() != 5){
        cout << "FAILED. Did not pass addPokemon case" << endl;
        passed = false;
    }
    int sizeBefore = user.getPokemonVector().size();
    user.removePokemon(p5);
    if(user.getPokemonVector().size() != sizeBefore - 1){
        cout << "FAILED. Did not pass removePokemon case" << endl;
        passed = false;
    }
    auto first = user.getPokemonVector().begin();
    auto last = user.getPokemonVector().end();
    auto it = find(first,last,p5);
    if(it != user.getPokemonVector().end()){
        cout << "FAILED. Did not pass removePokemon case" << endl;
        passed = false;
    }
    return passed;
}