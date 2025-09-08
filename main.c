#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/types.h"
#include "include/utils.h"
#include "include/fen.h"

char *getFen(void);

int main(void)
{
    while (1)
    {
        char *fen = getFen();
        fen_to_position(fen);
        free(fen);
        printBoard(position);
        printf("Side to move: %s\n", turn == WHITE_TO_MOVE ? "White" : "Black");
        printf("White kingside castling: %s\n", white_kingside_castle ? "Yes" : "No");
        printf("White queenside castling: %s\n", white_queenside_castle ? "Yes" : "No");
        printf("Black kingside castling: %s\n", black_kingside_castle ? "Yes" : "No");
        printf("Black queenside castling: %s\n", black_queenside_castle ? "Yes" : "No");
        printf("Halfmove clock: %d\n", halfmove_clock);
        printf("Fullmove number: %d\n", fullmove_number);
    }
    return 0;
}

char *getFen(void)
{
    char *fen = malloc(256 * sizeof(char));
    if (fen == NULL)
    {
        perror("Failed to allocate memory for FEN string");
        exit(EXIT_FAILURE);
    }
    printf("Enter your fen string: ");
    if (fgets(fen, 128, stdin) == NULL)
    {
        perror("Failed to read FEN string");
        free(fen);
        exit(EXIT_FAILURE);
    }
    return fen;
}