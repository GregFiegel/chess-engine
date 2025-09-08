#include <stdint.h>
#include <stdbool.h>
#include "include/types.h"

enum to_move turn = WHITE_TO_MOVE;

bool white_kingside_castle;
bool white_queenside_castle;
bool black_kingside_castle;
bool black_queenside_castle;
int halfmove_clock;
int fullmove_number;

int8_t position[120] = 
   {OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD, 
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
    OFF_BOARD, OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,   OFF_BOARD,  OFF_BOARD,    OFF_BOARD,    OFF_BOARD,  OFF_BOARD};

bool en_passant_target_square[120] = {false};
