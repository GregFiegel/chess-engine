#include <stdint.h>
#include <stdlib.h>

#include "types.h"

uint64_t generate_pseudo_legal_moves(struct position *position){

    uint64_t full_bitboard = (position->white_pawns|position->white_rooks|position->
        white_knights|position->white_bishops|position->white_queens|position->white_king|position->
        black_pawns|position->black_rooks|position->black_knights|position->
        black_bishops|position->black_queens|position->black_king);
        
    enum to_move turn = position->turn;

    uint64_t pawn_moves = generate_pseudo_legal_pawn_moves(&position, position);
}

uint64_t generate_pseudo_legal_pawn_moves(struct position *position, uint64_t pawn_bitboard){
    if (turn == WHITE_TO_MOVE){

    } else if (turn == BLACK_TO_MOVE){

    } else {
        perror("Invalid to_move value");
        exit(EXIT_FAILURE);
    }
}