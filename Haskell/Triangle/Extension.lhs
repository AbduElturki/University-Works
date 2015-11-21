
> import Text.Printf

> pascal :: [[Integer]]
> pascal = iterate (\prev -> 1 : zipWith (+) prev (tail prev) ++ [1]) [1]

> drawpascal :: Int -> IO ()
> drawpascal n = mapM_ (\r -> printf "%*s\n" (div (long + length r) 2) r) row
>     where row = map (unwords . map show) $ take (n + 1) pascal
>           long = length $ last row

< acos :: Float -> a -> a

> betweenAB :: Integer->Integer->Integer-> Float
> betweenAB ia ib ic = acos(((a*a)+(b*b)-(c*c))/(2*a*b)) * (180/pi)
>   where (a, b, c) = (fromInteger ia, fromInteger ib, fromInteger ic)

> betweenBC :: Integer->Integer->Integer-> Float
> betweenBC ia ib ic = acos(((b*b)+(c*c)-(a*a))/(2*b*c)) * (180/pi)
>   where (a, b, c) = (fromInteger ia, fromInteger ib, fromInteger ic)

> betweenAC :: Integer->Integer->Integer-> Float
> betweenAC ia ib ic = acos(((a*a)+(c*c)-(b*b))/(2*a*c)) * (180/pi)
>   where (a, b, c) = (fromInteger ia, fromInteger ib, fromInteger ic)

> perimeter :: Integer->Integer->Integer->Integer
> perimeter ia ib ic = a+b+c
>  where (a, b, c) = (fromInteger ia, fromInteger ib, fromInteger ic)

> height :: Integer->Integer->Integer-> Float
> height ia ib ic = (area/a)*2
>   where (a, b, c) = (fromInteger ia, fromInteger ib, fromInteger ic)
>         area = sqrt(s * (s - a)*(s - b)*(s - c))
>         s = (a + b + c) / 2
