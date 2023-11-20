#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

double windowWidth=700,windowHeight=700;
void Rectangular()
{
    glBegin(GL_QUADS);
    glColor3f(0.5,.5,.8);

    glVertex2f(.8,0);
    glVertex2f(1.5,0);
    glVertex2f(1.8,2.5);
    glVertex2f(0.8,2.5);

    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-3,3,-3,3);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glViewport(0, 0,windowWidth,windowHeight);
    Rectangular();
    glFlush();
    glutSwapBuffers();
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300,300);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Rectangular");
    glShadeModel( GL_SMOOTH );
    glEnable(GL_DEPTH_TEST );
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
