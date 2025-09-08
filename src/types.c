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
    .board = {
        OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD,
        OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, EMPTY,      EMPTY,        EMPTY,        EMPTY,       EMPTY,      EMPTY,        EMPTY,        EMPTY,      OFF_BOARD,
        OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD,
        OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD
    },
    .en_passant_target_square = { false }
};
