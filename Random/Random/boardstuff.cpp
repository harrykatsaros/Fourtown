#include "boardstuff.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;

int spaceY = 20;
int radius = 40;
int spaceX = 20;
sf::Color emptytoken(130, 200, 224);
sf::Color red(214, 30, 0);
sf::Color yellow(235, 235, 0);
sf::Color wordColor(150, 200, 224);


int choosecol(int array[][col], player active, sf::Vector2i mouse_position) {
    int pickc = 7;

    if ((mouse_position.x < 140 && mouse_position.x > 60)) { // check if within each column

        pickc = 0;

    }
    else if ((mouse_position.x > 160 && mouse_position.x < 240)) {

        pickc = 1;

    }
    else if ((mouse_position.x > 260 && mouse_position.x < 340)) {

        pickc = 2;

    }
    else if ((mouse_position.x > 360 && mouse_position.x < 440)) {

        pickc = 3;

    }
    else if ((mouse_position.x > 460 && mouse_position.x < 540)) {

        pickc = 4;

    }
    else if ((mouse_position.x > 560 && mouse_position.x < 640)) {

        pickc = 5;

    }
    else if ((mouse_position.x > 660 && mouse_position.x < 740)) {

        pickc = 6;

    }

    if (array[0][pickc] == 1 || array[0][pickc] == -1) {
        pickc = 7;
    }
    return pickc;
}

void deleterow(int array[][col], player active, int pickc) {
    bool change = false;
    int height = 5;

    while (change == false) {
        if (array[height][pickc] != 1 && array[height][pickc] != -1) {
            array[height][pickc] = active.color;
            change = true;
        }
        else
            height = height - 1;
    }
}

void createarray(int array[][col], sf::RenderWindow& window) {

    for (int y = 1; y <= 6; y++)
    {
        // Get the center of the next row of circles
        float centerY = (spaceY + radius) * y + radius * (y - 1);
        for (int x = 1; x <= 7; x++)
        {
            // Get the center of the next column of circles
            float centerX = (spaceX + radius) * x + radius * (x - 1);
            // Set the color of the circle
            sf::Color fillColor;
            if (array[y - 1][x - 1] == 0)
                fillColor = emptytoken;
            else if (array[y - 1][x - 1] == 1)
                fillColor = red;
            else
                fillColor = yellow;
            

            // Draw the circle in the buffer
            sf::CircleShape Circle(200.f);

            Circle.setRadius(radius);
            Circle.setFillColor(fillColor);
            Circle.setPosition(centerX, centerY + 100);

            window.draw(Circle);

        }
    }
}

bool checkwin(int array[][col], player active) {
    bool win = false;
    int findcolor = active.color;

    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= 3; j++) {

            if (array[i][j] == findcolor && array[i][j + 1] == findcolor && array[i][j + 2] == findcolor && array[i][j + 3] == findcolor) { //horizontal 
                win = true;
            }
        }
    }

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= col; j++) {

            if (array[i][j] == findcolor && array[i + 1][j] == findcolor && array[i + 2][j] == findcolor && array[i + 3][j] == findcolor) {  //vertical
                win = true;
            }
        }
    }

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= col; j++) {

            if (array[i][j] == findcolor && array[i + 1][j + 1] == findcolor && array[i + 2][j + 2] == findcolor && array[i + 3][j + 3] == findcolor) { //diagonal negative slope
                win = true;

            }
        }
    }

    for (int i = 0; i <= 2; i++) {
        for (int j = 3; j <= col; j++) {

            if (array[i][j] == findcolor && array[i + 1][j - 1] == findcolor && array[i + 2][j - 2] == findcolor && array[i + 3][j - 3] == findcolor) { //diagonal positive slope
                win = true;
            }
        }
    }





    return win;
}

int checkfull(int array[][col]) {
    //int findcolor = active.color;
    int full = 0;

    if (full != 7) {
        for (int i = 0; i < 7; i++) {
            if (array[0][i] != 0) {
                full++;
            }
        }
    }

    return full;

}

