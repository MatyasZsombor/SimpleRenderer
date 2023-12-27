//
// Created by poci on 12/27/23.
//
#include "header_files/all_headers.h"

void multiply(float sc, Vector v)
{
    v.x *= sc;
    v.y *= sc;
    v.z *= sc;
}

float distance(float x1, float y1, float x2, float y2)
{
    return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
}

float magnitude(Vector v)
{
    return sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
}

void normalize(Vector v)
{
    float mag = magnitude(v);
    v.x = v.x / mag;
    v.y = v.y / mag;
    v.z = v.z / mag;
}

float dot_product(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector add(Vector v1, Vector v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector cross_product(Vector v1, Vector v2)
{
    Vector res;
    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
    return res;
}

bool orthogonality(Vector v1, Vector v2)
{
    return dot_product(v1, v2) == 0;
}