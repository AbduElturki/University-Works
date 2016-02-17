-- Generate a colony to use as test input to a game-of-life program.
import System.Environment
import System.IO
import System.Exit
import Control.Exception

-- Given a sequence number n on the command line, print n'th colony.
main :: IO ()
main = do [input] <- getArgs
          let n = read input
          putStr (unlines (colonies !! n))
       `onException` crash

-- Print an error message if the program is misused
crash :: IO ()
crash = do
  hPutStrLn stderr (
    "Use: ./colony i\n\
    \where i is a number from 0 to " ++ show (length colonies - 1))
  exitFailure

-- Define the colonies as a list.  Each colony is a list of strings. 
colonies :: [[String]]
colonies =
  [ [ "....."
    , "....."
    , ".###."
    , "....."
    , "....." ]
  , [ "....."
    , "..#.."
    , "..#.."
    , "..#.."
    , "....." ]
  , [ "...."
    , ".##."
    , ".##."
    , "...." ]
  , [ "......"
    , "..#..."
    , "...#.."
    , ".###.."
    , "......"
    , "......" ]
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
    , "......" ] ]
