#include "vector.h"
#include <math.h>

vec2_t vec_Multiply(vec2_t vec1, vec2_t vec2) {
    return (vec2_t) {vec1.x * vec2.x, vec1.y * vec2.y};
}

vec2_t vec_MultiplyFloat(vec2_t vec, float val) {
    return (vec2_t) {vec.x * val, vec.y * val};
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

void vec_Rotate(vec2_t* vec, float degrees) {
    float new_x = vec->x + (cosf(vec->x * degrees) - sinf(vec->y * degrees));
    vec->y = vec->y + (sinf(vec->x * degrees) -  cosf(vec->y * degrees));
    vec->x = new_x;
}

vec2_t get_face_normal(vec2_t vert1, vec2_t vert2) { // normal * length
    
    vec2_t normal_vec;
    vec2_t norm_vert1;
    vec2_t norm_vert2;
    
    norm_vert1.x = vert1.x;
    norm_vert1.y = vert2.y;
    norm_vert2.x = vert2.x;
    norm_vert2.y = vert1.y;

    if (vert1.x < vert2.x)
        normal_vec = vec_Subtract(norm_vert2, norm_vert1);
    else
        normal_vec = vec_Subtract(norm_vert1, norm_vert2);

    return normal_vec;
}

