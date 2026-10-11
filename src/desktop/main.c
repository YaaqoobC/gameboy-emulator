#include <stdio.h>

#include "gb/gameboy.h"

int main() {
    GameBoy gb;
    gb_init(&gb);
    
    printf("Game Boy Emulator\n");

    for (int i = 0; i < 10; i++) {
        gb_step(&gb);
    }

    printf("Emulator ticks: %llu\n", (unsigned long long)gb.ticks);

    return 0;
}