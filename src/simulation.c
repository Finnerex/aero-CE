#include "simulation.h"
#include "objects.h"
#include "vector.h"
#include <graphx.h>
#include <math.h>

#define PI 3.14159265358979

vec2_t calculate_net_force(sim_state_t sim_state, obj_t* object) {

    vec2_t net_force = {0, 0};

    for (int i = 0; i < object->num_faces; i++) {

        vec2_t normal = vec_MultiplyFloat(object->normals[i], (1.0f/PIXELS_PER_METER));

        float angle = angle_between_vecs(sim_state.wind_velocity, normal);
        
        if (angle < PI/2 && angle > -PI/2)
            continue;

        vec2_t projected_velocity = vec_AsComponentOf(sim_state.wind_velocity, normal);
        vec2_t pressure = vec_MultiplyFloat(vec_Multiply(projected_velocity, projected_velocity), sim_state.air_density / 2);

        vec2_t normed_vec = vec_Normalize(normal);

        vec2_t face_force = vec_Multiply(vec_MultiplyFloat(pressure, -vec_Magnitude(normal)), (vec2_t){sign(normed_vec.x), sign(normed_vec.y)}); // might want to just do signs instead of the norm

        net_force = vec_Add(net_force, face_force);
    }

    return net_force;

}

void update_sim_state(sim_state_t* sim_state, obj_t* object) {
    
    sim_state->net_force = calculate_net_force(*sim_state, object);
    sim_state->wind_speed = vec_Magnitude(sim_state->wind_velocity);
    
}

