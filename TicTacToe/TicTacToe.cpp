#include <iostream>
#include <stdlib.h>

using namespace std;

char matrix[3][3];

char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();


int main()
{
    char done;

    cout << "Lets start a XOX game together! " << endl;
    cout << "You will be play against to the computer. " << endl;

    done = ' ';
    init_matrix();

    do{
        disp_matrix();
        get_player_move();

        done = check(); /** See if winner **/
        if (done != ' ') break; /** Winner **/

        get_computer_move();
        done = check();/** See if winner **/
    } while (done == ' ');

    if (done == 'X') cout << "You won! " << endl;
    else cout << "Haha we won! " << endl;
    
    disp_matrix(); 

    return 0;
}

void init_matrix() {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) matrix[i][j] = ' ';
    }

}


/** Get player's move **/
void get_player_move() {

    int x, y;

    cout << "Enter X,Y coordinates for your move: ";
    cin >> x >> y;

    x--, y--;
    
    if (matrix[x][y] != ' ') {
        cout << "Invalid move, try again. " << endl;
        get_player_move();
    } else 
        matrix[x][y] = 'X';

}

void get_computer_move() {

    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == ' ') break;
        if (matrix[i][j] == ' ') break;
    }

    if (i * j == 9) {
        cout << "draw\n";
        exit(0);
    } else matrix[i][j] = 'O';

}

void disp_matrix() {

    for (int t = 0; t < 3; t++) {
        cout << " " << matrix[t][0] << " | " << matrix[t][1] << " | " << matrix[t][2];
        if (t != 2) cout << "\n---|---|---\n";
    }

    cout << "\n";

}

char check() {

    int i;

    /** check rows **/
    for (i = 0; i < 3; i++)
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            return matrix[i][0];

    /** check columns **/
    for (i = 0; i < 3; i++)
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            return matrix[0][i];

    /** check diagonals **/
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];

    return ' ';
        
}

