#ifndef boardstuff_H
#define boardstuff_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

struct player {
    string name;
    int color; //red=1, yellow=-1, empty=0
};

constexpr auto row = 6;
constexpr auto col = 7;


int choosecol(int array[][col], player active);
void deleterow(int array[][col], player active, int pickc);
void createarray(int array[][col], sf::RenderWindow &window);
bool checkwin(int array[][col], player active);
int checkfull(int array[][col]);
void displaywinner(player active); //ongoing game = 0, player 1 = 1, player 2 = 2, draw = 3
int restart(int array[][col]);



#endif // !1
