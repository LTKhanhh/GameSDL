# Welcome to Flappy Bird 
## Table contents 
1. [Introduction](#introduction)
2. [Features](#features)
3. [How to play](#play)
4. [Installation](#installation)
## Introduction <a name="introduction"></a>
* The game is inspired by [Flappy Bird](https://wikipedia.org/wiki/Flappy_Bird) - the famous Vietnamese game developed by Nguyen Ha Dong in 2013.
* Flappy Bird was created using [SDL2](https://www.libsdl.org/download-2.0.php) and C++.
## Features <a name="features"></a>
**1. GameWindow**
* Handles collisions between birds and pipes,birds and the ground.
* Handles the player's key/mouse actions.
* Display score.
* The ground, moving birds make the game more realistic.
* Limit FPS to be compatible with all devices (if not, when running the game on a high-configuration machine, the image will be rendered too fast, causing the "fast forward" effect).

**2. Menu**
* Display 2 option (Play/Exit).
* Handles the player's mouse actions.

**3. Gameover screen**
* Display "Game over" and score.
* Display 2 option (Play again/Exit).
* Handles the player's mouse actions.
## How to play <a name="play"></a>
* Press SPACE/UP key to play.
* Press ESC to pause.
* Press ESC again to resume.
## Installation <a name="installation"></a>
After installing SDL2, SDL_Image, SDL_TTF, và SDL_Mixer, run Game.exe to enter the game.
