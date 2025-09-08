#include <stdint.h>
#include <stdbool.h>

// Piece definitions
#ifndef TYPES_H
#define TYPES_H

#define PAWN          (int8_t)0x01
#define KNIGHT        (int8_t)0x02
#define BISHOP        (int8_t)0x03
#define ROOK          (int8_t)0x04
#define QUEEN         (int8_t)0x05
#define KING          (int8_t)0x06
#define EMPTY         (int8_t)0x00
#define OFF_BOARD     (int8_t)0xFF
#define BLACK         (int8_t)0x80
#define WHITE         (int8_t)0x00
#define HAS_MOVED     (int8_t)0x08

#endif // TYPES_H

extern enum to_move {WHITE_TO_MOVE, BLACK_TO_MOVE} turn;

extern bool white_kingside_castle;
extern bool white_queenside_castle;
extern bool black_kingside_castle;
extern bool black_queenside_castle;
extern int halfmove_clock;
extern int fullmove_number;

extern int8_t position[120];

extern bool en_passant_target_square[120];