--------------------------------------------------------------------------------
--  Halve list into two lists --------------------------------------------------
--------------------------------------------------------------------------------


-- type
halve :: [a] -> ([a], [a])

-- main def
halve xs = splitAt (length xs `div` 2) xs


--------------------------------------------------------------------------------
--  Merge two sorted lists  ----------------------------------------------------
--------------------------------------------------------------------------------


-- type
merge :: Ord a => [a] -> [a] -> [a]

-- boundary cases
merge xs [] = xs
merge [] ys = ys

-- main def
merge (x:xs) (y:ys)
    | y < x         = y : merge (x:xs) ys
    | otherwise     = x : merge xs (y:ys)


--------------------------------------------------------------------------------
--  Merge-Sort  ----------------------------------------------------------------
--------------------------------------------------------------------------------


-- type
msort :: Ord a => [a] -> [a]

-- boundary cases
msort []  = []
msort [x] = [x]

-- main def
msort xs = merge (msort ys) (msort zs)
    where (ys, zs) = halve xs


--------------------------------------------------------------------------------
--  main  ----------------------------------------------------------------------
--------------------------------------------------------------------------------

string2int :: String -> Integer
string2int s = read s :: Integer

main = do
    s <- readFile "IntegerArray_example.txt"
    let a = map string2int (lines s)
    print a
    print $ msort a











