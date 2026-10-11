#include "gb/gameboy.h"

/**
 * Initialize the GameBoy State.
 */
void gb_init(GameBoy *gb) {
    gb->ticks = 0;
    gb->running = 1;
}

/**
 * Step the GameBoy State;
 * -> Execute CPU instructions
 */
void gb_step(GameBoy *gb){
    if (!gb->running) {
        return;
    }

    // CPU execution placeholder
    gb->ticks++;
}