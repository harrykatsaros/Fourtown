
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

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

    //std::ofstream{ "Hello.txt" }; 
    

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

    //initGame(board);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Connect Four");

    window.setKeyRepeatEnabled(false);



    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::MouseButtonPressed:
                    cout << "Button " << event.mouseButton.button << " @ "
                        << sf::Mouse::getPosition(window).x << ", "
                        << sf::Mouse::getPosition(window).y << "\n";

                break;
            }
        }



        //sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        
        sf::Font font;
        
          if (!font.loadFromFile("sansation.ttf"))
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



        sf::Vector2u size = window.getSize();
        unsigned int width = size.x;
        unsigned int height = size.y; //window stuff

        sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
        rectangle.setPosition(0, 130);
        rectangle.setFillColor(sf::Color::Blue);

        window.draw(rectangle);

        sf::CircleShape CircleRed(200.f);
        CircleRed.setRadius(radius);
        CircleRed.setFillColor(sf::Color::Red);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) {
            if ((sf::Mouse::getPosition(window)).x > 50 && sf::Mouse::getPosition(window).x < 145) {
                board._slots[0][5] = Red;

            } else if ((sf::Mouse::getPosition(window)).x > 145  && sf::Mouse::getPosition(window).x < 235) {
                CircleRed.setPosition(160, 660);
                window.draw(CircleRed);

            }
            else if ((sf::Mouse::getPosition(window)).x > 235 && sf::Mouse::getPosition(window).x < 325) {
                CircleRed.setPosition(260, 660);
                window.draw(CircleRed);

            }
            else if ((sf::Mouse::getPosition(window)).x > 325 && sf::Mouse::getPosition(window).x < 415) {
                CircleRed.setPosition(360, 660);
                window.draw(CircleRed);

            } else if ((sf::Mouse::getPosition(window)).x > 415 && sf::Mouse::getPosition(window).x < 505) {
                CircleRed.setPosition(460, 660);
                window.draw(CircleRed);

            } else if ((sf::Mouse::getPosition(window)).x > 505 && sf::Mouse::getPosition(window).x < 625) {
                CircleRed.setPosition(560, 660);
                window.draw(CircleRed);

            } else if ((sf::Mouse::getPosition(window)).x > 595 && sf::Mouse::getPosition(window).x < 740) {
                CircleRed.setPosition(660, 660);
                window.draw(CircleRed);

            }

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
               // if (Board.cell[y][x] == Empty) 
                //fillColor = emptyColor;
                
                fillColor = sf::Color::White;
                //else if (board[y][x] == Red)
                    //fillColor = redColor;
                //else
                    //fillColor = yellowColor;
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
        
        


/*
        if (sf::Event::MouseButtonPressed) {

            if ((sf::Mouse::getPosition(window).x >= 262 && sf::Mouse::getPosition(window).x <= 336) && (sf::Mouse::getPosition(window).y >= 661 && sf::Mouse::getPosition(window).y <= 735)) {
       
                CircleRed.setPosition(260, 660);
                window.draw(CircleRed);

            }
        }
       
        */


        //window.clear();

        window.draw(title);
        window.draw(info);

        //window.draw(circle);
       // window.draw(circle2); 


        // end the current frame
        window.display();

    }



    
    
}


