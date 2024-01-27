#ifndef SIM_H
#define SIM_H

#include "vector.h"

#define PIXELS_PER_METER 50
#define INIT_WIND_SPEED 10.0f
#define INIT_COEF_DRAG 0.05f
#define INIT_AIR_DENSITY 1.225f

#define CENTER_X (GFX_LCD_WIDTH / 2)
#define CENTER_Y (GFX_LCD_HEIGHT / 2)

// indices of two points that are the endpoints of the face
typedef int face_t[2];

typedef struct {
    face_t* faces; // 8 max faces
    vec2_t* verts;
    vec2_t normals[8]; // not actually normalized vectors because length

    int num_faces;
    int num_verts;
} object_t;

typedef struct {
    vec2_t wind_velocity; // this is in meters though
    float wind_speed;

    float air_density;
    vec2_t net_force;
    float coef_drag;

    object_t* object;
    
} sim_state_t;

vec2_t calculate_net_force(sim_state_t sim_state);
void update_sim_state(sim_state_t* sim_state);

#endif