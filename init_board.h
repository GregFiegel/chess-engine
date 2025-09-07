#ifndef INIT_BOARD_H
#define INIT_BOARD_H

#include <stdint.h>

// Piece constants
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

// Board array
extern int8_t b[120];

// Function declarations
int printBoard(int8_t board[]);
char* getMove(void);
int movePiece(char* move, int8_t board[]);
int isMoveLegal(char* move, int8_t board[]);

#endif // INIT_BOARD_H