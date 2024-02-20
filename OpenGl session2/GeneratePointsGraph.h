#pragma once
#include <vector>
#include <glad/glad.h>
class GeneratePointsGraph
{
    int numVertices = 1000;
    float h = 0.05f;
    GLfloat x0, x1, y0, y1, z0 = 0.0f;
public:

	GeneratePointsGraph(float a, float b, float c, float d, std::vector<GLfloat>& vector) 
	{
        //posetive
        for (int i = 0; i < numVertices; ++i) {

            x1 = i * h - 32;
            // y1 = a*(x1 * x1) +  b*x1 + c; // Your function here //minste kvadrat
            y1 = a * (x1 * x1 * x1) + b * (x1 * x1) + c * x1 + d; // Your function here //interpolasjon
            vector.push_back(x1);
            vector.push_back(y1);
            vector.push_back(z0);
            vector.push_back(0.0f);
            vector.push_back(1.0f);
            vector.push_back(0.0f);

        }
	};
};

