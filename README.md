# Bulls and Cows Game (C++)

A command-line implementation of the classic Bulls and Cows game using C++ and STL.

##  Description

The program generates a random number with unique digits.
The player must guess the number within multiple attempts.

* **Bulls** → correct digit in the correct position
* **Cows** → correct digit in the wrong position

##  Features

* Random number generation with unique digits
* Digits are chosen from **0–9** (including leading zeros)
* Input validation (length + uniqueness)
* Uses C++ STL (`vector`, `set`)
* Interactive CLI gameplay

##  Concepts Used

* STL containers (`vector`, `set`)
* Random number generation (`rand()`, `srand()`)
* Basic algorithms and iteration
* Input validation and game logic

##  How to Run

### Compile
- Install GCC compiler ([Windows](https://youtu.be/k6juv3mIr9o?si=is3sMkluM_ar-bbV))

```bash
g++ main.cpp -o game
```

### Run

```bash
./game
```

##  Example Gameplay

```
Choose the number of digits (1-9): 4
Give your guess:
1234
There are 1 bulls and 2 cows
```

##  Notes

* Digits are unique (no repetition allowed)
* Computer-generated digits are from **0 to 9** (all digits supported, including leading zeros)
* Randomness is based on `rand()`

##  Possible Improvement

* Support digits from 0–9 (including leading zeros) ✅
* Use modern C++ `<random>` for better randomness
* Refactor cow calculation to iterate over `choiceVector` directly instead of using `set` size as loop bound ✅
* Add attempt counter / scoring system ✅
* Refactor to use strings instead of integers



