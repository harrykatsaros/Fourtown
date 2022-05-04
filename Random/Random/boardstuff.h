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


int choosecol(int array[][col], player active, sf::Vector2i mouse_position);
void deleterow(int array[][col], player active, int pickc);
void createarray(int array[][col], sf::RenderWindow& window);
bool checkwin(int array[][col], player active);
int checkfull(int array[][col]);
void displaywinner(player active, sf::RenderWindow& window, sf::Font& font); //ongoing game = 0, player 1 = 1, player 2 = 2, draw = 3
void restart(int array[][col]);

void drawstuff(sf::RenderWindow& window, player active, sf::Font& font);

#endif // !1