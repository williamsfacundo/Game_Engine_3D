#ifndef TRIANGLE_SHAPE_H
#define TRIANGLE_SHAPE_H

#include "Shape.h"

class TriangleShape : public Shape
{
private:
    float positions[6];
    unsigned int indices[3];

    DllExport void  setVertices();
    DllExport void  setIndixs();

public:
    DllExport TriangleShape(glm::vec4 RGBA, glm::vec3 initialPosition);
};

#endif