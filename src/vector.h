#ifndef VECTOR_H
#define VECTOR_H

// measures are in pixels
typedef struct {
    float x;
    float y;
} vec2_t;

vec2_t vec_Multiply(vec2_t vec1, vec2_t vec2);
vec2_t vec_MultiplyFloat(vec2_t vec, float val);
vec2_t vec_Add(vec2_t vec1, vec2_t vec2);
vec2_t vec_AddLength(vec2_t vec, float add);
vec2_t vec_Subtract(vec2_t vec1, vec2_t vec2);
float vec_Magnitude(vec2_t vec);
void vec_Rotate(vec2_t* vec, float radians);
vec2_t get_face_normal(vec2_t vert1, vec2_t vert2);

#endif