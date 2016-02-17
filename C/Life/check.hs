-- Test a colony which has been output from a game-of-life program.
import System.Environment
import System.IO
import System.Exit
import Control.Exception

-- Get the colony number from the command line, then check to see if
-- the input colony matches the expected one.
main :: IO ()
main = do [input] <- getArgs
          let n = read input
          file <- getContents
          let colony = lines file
          let message =
                if colony == (colonies !! n)
                  then "OK"
                  else "actual colony read in:\n" ++
                       unlines colony ++
                       "colony expected:\n" ++
                       unlines (colonies !! n)
          putStrLn message
       `onException` crash

-- Print an error message if the program is misused
crash :: IO ()
crash = do
  hPutStrLn stderr (
    "Use: ./check i\n\
    \where i is a number from 0 to " ++ show (length colonies - 1))
  exitFailure


-- Define the colonies as a list.  Each colony is a list of strings. 
colonies :: [[String]]
colonies =
  [ [ "....."
    , "..#.."
    , "..#.."
    , "..#.."
    , "....." ]
  , [ "....."
    , "....."
    , ".###."
    , "....."
    , "....." ]
  , [ "...."
    , ".##."
    , ".##."
    , "...." ]
  , [ "......"
    , "......"
    , ".#.#.."
    , "..##.."
    , "..#..."
    , "......" ]
  , [ "......"
    , "......"
    , "...#.."
    , ".#.#.."
    , "..##.."
    , "......" ]
  , [ "......"
    , "......"
    , "..#..."
    , "...##."
    , "..##.."
    , "......" ]
  , [ "......"
    , "......"
    , "...#.."
    , "....#."
    , "..###."
    , "......" ] ]
