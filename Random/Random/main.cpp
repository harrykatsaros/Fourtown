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
    
    ///initialize the array////
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {

            array[i][j] = 0;

        }
    }

    //Assign names and colors to p1, p2
    cout << "Let's Play Connect 4" << endl << endl;

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
            if (!font.loadFromFile("arial.ttf"))
            {
                cout << "Error" << endl;
            }

            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || (r == 2)) {
                    window.close();
                } 
                else if ((mouse_position.y < 741 && mouse_position.y > 159) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    cout << mouse_position.x << " " << mouse_position.y << endl;
                    cout << current.name << endl;
                    
                    pickc = choosecol(array, current,mouse_position);
                    if (pickc != 7) {
                        deleterow(array, current, pickc);
                        //drawstuff(window, current, font);
                        //createarray(array, window);
                        //window.display();

                        if (current.color == p1.color) {
                            current = p2;
                        }
                        else {
                            current = p1;
                        }
                    }
                }
            }
            window.clear(sf::Color::Black);
            drawstuff(window, current, font);
            createarray(array, window);
            window.display();
            
        }
        
    }
    
    return 0;
}