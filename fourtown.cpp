#include <iostream>
using namespace std;
#DEFINE row = 5;
#DEFINE col = 6;

struct player{
    char name[50];
    int color; //red=1, yellow=-1, empty=0
};

int choosecol(int array[][col], player active){
    int pickc;
    
    // display current player's turn
    cin << pickc; //input periferals
    while(pickc < 0 || pickc > 6){
        if(array[1][pickc] == 1 || array[1][pickc] == -1){
            cout << "Row is full, please choose new number: ";
            cin >> pickc; //input periferals
        }
    }
    return pickc;
}

void deleterow(int array[][6], player active, int pickc){
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

void createarray(int array[][6]){
    for(int i = 0; i<= row; i++){
        for(int j = 0; j <= col; j++){
            if(array[i][j] != 1 && array[i][j] != -1){
                array[i][j] = 0;
            }
        }
    }
}

bool checkwin(int array[][6], player active){
    bool win = false;
    int findcolor = active.color;

    for(int i = rows; i >= 0; --i){
        for(int j = col; j >= 0; --j){

            if(array[i][j] == findcolor && array[i][j-1] == findcolor && array[i][j-2] == findcolor && array[i][j-3] == findcolor){ //vertical
                win true;
            }

            if(array[i][j] == findcolor && array[i][j+1] == findcolor && array[i][j+2] == findcolor && array[i][j+3] == findcolor){ //horizontal right
                win true;
            }

            if(array[i][j] == findcolor && array[i-1][j] == findcolor && array[i-2][j] == findcolor && array[i-3][j] == findcolor){ //horizontal left
                win true;
            }

            if(array[i][j] == findcolor && array[i-1][j-1] == findcolor && array[i-2][j-2] == findcolor && array[i-3][j-3] == findcolor){ //diagonal negative slope
                win true;
            }

            if(array[i][j] == findcolor && array[i-1][j+1] == findcolor && array[i-2][j+2] == findcolor && array[i-3][j+3] == findcolor){ //diagonal positive slope
                win true;
            }
        }
    }
    return win;
}

int checkfull(int array[][6]){
    int fullcol = 0;

    for(int i = 0; i < col; ++i){
        if(array[1][i] != 0){
            fullcol = fullcol + 1;
        }
    }

    return fullcol;
}

int displayfinal(){ //player 1 = 1, player 2 = 2, draw = 3
    //idk rn
}

int restart(int array[][6]){
    int restart;

    if(restart == 1){ //button pressed
        for(int i = 0; i <= 5; i++){
            for(int j = 0; j <= 6; j++){
                array[i][j] = 0;
            }
        }
    }
    else{
        // exit
    }
    return restart;
}