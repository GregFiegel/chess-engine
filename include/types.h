#include <stdint.h>
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

// Piece definitions
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

// Side to move
enum to_move {WHITE_TO_MOVE, BLACK_TO_MOVE};

// Game state container
struct position {
    enum to_move turn;
    bool white_kingside_castle;
    bool white_queenside_castle;
    bool black_kingside_castle;
    bool black_queenside_castle;
    int halfmove_clock;
    int fullmove_number;

    // 10x12 mailbox board
    int8_t board[120];

    // En passant flags per square in mailbox
    bool en_passant_target_square[120];
};

// Global current position
extern struct position position;

#endif // TYPES_H
