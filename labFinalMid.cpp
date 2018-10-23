#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>



void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glPointSize(5.0);


int i=0;
int j=0;

for(int x=0;x<600;x+=20)
{
    for(int y=0;y<240;y+=20)
    {
        i++;
        //printf("%d ",i);
        if((j>=0 && j<7))
        {
            if(i>j*12-1 && i<j*12+7)
            {
                //printf("%d ",i);
                glColor3f(0.97,0.88,0.03);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        //||(j>=12 && j<19)||(j>=24 && j<29)
        if((i>25&&i<36)||(i>37&&i<48))
        {
            glColor3f(0.0,0.0,0.0);
        }
        else if(j==20 || j==27)
        {
            if(i>j*12+1 && i<j*12+10)
            {
                //printf("1");
                glColor3f(0.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==21 || j==26)
        {
            if(i>j*12+1 && i<j*12+11)
            {
                //printf("1");
                glColor3f(0.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==22 || j==25)
        {
            if(i>j*12+8 && i<j*12+12)
            {
                //printf("1");
                glColor3f(0.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==23 || j==24)
        {
            if(i>j*12+9 && i<j*12+12)
            {
                //printf("1");
                glColor3f(0.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==8 || j==17)
        {
            if(i>j*12+2 && i<j*12+8)
            {
                //printf("%d\n",i);
                //printf("1");
                glColor3f(1.0,0.0,0.0);
            }

            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==9 || j==16)
        {
            if(i>j*12+1 && i<j*12+9)
            {
                //printf("1");
                glColor3f(1.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==10 || j==15)
        {
            if(i>j*12+1 && i<j*12+10)
            {
                //printf("1");
                glColor3f(1.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==11 || j==14)
        {
            if(i>j*12+1 && i<j*12+11)
            {
                //printf("1");
                glColor3f(1.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }
        else if(j==12 || j==13)
        {
            if(i>j*12+2 && i<j*12+12)
            {
                //printf("1");
                glColor3f(1.0,0.0,0.0);
            }
            else
            {
                glColor3f(1.0,1.0,0.0);
            }
        }

//        else{//background
//            glColor3f(1.0,1.0,0.0);
//        }
        if(i==112 || i==123)
        {
            glColor3f(1.0,1.0,1.0);
        }

        glBegin(GL_QUADS);
        glVertex2i(x+0,y+0);
        glVertex2i(x+20,y+0);
        glVertex2i(x+20,y+20);
        glVertex2i(x+0,y+20);
        glEnd();
    }
    //printf("\n%d\n",j);
    j++;

}

glFlush ();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 0.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluOrtho2D(0.0, 600.0, 240.0, 0.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_MULTISAMPLE | GLUT_RGB);
glutInitWindowSize (600, 240);
glutInitWindowPosition (0, 0);

glutCreateWindow ("attempt");
glutDisplayFunc(myDisplay);

myInit ();
glutMainLoop();
}
