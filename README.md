Nicholas Lovera Open-Project 2
This program is a continuation of my open project for module one, where I created the groundwork for a Pokemon battle
simulator, in this module we create the first prototype of the "finished" game. In this interation of my game, I use
the following concepts learned from module 2:
- "Is a" Class Relationship
- "Has a" Class Relationship
- Rand() and srand()
- String manipulations
- File in/output

As for bugs in this program, there is one that with more time I think I could have hopefully figured out. This bug is in
the testing_Pokemon.cpp file and is commented out, as I could not figure out for the life of me what was going on. This 
bug was returning true for the randomAttack method in opponent, even though I went through and checked and could assure 
myself that it should be returning false as it was able to find a random attack. I hope to expand this simulator further
into a whole game with rounds, packs to gather new Pokemon, abilities to evolve new Pokemon, add new moves, etc. I play
a lot of Balatro, and I really want this game to become like that just with Pokemon cards. I also really wanted to 
implemnt a super effective and least effective move, but in the time frame I sadly had due to other school-work, I could
not get to implementing that, but I may start to implement it as we start the next module and the work-load is lighter.

For this module, I believe I deserve a 75-80 range. This time around, my project is very complex and robust with a lot
of moving pieces all in someway using each other. My testing class is not great, since I had a failed test case in there
and I am sure I am forgetting some cases I should be testing, so I understand getting 10 off there. But my implementations
for everything else have a clear and complex purpose. I use file I/O to read all my created CSV files for the Pokemon,
I use rand() and srand() to choose a random Pokemon, a random attackMove for the computer, even using it to fill the 
user's base attack moveset with moves. I use iterators and string manipulations to find many things inside the various
vectors lying around, and my "is a" and "has a" class relationships are exactly how we learned in class and are used in
a complex and robust way that only could work if that is how I wanted the program to function. I will say that I can see
losing a couple of points for how basic my overridden method in Opponent:Pokemon for setXP() is, but for what I wanted
thses functions to do and how this game to run I felt as if that was the only override method I needed. 



Work Cited: https://stackoverflow.com/questions/64814990/reading-a-specific-row-in-csv-file-in-c