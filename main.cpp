#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <Windows.h>
#include "boardstuff.h"
#include <fstream>

using namespace std;


const int width = 7;
const int height = 6;

const int row = 6;
const int col = 7;

int BOARD_Y_SIZE = 6;
int BOARD_X_SIZE = 7;
int spaceY = 20;
int radius = 40;
int spaceX = 20;
sf::Color emptyColor(150, 200, 224);
sf::Color redColor(214, 30, 0);
sf::Color yellowColor(235, 235, 0);
sf::Color lineColor(0, 51, 102);
sf::Color boardColor(0, 102, 153);
sf::Color highlightColor(255, 153, 0);



enum Cells {
    Red = 1,
    Blue = -1,
    Empty = 0
};


struct Board {
    Cells _slots[height][width];
};

struct player {
    string name;
    int color; //red=1, yellow=-1, empty=0
};

//FUNCTION STUBS
int choosecol(int array[][col], player active, sf::Vector2i mouse_position);
void deleterow(int array[][col], player active, int pickc);
void createarray(int array[][col]);
bool checkwin(int array[][col], player active);
int checkfull(int array[][col]);
void displaywinner(player active); //ongoing game = 0, player 1 = 1, player 2 = 2, draw = 3
int restart(int array[][col]);



int main() {
    
    player p1, p2;
    int array[row][col];
    int pickc;
    bool win = false;
    int fullcol = 0;
    int r = 0;


    //////////// create Board ////////////////
    Board board;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {

            array[i][j] = 0;

            //cout << array[i][j] << " ";

        }
        cout << endl;
    }

    //Assign names and colors to p1, p2
    cout << "Let's Play Connect 4" << endl << endl;
    //cout << "Player One please enter your name: ";
    //cin >> p1.name;
    p1.name = "Player 1";
    p1.color = 1;
    //cout << "Player Two please enter your name: ";
    //cin >> p2.name;
    p2.name = "Player 2";
    p2.color = -1;

   
  

    // menu
    bool menu = true;
    // init Game -> fill Board with empty coins and ask for game mode
    
    




    //initGame(board); SOMETHING IS WRONG WITH THIS STUFF HERE FOR SOME REASON WHEN WE LEAVE THE WINDOW IT STOPS WORKING 
    for (int y = 0; y < BOARD_Y_SIZE; y++)
    {
        // Get the center of the next row of circles
        for (int x = 0; x < BOARD_X_SIZE; x++)
        {
            board._slots[x][y] = Empty;
            cout << board._slots[x][y];
        }
        cout<<endl;
    }
    
    createarray(array);

    
    sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");

    // run the program as long as the window is open
    while (window.isOpen())
    {    

        sf::Event event;
        while (window.pollEvent(event))
        {          
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                window.close();
            }
        }

        // clear the window 
        window.clear(sf::Color::Black);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "Error" << endl;
        }

        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);


        /////DRAW BOARD WITHOUT CIRCLES////////
        sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
        rectangle.setPosition(0, 130);
        rectangle.setFillColor(sf::Color::Blue);

        window.draw(rectangle);
        /////////////GAME PLAY LOOP //////////////////////

        while (r != 2) {
            //PLAYER 1 LOOP
            pickc = choosecol(array, p1, mouse_position);
            deleterow(array, p1, pickc);
            createarray(array);
            win = checkwin(array, p1);

            if (win == true) {
                displaywinner(p1);
                r = restart(array);
                if (r == 2) {
                    break;
                }
            }
            //PLAYER 2 LOOP
            pickc = choosecol(array, p2, mouse_position);
            deleterow(array, p2, pickc);
            createarray(array);
            win = checkwin(array, p2);
            if (win == true) {
                displaywinner(p2);
                r = restart(array);
                if (r == 2) {
                    break;
                }
            }
            //CHECKING FULL BOARD
            fullcol = checkfull(array);
            if (fullcol == 7) {
                cout << "The board is full, it is a draw!" << endl; //assign check = 3 (draw)
                r = restart(array);
            }
        }

        

        

        /////// MOUSE STUFF ////////

        // Moved into Choose Column function. 
        

        ///////////window stuff///////////////////


        sf::Vector2u size = window.getSize();
        unsigned int width = size.x;
        unsigned int height = size.y; 

    

        /////////DRAWING BOARD STUFF /////////////////

        sf::Text title;
        title.setFont(font);
        title.setString("Connect Four");
        title.setCharacterSize(50);
        title.setFillColor(emptyColor);
        title.setStyle(sf::Text::Bold | sf::Text::Underlined);
        title.setOrigin(150, 0);
        title.setPosition(400.f, 10.f);

        sf::Text info;
        info.setFont(font);
        info.setString("Player One moves");
        info.setCharacterSize(50);
        info.setFillColor(emptyColor);
        info.setStyle(sf::Text::Bold);
        info.setOrigin(200, 0);
        info.setPosition(400.f, 800.f);

        window.draw(title);
        window.draw(info);
        


        // end the current frame
        window.display();
    }


    return 0;
    
}

