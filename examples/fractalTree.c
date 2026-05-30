#include "../turtlec.h"
#include <time.h>
#include <stdlib.h>

void fractalTree(Turtle *, float, int, int);

int main(void){
  srand(time(NULL));
  
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
  fractalTree(t, 200.0f, 10, 10);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
} 

void fractalTree(Turtle *turtle, float length, int depth, int depthOrig){
  if(depth == 0 || length < 5)
    return;
    
  float randLeft = -0.4f + ((float)rand() / RAND_MAX) * (0.6f);
  float randRight = -0.4f + ((float)rand() / RAND_MAX) * (0.6f);
  
  float t = (float)depth / depthOrig; 
  
  int r = 54  + (170 - 54) * t;
  int g = 90 + (140 - 90) * t;
  int b = 54  + (60  - 54)  * t;
  turtleSetColor(turtle, r, g, b);
/*  
  if (depth > 9)
    turtleSetColor(turtle, 165, 105, 44);  
  else if (depth > 8)
    turtleSetColor(turtle, 230, 196, 162);  
  else if (depth > 5)
    turtleSetColor(turtle, 54, 109, 54);   
  else
    turtleSetColor(turtle, 176, 216, 176);     
*/

  turtleForward(turtle, length);

  turtleLeft(turtle, 30.0);
  fractalTree(turtle, length * (0.7 + randLeft), depth - 1, depthOrig);

  turtleRight(turtle, 60.0);
  fractalTree(turtle, length * (0.7 + randRight), depth - 1, depthOrig);

  turtleLeft(turtle, 30.0);
  
  turtlePenUp(turtle);
  
  turtleBackward(turtle, length);
  
  turtlePenDown(turtle);
}
