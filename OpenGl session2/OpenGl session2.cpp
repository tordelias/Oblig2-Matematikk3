

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"
#include "Cube.h"
#include"GeneratePointsGraph.h"
#include "LSM.h"
#include "Interpolasjon.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);






// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

std::vector<GLfloat> flattenVertices(std::vector<Vertex> mvert) {
    std::vector<GLfloat> flattenedVertices;
    for (const Vertex& vertex : mvert) {
        flattenedVertices.push_back(vertex.x);
        flattenedVertices.push_back(vertex.y);
        flattenedVertices.push_back(vertex.z);
        flattenedVertices.push_back(vertex.r);
        flattenedVertices.push_back(vertex.g);
        flattenedVertices.push_back(vertex.b);
    }
    return flattenedVertices; 
}





int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




    // glfw window creation
// --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
   // ------------------------------------
    ShaderClass shaderProgram("VertexShader.vert", "FragmentShader.frag");



    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    //Circle 
    //std::vector<GLfloat> circleVertices;
    //GLfloat radius = 0.5f;
    //GLfloat twoPi = 2.0f * 3.14159f;
    //for (GLfloat i = 0; i <= twoPi; i += 0.1) {
    //    circleVertices.push_back(cos(i) * radius);
    //    circleVertices.push_back(sin(i) * radius);
    //    circleVertices.push_back(0.0f);
    //    circleVertices.push_back(0.0f);
    //    circleVertices.push_back(1.0f);
    //    circleVertices.push_back(0.0f);
    //}

    //sphere V=4/3 * pi * r^3 A=4 * pi * r^2
 //   std::vector<GLfloat> sphereVertices;
 //   for (float i = 0; i <= twoPi; i += 0.1) {
 //       for (float j = 0; j <= twoPi; j += 0.1) {
	//		sphereVertices.push_back(cos(i) * cos(j));
	//		sphereVertices.push_back(sin(i) * cos(j));
	//		sphereVertices.push_back(sin(j));
	//		sphereVertices.push_back(0.0f);
	//		sphereVertices.push_back(1.0f);
	//		sphereVertices.push_back(0.0f);
	//	}
	//}

 
    float a = 0.0f, b = 0.0f, c = 0.0f, d = 0.0f;

    //Interpolasjon
    Interpolasjon interpol(new float[4]{ 1,2,3,4 }, new float[4]{ 1,2,3,4 }, a, b, c, d);


    GLfloat Points[] = 
    {
        1.f, 1.f, 0.f, 1.f, 0.f, 0.f,
        2.f, 2.f, 0.f, 1.f, 0.f, 0.f,
		3.f, 3.f, 0.f, 1.f, 0.f, 0.f,
		4.f, 4.f, 0.f, 1.f, 0.f, 0.f
    };
 
    //minsteKvadrat
    //LSM lsm(b, c, d);

    std::vector<GLfloat> vertices;
    //generate cordinates for the graph
    GeneratePointsGraph graph(a, b, c, d, vertices);
/*
    GLfloat Points[] = {
        2.f, 1.f, 0.f , 1.0f, 0.0f, 0.0f,
        2.f, 3.f, 0.f , 1.0f, 0.0f, 0.0f,
        4.f, 2.f, 0.f , 1.0f, 0.0f, 0.0f,
        4.f, 5.f, 0.f , 1.0f, 0.0f, 0.0f,
        6.f, 5.f, 0.f , 1.0f, 0.0f, 0.0f,
        6.f, 7.f, 0.f , 1.0f, 0.0f, 0.0f,
        8.f, 7.f, 0.f , 1.0f, 0.0f, 0.0f,
        8.f, 9.f, 0.f , 1.0f, 0.0f, 0.0f
    };*/  



  //  Cube cube(1.0f); 
  //std::vector<GLfloat> vertices =  flattenVertices(cube.mVertecies); 
   //std::vector<GLfloat> vertices = sphereVertices;


    //unsigned int indices[] = {
    //    0, 1, 2, // first triangle
    //    2, 3, 0  // second triangle
    //};


    VAO VAO1;
    VAO VAO2;
    VAO1.Bind();
    VAO2.Bind();

    VBO VBO1(vertices.data(), vertices.size() * sizeof(GLfloat));
 
    VBO VBO2(Points,  sizeof(Points));

    //EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // For position
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // For color

    VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // For position
    VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // For color


    VAO1.Unbind();
    VBO1.Unbind();

    VAO2.Unbind();
    VBO2.Unbind();


    //camera 
    Camera camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));


    glEnable(GL_DEPTH_TEST);


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




        //color
    /*    float timeValue = glfwGetTime(); 
        float GreenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram.ID, "OurColor");*/

        // draw our first triangle
        shaderProgram.Activate();

        //camera
        camera.inputs(window); 
        camera.matrix(45.f, 0.1f, 100.0f, shaderProgram, "camMatrix");


        glUniform4f(0, 0.0f, 1, 0.0f, 1.0f);
        VAO1.Bind(); 
        glDrawArrays(GL_LINE_STRIP, 0, vertices.size());

       // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_LINES, 0, 3);
       VAO1.Unbind();

       VAO2.Bind();
       //draw
       glPointSize(20);
       glDrawArrays(GL_POINTS, 0, sizeof(Points));
       VAO2.Unbind();


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
   VAO1.Delete();
    VBO1.Delete();

    VAO2.Delete();
    VBO2.Delete();
    //EBO1.Unbind();
    //EBO1.Delete();
   shaderProgram.DeleteShader();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    //if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    //    std::cout << "A key pressed ..." << std::endl;
    //}
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    std::cout << " windows resized with " << width << " Height " << height << std::endl;
}



