#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
class LSM
{
public:
    LSM(float& a, float& b, float& c)
    {
        // x = BInverse * ATy  B= AT * A, C= AT * Y
        // // variables
        // //glm::mat3x2 A(1,1,2,1,4,1);
        // //glm::vec3 Y(0.5, 0, 1);
        // //glm::mat2x3 AT = glm::transpose(A);


        glm::vec3 C(236, 243, 39);
        glm::mat<3, 3, double> B(240, 236, 40, 236, 243, 39, 40, 39, 8);
        glm::mat<3, 3, double> BInverse = glm::inverse(B);
        glm::vec<3, double> X = C * BInverse;

        a = X.x;
        b = X.y;
        c = X.z;

        std::cout << "X = " << X.x << " " << X.y << " " << X.z << std::endl;

    };
};
