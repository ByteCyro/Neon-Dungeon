# NEON DUNGEON 🎮

Hey Guys Welcome to My another project-- **NEON DUNGEON 🎮**

**NEON DUNGEON** is a terminal-based adventure game written in C. Explore a dungeon, collect treasure, find the key, encounter an enemy, and reach the exit to escape.

> **Project status:** Work in progress.

## Features

* Dungeon exploration using WASD controls
* Treasure collection and gold tracking
* Key collection and a locked exit
* Turn-based combat and the option to retreat
* Player statistics showing health, gold, and keys
* Victory screen with final statistics
* Main menu and game instructions

## Controls

| Key | Action                  |
| --- | ----------------------- |
| W   | Move up                 |
| A   | Move left               |
| S   | Move down               |
| D   | Move right              |
| I   | View player statistics  |
| Q   | Return to the main menu |

During combat, choose Attack or Retreat.

## Map Legend

| Symbol | Meaning     |
| ------ | ----------- |
| `@`    | Player      |
| `#`    | Wall        |
| `.`    | Empty floor |
| `$`    | Treasure    |
| `E`    | Enemy       |
| `K`    | Key         |
| `X`    | Exit        |

Collect the key before attempting to escape through the exit.

## Starting Stats

**Player Stats**
    Health:100
    Keys:0
    Gold:0


## Gameplay Guide

Your objective is to escape the dungeon by finding the key and reaching the exit (`X`) while keeping your health above zero.

### What Happens During a Game?

**1. Start Exploring**

Choose **Start Game** from the main menu. You begin near the upper-left part of the dungeon.

**2. Explore the Dungeon**

Use WASD to move through the corridors. Walls (`#`) block your path, so you'll need to find a route through the dungeon.

**3. Collect Treasure 💰**

Walk onto a treasure tile (`$`) to collect **25 gold**. The treasure disappears after collection, so it cannot be collected twice.

**4. Find the Key 🔑**

Locate the key (`K`) and collect it. You'll need at least one key to escape through the exit.

**5. Fight or Retreat ⚔️**

Moving into the enemy tile (`E`) starts combat.

* **Attack:** Deal 20 damage to the enemy.
* **Enemy retaliation:** If the enemy survives your attack, it deals 10 damage to you.
* **Retreat:** Leave the encounter without moving into the enemy's tile.
* **Game Over:** If your health reaches zero, the game ends.

Defeated enemies can be passed through.

**6. Escape the Dungeon 🚪**

The exit is marked `X`. Without a key, the exit remains locked. Once you have a key, reach the exit to complete the game and see your final statistics.

**7. Check Your Status 📊**

Press `I` during exploration to view your health, gold, and keys. Press `Q` to return to the main menu.

### Your Mission

Collect treasure, find the key, manage your health, deal with the enemy, and escape successfully!


## Build and Run

**Requirements:** A C compiler supporting C99, such as GCC.

Compile the game:

```bash
gcc -std=c99 -Wall -Wextra -pedantic neon_dungeon.c -o neon_dungeon
```

Run on Linux or macOS:

```bash
./neon_dungeon
```

On Windows with GCC/MinGW:

```bash
neon_dungeon.exe
```

## Concepts Practised

* Structures (`struct`)
* Two-dimensional arrays
* Functions
* Loops and `switch` statements
* Conditional logic
* Game-state management
* Functions for movement, statistics, and combat

## Planned Improvements

* Improved input validation
* Further combat and retreat testing
* Cleaner new-game initialization
* Additional rooms and enemies
* More collectibles and gameplay improvements

## Author
Arnav Verma aka CyroByte(ByteCyro)
Created as a learning project while practising C programming.
