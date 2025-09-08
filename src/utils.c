#include <stdint.h>
#include <stdio.h>
#include "types.h"

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
