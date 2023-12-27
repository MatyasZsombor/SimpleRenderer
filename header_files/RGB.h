//
// Created by poci on 12/27/23.
//

#ifndef RENDERER_RGB_H
#define RENDERER_RGB_H
struct RGB{
public:
    float red, green, blue;
    explicit RGB(float r = 0, float g = 0, float b = 0)
    {
        red = r;
        green = g;
        blue = b;
    }
    void divide(float d);
};
#endif //RENDERER_RGB_H
