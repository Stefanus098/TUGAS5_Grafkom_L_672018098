#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


int is_depth;
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(200, 40);
    glutCreateWindow("Abyarake Adiyoga - 672018098");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(65/255.0f, 255/255.0f, 225/255.0f, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(2.0f);
}

void myinit()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    //DEPAN
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 227/255.0f, 200/255.0f);
    glVertex3f(-50.0, -25.0, 15.0);
    glVertex3f(-50.0, 15.0, 15.0);
    glVertex3f(20.0, 15.0, 15.0);
    glVertex3f(20.0, -25.0, 15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(222/255.0f, 184/255.0f, 135/255.0f);
    glVertex3f(20.0, 15.0, 15.0);
    glVertex3f(20.0, -25.0, 15.0);
    glVertex3f(20.0, -25.0, 40.0);
    glVertex3f(20.0, 15.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 227/255.0f, 200/255.0f);
    glVertex3f(20.0, -25.0, 40.0);
    glVertex3f(20.0, 15.0, 40.0);
    glVertex3f(50.0, 15.0, 40.0);
    glVertex3f(50.0, -25.0, 40.0);
    glEnd();

    //SAMPING
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 227/255.0f, 200/255.0f);
    glVertex3f(50.0, 15.0, 40.0);
    glVertex3f(50.0, -25.0, 40.0);
    glVertex3f(50.0, -25.0, -40.0);
    glVertex3f(50.0, 15.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 227/255.0f, 200/255.0f);
    glVertex3f(-50.0, 15.0, -40.0);
    glVertex3f(-50.0, -25.0, -40.0);
    glVertex3f(-50.0, -25.0, 15.0);
    glVertex3f(-50.0, 15.0, 15.0);
    glEnd();

    //LEMARI
    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(49.0, 5.0, 20.0);
    glVertex3f(49.0, -25.0, 20.0);
    glVertex3f(44.0, -25.0, 20.0);
    glVertex3f(44.0, 5.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(49.0, 5.0, 20.0);
    glVertex3f(44.0, 5.0, 20.0);
    glVertex3f(44.0, 5.0, 5.0);
    glVertex3f(49.0, 5.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(49.0, 5.0, 5.0);
    glVertex3f(49.0, -25.0, 5.0);
    glVertex3f(44.0, -25.0, 5.0);
    glVertex3f(44.0, 5.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(44.0, -25.0, 20.0);
    glVertex3f(44.0, 5.0, 20.0);
    glVertex3f(44.0, 5.0, 5.0);
    glVertex3f(44.0, -25.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(49.0, -25.0, 20.0);
    glVertex3f(49.0, 5.0, 20.0);
    glVertex3f(49.0, 5.0, 5.0);
    glVertex3f(49.0, -25.0, 5.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(48.5, -24.5, 20.0);
    glVertex3f(48.5, 4.5, 20.0);
    glVertex3f(48.5, 4.5, 5.0);
    glVertex3f(48.5, -24.5, 5.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(48.5, -24.5, 12.5);
    glVertex3f(48.5, 4.5, 12.5);
    glEnd();

    //BELAKANG
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 227/255.0f, 200/255.0f);
    glVertex3f(50.0, -25.0, -40.0);
    glVertex3f(50.0, 15.0, -40.0);
    glVertex3f(-50.0, 15.0, -40.0);
    glVertex3f(-50.0, -25.0, -40.0);
    glEnd();

    //AC
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.0, 13.0, -40.0);
    glVertex3f(20.0, 13.0, -35.0);
    glVertex3f(-10.0, 13.0, -35.0);
    glVertex3f(-10.0, 13.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.0, 13.0, -40.0);
    glVertex3f(20.0, 13.0, -35.0);
    glVertex3f(20.0, 5.0, -35.0);
    glVertex3f(20.0, 5.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.0, 5.0, -40.0);
    glVertex3f(20.0, 5.0, -35.0);
    glVertex3f(-10.0, 5.0, -35.0);
    glVertex3f(-10.0, 5.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10.0, 13.0, -40.0);
    glVertex3f(-10.0, 13.0, -35.0);
    glVertex3f(-10.0, 5.0, -35.0);
    glVertex3f(-10.0, 5.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10.0, 13.0, -35.0);
    glVertex3f(-10.0, 5.0, -35.0);
    glVertex3f(20.0, 5.0, -35.0);
    glVertex3f(20.0, 13.0, -35.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 13.0, -35.0);
    glVertex3f(-10.0, 5.0, -35.0);
    glVertex3f(20.0, 5.0, -35.0);
    glVertex3f(20.0, 13.0, -35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 7.0, -35.0);
    glVertex3f(20.0, 7.0, -35.0);
    glVertex3f(-10.0, 8.0, -35.0);
    glVertex3f(20.0, 8.0, -35.0);
    glVertex3f(-10.0, 9.0, -35.0);
    glVertex3f(20.0, 9.0, -35.0);
    glVertex3f(-10.0, 10.0, -35.0);
    glVertex3f(20.0, 10.0, -35.0);
    glEnd();

    //BAWAH
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 184/255.0f, 135/255.0f);
    glVertex3f(50.0, -25.0, -40.0);
    glVertex3f(-50.0, -25.0, -40.0);
    glVertex3f(-50.0, -25.0, 65.0);
    glVertex3f(50.0, -25.0, 65.0);
    glEnd();

    //KASUR
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 128/255.0f);
    glVertex3f(10.0, -25.0, -39.5);
    glVertex3f(10.0, -25.0, -19.0);
    glVertex3f(10.0, -20.0, -19.0);
    glVertex3f(10.0, -20.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 128/255.0f);
    glVertex3f(10.0, -25.0, -19.0);
    glVertex3f(10.0, -20.0, -19.0);
    glVertex3f(49.5, -20.0, -19.0);
    glVertex3f(49.5, -25.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 128/255.0f);
    glVertex3f(49.5, -20.0, -19.0);
    glVertex3f(49.5, -25.0, -19.0);
    glVertex3f(49.5, -25.0, -39.5);
    glVertex3f(49.5, -20.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 128/255.0f);
    glVertex3f(49.5, -25.0, -39.5);
    glVertex3f(49.5, -20.0, -39.5);
    glVertex3f(10.0, -20.0, -39.5);
    glVertex3f(10.0, -25.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 128/255.0f);
    glVertex3f(10.0, -20.0, -19.0);
    glVertex3f(10.0, -20.0, -39.5);
    glVertex3f(49.5, -20.0, -39.5);
    glVertex3f(49.5, -20.0, -19.0);
    glEnd();

    //BEDCOVER
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.5, -20.0, -19.5);
    glVertex3f(10.5, -17.0, -19.5);
    glVertex3f(49.0, -17.0, -19.5);
    glVertex3f(49.0, -20.0, -19.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(49.0, -17.0, -19.5);
    glVertex3f(49.0, -20.0, -19.5);
    glVertex3f(49.0, -20.0, -39.0);
    glVertex3f(49.0, -17.0, -39.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.5, -20.0, -39.0);
    glVertex3f(10.5, -17.0, -39.0);
    glVertex3f(49.0, -17.0, -39.0);
    glVertex3f(49.0, -20.0, -39.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.5, -17.0, -19.5);
    glVertex3f(10.5, -20.0, -19.5);
    glVertex3f(10.5, -20.0, -39.0);
    glVertex3f(10.5, -17.0, -39.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.5, -17.0, -39.0);
    glVertex3f(49.0, -17.0, -39.0);
    glVertex3f(49.0, -17.0, -19.5);
    glVertex3f(10.5, -17.0, -19.5);
    glEnd();

    //BANTAL
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(48.5, -17.0, -24.5);
    glVertex3f(48.5, -17.0, -34.0);
    glVertex3f(48.5, -16.0, -34.0);
    glVertex3f(48.5, -16.0, -24.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(48.5, -17.0, -34.0);
    glVertex3f(48.5, -16.0, -34.0);
    glVertex3f(44.5, -16.0, -34.0);
    glVertex3f(44.5, -17.0, -34.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(44.5, -17.0, -24.5);
    glVertex3f(44.5, -17.0, -34.0);
    glVertex3f(44.5, -16.0, -34.0);
    glVertex3f(44.5, -16.0, -24.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(48.5, -17.0, -24.5);
    glVertex3f(48.5, -16.0, -24.5);
    glVertex3f(44.5, -16.0, -24.5);
    glVertex3f(44.5, -17.0, -24.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(48.5, -16.0, -24.5);
    glVertex3f(44.5, -16.0, -24.5);
    glVertex3f(44.5, -16.0, -34.0);
    glVertex3f(48.5, -16.0, -34.0);
    glEnd();

    //MEJA
    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -15.0, -39.5);
    glVertex3f(9.0, -15.0, -30.5);
    glVertex3f(-9.0, -15.0, -30.5);
    glVertex3f(-9.0, -15.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -15.0, -30.5);
    glVertex3f(-9.0, -15.0, -30.5);
    glVertex3f(-9.0, -13.0, -30.5);
    glVertex3f(9.0, -13.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -13.0, -39.5);
    glVertex3f(9.0, -13.0, -30.5);
    glVertex3f(-9.0, -13.0, -30.5);
    glVertex3f(-9.0, -13.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -15.0, -39.5);
    glVertex3f(-9.0, -15.0, -39.5);
    glVertex3f(-9.0, -13.0, -39.5);
    glVertex3f(9.0, -13.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-9.0, -13.0, -30.5);
    glVertex3f(-9.0, -13.0, -39.5);
    glVertex3f(-9.0, -25.0, -39.5);
    glVertex3f(-9.0, -25.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-8.0, -13.0, -30.5);
    glVertex3f(-8.0, -13.0, -39.5);
    glVertex3f(-8.0, -25.0, -39.5);
    glVertex3f(-8.0, -25.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-9.0, -15.0, -30.5);
    glVertex3f(-8.0, -15.0, -30.5);
    glVertex3f(-8.0, -25.0, -30.5);
    glVertex3f(-9.0, -25.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-9.0, -15.0, -39.5);
    glVertex3f(-8.0, -15.0, -39.5);
    glVertex3f(-8.0, -25.0, -39.5);
    glVertex3f(-9.0, -25.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -13.0, -30.5);
    glVertex3f(9.0, -13.0, -39.5);
    glVertex3f(9.0, -25.0, -39.5);
    glVertex3f(9.0, -25.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(8.0, -13.0, -30.5);
    glVertex3f(8.0, -13.0, -39.5);
    glVertex3f(8.0, -25.0, -39.5);
    glVertex3f(8.0, -25.0, -30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -15.0, -39.5);
    glVertex3f(8.0, -15.0, -39.5);
    glVertex3f(8.0, -25.0, -39.5);
    glVertex3f(9.0, -25.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(9.0, -15.0, -30.5);
    glVertex3f(8.0, -15.0, -30.5);
    glVertex3f(8.0, -25.0, -30.5);
    glVertex3f(9.0, -25.0, -30.5);
    glEnd();

    //KURSI
    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-3.0, -25.0, -27.0);
    glVertex3f(-3.0, -25.0, -23.0);
    glVertex3f(-3.0, -17.0, -23.0);
    glVertex3f(-3.0, -17.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(-3.0, -17.0, -23.0);
    glVertex3f(-3.0, -17.0, -27.0);
    glVertex3f(3.0, -17.0, -27.0);
    glVertex3f(3.0, -17.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(3.0, -25.0, -27.0);
    glVertex3f(3.0, -25.0, -23.0);
    glVertex3f(3.0, -17.0, -23.0);
    glVertex3f(3.0, -17.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(3.0, -25.0, -23.0);
    glVertex3f(3.0, -17.0, -23.0);
    glVertex3f(-3.0, -17.0, -23.0);
    glVertex3f(-3.0, -25.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(184/255.0f, 134/255.0f, 11/255.0f);
    glVertex3f(3.0, -25.0, -27.0);
    glVertex3f(3.0, -17.0, -27.0);
    glVertex3f(-3.0, -17.0, -27.0);
    glVertex3f(-3.0, -25.0, -27.0);
    glEnd();

    //ATAS
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 184/255.0f, 135/255.0f);
    glVertex3f(15.0, 15.0, 20.0);
    glVertex3f(15.0, 15.0, 45.0);
    glVertex3f(55.0, 15.0, 45.0);
    glVertex3f(55.0, 15.0, -45.0);
    glVertex3f(-55.0, 15.0, -45.0);
    glVertex3f(-55.0, 15.0, 20.0);
    glEnd();

    //ATAP GARASI
    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(-55.0, 15.0, 20.0);
    glVertex3f(-55.0, 15.0, -45.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.0, 15.0, 20.0);
    glVertex3f(-55.0, 15.0, -45.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(-55.0, 15.0, -45.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(55.0, 15.0, -45.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.0, 15.0, -45.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(55.0, 15.0, -45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(15.0, 15.0, 20.0);
    glVertex3f(-55.0, 15.0, 20.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(15.0, 15.0, 20.0);
    glVertex3f(-55.0, 15.0, 20.0);
    glVertex3f(-30.0, 15.0 + 30.0, -12.5);
    glEnd();

    //ATAP DEPAN
    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(15.0, 15.0, 45.0);
    glVertex3f(55.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 15.0, 45.0);
    glVertex3f(55.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(55.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(55.0, 15.0, -45.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(55.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(55.0, 15.0, -45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(15/255.0f, 42/255.0f, 42/255.0f);
    glVertex3f(15.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(15.0, 15.0, 20.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 15.0, 45.0);
    glVertex3f(28.0, 15.0 + 30.0, 13.0);
    glVertex3f(28.0, 15.0 + 30.0, -13.0);
    glVertex3f(15.0, 15.0, 20.0);
    glEnd();

    //PINTU
    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(19.5, -25.0, 25.0);
    glVertex3f(19.5, -25.0, 35.0);
    glVertex3f(19.5, 0.0, 35.0);
    glVertex3f(19.5, 0.0, 25.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(19.5, -25.0, 25.0);
    glVertex3f(19.5, 0.0, 25.0);
    glVertex3f(20.0, 0.0, 25.0);
    glVertex3f(20.0, -25.0, 25.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(19.5, -25.0, 35.0);
    glVertex3f(19.5, 0.0, 35.0);
    glVertex3f(20.0, 0.0, 35.0);
    glVertex3f(20.0, -25.0, 35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(19.5, 0.0, 35.0);
    glVertex3f(19.5, 0.0, 25.0);
    glVertex3f(20.0, 0.0, 25.0);
    glVertex3f(20.0, 0.0, 35.0);
    glEnd();

    //PINTU GARASI
    glBegin(GL_QUADS);
    glColor3f(211/255.0f, 211/255.0f, 211/255.0f);
    glVertex3f(-45.0, -25.0, 15.1);
    glVertex3f(10.0, -25.0, 15.1);
    glVertex3f(10.0, 10.0, 15.1);
    glVertex3f(-45.0, 10.0, 15.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.0, -22.0, 15.2);
    glVertex3f(-18.0, -22.0, 15.2);
    glVertex3f(-45.0, -20.0, 15.2);
    glVertex3f(10.0, -20.0, 15.2);
    glVertex3f(-45.0, -17.0, 15.2);
    glVertex3f(10.0, -17.0, 15.2);
    glVertex3f(-45.0, -14.0, 15.2);
    glVertex3f(10.0, -14.0, 15.2);
    glVertex3f(-45.0, -11.0, 15.2);
    glVertex3f(10.0, -11.0, 15.2);
    glVertex3f(-45.0, -8.0, 15.2);
    glVertex3f(10.0, -8.0, 15.2);
    glVertex3f(-45.0, -5.0, 15.2);
    glVertex3f(10.0, -5.0, 15.2);
    glVertex3f(-45.0, -2.0, 15.2);
    glVertex3f(10.0, -2.0, 15.2);
    glVertex3f(-45.0, 1.0, 15.2);
    glVertex3f(10.0, 1.0, 15.2);
    glVertex3f(-45.0, 4.0, 15.2);
    glVertex3f(10.0, 4.0, 15.2);
    glVertex3f(-45.0, 7.0, 15.2);
    glVertex3f(10.0, 7.0, 15.2);
    glVertex3f(-45.0, 10.0, 15.2);
    glVertex3f(10.0, 10.0, 15.2);
    glEnd();

    //JENDELA DEPAN
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(25.0, -15.0, 40.5);
    glVertex3f(45.0, -15.0, 40.5);
    glVertex3f(45.0, 5.0, 40.5);
    glVertex3f(25.0, 5.0, 40.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(25.0, -15.0, 40.5);
    glVertex3f(45.0, -15.0, 40.5);
    glVertex3f(45.0, -15.0, 40.0);
    glVertex3f(25.0, -15.0, 40.);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(45.0, -15.0, 40.5);
    glVertex3f(45.0, 5.0, 40.5);
    glVertex3f(45.0, 5.0, 40.0);
    glVertex3f(45.0, -15.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(45.0, 5.0, 40.5);
    glVertex3f(25.0, 5.0, 40.5);
    glVertex3f(25.0, 5.0, 40.0);
    glVertex3f(45.0, 5.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(25.0, -15.0, 40.5);
    glVertex3f(25.0, 5.0, 40.5);
    glVertex3f(25.0, 5.0, 40.0);
    glVertex3f(25.0, -15.0, 40.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.0, -15.0, 40.6);
    glVertex3f(45.0, -15.0, 40.6);
    glVertex3f(45.0, 5.0, 40.6);
    glVertex3f(25.0, 5.0, 40.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(35.0, -15.0, 40.6);
    glVertex3f(35.0, 5.0, 40.6);
    glVertex3f(25.0, 0.0, 40.6);
    glVertex3f(45.0, 0.0, 40.6);
    glEnd();

    //JENDELA SAMPING
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(50.5, -15.0, -10.0);
    glVertex3f(50.5, 5.0, -10.0);
    glVertex3f(50.5, 5.0, -30.0);
    glVertex3f(50.5, -15.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(50.5, -15.0, -10.0);
    glVertex3f(50.5, 5.0, -10.0);
    glVertex3f(50.0, 5.0, -10.0);
    glVertex3f(50.0, -15.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(50.5, 5.0, -10.0);
    glVertex3f(50.5, 5.0, -30.0);
    glVertex3f(50.0, 5.0, -30.0);
    glVertex3f(50.0, 5.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(50.5, 5.0, -30.0);
    glVertex3f(50.5, -15.0, -30.0);
    glVertex3f(50.0, -15.0, -30.0);
    glVertex3f(50.0, 5.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(50.5, -15.0, -10.0);
    glVertex3f(50.5, -15.0, -30.0);
    glVertex3f(50.0, -15.0, -30.0);
    glVertex3f(50.0, -15.0, -10.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.6, -15.0, -10.0);
    glVertex3f(50.6, 5.0, -10.0);
    glVertex3f(50.6, 5.0, -30.0);
    glVertex3f(50.6, -15.0, -30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.6, -15.0, -20.0);
    glVertex3f(50.6, 5.0, -20.0);
    glVertex3f(50.6, -0.0, -10.0);
    glVertex3f(50.6, -0.0, -30.0);
    glEnd();

    //KANOPI
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-50.0, 14.0 , 15.5);
    glVertex3f(19.5, 14.0 , 15.5);
    glVertex3f(19.5, 14.0, 65.0);
    glVertex3f(-50.0, 14.0, 65.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-50.0, 14.0 , 15.5);
    glVertex3f(19.5, 14.0 , 15.5);
    glVertex3f(19.5, 14.0 , 15.0);
    glVertex3f(-50.0, 14.0 , 15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(19.5, 14.0, 65.0);
    glVertex3f(-50.0, 14.0, 65.0);
    glVertex3f(-50.0, 11.0, 65.0);
    glVertex3f(19.5, 11.0, 65.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-50.0, 11.0, 65.0);
    glVertex3f(19.5, 11.0, 65.0);
    glVertex3f(19.5, 11.0, 15.5);
    glVertex3f(-50.0, 11.0, 15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-50.0, 11.0 , 15.5);
    glVertex3f(19.5, 11.0 , 15.5);
    glVertex3f(19.5, 11.0 , 15.0);
    glVertex3f(-50.0, 11.0 , 15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(19.5, 11.0 , 15.0);
    glVertex3f(19.5, 14.0 , 15.0);
    glVertex3f(19.5, 14.0 , 65.0);
    glVertex3f(19.5, 11.0 , 65.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-50.0, 11.0 , 15.0);
    glVertex3f(-50.0, 14.0 , 15.0);
    glVertex3f(-50.0, 14.0 , 65.0);
    glVertex3f(-50.0, 11.0 , 65.0);
    glEnd();

    //TIANG KANOPI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-48.0, 11.0, 60.0);
    glVertex3f(-45.0, 11.0, 60.0);
    glVertex3f(-45.0, -11.0, 60.0);
    glVertex3f(-48.0, -11.0, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-45.0, 11.0, 60.0);
    glVertex3f(-45.0, 11.0, 57.0);
    glVertex3f(-45.0, -11.0, 57.0);
    glVertex3f(-45.0, -11.0, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-45.0, 11.0, 57.0);
    glVertex3f(-48.0, 11.0, 57.0);
    glVertex3f(-48.0, -11.0, 57.0);
    glVertex3f(-45.0, -11.0, 57.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-48.0, 11.0, 57.0);
    glVertex3f(-48.0, 11.0, 60.0);
    glVertex3f(-48.0, -11.0, 60.0);
    glVertex3f(-48.0, -11.0, 57.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-49.0, -11.0, 61.0);
    glVertex3f(-44.0, -11.0, 61.0);
    glVertex3f(-44.0, -11.0, 56.0);
    glVertex3f(-49.0, -11.0, 56.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-49.0, -11.0, 61.0);
    glVertex3f(-44.0, -11.0, 61.0);
    glVertex3f(-44.0, -25.0, 61.0);
    glVertex3f(-49.0, -25.0, 61.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-44.0, -11.0, 61.0);
    glVertex3f(-44.0, -11.0, 56.0);
    glVertex3f(-44.0, -25.0, 56.0);
    glVertex3f(-44.0, -25.0, 61.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-44.0, -11.0, 56.0);
    glVertex3f(-49.0, -11.0, 56.0);
    glVertex3f(-49.0, -25.0, 56.0);
    glVertex3f(-44.0, -25.0, 56.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-49.0, -11.0, 56.0);
    glVertex3f(-49.0, -11.0, 61.0);
    glVertex3f(-49.0, -25.0, 61.0);
    glVertex3f(-49.0, -25.0, 56.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(17.5, 11.0, 60.0);
    glVertex3f(14.5, 11.0, 60.0);
    glVertex3f(14.5, -11.0, 60.0);
    glVertex3f(17.5, -11.0, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.5, 11.0, 60.0);
    glVertex3f(14.5, 11.0, 57.0);
    glVertex3f(14.5, -11.0, 57.0);
    glVertex3f(14.5, -11.0, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.5, 11.0, 57.0);
    glVertex3f(17.5, 11.0, 57.0);
    glVertex3f(17.5, -11.0, 57.0);
    glVertex3f(14.5, -11.0, 57.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(17.5, 11.0, 57.0);
    glVertex3f(17.5, 11.0, 60.0);
    glVertex3f(17.5, -11.0, 60.0);
    glVertex3f(17.5, -11.0, 57.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(18.5, -11.0, 61.0);
    glVertex3f(13.5, -11.0, 61.0);
    glVertex3f(13.5, -11.0, 56.0);
    glVertex3f(18.5, -11.0, 56.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(18.5, -11.0, 61.0);
    glVertex3f(13.5, -11.0, 61.0);
    glVertex3f(13.5, -25.0, 61.0);
    glVertex3f(18.5, -25.0, 61.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(13.5, -11.0, 61.0);
    glVertex3f(13.5, -11.0, 56.0);
    glVertex3f(13.5, -25.0, 56.0);
    glVertex3f(13.5, -25.0, 61.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(13.5, -11.0, 56.0);
    glVertex3f(18.5, -11.0, 56.0);
    glVertex3f(18.5, -25.0, 56.0);
    glVertex3f(13.5, -25.0, 56.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(18.5, -11.0, 56.0);
    glVertex3f(18.5, -11.0, 61.0);
    glVertex3f(18.5, -25.0, 61.0);
    glVertex3f(18.5, -25.0, 56.0);
    glEnd();

    // JENDELA BELAKANG
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-30.0, -15.0, -40.5);
    glVertex3f(-10.0, -15.0, -40.5);
    glVertex3f(-10.0, 5.0, -40.5);
    glVertex3f(-30.0, 5.0, -40.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-30.0, -15.0, -40.5);
    glVertex3f(-10.0, -15.0, -40.5);
    glVertex3f(-10.0, -15.0, -40.0);
    glVertex3f(-30.0, -15.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-10.0, -15.0, -40.5);
    glVertex3f(-10.0, 5.0, -40.5);
    glVertex3f(-10.0, 5.0, -40);
    glVertex3f(-10.0, -15.0, -40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-10.0, 5.0, -40.5);
    glVertex3f(-30.0, 5.0, -40.5);
    glVertex3f(-30.0, 5.0, -40);
    glVertex3f(-10.0, 5.0, -40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-30.0, -15.0, -40.0);
    glVertex3f(-30.0, -15.0, -40.5);
    glVertex3f(-30.0, 5.0, -40.5);
    glVertex3f(-30.0, 5.0, -40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30.0, -15.0, -40.6);
    glVertex3f(-10.0, -15.0, -40.6);
    glVertex3f(-10.0, 5.0, -40.6);
    glVertex3f(-30.0, 5.0, -40.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.0, -15.0, -40.6);
    glVertex3f(-20.0, 5.0, -40.6);
    glVertex3f(-30.0, 0.0, -40.6);
    glVertex3f(-10.0, 0.0, -40.6);
    glEnd();

    //JENDELA SAMPING
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-50.5, -15.0, 10.0);
    glVertex3f(-50.5, 5.0, 10.0);
    glVertex3f(-50.5, 5.0, -10.0);
    glVertex3f(-50.5, -15.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-50.5, -15.0, 10.0);
    glVertex3f(-50.5, 5.0, 10.0);
    glVertex3f(-50.0, 5.0, 10.0);
    glVertex3f(-50.0, -15.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-50.5, 5.0, 10.0);
    glVertex3f(-50.5, 5.0, -10.0);
    glVertex3f(-50.0, 5.0, -10.0);
    glVertex3f(-50.0, 5.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-50.5, 5.0, -10.0);
    glVertex3f(-50.5, -15.0, -10.0);
    glVertex3f(-50.0, -15.0, -10.0);
    glVertex3f(-50.0, 5.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(150/255.0f, 75/255.0f, 0.0);
    glVertex3f(-50.5, -15.0, -10.0);
    glVertex3f(-50.5, -15.0, 10.0);
    glVertex3f(-50.0, -15.0, 10.0);
    glVertex3f(-50.0, -15.0, -10.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.6, -15.0, 10.0);
    glVertex3f(-50.6, 5.0, 10.0);
    glVertex3f(-50.6, 5.0, -10.0);
    glVertex3f(-50.6, -15.0, -10.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.6, -15.0, 0.0);
    glVertex3f(-50.6, 5.0, 0.0);
    glVertex3f(-50.6, 0.0, -10.0);
    glVertex3f(-50.6, 0.0, 10.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }else
        mouseDown = false;
}

void mouseMotion(int x, int y){
    myinit();
    if (mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;

    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '0':
        glRotatef(2.0, 0.0, -1.0, 0.0);
        break;
    case '3':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '5':
            if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
        }
        tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

