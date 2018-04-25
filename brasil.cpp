
#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif
#define PI 3.14159265358979324

#include <math.h>

// Rectangle
float RX = -100;
float RY = -100;

// Diamond
float alpha = 90.0;

// Circle
static float CR = 15.0;       // Radius of circle.
static float CX = 50.0;       // X-coordinate of center of circle.
static float CY = 31.3;       // Y-coordinate of center of circle.
static int numVertices = 100; // Number of vertices on circle.

// Refresh Time
static int refreshMillis = 30; // Refresh period in milliseconds

// Drawing routine.
void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
   glLoadIdentity();              // Reset model-view matrix

   //Green Rectangle
   glPushMatrix();
      glTranslatef(RX, RY, 0.0f);
      glColor3f(0.0, 0.61, 0.23);
      glBegin(GL_POLYGON);
         glVertex3f(  0.0,  0.0, 0.0);
         glVertex3f(100.0,  0.0, 0.0);
         glVertex3f(100.0,100.0, 0.0);
         glVertex3f(  0.0,100.0, 0.0);
      glEnd();
   glPopMatrix();

   /*
   if(RX != 0 || RY != 0){
      RX += 0.5;
      RY += 0.5;
   }
   */

   //Yellow Diamond
   glPushMatrix();
      glRotatef((GLfloat) alpha, 0.0, 0.0, 1.0);
      glColor3f(1.0, 0.87, 0.0);
      glBegin(GL_POLYGON);
         glVertex3f(10.0, 50.0, 0.0);
         glVertex3f(50.0, 10.0, 0.0);
         glVertex3f(90.0, 50.0, 0.0);
         glVertex3f(50.0, 90.0, 0.0);
      glEnd();
   glPopMatrix();

   if(alpha > 0){
      alpha -= 0.5;
   }

   /*
   //Blue Circle
   glPushMatrix();
      glColor3f(0.0, 0.15, 0.46);
      glScalef(1.0, 1.6, 1.0);
      glBegin(GL_POLYGON);
         float t = 0;
         for(int i = 0; i < numVertices; ++i){
            glVertex3f(CX + CR * cos(t), CY + CR * sin(t), 0.0);
            t += 2 * PI / numVertices;
         }
      glEnd();
   glPopMatrix();
   */
   glFlush();
}

// Initialization routine.
void setup(void)
{
   glColor3f(0.0, 0.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void Timer(int value) {
   glutPostRedisplay();                      // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0);   // subsequent timer call at milliseconds
}

// Main routine.
int main(int argc, char **argv)
{
   glutInit(&argc, argv);

   glutInitContextVersion(2, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(800, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("brasil.cpp");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glutTimerFunc(0, Timer, 0);

   glewExperimental = GL_TRUE;
   glewInit();

   setup();

   glutMainLoop();
}
