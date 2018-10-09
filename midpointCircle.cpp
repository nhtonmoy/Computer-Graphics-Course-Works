#include<stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

int a=0,b=0;

void draw(int x, int y)
{
    glVertex2i(x+a,y+b);
    glVertex2i(x+a,-y+b);
    glVertex2i(-x+a,y+b);
    glVertex2i(-x+a,-y+b);
    glVertex2i(y+a,x+b);
    glVertex2i(y+a,-x+b);
    glVertex2i(-y+a,x+b);
    glVertex2i(-y+a,-x+b);

}

void midpointCircle(int R)
{
    int x=0, y=R;

    float decision=1-R;
    printf("%f\n",decision);
    glVertex2i(x,y);
    while(y>x)
    {
        draw(x,y);
        if(decision<0)
        {
            printf("%d %d\n",x,y);

            decision=decision+2*x+3;
            x++;
        }
        else
        {
            printf("%d %d\n",x,y);

            decision=decision+(2*(x-y))+5;
            y--;x++;
        }
    }
    printf("%d %d\n",x,y);
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    midpointCircle(350);
    glEnd();

    glFlush ();
}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //Background Color and Opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800); //Setting Window Size
    glutInitWindowPosition (200, 150); //Setting Window Position On The Screen

    glutCreateWindow ("Hello World"); //Creating New Window
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();

}
