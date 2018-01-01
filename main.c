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
