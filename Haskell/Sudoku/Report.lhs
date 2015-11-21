I have also included x_sudoku.lhs which is part of my extension.

Commands:
getDiagonal xs -- Gets the diagonal of list of lists.
sudoku x -- shows the X-Sudoku puzzle that is saved.
solve (sudoku x) -- solves the X-Sudoku puzzle that is saved.

-------------------------------------------------------------------------------
This report is about creating a program that solves X-Sudoku.

Firstly, X-Sudoku is a variant of Sudoku with additional rule where the main
diagonals should have a unique number that is from 1 to 9. Hence, it is called
X-Sudoku since when but diagonals intersect it will look like letter X.

The concept of this program is pretty simple. I have written a function called
getDiagonal, where it take [[a]] and returns [a] which is a list that contains
the diagonal elements of [[a]]. Therefore, I was able to write function that
defines the diagonals, which are very similar to rows,cols, and boxs functions.
The first diagonal called diagonalrown (right + down) gets the diagonal of the
rows, whereas the second diagonal called diagonallown (left + down) get the
diagonal of reverse of the rows.

Now that both diagonals are defined, the only thing left is to check their
validity, where in valid function I have included 2 extra line of codes,
which are:

>             && all (unique . filter lone) (diagonalrown puzzle)
>             && all (unique . filter lone) (diagonallown puzzle)

To test this to work I have included a puzzle I have found on
http://www.sudoku-space.com/x-sudoku/ . To print out the actual puzzle use
command "sudoku x", and to solve it use command "solve (sudoku x)". On my
computer, which has Sandybridge-E i7 processor it took about 2 minutes to solve
it. I believe is due the fact we are using lists instead of matrix, also using
getDiagonal function might be the cause as well.

During making this program, I have thought of an idea of creating X^9-Sudoku,
where is the diagonals of each box has to be unique. I could have implemented a
solver easily. However, what's the point of creating a program that solves a
problem that doesn't exist?. Perhaps, I need learn to make a Sudoku puzzle
generator, in order to make X^9-Sudoku puzzle, which it can be used in the
solver.
