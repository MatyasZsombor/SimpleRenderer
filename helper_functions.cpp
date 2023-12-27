//
// Created by poci on 12/27/23.
//
#include "header_files/all_headers.h"

double magnitude(Vector v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

void normalize(Vector v)
{
    double mag = magnitude(v);
    v.x = v.x / mag;
    v.y = v.y / mag;
    v.z = v.z / mag;
}

double dot_product(Vector vs[], int n)
{
    double res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        res += vs[i].x * vs[i + 1].x + vs[i].y * vs[i + 1].y + vs[i].z * vs[i + 1].z;
    }
    return res;
}

Vector add(Vector vs[], int n)
{
    Vector res;
    for (int i = 0; i < n; i++)
    {
        res.x += vs[i].x;
        res.y += vs[i].y;
        res.z += vs[i].z;
    }
    return res;
}

Vector cross_product(Vector v1, Vector v2)
{
    Vector res;
    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
}

bool orthogonality(Vector v1, Vector v2)
{
    Vector vs[] = {v1, v2};
    return dot_product(vs, 2) == 0;
}