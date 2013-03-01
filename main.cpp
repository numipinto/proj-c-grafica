/*
 *  main.cpp
 *  Lab0
 *
 *  Created by Afonso Tsukamoto on 2/24/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#define DEBUG

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else 
#include <GL/glut.h>
#endif

#include <iostream>

void myReshape(GLsizei w, GLsizei h);

void myDisplay(void);

void myDisplay2(void);

void myDisplay4(void);

void myReshape3(GLsizei w, GLsizei h);

void myReshape4(GLsizei w, GLsizei h);

GLsizei WIDTH;
GLsizei HEIGHT;


int main(int argc, char** argv){ 
  
	/*Initialization*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow(" Teste"); 
	
	/*Event Registration*/
	
	glutDisplayFunc(myDisplay4);
	glutReshapeFunc(myReshape4);
	glutPostRedisplay();
	
	/*Let it looop mofo!*/
	glutMainLoop();
}





/********** EX. 1 **************/
void myReshape(GLsizei w, GLsizei h){
	
	
	/*glViewport(distance from bottom left display ex,
	             distance from bottom left display ey,
					 width,
	             height);
	*/
	glViewport(0, 0, w, h);
	
	/*The current_matrix pointer is pointing to the projection matrix stack
	 Constants are: 
		GL_PROJECTION
		GL_MODELVIEW
		GL_TEXTURE
	   GL_COLOR
	 Type:GLenum
	*/
	glMatrixMode(GL_PROJECTION);
	
	/*Graphics are based on multiplication of matrixes
	 - if load(or init) was to all zeros, all the multiplications would be zero
	*/
	glLoadIdentity();
	
	
	/*Based on the left hand coordinates system
	 Based on the 'cube', the arguments are:
	 left, right, bottom, top, near , far
	*/
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void myDisplay(void){
	/*Clear de viewport to black
	  Colors must be between 0 and 1
	*/
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	/*glClear(GLbitfield mask);
	  Clears the buffers defined in mask.
	  Mask is a bitwise OR.
	  Constants are:
			GL_COLOR_BUFFER_BIT
			GL_DEPTH_BUFFER_BIT
			GL_STENCIL_BUFFER_BIT
	 */
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*Setting the color to draw.
	  There are one different glColor to each data type allowed
	  OO overload is not suitable for performance purposes
	  Arguments are R,G,B
	*/
	glColor3f(1.0f, 1.0f, 1.0f);
	
	/*Marks the beggining of a list of vertixes
	  The argument sets the type of primitive to be drawn.
	  Constants are: 
			GL_POINTS		  //		GL_LINES
			GL_LINE_STRIP	  //		GL_LINE_LOOP
			GL_TRIANGLES	  //		GL_TRIANGLE_STRIP
			GL_TRIANGLE_FAN  //		GL_QUADS
			GL_QUAD_STRIP	  //		GL_POLYGON
	 */
	glBegin(GL_POLYGON);
		
		/*Analogous to glColor, there are one different glVertex to each data type allowed for the same purposes*/
		glVertex3f (-1.0f, -1.0f, 0.0f);
		glVertex3f (1.0f, -1.0f, 0.0f);
		glVertex3f (1.0f, 1.0f, 0.0f); 
		glVertex3f (-1.0f, 1.0f, 0.0f);
	glEnd();
	
	/*Empties all the commands buffers: Network, graphics accelerator,... */
	glFlush();


}



/*************** EX. 2 *****************/

/* Drawing two rectangles instead of a square */

void myDisplay2(void){
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*First rectangle*/
	glColor3f(0.0f, 1.0f, 0.0f); /*Green*/
	
	glBegin(GL_POLYGON);
	glVertex3f (-1.0f, -1.0f, 0.0f);
	glVertex3f (0.0f, -1.0f, 0.0f);
	glVertex3f (0.0f, 1.0f, 0.0f); 
	glVertex3f (-1.0f, 1.0f, 0.0f);
	glEnd();
	
	/*Second rectangle*/
	glColor3f(1.0f, 0.0f, 0.0f); /*Red*/
	
	glBegin(GL_POLYGON);
	glVertex3f (0.0f, -1.0f, 0.0f);
	glVertex3f (1.0f, -1.0f, 0.0f);
	glVertex3f (1.0f, 1.0f, 0.0f); 
	glVertex3f (0.0f, 1.0f, 0.0f);
	glEnd();
	
	/*Empties all the commands buffers: Network, graphics accelerator,... */
	glFlush();
	
	
}


/********** EX. 3 **************/
void myReshape3(GLsizei w, GLsizei h){
	
	if(h == 0) h = 1;
	GLfloat aspect =(GLfloat)w / (GLfloat)h;
	
	glViewport(0, 0, w, h);
	
	/*The current_matrix pointer is pointing to the projection matrix stack
	 Constants are: 
	 GL_PROJECTION
	 GL_MODELVIEW
	 GL_TEXTURE
	 GL_COLOR
	 Type:GLenum
	 */
	glMatrixMode(GL_PROJECTION);
	
	/*Graphics are based on multiplication of matrixes
	 - if load(or init) was to all zeros, all the multiplications would be zero
	 */
	glLoadIdentity();
	
	
	if (w >= h) {
		// aspect >= 1, set the height from -1 to 1, with larger width
      glOrtho(-2.0f*aspect, 2.0f*aspect, -2.0f, 2.0f, -2.0f, 2.0f);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
		glOrtho(-2.0f, 2.0f, -2.0f/aspect, 2.0f/aspect, -2.0f, 2.0f);
   }
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}


/********** EX. 4 **************/
void drawSquares(GLfloat aspect){
	
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	
	
	if (aspect >= 1) {
      glOrtho(-2.0f*aspect, 2.0f*aspect, -2.0f, 2.0f, -2.0f, 2.0f);
   } else {
		glOrtho(-2.0f, 2.0f, -2.0f/aspect, 2.0f/aspect, -2.0f, 2.0f);
   }
	
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 1.0f, 0.0f); /*Green*/
	
	glBegin(GL_POLYGON);
	glVertex3f (-1.0f, -1.0f, 0.0f);
	glVertex3f (0.0f, -1.0f, 0.0f);
	glVertex3f (0.0f, 1.0f, 0.0f); 
	glVertex3f (-1.0f, 1.0f, 0.0f);
	glEnd();
	
	/*Second rectangle*/
	glColor3f(1.0f, 0.0f, 0.0f); /*Red*/
	
	glBegin(GL_POLYGON);
	glVertex3f (0.0f, -1.0f, 0.0f);
	glVertex3f (1.0f, -1.0f, 0.0f);
	glVertex3f (1.0f, 1.0f, 0.0f); 
	glVertex3f (0.0f, 1.0f, 0.0f);
	glEnd();
	




}








void myDisplay4(void){
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	GLfloat aspect =((GLfloat)WIDTH/2) / (GLfloat)HEIGHT;
	
	glViewport(0, 0, WIDTH/2.0, HEIGHT);
	
	drawSquares(aspect);
	
	glViewport(WIDTH/2.0, 0, WIDTH/2., HEIGHT);
	
	drawSquares(aspect);
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	glFlush();
	
	
}




void myReshape4(GLsizei w, GLsizei h){
	
	if(h == 0) h = 1;
	
	WIDTH = w;
	HEIGHT = h;
}

