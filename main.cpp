#include <iostream>
#include "Pokemon.h"
#include "attackMoves.h"
#include "Opponent.h"
#include "User.h"
#include "pokemonBattle.h"



string userInput();

int main() {
    srand(time(0));
    User user;

    string input = userInput();

    if (input == "Charmander"){
        Pokemon p1("Charmander");
        user.addPokemon(p1);
        user.string_return();
    }

    else if (input == "Squirtle"){
        Pokemon p1("Squirtle");
        user.addPokemon(p1);
        user.string_return();
    }

    else{
        Pokemon p1("Bulbasaur");
        user.addPokemon(p1);
        user.string_return();
    }

    cout << "Now take your Pokemon out to battle! *Loading*" << endl;
    pokemonBattle battle(user);

    return 0;
}


// User validation
string userInput(){
    string input;
    string choice;
    bool validation = true;
    cout << "Welcome! Here are some of our Pokemon!" << endl;
    cout << "Charmander | Squirtle | Bulbasaur" << endl;
    // I wanted to make this so that the input is put to lowercase, but I could not figure it out
    cout << "Please select one of our Pokemon to be yours! (Please capitalize): " << endl;
    while (validation){
        getline(cin,input);

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

        if(isAllWhtSpce || input.length() == 0){
            cout << "No input. Please select a Pokemon!: " << endl;
        }

        else if(input != "Charmander" && input != "Squirtle" && input != "Bulbasaur"){
            cout << "That is not one of the available Pokemon, try again!" << endl;
        }

        else{
            choice = input;
            validation = false;
        }

    }
    return choice;



}
