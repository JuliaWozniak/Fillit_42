# Fillit_42
My second project at Unit Factory. 

# Description
This is a program that takes as an input a file with tetraminos (tetris figures) and assembles them into the smallest possible square.
In choosing the answer it takes into account that
- the position of figures should (if possible) correspond to their order of appearance (e.g. first figure is in the upper left corner and so on).
- to this end, figures are represented by letters which indicate their order of appearance.
- the program can't rotate a tetramino to fit it into free space.

# Input
The input text file should contain from 1 to 26 valid tetraminos. A valid tetramino is represented like this

#...
#...
#...
#...

It should be composed of exactly 4 '#' and each of this '#' should touch at least one another '#'.
Two different tetraminos should be separated by exactly 1 empty line.
If input file is invalid for at least one of the abovementioned reasons the program should show "error" message and stop.

# Output
After finding the answer, program prints it like

AAB.
AAB.
..B.
..B.

which is an answer to the input file

..AA
..AA
....
....

.B..
.B..
.B..
.B..
