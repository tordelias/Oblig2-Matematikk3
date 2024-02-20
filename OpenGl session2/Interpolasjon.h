#pragma once
#include <iostream>
#include <glm/glm.hpp>
class Interpolasjon {
    float y0 = 0;
    float x0 = 5;

public:
    Interpolasjon(float x[], float y[], float& a, float& b, float& c, float& d) {
        glm::mat<4, 4, double> A(
            powf(x[0], 3), powf(x[1], 3), powf(x[2], 3), powf(x[3], 3),
            powf(x[0], 2), powf(x[1], 2), powf(x[2], 2), powf(x[3], 2),
            powf(x[0], 1), powf(x[1], 1), powf(x[2], 1), powf(x[3], 1),
            1, 1, 1, 1
        );

        glm::vec4 Y(y[0], y[1], y[2], y[3]);
        glm::vec4 X = glm::inverse(A) * Y;

        y0 = X.x * powf(x0, 3) + X.y * powf(x0, 2) + X.z * x0 + X.w;

        std::cout << "X = " << X.x << " " << X.y << " " << X.z << " " << X.w << std::endl;

        a = X.x;
        b = X.y;
        c = X.z;
        d = X.w;
    }
};


