#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "glm/glm.hpp"

#include "DDLExport.h"

class CollisionManager
{
public:
	DllExport static bool IntersectPolygons(glm::vec3 verticesA[], int sizeA, glm::vec3 verticesB[], int sizeB, glm::vec3& normal, double& depth);

	DllExport static void ProjectVertices(glm::vec3 vertices[], int size, glm::vec3 axis, double& min, double& max);

	DllExport static glm::vec3 FindArithmeticMean(glm::vec3 vertices[], int size);
};

#endif