This extension allows you to calculate the angles in triangles, also calculates
the height, the perimeter of a triangle and can write pascal triangle. this document will explain how to
use the functions that this program supports.

1. "betweenAB a b c" where a b c are valid integers. this function will calculate
the angle between a b. the cosine rule of triangle was used (acos(((a*a)+(c*c)-(b*b))/(2*a*c)))
then multiplied by (180/pi) to convert the answer into degrees.

2. "betweenBC a b c" where a b c are valid integers. this function will calculate
the angle between b c. the cosine rule of triangle was used (acos(((a*a)+(c*c)-(b*b))/(2*a*c)))
then multiplied by (180/pi) to convert the answer into degrees.

3. "betweenAC a b c" where a b c are valid integers. this function will calculate
the angle between a c. the cosine rule of triangle was used (acos(((a*a)+(c*c)-(b*b))/(2*a*c)))
then multiplied by (180/pi) to convert the answer into degrees.

4. "perimeter a b c" where a b c are valid integers. this function will calculate
the perimeter of triangle a, b, and c. basic formula was used which is (a+b+c).

5. "height a b c" where a b c are valid integers, and a is the base. this function
will calculate the height of the triangle. heron's formula was used in this function
to get the area of triangle then the answer was retreived by using this formula
2*(area/base).

6. "drawpascal n" where n is a valid Integer. this will write down the pascal triangle
up to 'n'th row. I would recommend to start with "drawpascal 10" having high n value
for example 50 might look ugly in the terminal, this all depends on the window
size of the terminal and your screen resolution. drawpascal function took me ages
to make I still don't believe that it is working. how it works: there is a function
called pascal was used in this function, where it create a list of numbers of
pascal triangle, and then later it will be 'prettified' within drawpascal function.

7. "pascallist n" where n is a valid integer. technically is the same as drawpascal
function, except it just prints of list of pascal triangle numbers. concept is the
same where it takes n of pascal function.
