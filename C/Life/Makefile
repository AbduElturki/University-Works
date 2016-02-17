default: c

c: check.c colony.c life.c
	gcc -std=c99 check.c -o check
	gcc -std=c99 colony.c -o colony
	gcc -std=c99 life.c -o life

haskell: check.hs colony.hs life.hs
	ghc check.hs
	ghc colony.hs
	ghc life.hs

test:
	./colony 0 | ./life | ./check 0
	./colony 1 | ./life | ./check 1

clean:
	rm -f *.hi *.o
	rm check colony life
