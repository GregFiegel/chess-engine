#include "include/types.h"
#include <stdio.h>
#include <stdlib.h>

int fen_to_position(char* fen){

    printf ("FEN: %s\n", fen);
    int i = 21; // Start from the first square
    int j = 0;
    // Set piece placement
    for (j=0; fen[j]!=' '; j++) {
        if (fen[j] >= '1' && fen[j] <= '8') {
            int empty_squares = fen[j] - '0';
            for (int k=0; k<empty_squares; k++) {
                position[i] = EMPTY;
                i++;
            }
        } else if (fen[j] == '/') {
            i += 2; // Move to the next row
        } else {
            int8_t piece = EMPTY;
            switch (fen[j]) {
                case 'p': piece = PAWN | WHITE; break;
                case 'r': piece = ROOK | WHITE; break;
                case 'n': piece = KNIGHT | WHITE; break;
                case 'b': piece = BISHOP | WHITE; break;
                case 'q': piece = QUEEN | WHITE; break;
                case 'k': piece = KING | WHITE; break;
                case 'P': piece = PAWN | BLACK; break;
                case 'R': piece = ROOK | BLACK; break;
                case 'N': piece = KNIGHT | BLACK; break;
                case 'B': piece = BISHOP | BLACK; break;
                case 'Q': piece = QUEEN | BLACK; break;
                case 'K': piece = KING | BLACK; break;
                default: perror("Invalid FEN string: unrecognized piece"); 
                         exit(EXIT_FAILURE);
            }
            position[i] = piece;
            i++;
        }
    }
    j++;

    // Set turn
    if (fen[j] == 'w') {
        turn = WHITE_TO_MOVE;
    } else if (fen[j] == 'b') {
        turn = BLACK_TO_MOVE;
    }
    else {
        perror("Invalid FEN string: missing turn information");
        exit(EXIT_FAILURE);
    }
    j += 2;

    // Set castling rights
    white_kingside_castle = false;
    white_queenside_castle = false;
    black_kingside_castle = false;
    black_queenside_castle = false;
    if (fen[j] == '-') {
        j++;
    } else {
        while (fen[j] != ' ') {
            switch (fen[j]) {
                case 'K': white_kingside_castle = true; break;
                case 'Q': white_queenside_castle = true; break;
                case 'k': black_kingside_castle = true; break;
                case 'q': black_queenside_castle = true; break;
                default: perror("Invalid FEN string: invalid castling rights");
                         exit(EXIT_FAILURE);
            }
            j++;
        }
    }
    j++;

    // Set en passant target square
    for (; fen[j] != ' '; j++){
        if (fen[j] == '-') {
            for (int k=0; k<120; k++) {
                en_passant_target_square[k] = false;
            }
        } else if (fen[j] < 'a' || fen[j] > 'h' || fen[j+1] < '1' || fen[j+1] > '8') {
            perror("Invalid FEN string: invalid en passant target square");
            exit(EXIT_FAILURE);
        } else {
            int file = fen[j] - 'a';
            int rank = fen[j+1] - '1';
            int index = 21 + rank * 10 + file;
            for (int k=0; k<120; k++) {
                en_passant_target_square[k] = false;
            }
            en_passant_target_square[index] = true;
            j++;
        }
    }
    j++;   

    // Set halfmove clock
    halfmove_clock = 0;
    for (; fen[j] != ' '; j++) {
        if (fen[j] < '0' || fen[j] > '9') {
            perror("Invalid FEN string: invalid halfmove clock");
            exit(EXIT_FAILURE);
        }
        halfmove_clock = halfmove_clock * 10 + (fen[j] - '0');
    }
    j++;

    // Set fullmove number
    fullmove_number = 0;
    for (; fen[j] != '\0' && fen[j] != '\n'; j++) {
        if (fen[j] < '0' || fen[j] > '9') {
            perror("Invalid FEN string: invalid fullmove number");
            exit(EXIT_FAILURE);
        }
        fullmove_number = fullmove_number * 10 + (fen[j] - '0');
    }

    return 0;
}