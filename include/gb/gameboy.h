#ifndef GB_GAMEBOY_H
#define GB_GAMEBOY_H

#include <stdint.h>

typedef struct {
    uint64_t ticks;
    uint8_t running;
} GameBoy;

void gb_init(GameBoy *gb);
void gb_step(GameBoy *gb);

#endif