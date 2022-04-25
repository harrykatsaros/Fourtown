#include <iostream>
using namespace std;
#define row 7
#define col 8
//BOARD IS 5 BY 6

struct player{
    char name[50];
    int color; //red=1, yellow=-1, empty=0
};

//FUNCTION STUBS
int choosecol(int array[][col], player active);
void deleterow(int array[][col], player active, int pickc);
void createarray(int array[][col]);
bool checkwin(int array[][col], player active);
int checkfull(int array[][col]);
void displaywinner(player active); //ongoing game = 0, player 1 = 1, player 2 = 2, draw = 3
int restart(int array[][col]);

//MAIN FUNCTION
int main(){
    player p1, p2;
    int array[row][col];
    int pickc;
    bool win = false;
    int fullcol = 0;
    int r = 0;

    //Assign names and colors to p1, p2
    cout << "Let's Play Connect 4" << endl << endl;
	cout << "Player One please enter your name: ";
    cin >> p1.name;
    p1.color = 1;
    cout << "Player Two please enter your name: ";
    cin >> p2.name;
    p2.color = -1;

    createarray(array);

    while(r != 2){
        //PLAYER 1 LOOP
        pickc = choosecol(array,p1);
        deleterow(array,p1,pickc);
        createarray(array);
        win = checkwin(array,p1);
        if(win == true){
            displaywinner(p1);
            r = restart(array);
            if(r == 2){
                break;
            }
        }
        //PLAYER 2 LOOP
        pickc = choosecol(array,p2);
        deleterow(array,p2,pickc);
        createarray(array);
        win = checkwin(array,p2);
        if(win == true){
            displaywinner(p2);
            r = restart(array);
            if(r == 2){
                break;
            }
        }
        //CHECKING FULL BOARD
        fullcol = checkfull(array);
        if(fullcol == 6){
            cout << "The board is full, it is a draw!" << endl; //assign check = 3 (draw)
            r = restart(array);
        }
    }
}

int choosecol(int array[][col], player active){
    int pickc;
    
    do{
        cout << active.name << "'s Turn ";
        cout << "Please enter a number between 1 and 6: ";
        cin >> pickc;
    
        while(array[1][pickc] == 1 || array[1][pickc] == -1){
            cout << "Row is full, please choose new number: ";
            cin >> pickc;
        }

    }while(pickc < 1 || pickc > 6);

return pickc;
}

void deleterow(int array[][col], player active, int pickc){
    bool change = false;
    int length = 5;

    while(change == false){
        if(array[length][pickc] != 1 || array[5][pickc] != -1){
            array[length][pickc] = active.color;
            change = true;
        }
        else
        length = length-1;
    }
}

void createarray(int array[][col]){
    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 6; j++){
            if(array[i][j] != 1 && array[i][j] != -1){
                array[i][j] = 0;
                cout << array[i][j] << " ";

            }
        }
        cout << endl;
    }
}

bool checkwin(int array[][col], player active){
    bool win = false;
    int findcolor = active.color;

    for(int i = row; i >= 0; --i){
        for(int j = col; j >= 0; --j){

            if(array[i][j] == findcolor && array[i][j-1] == findcolor && array[i][j-2] == findcolor && array[i][j-3] == findcolor){ //vertical
                win = true;
            }

            if(array[i][j] == findcolor && array[i][j+1] == findcolor && array[i][j+2] == findcolor && array[i][j+3] == findcolor){ //horizontal right
                win = true;
            }

            if(array[i][j] == findcolor && array[i-1][j] == findcolor && array[i-2][j] == findcolor && array[i-3][j] == findcolor){ //horizontal left
                win = true;
            }

            if(array[i][j] == findcolor && array[i-1][j-1] == findcolor && array[i-2][j-2] == findcolor && array[i-3][j-3] == findcolor){ //diagonal negative slope
                win = true;
            }

            if(array[i][j] == findcolor && array[i-1][j+1] == findcolor && array[i-2][j+2] == findcolor && array[i-3][j+3] == findcolor){ //diagonal positive slope
                win = true;
            }
        }
    }
    return win;
}

int checkfull(int array[][col]){
    int fullcol = 0;

    for(int i = 0; i < col; ++i){
        if(array[1][i] != 0){
            fullcol = fullcol + 1;
        }
    }

    return fullcol;
}

void displaywinner(player active){ //player 1 = 1, player 2 = 2, draw = 3
    cout << endl << active.name << " Connected Four, You Win!" << endl;
}

int restart(int array[][col]){
    int r;

    cout << "Would you like to restart? Yes(1) No(2): ";
    cin >> r;
    if(r == 1){ //button pressed
        for(int i = 0; i <= row; i++){
            for(int j = 0; j <= col; j++){
                array[i][j] = 0;
            }
        }
    }
    else{
        cout << "Bye!" << endl; //EXIT
    }
    return r;
}