int choosecol(int array[][col], player active, sf::Vector2i mouse_position) {
    int pickc = 0;

    do {
        //cout << active.name << "'s Turn ";
        //cout << "Please enter a number between 1 and 6: ";
        //cin >> pickc;

        

        cout << mouse_position.x << " " << mouse_position.y << endl;
        if ((mouse_position.y < 741 && mouse_position.y > 159) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //if within playable region

            if ((mouse_position.x < 140 && mouse_position.x > 60)) { // check if within each column
                           
                pickc = 1;

            }
            else if ((mouse_position.x > 160 && mouse_position.x < 240)) {

                pickc = 2;

            }
            else if ((mouse_position.x > 260 && mouse_position.x < 340)) {

                pickc = 3;

            }
            else if ((mouse_position.x > 360 && mouse_position.x < 440)) {

                pickc = 4;

            }
            else if ((mouse_position.x > 460 && mouse_position.x < 540)) {

                pickc = 5;

            }
            else if ((mouse_position.x > 560 && mouse_position.x < 640)) {

                pickc = 6;

            }
            else if ((mouse_position.x > 660 && mouse_position.x < 740)) {

                pickc = 7;

            }
        }

        while (array[1][pickc] == 1 || array[1][pickc] == -1) {
            cout << "Row is full, please choose new number: ";
            if ((mouse_position.y < 741 && mouse_position.y > 159) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //if within playable region

                if ((mouse_position.x < 140 && mouse_position.x > 60)) { // check if within each column

                    pickc = 1;

                }
                else if ((mouse_position.x > 160 && mouse_position.x < 240)) {

                    pickc = 2;

                }
                else if ((mouse_position.x > 260 && mouse_position.x < 340)) {

                    pickc = 3;

                }
                else if ((mouse_position.x > 360 && mouse_position.x < 440)) {

                    pickc = 4;

                }
                else if ((mouse_position.x > 460 && mouse_position.x < 540)) {

                    pickc = 5;

                }
                else if ((mouse_position.x > 560 && mouse_position.x < 640)) {

                    pickc = 6;

                }
                else if ((mouse_position.x > 660 && mouse_position.x < 740)) {

                    pickc = 7;

                }
            }
        }

    } while (pickc <= 1 || pickc >= 7);

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

void createarray(int array[][col]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (array[i][j] != 1 && array[i][j] != -1) {
                array[i][j] = 0;
            }
            cout << array[i][j] << " ";

        }
        cout << endl;
    }

    for (int y = 1; y <= BOARD_Y_SIZE; y++)
    {
        // Get the center of the next row of circles
        float centerY = (spaceY + radius) * y + radius * (y - 1);
        for (int x = 1; x <= BOARD_X_SIZE; x++)
        {
            // Get the center of the next column of circles
            float centerX = (spaceX + radius) * x + radius * (x - 1);
            // Set the color of the circle
            sf::Color fillColor;
            if (array[x - 1][y - 1] == 0)
                fillColor = emptyColor;
            else if (array[x - 1][y - 1] == 1)
                fillColor = redColor;
            else
                fillColor = yellowColor;
            // Set the color of the tokens outline
            sf::Color outlineColor;

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

            if (array[i][j] == findcolor && array[i][j + 1] == findcolor && array[i][j + 2] == findcolor && array[i][j + 3] == findcolor) { //horizontal right
                win = true;
            }

            if (array[i][j] == findcolor && array[i - 1][j] == findcolor && array[i - 2][j] == findcolor && array[i - 3][j] == findcolor) { //horizontal left
                win = true;
            }

            if (array[i][j] == findcolor && array[i - 1][j - 1] == findcolor && array[i - 2][j - 2] == findcolor && array[i - 3][j - 3] == findcolor) { //diagonal negative slope
                win = true;
            }

            if (array[i][j] == findcolor && array[i - 1][j + 1] == findcolor && array[i - 2][j + 2] == findcolor && array[i - 3][j + 3] == findcolor) { //diagonal positive slope
                win = true;
            }
        }
    }
    return win;
}

int checkfull(int array[][col]) {
    int fullcol = 0;

    for (int i = 0; i < col; ++i) {
        if (array[1][i] != 0) {
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
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j <= col; j++) {
                array[i][j] = 0;
            }
        }
    }
    else {
        cout << "Bye!" << endl; //EXIT
    }
    return r;
}