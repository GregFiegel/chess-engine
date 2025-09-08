#include <stdint.h>
#include <stdbool.h>
#include "types.h"

// Global current position instance
struct position position = {
    .turn = WHITE_TO_MOVE,
    .white_kingside_castle = false,
    .white_queenside_castle = false,
    .black_kingside_castle = false,
    .black_queenside_castle = false,
    .halfmove_clock = 0,
    .fullmove_number = 0,
    .white_pawns = 0,
    .white_knights = 0,
    .white_bishops = 0,
    .white_rooks = 0,
    .white_queens = 0,
    .white_king = 0,
    .black_pawns = 0,
    .black_knights = 0,
    .black_bishops = 0,
    .black_rooks = 0,
    .black_queens = 0,
    .black_king = 0,
    .en_passant_target_square = { false }
};