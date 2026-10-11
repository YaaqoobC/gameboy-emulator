# Desktop — Outcome-based Delivery Roadmap

> **Epics** group work by subsystem; **stories** represent individual changes; **milestones** are demonstrable integration results. The original M1–M12 story prefixes are permanent backlog identifiers, **not** native GitHub milestones. Milestones below intentionally span epics. No dates are committed.

| Checkpoint | Demonstrable outcome | Required verification | Contributing epics |
|---|---|---|---|
| D1 | **Core skeleton boots a diagnostic ROM** | C11/CMake build, core APIs, cartridge load, deterministic instruction stepping; a test ROM can be loaded and traced. | #1, #2, #3 |
| D2 | **CPU passes reference tests** | Legal SM83 base/CB instructions, flags and timings pass selected instruction test ROMs; interrupts and timers validated. | #2, #3 |
| D3 | **First accurate rendered frame** | LCD mode scheduling, background/window/sprites and DMA produce a verified 160×144 frame. | #3, #4 |
| D4 | **First playable game** | SDL3 presents frames; joypad input works; ROM runs interactively at appropriate emulated timing. | #2, #3, #4, #5 |
| D5 | **Desktop v1.0 release** | APU output, supported cartridge banking and saves, regression/compatibility test matrix, downloadable build and docs. | #3, #5, #6, #7 |

## Rules for milestone completion

1. Attach test logs, captured frames or on-device evidence to a tracking issue or release notes.
2. All critical acceptance tests must pass; any exceptions are explicitly documented.
3. An epic's stories can contribute to several checkpoints and an epic can stay open after a milestone completes.
4. This table is a **milestone specification** in documentation, not native GitHub Milestones; those require creation and issue assignment separately.

## Existing backlog

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
