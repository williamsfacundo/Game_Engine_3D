#pragma once

#include "Shape.h"

class RectangleShape : public Shape
{

private:


    int width, height;
    float positions[8];
    unsigned int indices[6];

    DllExport void  setVertices();
    DllExport void  setIndixs();
    DllExport void calculateVertices();

public:
    
    DllExport RectangleShape(glm::vec3 initialPosition);

    DllExport void setColor(glm::vec4 RGBA);

};

