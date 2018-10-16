#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int xp[100], yp[100], total, tfx, tfy, dx[100], dy[100];
float sfx, sfy;

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(5.0);


    glBegin(GL_POLYGON);
    for(int i=0;i<total;i++)
    {
        glVertex2i(xp[i],yp[i]);
        printf("original: %d %d\n",xp[i],yp[i]);
    }
    glEnd();

    glFlush ();
}

void myDisplayTranslation(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(5.0);
    int newX, newY;


    glBegin(GL_POLYGON);
    for(int i=0;i<total;i++)
    {

        newX=dx[i]+tfx;
        newY=dy[i]+tfy;
        glVertex2i(newX,newY);
        printf("translate: %d %d\n",dx[i],dy[i]);
    }
    glEnd();

    glFlush ();
}

void myDisplayScaling(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(5.0);
    float newX, newY;


    glBegin(GL_POLYGON);
    for(int i=0;i<total;i++)
    {

        newX=(float)dx[i]*sfx;
        newY=(float)dy[i]*sfy;
        glVertex2i(newX,newY);
        printf("translate: %d %d\n",dx[i],dy[i]);
    }
    glEnd();

    glFlush ();
}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-200.0, 600.0, -200.0, 600.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_MULTISAMPLE | GLUT_RGB);
glutInitWindowSize (800, 800);
glutInitWindowPosition (0, 0);

int choice;
printf("Enter your choice:\n");
printf("\n1. Translation\n2. Scaling\n3. Exit\n");
scanf("%d",&choice);

printf("Enter the no. of edges:-");
scanf("%d",&total);
for(int i=0; i<total; i++)
{
    printf("Enter the co-ordinates of vertex %d:-",i+1);
    scanf("%d %d",&xp[i] ,&yp[i]);
    dx[i]=xp[i];
    dy[i]=yp[i];
}


if(choice==1)
{
    printf("Enter the Translation factor for x and y: ");
    scanf("%d %d",&tfx, &tfy);

    glutCreateWindow ("Original");
    glutDisplayFunc(myDisplay);
    myInit ();

    glutCreateWindow("Translation");
    glutDisplayFunc(myDisplayTranslation);
    myInit ();
}
else if(choice==2)
{
    printf("Enter the Scaling factor for x and y: ");
    scanf("%f %f",&sfx,&sfy);

    glutCreateWindow ("Original");
    glutDisplayFunc(myDisplay);
    myInit ();

    glutCreateWindow("Scaling");
    glutDisplayFunc(myDisplayScaling);
    myInit ();
}

glutMainLoop();
}
