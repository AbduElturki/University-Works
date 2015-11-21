Preamble
========

The following lines define this module and make sure that your
definitions won't conflict with those from the `Prelude`.

> module Fold where
> import Prelude hiding (sum, product, length, and, or, all, some, filter)

Tasks
=====

The tasks for you to complete are below:

> -- TODO #F1
> sum :: Num a => [a] -> a
> sum [] = 0
> sum xs = foldr (+) 0 xs

> -- TODO #F2
> product :: Num a => [a] -> a
> product [] = 0
> product xs = foldr (*) 1 xs

> -- TODO #F3
> and :: [Bool] -> Bool
> and [] = False
> and xs = foldr (&&) True xs

> -- TODO #F4
> or :: [Bool] -> Bool
> or [] = False
> or xs = foldr (||) False xs

> -- TODO #F5
> all :: (a -> Bool) -> [a] -> Bool
> all p [] = False
> all p xs =  foldr (&&) True (map p xs)

> -- TODO #F6
> some :: (a -> Bool) -> [a] -> Bool
> some p [] = False
> some p xs = foldr (||) False (map p xs)

> -- TODO #F7
> length :: [a] -> Int
> length [] = 0
> length xs = foldr (\_ n -> 1 + n) 0 xs

> -- TODO #F8
> filter :: (a -> Bool) -> [a] -> [a]
> filter p [] = []
> filter p xs = foldr (\x xs -> if p x then x : xs else xs) [] xs

> -- TODO #F9
> group :: Eq a => [a] -> [[a]]
> group = foldr f []
>    where
>        f a [] = [[a]]
>        f a list@((x:xs):ys) | x == a = (a:x:xs):ys
>                             | otherwise = [a]:list

> -- TODO #F10
> transpose :: [[a]] -> [[a]]
> transpose xs = foldr (zipWith (:)) (repeat []) xs


> -- TODO #F11
> permute :: [a] -> [[a]]
> permute = foldr (concatMap . insert) [[]]
>   where insert x []     = [[x]]
>         insert x (y:ys) = (x:y:ys):[ y:result | result <- insert x ys]
