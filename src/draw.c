#include "simulation.h"
#include "vector.h"
#include "draw.h"
#include <graphx.h>

void draw_object(obj_t* obj) {

    for (int i = 0; i < obj->num_faces; i++) {
        vec2_t* verts[2] = {obj->verts[*obj->faces[i][0]], obj->verts[*obj->faces[i][1]]};
        gfx_Line(verts[0]->x, verts[0]->y, verts[1]->x, verts[1]->y);
    }

}

void print_float(float in, int places) {
    gfx_PrintInt(in, 1);
    gfx_PrintString(".");
    gfx_PrintInt((int)(in * 10 * places) % (10 * places), 1);
}

void draw_info(sim_state_t* state) {

    gfx_HorizLine(0, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT, GFX_LCD_WIDTH);

    gfx_SetTextXY(5, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT / 2);
    gfx_PrintString("Wind Speed: ");
    print_float(state->wind_speed, 1);
    gfx_PrintString("m/s");
    
    gfx_SetTextXY(GFX_LCD_WIDTH, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT / 2);
    gfx_PrintString("\tAir Density: ");
    gfx_PrintInt(state->air_density, 2);
    gfx_PrintString("kg/m^3");

}

void draw_forces(sim_state_t* state) {
    
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X, CENTER_Y + state->net_force.y); // lift arrow body
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X + state->net_force.x, CENTER_Y); // drag arrow body
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X + state->net_force.x, CENTER_Y + state->net_force.y); // net force arrow body
}