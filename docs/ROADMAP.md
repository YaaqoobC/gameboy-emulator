# Game Boy Emulator — Desktop Roadmap

Portable, original Nintendo Game Boy (DMG-01) emulator written in **C11**. Desktop host uses **SDL3**; core must remain independent of SDL, Pico SDK and FreeRTOS.

## Architecture
```
Game ROM → cartridge/bus → SM83 CPU ↔ timers/interrupts
                            ↕
                         PPU / APU / joypad
                            ↕
                 Platform-neutral host API
                            ↕
                    SDL3 desktop frontend
```
Maintain one deterministic virtual hardware clock across all emulated components.

## Epic / milestone tracking
| Roadmap | Epic | Completion gate |
|---|---|---|
| M1 | #1 Foundation & Architecture | Build/tests, architecture and diagnostics |
| M2 | #2 SM83 CPU | Instruction legality, flags, cycle and test coverage |
| M3 | #3 Bus, Cartridge & Timing | Memory map, banked ROM, DMA, timers and interrupts |
| M4 | #4 PPU Video | LCD timing and reference pixel tests |
| M5 | #5 Desktop Frontend | Interactive SDL3 application |
| M6 | #6 APU & Compatibility | Four audio channels, saves and reference ROMs |
| M7 | #7 Desktop 1.0 Release | Release artifact, regression suite and documentation |

Each epic links to its child user stories. Finish M7 before declaring the portable core ready for the embedded port.

## Definition of done
- CI and relevant unit/integration ROM tests pass.
- New behavior has repeatable test coverage.
- No commercial ROMs or proprietary Nintendo boot ROM images are committed.
- Core stays portable C11 and is built independently of host-facing libraries.
- Timing and compatibility limitations are documented.

## Resources
- [Pan Docs](https://gbdev.io/pandocs/)
- [Mooneye test suite](https://github.com/Gekkio/mooneye-test-suite)
- [Blargg Game Boy test ROMs](https://github.com/retrio/gb-test-roms)

## Related repository
[Game Boy Pico / FreeRTOS](https://github.com/YaaqoobC/gameboy-pico).
