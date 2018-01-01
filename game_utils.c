#include <util/delay.h>
#include "../lcdlib/lcd.h"
#include "bat.h"
#include "ball.h"
#include "game_utils.h"

void set_game() {
  set_bat();
  set_ball();
  _delay_ms(1000);
  return;
}
void play_pong() {
  moveBat();
  moveBall();
  _delay_ms(50);
  return;
}
uint8_t checkEnd() {
  rectangle bat = get_bat(),
            ball = get_ball();
  if((bat.bottom == ball.top) && ((bat.left > ball.right) || (bat.right < ball.left))) {
    clear_screen();
    display_string("Game Over!");
    _delay_ms(50000);
    clear_screen();
    return 1;
  }
  return 0;
}
