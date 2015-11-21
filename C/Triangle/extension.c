#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *area = "area";
char *perimeter ="perimeter";
char *help = "help";
char *angle = "angle";
char *height = "height";
char *class = "class";

//Square Root extension

double sq_root(double x) {
    double root = 1, oroot = 0;
    while(oroot!=root) {
        oroot = root;
        root = ((x/root) + root) / 2;}
    return root;
}

int main (int argc, char **argv) {
  if (argc == 1) {
  printf("this extension can calculate the area, prerimeter and height of a triangle.\n");
  printf("\n");
  printf("To calculate the prerimeter use \"./extension x y z prerimeter\"\n");
  printf("where x y z are vaild integers\n");
  printf("\n");
  printf("To calculate the area, there are two method can be used:\n");
  printf("First method is by using the base and height use \"./extension b h area\"\n");
  printf("where b is base and h is height, both has to be valid intgers.\n");
  printf("\n");
  printf("Second method is by using all 3 lenghts of the triangle.\n");
  printf("This method isn't accurate as the first method,\n");
  printf("since it uses Newton-Raphson formula for square root in order to find\n");
  printf("the area. to use this method write down \"./extension x y z area\" \n");
  printf("where x y z are valid integers.\n");
  printf("\n");
  printf("To caculate the approximation of the triangle height use\n");
  printf("\"./extension x y z height\" where x y z are valid integers.\n");
  printf("Note: this also uses Newton-Raphson formula of finding square root.\n");
  printf("therefore the caculation will not be accurate\n");
  printf("\n");
  printf("If you would explanition meaning of each class of triangle use \"./extension class\"\n");
    }

    //extension area

  else if (argc == 4 && strcmp(argv[3],area)==0) {
      int a = atoi(argv[1]);
      int b = atoi(argv[2]);
      char slength1[11] = {0};
      sprintf(slength1, "%d", a);
      char slength2[11] = {0};
      sprintf(slength2, "%d", b);
      if ( a == 0 || b == 0 ||
          strcmp(slength1,argv[1]) != 0 || strcmp(slength2,argv[2]) != 0)
      {printf("the numbers that were imported are not valid intgers or incorrect dimensions. \n");
       exit(1);}
      int aarea = (a*b)/2;
      printf("the area of the triangle is %d\n", aarea); }

  //extension perimeter

  else if (argc == 5 && strcmp(argv[4],perimeter)==0) {
      int a = atoi(argv[1]);
      int b = atoi(argv[2]);
      int c = atoi(argv[3]);
      int pperimeter;
      char slength1[11] = {0};
      sprintf(slength1, "%d", a);
      char slength2[11] = {0};
      sprintf(slength2, "%d", b);
      char slength3[11] = {0};
      sprintf(slength3, "%d", c);
      if ( a == 0 || b == 0 || c == 0 ||
          strcmp(slength1,argv[1]) != 0 || strcmp(slength2,argv[2]) != 0 || strcmp(slength3,argv[3]) != 0 ||
          a + b < c || a + c < b || b + c < a)
      {printf("the numbers that were imported are not valid intgers or incorrect dimensions. \n");
       exit(1);}
      else pperimeter = a+b+c;
      printf("the perimeter of the triangle is %d\n", pperimeter);
    }

    //extension class

    else if (argc == 2 && strcmp(argv[1],class)==0) {
      printf("Equilateral     all sides equal\n");
      printf("Isosceles       two sides equal\n");
      printf("Right           has a right angle\n");
      printf("Scalene         sides unequal, but no right angle\n");
      printf("Flat            no area\n");
      printf("Impossible      lengths don't add up\n");
      printf("Illegal         lengths are invalid\n");

    }

    //extension height

    else if (argc == 5 && strcmp(argv[4],height)==0) {
      int a = atoi(argv[1]);
      int b = atoi(argv[2]);
      int c = atoi(argv[3]);
      int s = (a+b+c)/2;
      char slength1[11] = {0};
      sprintf(slength1, "%d", a);
      char slength2[11] = {0};
      sprintf(slength2, "%d", b);
      char slength3[11] = {0};
      sprintf(slength3, "%d", c);
      if ( a == 0 || b == 0 || c == 0 ||
          strcmp(slength1,argv[1]) != 0 || strcmp(slength2,argv[2]) != 0 || strcmp(slength3,argv[3]) != 0 ||
          a + b < c || a + c < b || b + c < a)
      {printf("the numbers that were imported are not valid intgers or incorrect dimensions. \n");
       exit(1);}
      int aarea = sq_root(s*(s-a)*(s-b)*(s-c));
      int height = 2*(aarea/a);
      printf("the height is %d, if the base of the triangle is %d\n", height, a);
    }

    //extension area

    else if (argc == 5 && strcmp(argv[4],area)==0) {
      int a = atoi(argv[1]);
      int b = atoi(argv[2]);
      int c = atoi(argv[3]);
      int s;
      char slength1[11] = {0};
      sprintf(slength1, "%d", a);
      char slength2[11] = {0};
      sprintf(slength2, "%d", b);
      char slength3[11] = {0};
      sprintf(slength3, "%d", c);
      if ( a == 0 || b == 0 || c == 0 ||
          strcmp(slength1,argv[1]) != 0 || strcmp(slength2,argv[2]) != 0 || strcmp(slength3,argv[3]) != 0 ||
          a + b < c || a + c < b || b + c < a)
      {printf("the numbers that were imported are not valid intgers or incorrect dimensions. \n");
       exit(1);}
      else s = (a+b+c)/2;
      int aarea = sq_root(s*(s-a)*(s-b)*(s-c));
      printf("The area of the triangle is %d\n", aarea);
    }
    else {
        fprintf(stderr, "please reffer to ./extension for help\n");
        exit(1);
      }

}
