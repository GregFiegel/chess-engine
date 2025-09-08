#include "types.h"
#include <stdio.h>
#include <stdlib.h>

int fen_to_position(char* fen){

    printf ("FEN: %s\n", fen);
    int i = 56; // Start from a8
    int j = 0;

    // Set piece placement
    position.white_pawns = 0;
    position.white_knights = 0;
    position.white_bishops = 0;
    position.white_rooks = 0;
    position.white_queens = 0;
    position.white_king = 0;
    position.black_pawns = 0;
    position.black_knights = 0;
    position.black_bishops = 0;
    position.black_rooks = 0;
    position.black_queens = 0;
    position.black_king = 0;
    for (j=0; fen[j]!=' '; j++) {
        if (fen[j] >= '1' && fen[j] <= '8') {
            int empty_squares = fen[j] - '0';
            i += empty_squares;
        } else if (fen[j] == '/') {
            i -= 16; // Move to the next rank
        } else {
            switch (fen[j]) {
                case 'p': position.black_pawns |= (1ULL << (i)); break;
                case 'r': position.black_rooks |= (1ULL << (i)); break;
                case 'n': position.black_knights |= (1ULL << (i)); break;
                case 'b': position.black_bishops |= (1ULL << (i)); break;
                case 'q': position.black_queens |= (1ULL << (i)); break;
                case 'k': position.black_king |= (1ULL << (i)); break;
                case 'P': position.white_pawns |= (1ULL << (i)); break;
                case 'R': position.white_rooks |= (1ULL << (i)); break;
                case 'N': position.white_knights |= (1ULL << (i)); break;
                case 'B': position.white_bishops |= (1ULL << (i)); break;
                case 'Q': position.white_queens |= (1ULL << (i)); break;
                case 'K': position.white_king |= (1ULL << (i)); break;
                default: perror("Invalid FEN string: unrecognized piece"); 
                         exit(EXIT_FAILURE);
            }
            i++;
        }
    }
    j++;

    // Set turn
    if (fen[j] == 'w') {
        position.turn = WHITE_TO_MOVE;
    } else if (fen[j] == 'b') {
        position.turn = BLACK_TO_MOVE;
    }
    else {
        perror("Invalid FEN string: missing turn information");
        exit(EXIT_FAILURE);
    }
    j += 2;

    // Set castling rights
    position.white_kingside_castle = false;
    position.white_queenside_castle = false;
    position.black_kingside_castle = false;
    position.black_queenside_castle = false;
    if (fen[j] == '-') {
        j++;
    } else {
        while (fen[j] != ' ') {
            switch (fen[j]) {
                case 'K': position.white_kingside_castle = true; break;
                case 'Q': position.white_queenside_castle = true; break;
                case 'k': position.black_kingside_castle = true; break;
                case 'q': position.black_queenside_castle = true; break;
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
                position.en_passant_target_square[k] = false;
            }
        } else if (fen[j] < 'a' || fen[j] > 'h' || fen[j+1] < '1' || fen[j+1] > '8') {
            perror("Invalid FEN string: invalid en passant target square");
            exit(EXIT_FAILURE);
        } else {
            int file = fen[j] - 'a';
            int rank = fen[j+1] - '1';
            int index = 21 + rank * 10 + file;
            for (int k=0; k<120; k++) {
                position.en_passant_target_square[k] = false;
            }
            position.en_passant_target_square[index] = true;
            j++;
        }
    }
    j++;   

    // Set halfmove clock
    position.halfmove_clock = 0;
    for (; fen[j] != ' '; j++) {
        if (fen[j] < '0' || fen[j] > '9') {
            perror("Invalid FEN string: invalid halfmove clock");
            exit(EXIT_FAILURE);
        }
        position.halfmove_clock = position.halfmove_clock * 10 + (fen[j] - '0');
    }
    j++;

    // Set fullmove number
    position.fullmove_number = 0;
    for (; fen[j] != '\0' && fen[j] != '\n'; j++) {
        if (fen[j] < '0' || fen[j] > '9') {
            perror("Invalid FEN string: invalid fullmove number");
            exit(EXIT_FAILURE);
        }
        position.fullmove_number = position.fullmove_number * 10 + (fen[j] - '0');
    }

    return 0;
}
