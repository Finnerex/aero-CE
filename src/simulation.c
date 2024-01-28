#include "simulation.h"
#include "objects.h"
#include "vector.h"
#include <graphx.h>
#include <debug.h>
#include <math.h>

#define PI 3.1415926535

vec2_t calculate_net_force(sim_state_t sim_state) {

    vec2_t net_force = {0, 0};

    for (int i = 0; i < sim_state.object->num_faces; i++) {

        vec2_t normal = vec_MultiplyFloat(sim_state.object->normals[i], (1.0f/PIXELS_PER_METER));

        float angle = angle_between_vecs(sim_state.wind_velocity, normal);
        
        if (angle > PI/2 || angle < -PI/2)
            continue;

        vec2_t projected_velocity = vec_MultiplyFloat(normal, vec_Dot(normal, sim_state.wind_velocity) / (vec_SqrMagnitude(normal)));
        vec2_t pressure = vec_MultiplyFloat(vec_Multiply(projected_velocity, projected_velocity), sim_state.air_density / 2);

        vec2_t face_force = vec_MultiplyFloat(pressure, vec_Magnitude(normal));
        face_force.y = -face_force.y;
        
        dbg_printf("Area: %f, %f, mag: %f\n", normal.x, normal.y, vec_Magnitude(normal));
        dbg_printf("face: %f, %f, mag: %f\n", face_force.x, face_force.y, vec_Magnitude(face_force));

        net_force = vec_Add(net_force, face_force);
    }

    return net_force;

}

void update_sim_state(sim_state_t* sim_state) {
    
    sim_state->net_force = calculate_net_force(*sim_state);
    sim_state->wind_speed = vec_Magnitude(sim_state->wind_velocity);
    
}