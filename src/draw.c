#include "simulation.h"
#include "vector.h"
#include "draw.h"
#include <graphx.h>
#include <math.h>
#include <debug.h>

void draw_object(obj_t* obj) {

    for (int i = 0; i < obj->num_faces; i++) {
        vec2_t* verts[2] = {&obj->verts[obj->faces[i][0]], &obj->verts[obj->faces[i][1]]};
        gfx_Line(verts[0]->x, verts[0]->y, verts[1]->x, verts[1]->y);
    } 

}

void draw_norms(obj_t* obj) {

    for (int i = 0; i < obj->num_faces; i++) {
        vec2_t* verts[2] = {&obj->verts[obj->faces[i][0]], &obj->verts[obj->faces[i][1]]};
    
        vec2_t normal_vec;
        vec2_t normal_vec2;
        vec2_t norm_vert1;
        vec2_t norm_vert2;

        norm_vert1.x = verts[0]->x;
        norm_vert1.y = verts[1]->y;
        norm_vert2.x = verts[1]->x;
        norm_vert2.y = verts[0]->y;

        vec2_t subtracter = *verts[0];

        vec2_t middle_of_face = vec_Add(vec_MultiplyFloat(vec_Subtract(*verts[1], subtracter), 0.5f), subtracter);

        normal_vec = vec_Subtract(norm_vert2, norm_vert1);
        vec2_t vec_check = vec_Add(normal_vec, middle_of_face);
        normal_vec2 = vec_Subtract(norm_vert1, norm_vert2);
        vec2_t vec_check2 = vec_Add(normal_vec2, middle_of_face);

        vec2_t center_vec = {CENTER_X, CENTER_Y};

        float distance_from_center = vec_Magnitude(vec_Subtract(vec_check, center_vec));
        float distance_from_center2 = vec_Magnitude(vec_Subtract(vec_check2, center_vec));

        gfx_SetColor(4);
        if (distance_from_center > distance_from_center2)
            gfx_Line(middle_of_face.x, middle_of_face.y, vec_check.x, vec_check.y);
        else
            gfx_Line(middle_of_face.x, middle_of_face.y, vec_check2.x, vec_check2.y);
        }    

}

void print_float(float in, int places) {
    int dec = powf(10, places);

    gfx_PrintInt(in, 1);
    gfx_PrintString(".");
    gfx_PrintInt(abs((int)(in * dec) % (dec)), 1);
}

void draw_info(sim_state_t* state) {

    gfx_HorizLine(0, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT, GFX_LCD_WIDTH);

    gfx_SetTextXY(5, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT / 2);
    gfx_PrintString("Wind Speed: ");
    print_float(state->wind_speed, 1);
    gfx_PrintString("m/s");
    
    gfx_SetTextXY(CENTER_X, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT / 2);
    gfx_PrintString("Air Density: ");
    print_float(state->air_density, 2);
    gfx_PrintString("kg/m^3");

    gfx_SetTextXY(10, 20);
    gfx_PrintString("Air speed - x: ");
    print_float(state->wind_velocity.x, 1);
    gfx_PrintString(" y: ");
    print_float(state->wind_velocity.y, 1);

    vec2_t wind_dir = vec_MultiplyFloat(vec_Normalize(state->wind_velocity), 10);
    gfx_Line(30, 30, 30 + wind_dir.x, 30 + wind_dir.y);
    gfx_SetColor(3);
    gfx_Rectangle(30 + wind_dir.x, 30 + wind_dir.y, 2, 2);

}

void draw_forces(sim_state_t* state) {
    
    gfx_SetColor(5);
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X, CENTER_Y + state->net_force.y); // lift arrow body
    gfx_SetTextFGColor(5);
    gfx_SetTextXY(5, GFX_LCD_HEIGHT - INFO_SECT_HEIGHT * 1.5f);
    gfx_PrintString("Lift: ");
    print_float(-state->net_force.y, 1);
    
    gfx_SetColor(3);
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X + state->net_force.x, CENTER_Y); // drag arrow body
    gfx_SetTextFGColor(3);
    gfx_PrintString(" Drag: ");
    print_float(state->net_force.x, 1);
    
    gfx_SetColor(4);
    gfx_Line(CENTER_X, CENTER_Y, CENTER_X + state->net_force.x, CENTER_Y + state->net_force.y); // net force arrow body
    gfx_SetTextFGColor(4);
    gfx_PrintString(" Net: ");
    print_float(vec_Magnitude(state->net_force), 1);

    dbg_printf("net mag: %f, lift: %f, drag: %f\n", vec_Magnitude(state->net_force), -state->net_force.y, state->net_force.x);

}