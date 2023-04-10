/*#ifndef TRIANGLE_SHAPE_H
#define TRIANGLE_SHAPE_H

#include "Entity2d.h"

class TriangleShape : public Entity2d
{
private:
    unsigned int _indices[3];
    
    float _positions[6];

    DllExport void setPositions();

    DllExport void setVertices();

    DllExport void setIndices();   
    
public:    

    DllExport TriangleShape(glm::vec4 RGBA);
};

#endif*/