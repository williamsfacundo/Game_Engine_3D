#ifndef TRIANGLE_SHAPE_H
#define TRIANGLE_SHAPE_H

#include "Shape.h"

class TriangleShape : public Shape
{
private:
    unsigned int _indices[3];
    
    float _positions[6];

    DllExport void  setVertices();
    DllExport void  setIndices();

    DllExport void setIndixs();
    DllExport void calculateVertices();
public:    

    DllExport TriangleShape(glm::vec4 RGBA, glm::vec3 initialPosition);
};

#endif