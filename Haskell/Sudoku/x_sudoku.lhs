

Preamble
========

The following lines define this module and import some useful
functions and definitions.


> module Sudoku where
> import System.Environment
> import Data.List



Here we define the type called `Sudoku`, and the synonym `Cell`.

> type Cell = [Char]
> data Sudoku = Sudoku [Cell]


> bundle :: Int -> [a] -> [[a]]
> bundle _ [] = []
> bundle n xs = (take n xs) : (bundle n (drop n xs))

> getDiagonal :: [[a]] -> [a]
> getDiagonal []     = []
> getDiagonal (x:xs) = head x : getDiagonal (map tail xs)

> stuck :: Sudoku -> Bool
> stuck (Sudoku cells) = any null cells

> fixed :: Sudoku -> Bool
> fixed (Sudoku cells) = all lone cells

> rows :: Sudoku -> [[Cell]]
> rows (Sudoku cells) = bundle 9 (cells)

> cols :: Sudoku -> [[Cell]]
> cols (Sudoku cells) = transpose (rows (Sudoku cells))

> boxs :: Sudoku -> [[Cell]]
> boxs (Sudoku cells) = ((boxbundle . map transpose) . boxrow) (rows (Sudoku cells))
>                         where
>                             boxrow   = split . map split
>                             split  = bundle 3
>                             boxbundle = (map concat) . concat

> diagonalrown :: Sudoku -> [[Cell]]
> diagonalrown (Sudoku cells) = bundle 9 (getDiagonal (bundle 9 (cells)))

> diagonallown :: Sudoku -> [[Cell]]
> diagonallown (Sudoku cells) = bundle 9 (getDiagonal(map reverse (bundle 9 (cells))))

Puzzles
=======

> broken :: String
> broken = (concat . concat . replicate 3)
>   [ concat (replicate 3 ['1' .. '3'])
>   , concat (replicate 3 ['4' .. '6'])
>   , concat (replicate 3 ['7' .. '9']) ]

> solved :: String
> solved = concat
>     [ simpleRow 1
>     , simpleRow 4
>     , simpleRow 7
>     , simpleRow 2
>     , simpleRow 5
>     , simpleRow 8
>     , simpleRow 3
>     , simpleRow 6
>     , simpleRow 9 ]
>   where
>     simpleRow n = take 9 (drop (n-1) (cycle ['1' .. '9']))


> x :: String
> x = "35 2 8   2 1     9   5   8   6  2      4     51 9  2       5  3     6   67  291  "

Appendix
========

> lone :: [a] -> Bool
> lone [x] = True
> lone xs  = False

> solve :: Sudoku -> [Sudoku]
> solve puzzle
>   | stuck puzzle       = []
>   | not (valid puzzle) = []
>   | fixed puzzle       = [puzzle]
>   | otherwise          = [puzzle'' | puzzle'  <- expand puzzle
>                                    , puzzle'' <- solve  puzzle']

> unique :: Eq a => [a] -> Bool
> unique xs = nub xs == xs

> valid :: Sudoku -> Bool
> valid puzzle = all (unique . filter lone) (rows puzzle)
>             && all (unique . filter lone) (cols puzzle)
>             && all (unique . filter lone) (boxs puzzle)
>             && all (unique . filter lone) (diagonalrown puzzle)
>             && all (unique . filter lone) (diagonallown puzzle)

> expand :: Sudoku -> [Sudoku]
> expand (Sudoku cells) = [ Sudoku (ls ++ [choice] : rs) | choice <- choices ]
>   where
>     (ls, choices:rs) = break (not . lone) cells

> main :: IO ()
> main = do
>   args <- getArgs
>   puzzle <- case args of
>                  [fileName] -> readFile fileName
>                  []         -> return x
>   print (solve (sudoku puzzle))

> sudoku :: String -> Sudoku
> sudoku xs
>   | length ys == 81 = Sudoku (map convert ys)
>   | otherwise       = error ("Invalid sudoku puzzle: " ++ show xs)
>   where convert x = if blank x then ['1'..'9'] else [x]
>         newline c = c == '\n'  || c == '\r'
>         blank c = c == ' ' || c == '.'
>         ys = filter (not . newline) xs

> instance Show Sudoku where
>   show (Sudoku xs) = "\n" ++
>       top ++
>       intercalate mid
>         [intercalate sep
>           [row (xss !! ((j*3) + i)) | i <- [0 .. 2] ] | j <- [0 .. 2]] ++
>       bot
>     where
>      row :: [String] -> String
>      top    = '╔' : intercalate "╦" (replicate 3 (intercalate "╤" (replicate 3 "═══"))) ++ "╗\n"
>      row rs = '║' : intercalate "║" (map (intercalate "│") (bundle 3 rs)) ++ "║\n"
>      mid    = '╠' : intercalate "╬" (replicate 3 (intercalate "╪" (replicate 3 "═══"))) ++ "╣\n"
>      sep    = '╟' : intercalate "╫" (replicate 3 (intercalate "┼" (replicate 3 "───"))) ++ "╢\n"
>      bot    = '╚' : intercalate "╩" (replicate 3 (intercalate "╧" (replicate 3 "═══"))) ++ "╝\n"
>      xss = bundle 9 ys
>      ys  = map summary xs
>      summary [x] = " " ++ [x] ++ " "
>      summary _   = "   "
