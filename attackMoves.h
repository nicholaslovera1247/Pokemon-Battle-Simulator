//
// Created by Nick Lovera on 9/12/24.
//

#ifndef M1OEP_NLOVERA_ATTACKMOVES_H
#define M1OEP_NLOVERA_ATTACKMOVES_H
#include <string>
using namespace std;


class attackMoves{
private:
    // Fields
    string moveName;
    int moveDamage;
    string moveElement;

public:
    // Default Constructor
    attackMoves();
    // Parameterized Constructor
    attackMoves(string name,string element,int dmg);
    // Getters

    string getMoveName() const;

    int getMoveDamage() const;

    string getMoveElement() const;

    // Setters

    void setMoveName(string name);

    void setMoveDamage(int damage);

    void setMoveElement(string element);

    vector<attackMoves> loadMovesFromFile();

    bool operator==(const attackMoves& other) const;




};
#endif //M1OEP_NLOVERA_ATTACKMOVES_H
