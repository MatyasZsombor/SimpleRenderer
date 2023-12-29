//
// Created by poci on 12/27/23.
//

#include "all_headers.h"
#ifndef RENDERER_HELPERFUNCTIONS_H
#define RENDERER_HELPERFUNCTIONS_H
Vector rotate(Vector v, float a);
Vector multiply(float sc, Vector v);
float distance(float x1, float y1, float x2, float y2);
float magnitude(Vector v);
void normalize(Vector v);
float dot_product(Vector v1, Vector v2);
Vector add(Vector v1, Vector v2);
Vector cross_product(Vector v1, Vector v2);
bool orthogonality(Vector v1, Vector v2);
#endif //RENDERER_HELPERFUNCTIONS_H
