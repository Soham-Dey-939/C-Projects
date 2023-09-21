
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard();
void printboard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkwinner();
void printwinner(char);

int main(){
    char winner = ' ';
    char response;
    do
    {
        winner = ' ';
        response = ' ';
        resetboard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printboard();
            
            playerMove();
            winner = checkwinner();
            if (winner != ' ' || checkFreeSpaces() == 0){
                break;
            }

            computerMove();
            winner = checkwinner();
            if (winner != ' ' || checkFreeSpaces() == 0){
                break;
            }
        }
        
        printboard();
        printwinner(winner);

        printf("DO YOU WANNA PLAY AGAIN? (Y/N) -> ");
        scanf(" %c",&response);
        response = toupper(response);
    } while (response == 'Y');
    
    printf("THANK YOU FOR PLAYING THE GAME!");

    return 0;
}

void resetboard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void printboard(){
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");

}

int checkFreeSpaces(){
    int freespaces = 9;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != ' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playerMove(){
    int x;
    int y;
   
    do
    {
        printf("Enter row#(1-3) -> ");
        scanf("%d",&x);
        x--;
        printf("Enter column#(1-3) -> ");
        scanf("%d",&y);
        y--;
        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');
    
}
void computerMove(){
    //creates a seed based on current time
    srand(time(0));
    int x;
    int y;
    if(checkFreeSpaces() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }

    else{
        printwinner(' ');
    }

}

char checkwinner(){
    //check rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board [i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int j = 0; j < 3; j++){
        if(board[0][j] == board [1][j] && board[0][j] == board[2][j]){
            return board[0][j];
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[2][0] == board [0][2]){
        return board[2][0];
    }

    return ' ';
    
    
}

void printwinner(char winner){
    if(winner == PLAYER ){
        printf("YOU WIN! :)\n");
    }
    else if(winner == COMPUTER){
        printf("YOU LOSE! :(\n");
    }
    else{
        printf("IT'S A TIE!\n");
    }
}