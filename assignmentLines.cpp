#include<stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

int Xf, Yf, Xi, Yi;

float Abs(float x)
{
    if(x<0) return x*(-1);
    else return x;
}

void midpointLine(int x0, int y0, int x1, int y1)
{
    int xinc, yinc;
    int dx = (x1-x0);
    int dy = (y1-y0);
    int d = 2*dy - dx;
    int incrE = 2*dy;
    int incrNE = 2*(dy-dx);
    int x=x0;
    int y=y0;
    glVertex2i(x,y);
    if(dx<0) xinc=-1;
    else xinc=1;
    if(dy<0) yinc=-1;
    else yinc=1;
    while(x!=x1)
    {
        if(d<=0) d=d+incrE;
        else
        {
            d=d+incrNE;
            y=y+yinc;
        }
        x=x+xinc;
        glVertex2i(x,y);
    }
}

void bressenham(int x0, int y0, int x1, int y1)
{
    int dx, dy, d, x, y, xinc, yinc;

    dx=(x1-x0);
    dy=(y1-y0);

    x=x0;
    y=y0;

    d=2*dy-dx;

    if(dx<0) xinc=-1;
    else xinc=1;
    if(dy<0) yinc=-1;
    else yinc=1;

    while(x!=x1)
    {
        if(d>=0)
        {
            //printf("%d %d\n",x,y);
            glVertex2i(x,y);
            y=y+yinc;
            d=d+2*dy-2*dx;
        }
        else
        {
            //printf("%d %d\n",x,y);
            glVertex2i(x,y);
            d=d+2*dy;
        }
        x=x+xinc;
    }
}

void dda(int x1, int y1, int x2, int y2)
{
    int len, lenX, lenY, xinc, yinc, x=0, y=0;
    lenX = (x2-x1);
    lenY = (y2-y1);
    if(lenY>lenX) len=lenY;
    else len=lenX;
    xinc = (x2-x1)/len;
    yinc = (y2-y1)/len;
    x = x1;
    y = y1;

    if(lenX<0) xinc=-1;
    else xinc=1;
    if(lenY<0) yinc=-1;
    else yinc=1;

    glVertex2i(x,y);


    int i = 0;
    while(x!=x2)
    {
        //printf("%d %d\n",x,y);
        x=x+xinc;
        y=y+yinc;
        glVertex2i(x,y);
    }
}

//1. triangle different window
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    dda(Xi,Yi,Xf,Yf);
    glEnd();

    glBegin(GL_POINTS);
    bressenham(Xi+100,Yi,Xf+100,Yf);
    glEnd();

    glBegin(GL_POINTS);
    midpointLine(Xi+200,Yi,Xf+200,Yf);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(Xi+300,Yi);
    glVertex2i(Xf+300,Yf);
    glEnd();

    glFlush ();
}

void myDisplayDDA(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    dda(Xi,Yi,Xf,Yf);
    glEnd();
    glFlush ();
}

void myDisplayBressenham(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    bressenham(Xi,Yi,Xf,Yf);
    glEnd();
    glFlush ();
}

void myDisplayMidpoint(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    midpointLine(Xi,Yi,Xf,Yf);
    glEnd();
    glFlush ();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //Background Color and Opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800); //Setting Window Size
    glutInitWindowPosition (200, 150); //Setting Window Position On The Screen

    int choice;

    printf("Enter your choice:\n");
    printf("1. DDA Algorithm\n");
    printf("2. Bressenham\n");
    printf("3. Midpoint\n");
    printf("4. Display all\n");
    printf("5. Exit\n");

    scanf("%d",&choice);
    if(choice==1){
        printf("Enter initial X & Y: ");
        scanf("%d %d",&Xi,&Yi);
        printf("Enter final X & Y: ");
        scanf("%d %d",&Xf,&Yf);
        glutCreateWindow ("Hello World"); //Creating New Window
        glutDisplayFunc(myDisplayDDA);
        myInit ();
        glutMainLoop();
    }
    else if(choice==2){
        printf("Enter initial X & Y: ");
        scanf("%d %d",&Xi,&Yi);
        printf("Enter final X & Y: ");
        scanf("%d %d",&Xf,&Yf);
        glutCreateWindow ("Hello World"); //Creating New Window
        glutDisplayFunc(myDisplayBressenham);
        myInit ();
        glutMainLoop();
    }
    else if(choice==3){
        printf("Enter initial X & Y: ");
        scanf("%d %d",&Xi,&Yi);
        printf("Enter final X & Y: ");
        scanf("%d %d",&Xf,&Yf);
        glutCreateWindow ("Hello World"); //Creating New Window
        glutDisplayFunc(myDisplayMidpoint);
        myInit ();
        glutMainLoop();
    }
    else if(choice==4){
        printf("Enter initial X & Y: ");
        scanf("%d %d",&Xi,&Yi);
        printf("Enter final X & Y: ");
        scanf("%d %d",&Xf,&Yf);
        glutCreateWindow ("Hello World"); //Creating New Window
        glutDisplayFunc(myDisplay);
        myInit ();
        glutMainLoop();
    }
    else if(choice==5){
        return 0;
    }
}
    //glutMainLoop();

