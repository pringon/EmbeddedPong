/*#include <avr/io.h>
#include <util/delay.h>
#include "../lcdlib/lcd.h"

uint8_t checkEnd(rectangle *bat, rectangle *ball);
void set_bat(rectangle *bat);
void set_ball(rectangle *ball, rectangle *direction);
void set_direction(rectangle *direction);

rectangle rectangle_slice(rectangle rect, char side, uint8_t amount);

void moveBat(rectangle *bat);
void moveBall(rectangle *bat, rectangle *ball, rectangle *direction);

void batLeft(rectangle *bat);
void batRight(rectangle *bat);

void ball_check_edges(rectangle *bat, rectangle *ball, rectangle *direction);
void ballTop(rectangle *bat, rectangle *ball, rectangle *direction);
void ballLeft(rectangle *ball, rectangle *direction);
void ballRight(rectangle *ball, rectangle *direction);
void ballBottom(rectangle *ball, rectangle *direction);


int main() {

	init_lcd();
  DDRD = _BV(PD2) | _BV(PD3);

  rectangle *bat, *ball, *direction;
  while(1) {

    set_bat(bat);
    set_ball(ball, direction);

  	fill_rectangle(*bat, GREEN);
    fill_rectangle(*ball, YELLOW);

    _delay_ms(10000);
  	while(checkEnd(bat, ball)) {

      moveBat(bat);
      moveBall(bat, ball, direction);
      _delay_ms(50);
  	}
    clear_screen();
    display_string("Game Over!");
    _delay_ms(50000);
    clear_screen();
  }

	return 0;
}

uint8_t checkEnd(rectangle *bat, rectangle *ball) {
  if((bat->bottom + 1 == ball->top) && ((bat->left > ball->right) || (bat->right < ball->left))) {
    return 0;
  }
  return 1;
}
void set_bat(rectangle *bat) {
  bat->left = 75;
  bat->right = 125;
  bat->top = 3;
  bat->bottom = 8;

  return;
}
void set_ball(rectangle *ball, rectangle *direction) {
  ball->left = 115;
  ball->right = 125;
  ball->top = 195;
  ball->bottom = 205;
  set_direction(direction);

  return;
}
void set_direction(rectangle *direction) {
  direction->left = 1;
  direction->right = 1;
  direction->top = -1;
  direction->bottom = -1;
  return;
}
rectangle rectangle_slice(rectangle rect, char side, uint8_t amount) {
  switch (side) {
    case 't':
      rect.top = rect.bottom - amount;
      break;
    case 'l':
      rect.left = rect.right - amount;
      break;
    case 'r':
      rect.right = rect.left + amount;
      break;
    case 'b':
      rect.bottom = rect.top + amount;
      break;
    default:
      side = 'R';
      side = 'I';
      side = 'P'; //You done goofed.
  }
  return rect;
}
void moveBat(rectangle *bat) {
  batLeft(bat);
  batRight(bat);
  return;
}
void moveBall(rectangle *bat, rectangle *ball, rectangle *direction) {
  fill_rectangle(*ball, BLACK);
  ball->left += direction->left;
  ball->right += direction->right;
  ball->top += direction->top;
  ball->bottom += direction->bottom;
  fill_rectangle(*ball, YELLOW);
  ball_check_edges(bat, ball, direction);
  return;
}
void ball_check_edges(rectangle *bat, rectangle *ball, rectangle *direction) {
  ballTop(bat, ball, direction);
  ballLeft(ball, direction);
  ballRight(ball, direction);
  ballBottom(ball, direction);
}

void batLeft(rectangle *bat) {
  if((PIND & _BV(PD2)) && bat->left > 1) {
    fill_rectangle(rectangle_slice(*bat, 'l', 2), BLACK);
    bat->left -= 2;
    bat->right -= 2;
    fill_rectangle(rectangle_slice(*bat, 'r', 2), GREEN);
  }
  return;
}
void batRight(rectangle *bat) {
  if((PIND & _BV(PD3)) && bat->right < 239) {
    fill_rectangle(rectangle_slice(*bat, 'r', 2), BLACK);
    bat->left += 2;
    bat->right += 2;
    fill_rectangle(rectangle_slice(*bat, 'l', 2), GREEN);
  }
  return;
}
void ballTop(rectangle *bat, rectangle *ball, rectangle *direction) {
  if(bat->bottom + 1 == ball->top) {
    direction->top = 1;
    direction->bottom = 1;
  }
  return;
}
void ballBottom(rectangle *ball, rectangle *direction) {
  if(ball->bottom == 320) {
    direction->top = -1;
    direction->bottom = -1;
  }
  return;
}
void ballLeft(rectangle *ball, rectangle *direction) {
  if(ball->left == 0) {
    direction->left = 1;
    direction->right = 1;
  }
  return;
}
void ballRight(rectangle *ball, rectangle *direction) {
  if(ball->right == 240) {
    direction->left = -1;
    direction->right = -1;
  }
  return;
}
*/


/* YOU'LL NEVER BE FORGOTTEN :'( */
#include <avr/io.h>
#include "../lcdlib/lcd.h"
#include "game_utils.h"

int main() {

	init_lcd();
  DDRD = _BV(PD2) | _BV(PD3);

  while(1) {
    set_game();
  	while(!checkEnd()) {
      play_pong();
  	}
  }

	return 0;
}
