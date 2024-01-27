#include "objects.h"

face_t square_faces[3] = {{0, 1}, {2, 3}, {3, 0}};
vec2_t square_verts[4] = {{CENTER_X - 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y - 20}, {CENTER_X - 20, CENTER_Y - 20}};
vec2_t square_norms[8];
obj_t square_data = {square_norms, square_faces, square_verts, 3, 4};

face_t face_face[1] = {{0, 1}};
vec2_t face_verts[2] = {{CENTER_X + 30, CENTER_Y + 30}, {CENTER_X - 10, CENTER_Y - 10}};
vec2_t face_norms[1];
obj_t face_data = {face_norms, face_face, face_verts, 1, 2};

// face_t user_faces[8];
// vec2_t user_verts[8];
// vec2_t user_norms[8];
// obj_t user_shape_data = {user_norms, user_faces, user_verts, 0, 0};