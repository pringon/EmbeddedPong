#include "../lcdlib/lcd.h"
#include "bat.h"
#include "ball.h"

static rectangle *ball, *direction;

//PRIVATE
void ballTop() {
  if(get_bat().bottom == ball->top) {
    direction->top = 1;
    direction->bottom = 1;
  }
  return;
}
void ballBottom() {
  if(ball->bottom == 320) {
    direction->top = -1;
    direction->bottom = -1;
  }
  return;
}
void ballLeft() {
  if(ball->left == 0) {
    direction->left = 1;
    direction->right = 1;
  }
  return;
}
void ballRight() {
  if(ball->right == 240) {
    direction->left = -1;
    direction->right = -1;
  }
  return;
}
void ball_check_edges() {
  ballTop();
  ballLeft();
  ballRight();
  ballBottom();
}
void set_direction() {
  direction->left = 1;
  direction->right = 1;
  direction->top = -1;
  direction->bottom = -1;
  return;
}

//PUBLIC
rectangle get_ball() {
  return *ball;
}
void set_ball() {
  ball->left = 115;
  ball->right = 125;
  ball->top = 195;
  ball->bottom = 205;
  fill_rectangle(*ball, YELLOW);
  set_direction();
  return;
}
void moveBall() {
  fill_rectangle(*ball, BLACK);
  ball->left += direction->left;
  ball->right += direction->right;
  ball->top += direction->top;
  ball->bottom += direction->bottom;
  fill_rectangle(*ball, YELLOW);
  ball_check_edges();
  return;
}
