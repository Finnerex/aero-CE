#include "objects.h"

face_t square_faces[4] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
vec2_t square_verts[4] = {{CENTER_X - 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y - 20}, {CENTER_X - 20, CENTER_Y - 20}};
vec2_t square_norms[8];
obj_t square_data = {square_norms, square_faces, square_verts, 4, 4};

// face_t user_faces[8];
// vec2_t user_verts[8];
// vec2_t user_norms[8];
// obj_t user_shape_data = {user_norms, user_faces, user_verts, 0, 0};