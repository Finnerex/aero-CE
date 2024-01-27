#include <graphx.h>
#include <stdbool.h>
#include <keypadc.h>

#include "simulation.h"
#include "objects.h"
#include "draw.h"
#include "vector.h"
#include "gfx/gfx.h"

void begin(void);
void end(void);
bool step(void);
void draw(void);

int main() {
    begin();                // No rendering allowed!

    gfx_Begin();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_SetDrawBuffer();    // Draw to the buffer to avoid rendering artifacts

    while (step()) {        // No rendering allowed in step!
        draw();             // As little non-rendering logic as possible
        gfx_SwapDraw();     // Queue the buffered frame to be displayed
    }

    gfx_End();
    end();

    return 0;
}

// global vars
sim_state_t sim_state;

bool step(void) {
    
    kb_Scan();
    
    if (kb_Data[6] & kb_Clear)
        return false;


    if (kb_Data[7] & kb_Up)
        vec_Rotate(&sim_state.wind_velocity, 2);
    else if (kb_Data[7] & kb_Down)
        vec_Rotate(&sim_state.wind_velocity, -2);

    if (kb_Data[7] & kb_Right)
        sim_state.wind_velocity = vec_AddLength(sim_state.wind_velocity, 0.1);
    else if (kb_Data[7] & kb_Left)
        sim_state.wind_velocity = vec_AddLength(sim_state.wind_velocity, -0.1);

    if (kb_Data[1] & kb_Del)
        sim_state.air_density += 0.1;
    else if (kb_Data[1] & kb_Del)
        sim_state.air_density -= 0.1;


    update_sim_state(&sim_state);


    return true;
}

void draw(void) {

    gfx_FillScreen(1);

    gfx_SetColor(2); // white

    draw_object(sim_state.object);
    draw_info(&sim_state);
    draw_forces(&sim_state);

}


void begin(void) {

    sim_state.wind_velocity.x = INIT_WIND_SPEED;
    sim_state.object = square;
    sim_state.coef_drag = INIT_COEF_DRAG;
    sim_state.air_density = INIT_AIR_DENSITY;

    for (int i = 0; i < sim_state.object->num_faces; i++) {
        vec2_t* verts[2] = {sim_state.object->verts[*sim_state.object->faces[i][0]],
                            sim_state.object->verts[*sim_state.object->faces[i][1]]}; 
        *sim_state.object->normals[i] = get_face_normal(*verts[0], *verts[1]);
    }
}

void end(void) {

}