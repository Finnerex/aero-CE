#include "vector.h"
#include <math.h>
#include "simulation.h"
#include <graphx.h>

vec2_t vec_Multiply(vec2_t vec1, vec2_t vec2) {
    return (vec2_t) {vec1.x * vec2.x, vec1.y * vec2.y};
}

vec2_t vec_MultiplyFloat(vec2_t vec, float val) {
    return (vec2_t) {vec.x * val, vec.y * val};
}

// vec2_t vec_Divide(vec2_t vec1, vec2_t vec2) {
//     return (vec2_t) {vec1.x / vec2.x, vec1.y / vec2.y};
// }

vec2_t vec_DivideFloat(vec2_t vec, float val) {
    return (vec2_t) {vec.x / val, vec.y / val};
}

vec2_t vec_Add(vec2_t vec1, vec2_t vec2) {
    return (vec2_t) {vec1.x + vec2.x, vec1.y + vec2.y};
}

vec2_t vec_AddLength(vec2_t vec, float add) {
    float length = vec_Magnitude(vec);
    float ratio = (length + add) / length;
    return (vec2_t) {vec.x * ratio, vec.y * ratio};
}

vec2_t vec_Subtract(vec2_t vec1, vec2_t vec2) {
    return (vec2_t) {vec1.x - vec2.x, vec1.y - vec2.y};
}

float vec_Magnitude(vec2_t vec) {
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float vec_SqrMagnitude(vec2_t vec) {
    return vec.x * vec.x + vec.y * vec.y;
}

vec2_t vec_Rotate(vec2_t vec, float radians) {
    float x = (vec.x * cosf(radians) + vec.y * sinf(radians));
    float y = (vec.y * cosf(radians) - vec.x * sinf(radians));
    return (vec2_t) {x, y};
}

vec2_t vec_Normalize(vec2_t vec) {
    float magnitude = vec_Magnitude(vec);
    return (vec2_t) {vec.x / magnitude, vec.y / magnitude};
}

float vec_Dot(vec2_t vec1, vec2_t vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

// component of vec1 that is perpendicular to vec2 (face = vec1, vel = vec2)
vec2_t vec_PerpendicularComponent(vec2_t vec1, vec2_t vec2) { 
    return vec_Subtract(vec1, vec_DivideFloat(vec_MultiplyFloat(vec2, vec_Dot(vec1, vec2)), vec_SqrMagnitude(vec2)));
}

vec2_t get_face_normal(vec2_t vert1, vec2_t vert2) { // normal * length
    
    vec2_t normal_vec;
    vec2_t normal_vec2;
    vec2_t norm_vert1;
    vec2_t norm_vert2;
    
    norm_vert1.x = vert1.x;
    norm_vert1.y = vert2.y;
    norm_vert2.x = vert2.x;
    norm_vert2.y = vert1.y;

    vec2_t subtracter = vert1;

    vec2_t middle_of_face = vec_Add(vec_MultiplyFloat(vec_Subtract(vert2, subtracter), 0.5f), subtracter);

    normal_vec = vec_Subtract(norm_vert2, norm_vert1);
    vec2_t vec_check = vec_Add(normal_vec, middle_of_face);
    normal_vec2 = vec_Subtract(norm_vert1, norm_vert2);
    vec2_t vec_check2 = vec_Add(normal_vec2, middle_of_face);

    vec2_t center_vec = {CENTER_X, CENTER_Y};
    
    float distance_from_center = vec_Magnitude(vec_Subtract(vec_check, center_vec));
    float distance_from_center2 = vec_Magnitude(vec_Subtract(vec_check2, center_vec));

    if (distance_from_center > distance_from_center2)
        return normal_vec;

    return normal_vec2;
}

float angle_between_vecs(vec2_t vec1, vec2_t vec2){
    return acosf(vec_Dot(vec1, vec2) / (vec_Magnitude(vec1) * vec_Magnitude(vec2)));
}
