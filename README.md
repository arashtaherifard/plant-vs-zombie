# Zombie vs. Plants

A graphical C++ game inspired by *Plants vs. Zombies*, developed as a project for the **Advanced Programming** course at the **University of Tehran**.

The project was implemented with **C++17** and **SFML** and served as a larger object-oriented programming exercise following the earlier assignments in the course.

## Features

The implementation includes:

- graphical game rendering with SFML;
- plant placement and management;
- pea-shooter and snow-shooter mechanics;
- sunflower-based resource generation;
- projectile handling;
- standard zombie enemies;
- giant zombie enemies;
- zombie movement and animation;
- plant/zombie collision handling;
- sun collection;
- game-state management;
- start/game-over presentation;
- audio support.

## Project Structure

- `src/` — C++ implementation
- `include/` — class declarations and interfaces
- `spriters/` — graphical/audio resources used by the historical project
- `Makefile` — build configuration

The source is organized around classes for the game state, player, plants, zombies, projectiles, resources, and UI/gameplay handlers.

## Build Requirements

The project requires:

- a C++17-compatible compiler;
- SFML graphics;
- SFML window;
- SFML system;
- SFML audio.

On macOS, SFML can be installed using Homebrew.

Build the project with:

    make

Then run:

    ./pvz.out

Clean generated build files with:

    make clean

## Technologies and Concepts

- C++17
- SFML
- object-oriented programming
- inheritance and class-based design
- real-time event handling
- sprite rendering
- animation
- collision/game-state logic
- resource management
- Make-based compilation

## Coursework Context

This project was developed during the Advanced Programming course at the University of Tehran.

The repository preserves the original development history. Later portfolio-oriented changes are limited mainly to documentation, repository hygiene, build portability, and preservation of the final local gameplay edits.

## Assets

This repository contains graphical, font, and audio assets used for the historical educational project.

These assets are not presented as original artwork owned by the repository author. Rights to third-party game imagery, fonts, audio, names, and related materials remain with their respective owners.

The programming implementation represented in `src/` and `include/` is the primary focus of this portfolio repository.
