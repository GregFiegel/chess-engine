#include <stdint.h>
#include <stdio.h>
#include "types.h"

int printBoard(struct position *position) {
    printf("╔════════╗\n");
    for (int i = 7; i >= 0; i--) {
        printf("║");
        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            if((position->white_pawns|position->white_rooks|position->white_knights|position->white_bishops|position->white_queens|position->white_king) & (1ULL << index)) {
                if (position->white_pawns & (1ULL << index)) {
                    printf("P");
                } else if (position->white_rooks & (1ULL << index)) {
                    printf("R");
                } else if (position->white_knights & (1ULL << index)) {
                    printf("N");
                } else if (position->white_bishops & (1ULL << index)) {
                    printf("B");
                } else if (position->white_queens & (1ULL << index)) {
                    printf("Q");
                } else if (position->white_king & (1ULL << index)) {
                    printf("K");
                }
            } else if((position->black_pawns|position->black_rooks|position->black_knights|position->black_bishops|position->black_queens|position->black_king) & (1ULL << index)) {
                if (position->black_pawns & (1ULL << index)) {
                    printf("p");
                } else if (position->black_rooks & (1ULL << index)) {
                    printf("r");
                } else if (position->black_knights & (1ULL << index)) {
                    printf("n");
                } else if (position->black_bishops & (1ULL << index)) {
                    printf("b");
                } else if (position->black_queens & (1ULL << index)) {
                    printf("q");
                } else if (position->black_king & (1ULL << index)) {
                    printf("k");
                }
            } else {
                printf(" ");
            }
        }
        printf("║\n");
    }
    printf("╚════════╝\n");
    return 0;
}
