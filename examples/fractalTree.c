#include "../turtlec.h"

void fractalTree(Turtle *, float, int);

int main(void){
  TurtleApp *app = turtleAppCreate(1600, 800, "Fractal Tree");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 800.0f, 750.0f);
  turtlePenDown(t);

  turtleLeft(t, 90.0);

  turtleSetColor(t, 61, 242, 192);
  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 200.0f, 4);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void fractalTree(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 5)
    return;

  turtleForward(turtle, length);

  turtleLeft(turtle, 120.0);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleRight(turtle, 60.0);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleLeft(turtle, 120.0);
  turtleBackward(turtle, length);
}
