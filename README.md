# Bulls and Cows Game (C++)

A command-line implementation of the classic Bulls and Cows game using C++ and STL.

`Note : I made this project over night just because I was too pumped to build something, this project matters a lot to me because this got me back into software design and automation.`

## Description

The program generates a random 4-digit number with all unique digits (0–9).
The player must guess the number in as few attempts as possible.

* **Bulls** → correct digit in the correct position
* **Cows** → correct digit in the wrong position

## Features

* Fixed 4-digit secret number, as per standard Bulls and Cows rules
* Random number generation with unique digits chosen from **0–9** (including leading zeros)
* Input validation (length + digits-only + uniqueness)
* Uses C++ STL (`vector`, `set`, `string`)
* Interactive CLI gameplay with attempt counter

## Concepts Used

* STL containers (`vector`, `set`)
* Random number generation (`rand()`, `srand()`)
* Basic algorithms and iteration
* Input validation and game logic

## How to Run

### Compile
- Install GCC compiler ([Windows](https://youtu.be/k6juv3mIr9o?si=is3sMkluM_ar-bbV))

```bash
g++ main.cpp -o game
```

### Run

```bash
./game
```

## Example Gameplay

```
Give your guess
1234
There are 1 bulls and 2 cows
Give your guess
5678
There are 0 bulls and 1 cows
Give your guess
1357
There are 4 bulls and 0 cows
You have successfully guessed the number in 3 attempts
```

## Notes

* The secret number is always exactly 4 digits
* All digits are unique (no repetition allowed)
* Digits are drawn from **0 to 9** (leading zeros are supported)
* Randomness is based on `rand()`

## Possible Improvement

* Use modern C++ `<random>` for better randomness
* Add a hint system
* Track and display best score across sessions
