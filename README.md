# Sudoku

### General Information

This is an implementation of the puzzle game [sudoku](https://en.wikipedia.org/wiki/Sudoku) written in C++. It is a one-player game where the player attempts to fill in each square inside of a 9 by 9 grid with a single digit number (1-9). There cannot be any duplicate digits in any row or column. The main grid is broken up into 3 by 3 grids, additionally which cannot contain duplicate digits. Example incomplete and complete boards are shown below.

Incomplete board

![Incomplete Board](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/Sudoku_Puzzle_by_L2G-20050714_standardized_layout.svg/500px-Sudoku_Puzzle_by_L2G-20050714_standardized_layout.svg.png)

Solution to board above

![Complete Board](https://upload.wikimedia.org/wikipedia/commons/thumb/1/12/Sudoku_Puzzle_by_L2G-20050714_solution_standardized_layout.svg/500px-Sudoku_Puzzle_by_L2G-20050714_solution_standardized_layout.svg.png)

### Features

### Compilation and Execution

Uses the make program to compile and generate executable binary. Simply execute the command `make` to compile all resources. Run the executable `sudoku` by running the command `./sudoku`.

### Checklist

- [ ] Generate random boards
- [ ] Validate if random board is valid
- [ ] Generate solution to an arbitrary board in O(9<sup>(n<sup>2</sup>)</sup>), where n is size of the set of single positive integers.
- [ ] Save progress to sqlite database to allow players to save progress

