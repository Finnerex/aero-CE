#include "objects.h"

face_t square_faces[4] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
vec2_t square_verts[4] = {{CENTER_X - 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y - 20}, {CENTER_X - 20, CENTER_Y - 20}};
vec2_t square_norms[4];
obj_t square_data = {square_norms, square_faces, square_verts, 4, 4};

face_t octogon_face[8] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 0}};
vec2_t octogon_verts[8] = {{CENTER_X - 24, CENTER_Y + 10}, {CENTER_X - 24, CENTER_Y - 10}, {CENTER_X - 8.36, CENTER_Y - 24.14}, {CENTER_X + 14.14, CENTER_Y - 24.14}, {CENTER_X + 28.28, CENTER_Y - 10}, {CENTER_X + 28.28, CENTER_Y + 10}, {CENTER_X + 14.14, CENTER_Y + 24.14}, {CENTER_X - 8.36, CENTER_Y + 24.14}};
vec2_t octogon_norms[8];
obj_t octogon_data = {octogon_norms, octogon_face, octogon_verts, 8, 8};

face_t tringle_faces[3] = {{0, 1}, {1, 2}, {2, 0}};
vec2_t tringle_verts[3] = {{CENTER_X - 40, CENTER_Y + 20}, {CENTER_X, CENTER_Y - 20}, {CENTER_X + 25, CENTER_Y + 20}};
vec2_t tringle_norms[3];
obj_t tringle_data = {tringle_norms, tringle_faces, tringle_verts, 3, 3};

face_t diamond_faces[4] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
vec2_t diamond_verts[4] = {{CENTER_X - 40, CENTER_Y}, {CENTER_X, CENTER_Y + 20}, {CENTER_X + 40, CENTER_Y}, {CENTER_X, CENTER_Y - 20}};
vec2_t diamond_norms[4];
obj_t diamond_data = {diamond_norms, diamond_faces, diamond_verts, 4, 4};

face_t kite_faces[4] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
vec2_t kite_verts[4] = {{CENTER_X - 40, CENTER_Y}, {CENTER_X - 10, CENTER_Y - 20}, {CENTER_X + 50, CENTER_Y}, {CENTER_X - 10, CENTER_Y + 20}};
vec2_t kite_norms[4];
obj_t kite_data = {kite_norms, kite_faces, kite_verts, 4, 4};

// face_t user_faces[8];
// vec2_t user_verts[8];
// vec2_t user_norms[8];
// obj_t user_shape_data = {user_norms, user_faces, user_verts, 0, 0};