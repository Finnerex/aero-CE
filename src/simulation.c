#include "simulation.h"
#include "objects.h"
#include "vector.h"

vec2_t calculate_net_force(sim_state_t* sim_state) {

    vec2_t net_force;

    for (int i = 0; i < sim_state->object->num_faces; i++) {
        float var = (sim_state->air_density / 2) * sim_state->coef_drag;
        vec2_t face_force = vec_Multiply(vec_MultiplyFloat(sim_state->object->normals[i], var), vec_Multiply(sim_state->wind_velocity, sim_state->wind_velocity));
        net_force = vec_Add(net_force, face_force);
    }

    return net_force;
}

void update_sim_state(sim_state_t* sim_state) {
    
    sim_state->net_force = calculate_net_force(sim_state);
    sim_state->wind_speed = vec_Magnitude(sim_state->wind_velocity);
    
}