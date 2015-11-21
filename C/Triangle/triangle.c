/* Classify a triangle according to the integer lengths of its sides. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Classify a triangle, given side lengths as strings:
// Not fully implemented yet
char *triangle(char *length1, char *length2, char *length3) {
char *letter;

 int IntL1 = atoi(length1);
 int IntL2 = atoi(length2);
 int IntL3 = atoi(length3);
 long SIntL1;
 long SIntL2;
 long SIntL3;

char slength1[11] = {0};
sprintf(slength1, "%d", IntL1);
char slength2[11] = {0};
sprintf(slength2, "%d", IntL2);
char slength3[11] = {0};
sprintf(slength3, "%d", IntL3);

SIntL1 = strtol (length1, &letter, 10);
SIntL2 = strtol (length2, &letter, 10);
SIntL3 = strtol (length3, &letter, 10);


//Checks if Triangle is Illegal
if ((letter == length1) ||
    (letter == length2) ||
    (letter == length3) || (*letter != '\0')
    || IntL1 <= 0 || IntL2 <= 0 || IntL3 <= 0
    || IntL1 > 2147483647 || IntL2 > 2147483647 || IntL3 > 2147483647
    || strcmp(slength1,length1) != 0 || strcmp(slength2,length2) != 0
    || strcmp(slength3,length3) != 0 )

{return "Illegal";}

//Checks if Triangle is Equilateral
else if (length1 == length2 && length1 == length3 && IntL1 > 0)
    {return "Equilateral";}

//Checks if Triangle is Isosceles
else  if (length1 == length2 || length1 == length3 || length2  == length3)
    {return "Isosceles";}

//Checks if Triangle has a Right angle
else if (((long)(IntL1 * IntL1) + (long)(IntL2 * IntL2) == (long)(IntL3 * IntL3)) ||
         ((long)(IntL3 * IntL3) + (long)(IntL2 * IntL2) == (long)(IntL1 * IntL1)) ||
         ((long)(IntL1 * IntL1) + (long)(IntL3 * IntL3) == (long)(IntL2 * IntL2)))
   {return "Right";}

//Checks if Triangle is Flat
else if (IntL1 + IntL2 == IntL3 ||
         IntL3 + IntL2 == IntL1 ||
         IntL1 + IntL3 == IntL2)
{return "Flat";}

//Checks if it is Impossible
else if ((long)IntL1 + (long)IntL2 < (long)IntL3 ||
         (long)IntL2 + (long)IntL3 < (long)IntL1 ||
         (long)IntL1 + (long)IntL3 < (long)IntL2)
{return "Impossible";}

//Checks if it is Scalene
else if (IntL1 != IntL2 && IntL1 != IntL3 && IntL2 != IntL3)
        {return  "Scalene";}

    return 0;}

// Check that two strings are equal
void eq(char *actual, char *expected) {
    if (strcmp(actual, expected) != 0) {
        fprintf(stderr, "Test failure, actual: %s\n", actual);
        fprintf(stderr, "Expected: %s\n", expected);
        exit(1);
    }
}

// Run tests on the triangle function.
void test() {
    int mark = 0;
    eq(triangle("8", "8", "8"), "Equilateral"); mark++;
    eq(triangle("1073", "1073", "1073"), "Equilateral"); mark++;
    eq(triangle("15", "15", "13"), "Isosceles"); mark++;
    eq(triangle("15", "13", "15"), "Isosceles"); mark++;
    eq(triangle("13", "15", "15"), "Isosceles"); mark++;
    eq(triangle("25", "25", "27"), "Isosceles"); mark++;
    eq(triangle("25", "27", "25"), "Isosceles"); mark++;
    eq(triangle("27", "25", "25"), "Isosceles"); mark++;
    eq(triangle("3", "4", "5"), "Right"); mark++;
    eq(triangle("5", "12", "13"), "Right"); mark++;
    eq(triangle("5", "13", "12"), "Right"); mark++;
    eq(triangle("12", "5", "13"), "Right"); mark++;
    eq(triangle("12", "13", "5"), "Right"); mark++;
    eq(triangle("13", "5", "12"), "Right"); mark++;
    eq(triangle("13", "12", "5"), "Right"); mark++;
    eq(triangle("12", "14", "15"), "Scalene"); mark++;
    eq(triangle("12", "15", "14"), "Scalene"); mark++;
    eq(triangle("14", "12", "15"), "Scalene"); mark++;
    eq(triangle("14", "15", "12"), "Scalene"); mark++;
    eq(triangle("15", "12", "14"), "Scalene"); mark++;
    eq(triangle("15", "14", "12"), "Scalene"); mark++;
    eq(triangle("7", "9", "16"), "Flat"); mark++;
    eq(triangle("7", "16", "9"), "Flat"); mark++;
    eq(triangle("9", "16", "7"), "Flat"); mark++;
    eq(triangle("16", "7", "9"), "Flat"); mark++;
    eq(triangle("16", "9", "7"), "Flat"); mark++;
    eq(triangle("2", "3", "13"), "Impossible"); mark++;
    eq(triangle("2", "13", "3"), "Impossible"); mark++;
    eq(triangle("13", "2", "3"), "Impossible"); mark++;
    eq(triangle("0", "0", "0"), "Illegal"); mark++;
    eq(triangle("0", "10", "12"), "Illegal"); mark++;
    eq(triangle("10", "0", "12"), "Illegal"); mark++;
    eq(triangle("10", "12", "0"), "Illegal"); mark++;
    eq(triangle("-1", "-1", "-1"), "Illegal"); mark++;
    eq(triangle("-1", "10", "12"), "Illegal"); mark++;
    eq(triangle("10", "-1", "12"), "Illegal"); mark++;
    eq(triangle("10", "12", "-1"), "Illegal"); mark++;
    eq(triangle("x", "y", "z"), "Illegal"); mark++;
    eq(triangle("10", "12", "13.4"), "Illegal"); mark++;
    eq(triangle("03", "4", "5"), "Illegal"); mark++;
    eq(triangle("3", "04", "5"), "Illegal"); mark++;
    eq(triangle("3", "4", "05"), "Illegal"); mark++;
    eq(triangle("3x", "4y", "5z"), "Illegal"); mark++;
    eq(triangle("2147483648","2147483647","2147483647"),"Illegal"); mark++;
    eq(triangle("2147483647","2147483648","2147483647"),"Illegal"); mark++;
    eq(triangle("2147483647","2147483647","2147483648"),"Illegal"); mark++;
    eq(triangle("2147483647","2147483647","2147483647"),"Equilateral"); mark++;
    eq(triangle("1100000000","1705032704","1805032704"),"Scalene"); mark++;
    eq(triangle("2000000001","2000000002","2000000003"),"Scalene"); mark++;
    eq(triangle("150000002","666666671","683333338"),"Scalene"); mark++;
    printf("Tests passed: %d\n", mark);
}

// Run the program or, if there are no arguments, test it.
int main(int argc, char **argv) {
    if (argc == 1) {
        test();
    }

    else if (argc == 4) {
        char *result = triangle(argv[1], argv[2], argv[3]);
        printf("%s\n", result);
    }

    else {
        fprintf(stderr, "Use e.g.: ./triangle 3 4 5\n");
        exit(1);
    }
}
