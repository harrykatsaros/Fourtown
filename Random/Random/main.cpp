#include <iostream>
#include <SFML/Graphics.hpp>
#include "boardstuff.h"


using namespace std;
sf::Color wordColor(150, 200, 224);

//MAIN FUNCTION
int main() {
    player p1, p2;
    int array[row][col];
    int pickc;
    bool win = false;
    int fullcol = 0;
    int r = 0;

    ///initialize the array////
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {

            array[i][j] = 0;

            //cout << array[i][j] << " ";

        }
        //cout << endl;
    }

    //Assign names and colors to p1, p2
    cout << "Let's Play Connect 4" << endl << endl;

    p1.name = "Player 1";
    p1.color = 1;
    p2.name = "Player 2";
    p2.color = -1;

    //createarray(array,window);//draws the board

    while (r != 2) {

        sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");

        // run the program as long as the window is open
        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || (r == 2)) {
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

            sf::RectangleShape rectangle(sf::Vector2f(800.f, 640.f));
            rectangle.setPosition(0, 130);
            rectangle.setFillColor(sf::Color::Blue);

            window.draw(rectangle);
            

            sf::Text title;
            title.setFont(font);
            title.setString("Connect Four");
            title.setCharacterSize(50);
            title.setFillColor(wordColor);
            title.setStyle(sf::Text::Bold | sf::Text::Underlined);
            title.setOrigin(150, 0);
            title.setPosition(400.f, 10.f);

            window.draw(title);

            //PLAYER 1 LOOP
            createarray(array, window);
            window.display();

            pickc = choosecol(array, p1);
            deleterow(array, p1, pickc);
            createarray(array,window);
            window.display();


            win = checkwin(array, p1);

            if (win == true) {
                displaywinner(p1);
                r = restart(array);
                if (r == 2) {
                    break;
                }
            }
            //PLAYER 2 LOOP
            pickc = choosecol(array, p2);
            deleterow(array, p2, pickc);
            createarray(array,window);
            window.display();

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
        
    }
    
    return 0;
}