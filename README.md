# City Skyline Solver
This project was developed as the Rush_01 project for the Piscine at 42 Barcelona. The exercise is a solver for the city skyline game. The specific solver created follows a specific input, that is checked against wrong inputs. More information in the code explaination. 

## :video_game: The game

The game is a common "Rompicapo" where the goal is to fill a N x N square with te height of each building knowing:
* Every building in the same row or column has a different height; Otherwise, there is no building as high as any other on the same line or column; 
* For each position on the side of the squares, it is given the amount of skyscrapeers visible from that specific location. 

### Variants known

* Easier version:
  * The visibility is also given for the diagonal;

* More complicated variants:
  * Part of the information about the amount of visible skyscrapeers is omitted.
  * The size of the square can be increased. Up to 6x6 is commonly found in enigmistics journals.

## The solving algorithm

This problem is solved via a simple backtracking algorithm that checks for all the possibilities. The current version checks for the first possible solution and prints it to screen. Note: This means it is not returned, nor it checks for additional possible solutions.

### Data input and sanitization

We are building a program, which means it works as a stand alone. The initial main allows 1 single input as a string of single digits spaced with a common space ' ' (ASCII code = 32). Other type of spaces are not allowed. The numbers must correspond to the values to be used as visibility in the following order:

1. Top side;
2. Bottom side;
3. Left side;
4. Right side;

**Note**: There must be no space at the end of the string passed as argument;

The input is checked for:

* The string is a series of single digits and spaces;
* Each entry is assigned to the board and trnslated into a **int** for easier calculations;
Few more mathematical checks are done in order to return a "No solution" message before the solution is even attempted;
* Each line with visibilities is checked to be $2*(N - 1)$ < SUM(Values)< $N*(N+1)/2$:
  * Even with all visibilities as 1, the minimum must be N. The actual minimum is as if all the values are equal to 2 except a single 1 (for the heighest building in the row).
  * The maximum is given by all the buildings being ordered so that each building in front of the maximum height one are visible. This is possible only with a visibility that goes from 1 to N with no repetition. The sum is given by the famous Gauss formula N(N+1)/2.

## Possible future updates:
* Allow for empty visibility;
* Allow dimensions bigger than 9 x 9;
