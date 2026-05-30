#include <math.h>
#include "../turtlec.h"

void levy(Turtle *, float, int);

int main(void){
  TurtleApp *app = turtleAppCreate(1600, 900, "Fractal Tree");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 900.0f, 300.0f);
  turtlePenDown(t);
  
  turtleLeft(t, 180.0);

  turtleSetColor(t, 209, 90, 205);
  turtleSetSpeed(t, 5.0f);  
  levy(t, 300.0f, 10);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
} 

void levy(Turtle *turtle, float length, int depth) {
  if (depth == 0) {
    turtleForward(turtle, length);
    return;
  }

  turtleLeft(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleRight(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}
