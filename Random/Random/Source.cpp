#include <iostream>
#include <SFML/Graphics.hpp>
#include "boardstuff.h"

using namespace std;

int main()
{
    player p1, p2, current;
    int array[row][col];
    int pickc = 7;
    bool win = false;
    int fullcol = 0;
    int r = 0;
    int full = 0;

    ///initialize the array////
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {

            array[i][j] = 0;

        }
    }

    p1.name = "Player 1";
    p1.color = 1;
    p2.name = "Player 2";
    p2.color = -1;

    current = p1;

    while (r != 2)
    {

        sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");

        while (window.isOpen()) // run the program as long as the window is open
        {
            sf::Event event;

            sf::Font font;
            if (!font.loadFromFile("sansation.ttf"))
            {
                cout << "Error" << endl;
            }

            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || (r == 2)) {
                    window.close();
                }
                else if ((mouse_position.y < 741 && mouse_position.y > 159) && event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) { // if the screen is clicked within the playable region

                    cout << mouse_position.x << " " << mouse_position.y << endl;
                    cout << current.name << endl;

                    pickc = choosecol(array, current, mouse_position);
                    if (pickc != 7) { //the range of playable moves is 0-6, so if pickc returns 7 that means either the column was full or something bad happened
                        deleterow(array, current, pickc);
                        win = checkwin(array, current);
                        full = checkfull(array);

                        if (win == false) { // as long as no one has won yet, players change
                            if (current.color == p1.color) {
                                current = p2;
                            }
                            else {
                                current = p1;
                            }
                        }
                    }

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    current = p1;
                    restart(array);
                    win = false;
                    fullcol = 0;
                }
            }
            window.clear(sf::Color::Black);
            if (win == true) {

                displaywinner(current, window, font);
                createarray(array, window); 

            }
            else if (full == 7) {
                sf::Color wordColor(150, 200, 224);

                sf::Text checkfull; 
                checkfull.setFont(font); 
                checkfull.setString("It's a Draw!"); 
                checkfull.setCharacterSize(50); 
                checkfull.setFillColor(wordColor); 
                checkfull.setStyle(sf::Text::Bold | sf::Text::Underlined); 
                checkfull.setOrigin(100, 0); 
                checkfull.setPosition(380.f, 200.f); 

                sf::Text restartscreen;
                restartscreen.setFont(font);
                restartscreen.setString("Press R to restart!");
                restartscreen.setCharacterSize(50);
                restartscreen.setFillColor(wordColor);
                restartscreen.setStyle(sf::Text::Bold);
                restartscreen.setOrigin(120, 0);
                restartscreen.setPosition(200.f, 400.f);

                window.draw(checkfull); 
                window.draw(restartscreen);
            }
            else {
                drawstuff(window, current, font);
                createarray(array, window);

            }
            window.display();

        }

    }

    return 0;
}