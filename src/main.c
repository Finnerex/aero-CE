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

#define NUM_OBJS 5
int selected_object = 1;
obj_t* objects[NUM_OBJS] = { tringle, octogon, square, diamond, kite };
bool dark_mode = true;

bool step(void) {

    kb_Scan();
    
    if (kb_Data[6] & kb_Clear)
        return false;

    static bool zero, last_zero;
    zero = kb_Data[3] & kb_0;

    if (zero && !last_zero)
        dark_mode = !dark_mode;

    last_zero = zero;

    if (kb_Data[7] & kb_Up)
        sim_state.wind_velocity = vec_Rotate(sim_state.wind_velocity, 0.05f);
    else if (kb_Data[7] & kb_Down)
        sim_state.wind_velocity = vec_Rotate(sim_state.wind_velocity, -0.05f);


    if (kb_Data[7] & kb_Right)
        sim_state.wind_velocity = vec_AddLength(sim_state.wind_velocity, 0.1f);
    else if (kb_Data[7] & kb_Left)
        sim_state.wind_velocity = vec_AddLength(sim_state.wind_velocity, -0.1f);


    if (kb_Data[1] & kb_Del)
        sim_state.air_density += 0.1f;
    else if (kb_Data[4] & kb_Stat)
        sim_state.air_density -= 0.1f;

    
    static bool second, last_second, alpha, last_alpha;
    second = kb_Data[1] & kb_2nd;
    alpha = kb_Data[2] & kb_Alpha;

    if (second && !last_second)
        selected_object += selected_object + 1 >= NUM_OBJS ? 0 : 1;
    else if (alpha && !last_alpha) 
        selected_object -= selected_object - 1 < 0 ? 0 : 1;

    last_second = second;
    last_alpha = alpha;


    update_sim_state(&sim_state, objects[selected_object]);
    
    return true;
}

void draw(void) {

    gfx_FillScreen(!dark_mode);

    gfx_SetColor(dark_mode);
    gfx_SetTextFGColor(dark_mode);

    draw_object(objects[selected_object]);
    draw_info(&sim_state);
    draw_forces(&sim_state);
    // draw_norms(objects[selected_object]);

}


void begin(void) {

    sim_state.wind_velocity.x = INIT_WIND_SPEED;
    sim_state.air_density = INIT_AIR_DENSITY;

    for (int j = 0; j < NUM_OBJS; j++) {
        obj_t* object = objects[j];

        for (int i = 0; i < object->num_faces; i++) {
            vec2_t verts[2] = {object->verts[object->faces[i][0]],
                                object->verts[object->faces[i][1]]}; 
            object->normals[i] = get_face_normal(verts[0], verts[1]);
        }
    }
}

void end(void) {

}