<<<<<<< HEAD
# C++ Turn-Based Combat Simulator

A turn-based combat simulator built in C++17 as a portfolio project targeting game studio internships. Designed to demonstrate clean OOP architecture, polymorphic game systems, and software engineering best practices including TDD and CI/CD.

## Features

- **Polymorphic action system** — `BasicAttack`, `HeavyAttack` (20% miss chance), and `Heal` (charge-limited, player-only) all derive from an abstract `Action` base class
- **Multi-enemy combat** — fight multiple enemies per level with dynamic target selection
- **Level system** — preset levels loaded via `LevelLoader` with distinct enemy rosters and difficulty
- **Enemy AI** — enemies randomly select between `BasicAttack` and `HeavyAttack` each turn
- **Input validation** — invalid actions and targets prompt the player to re-select
- **TDD** — 6 test suites written alongside each class, covering all entities and actions
- **CI/CD** — GitHub Actions builds and runs all tests on every push; passing builds are automatically released as compiled binaries

## Project Structure

```
/src
  /entities       — Entity, Player, Enemy
  /actions        — Action (abstract), BasicAttack, HeavyAttack, Heal
  /engine         — GameEngine (game loop, turn processing, rendering)
  /levels         — Level struct, LevelLoader presets
  main.cpp
/tests
  test_entity_player.cpp
  test_entity_enemy.cpp
  test_basic_attack.cpp
  test_heavy_attack.cpp
  test_heal.cpp
  test_game_engine.cpp
```

## Getting Started

**Requirements:** g++ with C++17 support, `make` (or `mingw32-make` on Windows)

**Build and play:**
```
make game
./game.exe
```

**Run tests:**
```
make tests
```

**Clean compiled binaries:**
```
make clean
```

## Combat Rules

| Action | Effect |
|---|---|
| Basic Attack | Deals `attackPower` damage to target |
| Heavy Attack | Deals `attackPower × 2` damage, 20% chance to miss |
| Heal | Restores 20 HP to self, limited to 3 charges per game (player only) |

## Architecture

The project follows a clean separation of concerns:

- **`Entity`** — base class for all combatants, owns HP and damage logic
- **`Action`** — abstract interface for all combat actions; adding a new action requires no changes to `Entity` or `GameEngine`
- **`GameEngine`** — owns the game loop, player/enemy turns, and rendering
- **`LevelLoader`** — static factory methods that return pre-configured levels
=======
# combatsystem
Built to explore scalable game architecture and real-time combat systems

# notes
to compile and run:
- make game
- ./game.exe

to run tests:
- make tests

delete compiled files:
- make clean

# refactor
move heal charges to Entity instead of player

>>>>>>> 1d4a909d66c6887cb8ee7529cebcd3ca61e7de1c
