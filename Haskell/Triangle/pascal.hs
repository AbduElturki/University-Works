import Text.Printf

pascal :: [[Integer]]
pascal = iterate (\prev -> 1 : zipWith (+) prev (tail prev) ++ [1]) [1]

drawpascal :: Int -> IO ()
drawpascal n = mapM_ (\r -> printf "%*s\n" (div (long + length r) 2) r) row
    where row = map (unwords . map show) $ take (n + 1) pascal
          long = length $ last row
