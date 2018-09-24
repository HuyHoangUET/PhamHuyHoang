#include <windows.h>
#include <cstdio>
#include "GL/glut.h"
#include "GL/glext.h"
const float ROTATE_SPEED = 0.05;
float rotation = 0;
float rotating = true;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotation, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5,  0.5);
    glVertex2f(0.5,  0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        rotating = !rotating;
        printf("click");
    }
}

void increateRotation(void) {
    if (rotating) {
        rotation += ROTATE_SPEED;
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initGL() {

    glEnable(GL_MULTISAMPLE);

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("cg-lab");

    glutDisplayFunc(displayMe);
    glutIdleFunc(increateRotation);
    glutMouseFunc(mouse);

    initGL();

    glutMainLoop();

    return 0;
}
