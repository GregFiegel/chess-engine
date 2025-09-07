#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "move_legality.h"

int printBoard (int8_t[]);
char* getMove (void);
int movePiece (char*, int8_t[]);
int isMoveLegal (char*, int8_t[]);

const int8_t PAWN =         0x01;
const int8_t KNIGHT =       0x02;
const int8_t BISHOP =       0x03;
const int8_t ROOK =         0x04;
const int8_t QUEEN =        0x05;
const int8_t KING =         0x06;
const int8_t EMPTY =        0x00;
const int8_t OFF_BOARD =    0xFF;
const int8_t BLACK =        0x80;
const int8_t HAS_MOVED =    0x08;
const int8_t CASTLE_FLAG =  0x10;

int8_t b[120]=
{OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD, 
 OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD, 
 OFF_BOARD, BLACK|ROOK, BLACK|KNIGHT, BLACK|BISHOP, BLACK|QUEEN, BLACK|KING, BLACK|BISHOP, BLACK|KNIGHT, BLACK|ROOK, OFF_BOARD,
 OFF_BOARD, BLACK|PAWN, BLACK|PAWN,   BLACK|PAWN,   BLACK|PAWN,  BLACK|PAWN, BLACK|PAWN,   BLACK|PAWN,   BLACK|PAWN, OFF_BOARD,
 OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
 OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
 OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
 OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
 OFF_BOARD, PAWN,       PAWN,         PAWN,         PAWN,        PAWN,       PAWN,         PAWN,         PAWN,       OFF_BOARD,
 OFF_BOARD, ROOK,       KNIGHT,       BISHOP,       QUEEN,       KING,       BISHOP,       KNIGHT,       ROOK,       OFF_BOARD,
 OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD, 
 OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD};

int main(void) {
    while (1) {
        printBoard(b);
        char* move = getMove();
        if (move[0] == 'q' || move[0] == 'Q') { // allow user to quit
            free(move);
            break;
        }
        movePiece(move, b);
        free(move);
    }
    return 0;
}

int printBoard(int8_t board[]){
    for (int i = 10; i < 120; i++) {
        if (i==110) break;
        int8_t piece = board[i];
        if (piece == OFF_BOARD) {
            printf("=");
        } else if ((piece & 0x07) == EMPTY) {
            printf("□");
        } else {
            int is_black = (piece & BLACK) ? 1 : 0;
            switch (piece & 0x07) {
                case PAWN:
                    printf(is_black ? "P" : "p");
                    break;
                case KNIGHT:
                    printf(is_black ? "H" : "h");
                    break;
                case BISHOP:
                    printf(is_black ? "B" : "b");
                    break;
                case ROOK:
                    printf(is_black ? "R" : "r");
                    break;
                case QUEEN:
                    printf(is_black ? "Q" : "q");
                    break;
                case KING:
                    printf(is_black ? "K" : "k");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    return 0;
}

char* getMove(void){
    char* move = malloc(5 * sizeof(char));
    printf("Enter your move (e.g., e2e4): ");
    scanf("%4s", move);
    return move;
}

int movePiece(char* move, int8_t board[]){
    if (move[0] < 'a' || move[0] > 'h' || move[2] < 'a' || move[2] > 'h' ||
        move[1] < '1' || move[1] > '8' || move[3] < '1' || move[3] > '8') {
        printf("Invalid move format.\n");
        return -1;
    }

    int from_col = move[0] - 'a';
    int from_row = move[1] - '1';
    int to_col = move[2] - 'a';
    int to_row = move[3] - '1';

    int from_index = 21 + from_row * 10 + from_col;
    int to_index = 21 + to_row * 10 + to_col;

    if (board[from_index] == EMPTY) {
        printf("No piece at the source position.\n");
        return -1;
    }

    // Basic move without validation
    if(isMoveLegal(move, board) != 0) {
        printf("Illegal move.\n");
        return -1;
    }
    board[to_index] = board[from_index];
    board[from_index] = EMPTY;

    return 0;
}

int isMoveLegal(char* move, int8_t board[]){
    // Placeholder for move legality check
    // This function should implement the actual chess rules
    return 0; // Assume all moves are legal for now
}