//int checkfull(int array[][col]) {
//    int fullcol = 0;
//
//    for (int i = 0; i < col; ++i) {
//        if (array[0][i] != 0) {
//            fullcol = fullcol + 1;
//        }
//    }
//
//    return fullcol;
//}

void displaywinner(player active, sf::RenderWindow& window, sf::Font& font) { //player 1 = 1, player 2 = 2, draw = 3


    sf::Text title;
    title.setFont(font);
    title.setString("Four in a row");
    title.setCharacterSize(50);
    title.setFillColor(wordColor);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setOrigin(150, 0);
    title.setPosition(400.f, 10.f);

    sf::Text checkfull;
    checkfull.setFont(font);
    checkfull.setString("It's a Draw!");
    checkfull.setCharacterSize(50);
    checkfull.setFillColor(wordColor);
    checkfull.setStyle(sf::Text::Bold | sf::Text::Underlined);
    checkfull.setOrigin(120, 0);
    checkfull.setPosition(380.f, 780.f);

    sf::Text playertitle;
    playertitle.setFont(font);
    playertitle.setString(active.name);
    playertitle.setCharacterSize(50);
    playertitle.setFillColor(wordColor);
    playertitle.setStyle(sf::Text::Bold);
    playertitle.setOrigin(150, 0);
    playertitle.setPosition(380.f, 780.f);

    sf::Text winscreen;
    winscreen.setFont(font);
    winscreen.setString("wins!");
    winscreen.setCharacterSize(50);
    winscreen.setFillColor(wordColor);
    winscreen.setStyle(sf::Text::Bold);
    winscreen.setOrigin(120, 0);
    winscreen.setPosition(550.f, 780.f);

    sf::Text restartscreen;
    restartscreen.setFont(font);
    restartscreen.setString("Press R to restart!");
    restartscreen.setCharacterSize(50);
    restartscreen.setFillColor(wordColor);
    restartscreen.setStyle(sf::Text::Bold);
    restartscreen.setOrigin(120, 0);
    restartscreen.setPosition(300.f, 400.f);

    window.draw(title);
    window.draw(winscreen);
    window.draw(playertitle);
    //window.draw(restartscreen);

    sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
    rectangle.setPosition(0, 130);
    rectangle.setFillColor(sf::Color::Blue);

    window.draw(rectangle);

    sf::Text smallreset;
    smallreset.setFont(font);
    smallreset.setString("Press r to reset");
    smallreset.setCharacterSize(20);
    smallreset.setFillColor(wordColor);
    smallreset.setStyle(sf::Text::Bold);
    smallreset.setOrigin(0, 0);
    smallreset.setPosition(20.f, 20.f);

    window.draw(smallreset);

}

void restart(int array[][col]) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }
}

void drawstuff(sf::RenderWindow& window, player active, sf::Font& font) {

    sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
    rectangle.setPosition(0, 130);
    rectangle.setFillColor(sf::Color::Blue);

    window.draw(rectangle);


    sf::Text title;
    title.setFont(font);
    title.setString("Four in a row");
    title.setCharacterSize(50);
    title.setFillColor(wordColor);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setOrigin(150, 0);
    title.setPosition(400.f, 10.f);

    sf::Text playertitle;
    playertitle.setFont(font);
    playertitle.setString(active.name);
    playertitle.setCharacterSize(50);
    playertitle.setFillColor(wordColor);
    playertitle.setStyle(sf::Text::Bold);
    playertitle.setOrigin(150, 0);
    playertitle.setPosition(380.f, 780.f);

    sf::Text move;
    move.setFont(font);
    move.setString("move");
    move.setCharacterSize(50);
    move.setFillColor(wordColor);
    move.setStyle(sf::Text::Bold);
    move.setOrigin(50, 0);
    move.setPosition(480.f, 780.f);

    sf::Text smallreset;
    smallreset.setFont(font);
    smallreset.setString("Press r to reset");
    smallreset.setCharacterSize(20);
    smallreset.setFillColor(wordColor);
    smallreset.setStyle(sf::Text::Bold);
    smallreset.setOrigin(0, 0);
    smallreset.setPosition(20.f, 20.f);

    window.draw(title);

    window.draw(playertitle);

    window.draw(move);

    window.draw(smallreset);

}