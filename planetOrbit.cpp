#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
using namespace std;
void update(int);
float _angle1 = 0.0f;
float _angle2 = 0.0f;
float speed = 0.0f;
float speed1 = 0.0f;
float savedSpeed = 0.0f;
float savedSpeed1 = 0.0f;
bool paused = false;
char text[] = "VENUS";
char text1[] = "NEPTUNE";

char t[] = "End";


//Print
void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,1.0,0.7);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }


}/*
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
*/
void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          speed+=0.05f;
          update(0);
          break;
      case GLUT_KEY_DOWN:
          speed-=0.05f;
          update(0);
          break;
      case GLUT_KEY_RIGHT:
          speed1+=0.1f;
          update(0);
      case GLUT_KEY_LEFT:
          speed1-=0.05f;
          update(0);

    }
}
void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
   }
}
void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
      paused = !paused;         // Toggle state
      if (paused) {
         savedSpeed = speed;  // Save parameters for restore later
         savedSpeed1 = speed1;
         speed = 0;            // Stop movement
         speed1=0;

      } else {
         speed = savedSpeed;  // Restore parameters
         speed1 = savedSpeed1;

      }
   }
}
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);


   // glRotatef(_angle, 1.0f, 0.0f, 0.0f); //Rotate the camera
///////////////////// Earth-thinOrbit ///////////////////////////
    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(0.0,1.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

///////////////////// Earth-thickOrbit ///////////////////////////
    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle2, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.8, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(0.5,0.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///////////////////// Orbit-thin ///////////////////////////
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

///////////////////// Orbit-thick ///////////////////////////
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

///////////////////// SUN ///////////////////////////

    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glutSolidSphere(.3,50,50);
        Sprint(.4,0,text);
    glPopMatrix();
    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glutSolidSphere(.3,50,50);
        Sprint(.75,0,text1);
    glPopMatrix();

    /*glPushMatrix();
        Sprint(.9,.9,text);
    glPopMatrix();
*/
	glutSwapBuffers();
}

void update(int value) {
    if(speed>1 || speed<0)
    {
        //cout<<speed<<endl;
        speed = 0.0f;
    }
    if(speed1>1 || speed1<0)
    {
        //cout<<speed<<endl;
        speed1 = 0.0f;
    }
	_angle1 += speed;
	_angle2 -= speed1;
	if (_angle1 < 360) {
		_angle1 += 360;
	}
	if (_angle2 < 360) {
		_angle2 += 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	//Create the window
	glutCreateWindow("Transformation");

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboard);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
