#include <avr/io.h>
#include "../lcdlib/lcd.h"
#include "bat.h"

static rectangle *bat;

//PRIVATE
void batLeft() {
  if((PIND & _BV(PD2)) && bat->left > 0) {
    bat->left -= 2;
    bat->right -= 2;
  }
  return;
}
void batRight() {
  if((PIND & _BV(PD3)) && bat->right < 240) {
    bat->left += 2;
    bat->right += 2;
  }
  return;
}

//PUBLIC
rectangle get_bat() {
  return *bat;
}
void set_bat() {
  bat->left = 80;
  bat->right = 120;
  bat->top = 0;
  bat->bottom = 10;
  fill_rectangle(*bat, GREEN);
  return;
}
void moveBat() {
  fill_rectangle(*bat, BLACK);
  batLeft();
  batRight();
  fill_rectangle(*bat, GREEN);
  return;
}
