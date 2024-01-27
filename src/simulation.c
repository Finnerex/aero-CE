#include "simulation.h"
#include "objects.h"
#include "vector.h"
#include <graphx.h>

vec2_t calculate_net_force(sim_state_t* sim_state) {

    vec2_t net_force;
    vec2_t pressure = vec_MultiplyFloat(vec_Multiply(sim_state->wind_velocity, sim_state->wind_velocity), (sim_state->air_density / 2));

    for (int i = 0; i < sim_state->object->num_faces; i++) {

        vec2_t normal = vec_MultiplyFloat(sim_state->object->normals[i], (1.0f/PIXELS_PER_METER));
        
        vec2_t face_force = vec_Multiply(normal, pressure);
        net_force = vec_Add(net_force, face_force);
    }

    return net_force;
}

void update_sim_state(sim_state_t* sim_state) {
    
    sim_state->net_force = calculate_net_force(sim_state);
    sim_state->wind_speed = vec_Magnitude(sim_state->wind_velocity);
    
}