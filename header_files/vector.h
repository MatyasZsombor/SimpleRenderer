//
// Created by poci on 12/27/23.
//

#ifndef RENDERER_VECTOR_H
#define RENDERER_VECTOR_H
struct Vector {
public:
    double x, y, z;
    explicit Vector(double X = 0, double Y = 0, double Z = 0)
    {
        x = X, y = Y, z = Z;
    }
};
#endif //RENDERER_VECTOR_H
