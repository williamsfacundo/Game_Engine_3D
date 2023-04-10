#ifndef RECTANGLE_SHAPE_H
#define RECTANGLE_SHAPE_H

#include "Entity2d.h"

class RectangleShape : public Entity2d
{
private:
    int _width; 
    int _height;

    float _positions[8];

    unsigned int _indices[6];        

    DllExport void setVertices();

    DllExport void setIndices();

public:    
    DllExport RectangleShape();

    DllExport void setColor(vec4 RGBA);
};

#endif