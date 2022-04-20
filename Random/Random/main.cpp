#include <iostream>
#include <SFML/Graphics.hpp>

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
        
        sf::RectangleShape rectangle(sf::Vector2f(800.f, 580.f));
        rectangle.setPosition(0,100);
        rectangle.setFillColor(sf::Color::Blue);





        window.draw(title);
        window.draw(info);
        window.draw(rectangle);


        // end the current frame
        window.display();
    }




}
