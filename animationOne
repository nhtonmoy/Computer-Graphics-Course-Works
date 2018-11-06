#include<GL/gl.h>
#include<GL/glut.h>
float transFactor = 0.0f;
float getX(int val)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    float frac = (float)val/((float)width/2);
    return frac;
}
float getY(int val)
{
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    float frac = (float)val/((float)height/2);
    return frac;
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glBegin(GL_QUADS);
            glColor3ub(0,0,255);
            glVertex2f(getX(-400),getY(-400));
            glVertex2f(getX(-400),getY(-80));
            glVertex2f(getX(400),getY(-80));
            glVertex2f(getX(400),getY(-400));
    glEnd();

    glColor3ub(255,0,0);
    glPushMatrix();
        glTranslatef(transFactor,0,0);
        glBegin(GL_QUADS);//main body
            glVertex2f(getX(-100),getY(-50));
            glVertex2f(getX(-200),getY(-100));
            glVertex2f(getX(-300),getY(-100));
            glVertex2f(getX(-400),getY(-50));
        glEnd();

        glBegin(GL_QUADS); //1st pillar
            glVertex2f(getX(-350),getY(-50));
            glVertex2f(getX(-350),getY(10));
            glVertex2f(getX(-330),getY(10));
            glVertex2f(getX(-330),getY(-50));
        glEnd();


        glBegin(GL_QUADS); //1st pillar's smoke 1
            glVertex2f(getX(-350),getY(40));
            glVertex2f(getX(-350),getY(20));
            glVertex2f(getX(-330),getY(20));
            glVertex2f(getX(-330),getY(40));
        glEnd();
        glBegin(GL_QUADS); //1st pillar's smoke 2
            glVertex2f(getX(-350+20),getY(70));
            glVertex2f(getX(-350+20),getY(50));
            glVertex2f(getX(-330+20),getY(50));
            glVertex2f(getX(-330+20),getY(70));
        glEnd();
        glBegin(GL_QUADS); //1st pillar's smoke 3
            glVertex2f(getX(-350+40),getY(100));
            glVertex2f(getX(-350+40),getY(80));
            glVertex2f(getX(-330+40),getY(80));
            glVertex2f(getX(-330+40),getY(100));
        glEnd();

        glBegin(GL_QUADS); //2nd pillar
            glVertex2f(getX(-270),getY(-50));
            glVertex2f(getX(-270),getY(10));
            glVertex2f(getX(-250),getY(10));
            glVertex2f(getX(-250),getY(-50));
        glEnd();

        glBegin(GL_QUADS); //2nd pillar's smoke 1
            glVertex2f(getX(-270),getY(40));
            glVertex2f(getX(-270),getY(20));
            glVertex2f(getX(-250),getY(20));
            glVertex2f(getX(-250),getY(40));
        glEnd();
        glBegin(GL_QUADS); //2nd pillar's smoke 2
            glVertex2f(getX(-270+20),getY(70));
            glVertex2f(getX(-270+20),getY(50));
            glVertex2f(getX(-250+20),getY(50));
            glVertex2f(getX(-250+20),getY(70));
        glEnd();
        glBegin(GL_QUADS); //2nd pillar's smoke 3
            glVertex2f(getX(-270+40),getY(100));
            glVertex2f(getX(-270+40),getY(80));
            glVertex2f(getX(-250+40),getY(80));
            glVertex2f(getX(-250+40),getY(100));
        glEnd();

        glBegin(GL_QUADS); //3rd pillar
            glVertex2f(getX(-190),getY(-50));
            glVertex2f(getX(-190),getY(10));
            glVertex2f(getX(-170),getY(10));
            glVertex2f(getX(-170),getY(-50));
        glEnd();

        glBegin(GL_QUADS); //3rd pillar's smoke 1
            glVertex2f(getX(-190),getY(40));
            glVertex2f(getX(-190),getY(20));
            glVertex2f(getX(-170),getY(20));
            glVertex2f(getX(-170),getY(40));
        glEnd();
        glBegin(GL_QUADS); //3rd pillar's smoke 2
            glVertex2f(getX(-190+20),getY(70));
            glVertex2f(getX(-190+20),getY(50));
            glVertex2f(getX(-170+20),getY(50));
            glVertex2f(getX(-170+20),getY(70));
        glEnd();
        glBegin(GL_QUADS); //3rd pillar's smoke 3
            glVertex2f(getX(-190+40),getY(100));
            glVertex2f(getX(-190+40),getY(80));
            glVertex2f(getX(-170+40),getY(80));
            glVertex2f(getX(-170+40),getY(100));
        glEnd();

    glPopMatrix();

    glutSwapBuffers();

}
void update(int value)
{
    transFactor+=0.01f;
    if(transFactor>getX(glutGet(GLUT_WINDOW_WIDTH)))
       transFactor = -1 * getX(100 * 2);
    glutPostRedisplay();
    glutTimerFunc(20,update,0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutTimerFunc(20,update,0);
	glutMainLoop();
	return 0;
}
