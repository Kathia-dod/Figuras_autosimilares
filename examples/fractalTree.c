#include "../turtlec.h"

void fractalTree(Turtle *, float, int);

int main(void){
  TurtleApp *app = turtleAppCreate(1600, 900, "Fractal Tree");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 600.0f, 600.0f);
  turtlePenDown(t);

  turtleLeft(t, 90.0);

  turtleSetColor(t, 61, 242, 192);
  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 200.0f, 8);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void fractalTree(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 5)
    return;

  turtleForward(turtle, length);

  turtleLeft(turtle, 40.04);
  fractalTree(turtle, length * 0.4, depth - 1);

  turtleRight(turtle, 80.0);
  fractalTree(turtle, length * 1.0, depth - 1);

  turtleLeft(turtle, 40.0);
  turtleBackward(turtle, length);
}
