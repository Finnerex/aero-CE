#ifndef OBJECTS_H
#define OBJECTS_H

#include "simulation.h"

face_t square_faces[] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
vec2_t square_verts[] = {{CENTER_X - 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y + 20}, {CENTER_X + 20, CENTER_Y - 20}, {CENTER_X - 20, CENTER_Y - 20}};
object_t square = {square_faces, square_verts, 4, 4};

face_t user_faces[8];
vec2_t user_verts[8];
object_t user_shape = {user_faces, user_verts, 0, 0}; 


#endif