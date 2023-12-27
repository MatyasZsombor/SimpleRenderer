//
// Created by poci on 12/27/23.
//

#include "all_headers.h"
#ifndef RENDERER_HELPERFUNCTIONS_H
#define RENDERER_HELPERFUNCTIONS_H
double magnitude(Vector v);
void normalize(Vector v);
double dot_product(Vector vs[], int n);
Vector add(Vector vs[], int n);
Vector cross_product(Vector v1, Vector v2);
bool orthogonality(Vector v1, Vector v2);
#endif //RENDERER_HELPERFUNCTIONS_H
