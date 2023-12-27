//
// Created by poci on 12/27/23.
//

#ifndef RENDERER_VECTOR_H
#define RENDERER_VECTOR_H
struct Vector {
public:
    float x, y, z;
    explicit Vector(float X = 0, float Y = 0, float Z = 0)
    {
        x = X, y = Y, z = Z;
    }
};
#endif //RENDERER_VECTOR_H
