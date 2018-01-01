#include "lcdlib/lcd.h"

//PRIVATE
void ballTop();
void ballBottom();
void ballLeft();
void ballRight();
void ball_check_edges();
void set_direction();

//PUBLIC
rectangle get_ball();
void set_ball();                //Takes ball and direction as arguments
void moveBall();                //Takes ball and direction as arguments
