#include "boardstuff.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;

int spaceY = 20;
int radius = 40;
int spaceX = 20;
sf::Color emptyColor(150, 200, 224);
sf::Color redColor(214, 30, 0);
sf::Color yellowColor(235, 235, 0);
sf::Color lineColor(0, 51, 102);
sf::Color boardColor(0, 102, 153);
sf::Color highlightColor(255, 153, 0);


int choosecol(int array[][col], player active) {
    int pickc;

    do {
        cout << active.name << "'s Turn ";
        cout << "Please enter a number between 0 and 6: ";
        cin >> pickc;

        while (array[0][pickc] == 1 || array[0][pickc] == -1) {
            cout << "Row is full, please choose new number: ";
            cin >> pickc;
        }

    } while (pickc < 0 || pickc > 6);

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

void createarray(int array[][col], sf::RenderWindow &window) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (array[i][j] != 1 && array[i][j] != -1) {
                array[i][j] = 0;
            }
            cout << array[i][j] << " ";

        }
        cout << endl;
    }
    for (int y = 1; y <= 6; y++)
    {
        // Get the center of the next row of circles
        float centerY = (spaceY + radius) * y + radius * (y-1);
        for (int x = 1; x <= 7; x++)
        {
            // Get the center of the next column of circles
            float centerX = (spaceX + radius) * x + radius * (x-1);
            // Set the color of the circle
            sf::Color fillColor;
            if (array[y-1][x-1] == 0)
                fillColor = emptyColor;
            else if (array[y-1][x-1] == 1)
                fillColor = redColor;
            else
                fillColor = yellowColor;
            // Set the color of the tokens outline
            //sf::Color outlineColor;

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

    for (int i = row; i >= 0; --i) {
        for (int j = col; j >= 0; --j) {

            if (array[i][j] == findcolor && array[i][j - 1] == findcolor && array[i][j - 2] == findcolor && array[i][j - 3] == findcolor) { //vertical
                win = true;
            }

            else if (array[i][j] == findcolor && array[i][j + 1] == findcolor && array[i][j + 2] == findcolor && array[i][j + 3] == findcolor) { //horizontal right
                win = true;
            }

            else if (array[i][j] == findcolor && array[i - 1][j] == findcolor && array[i - 2][j] == findcolor && array[i - 3][j] == findcolor) { //horizontal left
                win = true;
            }

            else if (array[i][j] == findcolor && array[i - 1][j - 1] == findcolor && array[i - 2][j - 2] == findcolor && array[i - 3][j - 3] == findcolor) { //diagonal negative slope
                win = true;
            }

            else if (array[i][j] == findcolor && array[i - 1][j + 1] == findcolor && array[i - 2][j + 2] == findcolor && array[i - 3][j + 3] == findcolor) { //diagonal positive slope
                win = true;
            }
        }
    }
    return win;
}

int checkfull(int array[][col]) {
    int fullcol = 0;

    for (int i = 0; i < col; ++i) {
        if (array[0][i] != 0) {
            fullcol = fullcol + 1;
        }
    }

    return fullcol;
}

void displaywinner(player active) { //player 1 = 1, player 2 = 2, draw = 3
    cout << endl << active.name << " Connected Four, You Win!" << endl;
}

int restart(int array[][col]) {
    int r;

    cout << "Would you like to restart? Yes(1) No(2): ";
    cin >> r;
    if (r == 1) { //button pressed
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                array[i][j] = 0;
            }
        }
    }
    else {
        cout << "Bye!" << endl; //EXIT
    }
    return r;
}