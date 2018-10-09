#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>



void myDisplayBatman(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glPointSize(5.0);


int i=0;
int j=0;
for(int x=0;x<660;x+=20){

        //printf("\n%d\n",j);
    for(int y=0;y<480;y+=20){
        i++;
        //printf("%d ",i);
        //2nd column
        if((i>32 && i<40) || (i>752 && i<760)){
            glColor3f(0.0,0.0,0.0);
        }
        else if(j==2 || j==32-2){ //3rd
            if(i==j*24+8 || i==j*24+16){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+8 && i<j*24+16){
                    glColor3f(1.0,1.0,0.0);
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if(j==3 || j==32-3){ //3rd
            if(i==j*24+7 || i==j*24+17){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+7 && i<j*24+17){
                    glColor3f(1.0,1.0,0.0);
                    if(i>j*24+9 && i<j*24+15){
                        glColor3f(0.0,0.0,0.0);
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if(j==4 || j==32-4){
            if(i==j*24+6 || i==j*24+18){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+6 && i<j*24+18){
                    glColor3f(1.0,1.0,0.0);
                    if(i>j*24+8 && i<j*24+16){
                        glColor3f(0.0,0.0,0.0);
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if(j==5 || j==32-5){
            if(i==j*24+5 || i==j*24+19){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+5 && i<j*24+19){
                    glColor3f(1.0,1.0,0.0);
                    if(i>j*24+7 && i<j*24+17){
                        glColor3f(0.0,0.0,0.0);
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if(j==6 || j==32-6){
            if(i==j*24+4 || i==j*24+20){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+4 && i<j*24+20){
                    glColor3f(1.0,1.0,0.0);
                    if(i>j*24+6 && i<j*24+18){
                        glColor3f(0.0,0.0,0.0);
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if(j==7 || j==32-7){
            if(i==j*24+3 || i==j*24+21){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+3 && i<j*24+21){
                    glColor3f(1.0,1.0,0.0);
                    if(i>j*24+5 && i<j*24+19){
                        glColor3f(0.0,0.0,0.0);
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else if((j>7) && (j<32-7)){
            if(i==j*24+2 || i==j*24+22){
                    glColor3f(0.0,0.0,0.0);
            }
            else if(i>j*24+2 && i<j*24+22){ //big yellow, critical designs, between highest and lowest black grids, designs will be put here, from the 113th line
                    glColor3f(1.0,1.0,0.0);
                    printf("\n%d\n",j);
                    if(j==8 || j==9 || j==23 || j==24){
                        if(i>j*24+4 && i<j*24+20){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==10 || j==22){
                        if(i>j*24+4 && i<j*24+21){
                            glColor3f(0.0,0.0,0.0);
                            if(i>j*24+5 && i<j*24+9){
                                glColor3f(1.0,1.0,0.0);
                            }
                        }
                    }
                    else if(j==11 || j==21){
                        if(i>j*24+9 && i<j*24+19){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==12 || j==20){
                        if(i>j*24+9 && i<j*24+18){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==13 || j==19){
                        if(i>j*24+8 && i<j*24+17){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==14 || j==18){
                        if(i>j*24+3 && i<j*24+18){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==15 || j==17){
                        if(i>j*24+4 && i<j*24+20){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
                    else if(j==16){
                        if(i>j*24+4 && i<j*24+21){
                            glColor3f(0.0,0.0,0.0);
                        }
                    }
            }
            else{
                glColor3f(1.0,1.0,1.0);
            }
        }
        else{
            glColor3f(1.0,1.0,1.0);
        }

        glBegin(GL_QUADS);
            glVertex2i(x+0,y+0);
            glVertex2i(x+20,y+0);
            glVertex2i(x+20,y+20);
            glVertex2i(x+0,y+20);
            glEnd();
    }
    j++;

}

glFlush ();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluOrtho2D(0.0, 660.0, 480.0, 0.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_MULTISAMPLE | GLUT_RGB);
glutInitWindowSize (660, 480);
glutInitWindowPosition (0, 0);

glutCreateWindow ("my Bat attempt");
glutDisplayFunc(myDisplayBatman);

myInit ();
glutMainLoop();
}
