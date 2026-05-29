#include "../turtlec.h"

void fractalTree(Turtle *, float, int);

int main(void){
  TurtleApp *app = turtleAppCreate(1600, 900, "Fractal Tree");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 800.0f, 800.0f);
  turtlePenDown(t);

  turtleLeft(t, 90.0);

  turtleSetColor(t, 61, 242, 192);
  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 200.0f, 15);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
} 

void fractalTree(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 5)
    return;
  
  //int r =   
  
  if (depth > 7)
    turtleSetColor(turtle, 165, 105, 44);  
  else if (depth > 5)
    turtleSetColor(turtle, 230, 196, 162);  
  else if (depth > 3)
    turtleSetColor(turtle, 54, 109, 54);   
  else
    turtleSetColor(turtle, 176, 216, 176);     

  turtleForward(turtle, length);

  turtleLeft(turtle, 30.0);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleRight(turtle, 60.0);
  fractalTree(turtle, length * 0.7, depth - 1);

  turtleLeft(turtle, 30.0);
  
  turtlePenUp(turtle);
  
  turtleBackward(turtle, length);
  
  turtlePenDown(turtle);
}
