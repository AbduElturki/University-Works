#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "display.h"

int getopcod(unsigned char b) {
  return (b>> 6) & 0x03;
}

int getoperand(unsigned char b) {
  return b&0x3F;
}

struct state {
  int x,y,sx,sy, pause;
  bool p;
};



void moveX (display *d, struct state *a, int operand) {
  if (operand >= 32) {operand = operand - 64;}
  a->x = operand + a->x;
  //if (a->x >= 32) {a->x = a->x - 32;}
}

void moveY (display *d, struct state *a, int operand) {
  if (operand >= 32) {operand = operand - 64;}
  a->y += operand;
//  if (a->y >= 64) {a->y = a->y - 64;}
}




// TODO: upgrade this function to read instructions from the file and obey them
void interpret(FILE *in, display *d) {
  struct state a = {0,0,0,0,0,false};
  unsigned char b = fgetc(in);
  while (!feof(in)) {
    int operand = getoperand(b);
    int opcod = getopcod(b);
  //  printf("%d  %02x\n",opcod, operand);


    //operands and opcod
    if (opcod == 0) {moveX(d,&a,operand);}


    else if (opcod == 1) {moveY(d,&a,operand);}


    else if (opcod == 2) {

      if (a.p == true && (a.x != a.sx || a.y != a.sy)){
        line(d,a.sx,a.sy,a.x,a.y);
        }

      pause(d, operand);
      a.sx = a.x;
      a.sy = a.y;


  }

    else if (opcod == 3) {
      if ((operand >> 5)==1){
        opcod = operand & 0x1F;
      //  printf("The opcod is %d\n",opcod);
        operand = fgetc(in);
      //  printf("The operand is %d\n", operand);
        if (((operand >> 7) & 0x01) ==1) {
          int signed nextbyte = fgetc(in);
          if (nextbyte == 0) {operand -= 1;}
          else {
          operand = nextbyte & 0x7F;
            printf("%d\n", operand);
        }

        }

      printf("The opcod is %d\n",opcod);
      printf("The operand is %d\n", operand);

        if (opcod == 2) {

          if (a.x == a.sx && a.y == a.sy) {pause(d, operand);}

          if (a.p == true){
            line(d,a.sx,a.sy,a.x,a.y);
            }

          pause(d, operand);
          a.sx = a.x;
          a.sy = a.y;
      }
    }

      else {
    if (operand == 4) {clear(d);}
    else if (operand == 5) {key(d);}
    else {
     if (a.p == true){
      line(d,a.sx,a.sy,a.x,a.y);
    }
      a.sx = a.x;
      a.sy = a.y;
      a.p  = !a.p;
    }
    }
  }
    b = fgetc(in);
 }
}





void run(char *filename, bool testing) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        printf("Can't open %s\n", filename);
        exit(1);
    }
    display *d = newDisplay(filename, 200, 200, testing);
    interpret(in, d);
    end(d);
    fclose(in);
    if (testing) printf("Sketch %s OK\n", filename);
}


// ----------------------------------------------------------------------------
// Nothing below this point needs to be changed.
// ----------------------------------------------------------------------------

void testSketches() {
    // Stage 1
    run("line.sketch", true);
    run("square.sketch", true);
    run("box.sketch", true);
    run("oxo.sketch", true);

    // Stage 2
    run("diag.sketch", true);
    run("cross.sketch", true);

    // Stage 3
    run("clear.sketch", true);
    run("key.sketch", true);

    // Stage 4
    run("pauses.sketch", true);
    run("field.sketch", true);
    run("lawn.sketch", true);
}

int main(int n, char *args[n]) {
    if (n == 1) testSketches();
    else if (n == 2) run(args[1], false);
    else {
        fprintf(stderr, "Usage: sketch [file.sketch]");
        exit(1);
    }
}
