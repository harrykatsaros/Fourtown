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


/*int dropMyDisk(Board& board, int column, Cells color)
{
    if (board._slots[0][column] != Empty)
    {
        std::cout << "It is full!" << std::endl;
        return -1;
    }
    else if (0 <= column && column <= 6)
    {
        for (int row = height - 1; row >= -1; row--)
        {
            if (row == 5)
            {
                if (board._slots[row][column] == Empty)
                {
                    board._slots[row][column] = color;
                    break;
                }
            }
            else if (board._slots[row + 1][column] != Empty && board._slots[row][column] == Empty)
            {
                board._slots[row][column] = color;
                break;
            }
        }
    }
    else
    {
        std::cout << "Invalid Move!" << std::endl;
        return -1;
    }
}
*/

/*
void initGame(Board& board) {
    // fill board with zeros
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            board._slots[y][x] = Empty;
        }
    }
}

*/






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
    
    
    //initGame(board);


	
    sf::RenderWindow window(sf::VideoMode(800, 800), "Connect Four");

    // run the program as long as the window is open
    while (window.isOpen())
    {    




        sf::Event event;
        while (window.pollEvent(event))
        {          
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "Error" << endl;
        }


        sf::Text title;
        title.setFont(font); 
        title.setString("Connect Four");
        title.setCharacterSize(50);
        title.setFillColor(sf::Color::White);
        title.setStyle(sf::Text::Bold | sf::Text::Underlined);
        title.setOrigin(150, 0);
        title.setPosition(400.f, 10.f);
        
        sf::Text info;
        info.setFont(font);
        info.setString("Player One moves");
        info.setCharacterSize(50);
        info.setFillColor(sf::Color::White);
        info.setStyle(sf::Text::Bold);
        info.setOrigin(200, 0);
        info.setPosition(400.f, 700.f);
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Text info3;
            info3.setFont(font);
            info3.setString("click");
            info3.setCharacterSize(50);
            info3.setFillColor(sf::Color::White);
            info3.setStyle(sf::Text::Bold);
            info3.setOrigin(200, 0);
            info3.setPosition(400.f, 750.f);

            window.draw(info3);
        }
        
        //sf::Mouse::setPosition(sf::Vector2i(100, 200), window);

        sf::Vector2u size = window.getSize();
        unsigned int width = size.x;
        unsigned int height = size.y; //window stuff

        /*sf::Text info2;
        info2.setFont(font);
        info2.setString("stuff");
        info2.setCharacterSize(50);
        info2.setFillColor(sf::Color::White);
        info2.setStyle(sf::Text::Bold);
        info2.setOrigin(200, 0);
        info2.setPosition(400.f, 700.f);*/



        sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
        rectangle.setPosition(0,30);
        rectangle.setFillColor(sf::Color::Blue);

        window.draw(rectangle);



        int BOARD_Y_SIZE = 6;
        int BOARD_X_SIZE = 7;
        int spaceY = 20;
        int radius = 40;
        int spaceX = 20;
        sf::Color emptyColor(224, 224, 244);
        sf::Color redColor(214, 71, 0);
        sf::Color yellowColor(235, 235, 0);
        sf::Color lineColor(0, 51, 102);
        sf::Color boardColor(0, 102, 153);
        sf::Color highlightColor(255, 153, 0);


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
                //if (Board.cell[y][x] == Empty)
                   fillColor = emptyColor;
                //else if (board[y][x] == Red)
                    fillColor = redColor;
                //else
                    //fillColor = yellowColor;
                // Set the color of the tokens outline
                sf::Color outlineColor;
                
                // Draw the circle in the buffer
                sf::CircleShape Circle(200.f);
                Circle.setRadius(radius);
                Circle.setFillColor(fillColor);
                Circle.setPosition(centerX, centerY);

                window.draw(Circle);
            }
        } 

        //sf::CircleShape pieces = new sf::CircleShape[width * height];

        /*for (int row = 0; row < width; row++) {
            for (int col = 0; col < height; col++) {
                sf::CircleShape piece(radius);
                piece.setFillColor(emptyColor);
                piece.setOrigin(radius, radius);
                piece.setOutlineThickness(5);
                piece.setOutlineColor(highlightColor);
                window.draw(piece);
            }
        }*/

        
        sf::CircleShape circle(200.f);
        circle.setRadius(40.f);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(0, 200);




        sf::CircleShape circle2(200.f);
        circle2.setRadius(40.f);
        circle2.setFillColor(sf::Color::Transparent);
        circle2.setPosition(0, 110);

        

        /*

                sf::CircleShape circle(radius);
                circle.setPosition(centerX, centerY);
                circle.setOrigin(radius / 2, radius / 2);
                circle.setFillColor(fillColor);
                circle.setOutlineThickness(outline);
                circle.setOutlineColor(outlineColor);
                // Draw the circle in the buffer
                window.draw(circle);
            }
        }*/






        













        
        //window.draw(title);
        //window.draw(info);
        
        //window.draw(circle);
        //window.draw(circle2);


        // end the current frame
        window.display();
    }




}
