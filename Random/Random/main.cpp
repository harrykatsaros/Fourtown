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


using namespace std;

#include <fstream>

const int width = 7;

const int height = 6;


enum Cells {
    Red = 1,
    Blue = -1,
    Empty = 0
};


struct Board {
    Cells _slots[height][width];
};




int main() {

    // create Board
    Board board;
    // init Player move
    int mymove = -1;
    // init check for finish
    int check = 0; //who wins? 1 = player 1, 2 = player 2, 0 means no one wins yet, 3 means draw (board is full)

    // menu
    bool menu = true;
    // init Game -> fill Board with empty coins and ask for game mode
    
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
    

    sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");

    // run the program as long as the window is open
    while (window.isOpen())
    {    

        sf::Event event;
        while (window.pollEvent(event))
        {          
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window 
        window.clear(sf::Color::Black);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "Error" << endl;
        }



        

        

        /////// MOUSE STUFF ////////


        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

        cout << mouse_position.x << " " << mouse_position.y << endl;
        if ((mouse_position.y < 741 && mouse_position.y > 159) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            if ((mouse_position.x < 140 && mouse_position.x > 60)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 1");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

                board._slots[0][5] = Red;
            }
            else if ((mouse_position.x > 160 && mouse_position.x < 240)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 2");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
            else if ((mouse_position.x > 260 && mouse_position.x < 340)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 3");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
            else if ((mouse_position.x > 360 && mouse_position.x < 440)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 4");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
            else if ((mouse_position.x > 460 && mouse_position.x < 540)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 5");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
            else if ((mouse_position.x > 560 && mouse_position.x < 640)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 6");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
            else if ((mouse_position.x > 660 && mouse_position.x < 740)) {

                sf::Text info3;
                info3.setFont(font);
                info3.setString("column 7");
                info3.setCharacterSize(50);
                info3.setFillColor(sf::Color::White);
                info3.setStyle(sf::Text::Bold);
                info3.setOrigin(200, 0);
                info3.setPosition(400.f, 750.f);

                window.draw(info3);

            }
        }

        ///////////window stuff///////////////////


        sf::Vector2u size = window.getSize();
        unsigned int width = size.x;
        unsigned int height = size.y; 

    

        /////////DRAWING BOARD STUFF /////////////////

        sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
        rectangle.setPosition(0,130);
        rectangle.setFillColor(sf::Color::Blue);

        window.draw(rectangle);


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
                if (board._slots[x-1][y-1] == Empty)
                   fillColor = emptyColor;
                else if (board._slots[x-1][y-1] == Red)
                    fillColor = redColor;
                //else
                    //fillColor = yellowColor;
                // Set the color of the tokens outline
                sf::Color outlineColor;
                
                // Draw the circle in the buffer
                sf::CircleShape Circle(200.f);
                
                Circle.setRadius(radius);
                Circle.setFillColor(fillColor);
                Circle.setPosition(centerX, centerY+100);

                window.draw(Circle);
            }
        } 

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




}
