#ifndef DRAW_H
#define DRAW_H

#include "simulation.h"

#define INFO_SECT_HEIGHT 20

void draw_object(obj_t* obj);
void draw_info(sim_state_t* state);
void draw_forces(sim_state_t* state);

#endif