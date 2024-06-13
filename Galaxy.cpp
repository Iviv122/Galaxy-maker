#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime> 
void drawSphere(float xcord, float zcord, float radius);
void drawOrbit(float angle,float r);

int planets_ = 12;

int main(void){

	float planets[planets_*2];

    std::srand(static_cast<unsigned int>(std::time(0)));

	for(int i=0;i<planets_*2;i+=2){
	float r = static_cast <float> (rand()) / static_cast <float >(RAND_MAX/(5));	
	float r2 = static_cast <float> (rand()) / static_cast <float >(RAND_MAX/(5));

	planets[i] = r;
	planets[i-1] = r2;

	std::cout << planets[i] << "\n";
	}


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) // While loop start 
    {
        glClear(GL_COLOR_BUFFER_BIT);

	glRotatef(1,0,1,1);

	glPushMatrix();
	glScalef(0.1,0.1,0.1);
		
	drawSphere(0,0,0.5);
	
	for(int i=0; i<planets_;i++){	
		drawSphere((2.5-planets[i])*3,(2.5-planets[i+1])*3,(2.5-planets[i])/3);
	}
	for(float i=0;i<15;i+=0.5){
	drawOrbit(-45,i);
	}

	glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    } 					// While loop end

    glfwTerminate();
    return 0;
}

void drawSphere(float xcord, float zcord, float radius){
	glPushMatrix();
	glTranslatef(xcord,0,zcord);
	for(int i=0;i<=360;i+=3){
		glRotatef(1*i, 0,1,0);
		for(int j=0;j<=360;j+=5){
			glPushMatrix();
			glRotatef(1*j,0,0,1);
			glBegin(GL_POINTS);
			glVertex3f(0,radius,0);
			glEnd();
			glPopMatrix();
		}
	}
	glPopMatrix();
}
void drawOrbit(float angle,float r){
	glPushMatrix();
	glRotatef(180+angle,1,1,1);
	glPushMatrix();
	for(float i=0;i<=360;i+=0.5){
	glRotatef(1*i,1,0,0);
	glBegin(GL_POINTS);
	glVertex3f(0,r,0);
	glEnd();
	}
	glPopMatrix();
	glPopMatrix();
}	
