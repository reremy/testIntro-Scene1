//#include <windows.h>
//#include <stdlib.h>
//#include <math.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//
//#define SCREEN_WIDTH 1000
//#define SCREEN_HEIGHT 600
//#define PI 3.141592653
//#define FPS 30
//
//// Global variables
//int frame = 0;
//int delay = 1000 / FPS; // Delay between frames in milliseconds
//float scaleX = 1.0f;
//float scaleY = 1.0f;
//float scaleSpeed = 0.05f; // adjust this for desired speed
//int delaySecondsBB = 3; // Delay before transitioning to monitor scene (in seconds)
//int delaySecondsMonitor = 5; // Delay before scaling monitor (in seconds)
//int delayBeforeZoom = 3; // Delay before starting the zoom animation (in seconds)
//
//bool firstTextDisplayed = false;
//
//void renderText(float x, float y, void* font, const char* string, int r, int g, int b) {
//    glColor3ub(r, g, b);
//    glRasterPos2f(x, y);
//    while (*string) {
//        glutBitmapCharacter(font, *string);
//        string++;
//    }
//}
//
//// Function to draw "B&B Studio Animation presents"
//void drawBBStudio() {
//    renderText(SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2, GLUT_BITMAP_TIMES_ROMAN_24, "B&B Studio Animation presents", 255, 255, 255);
//}
//
//// Function to draw "Bits & Bytes"
//void drawBitsBytes() {
//    renderText(SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2, GLUT_BITMAP_TIMES_ROMAN_24, "'Bits & Bytes'", 255, 255, 255);
//}
//
//// Function to handle display of the introduction scene
//void displayIntro() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    if (!firstTextDisplayed) {
//        drawBBStudio();
//    }
//    else {
//        drawBitsBytes();
//    }
//    glutSwapBuffers();
//}
//
////rectangle function
//void rectangle(int x, int y, int w, int h, int r, int g, int b) {
//    glBegin(GL_POLYGON);
//    glColor3ub(r, g, b);
//    glVertex2i(x, y);
//    glVertex2i(x + w, y);
//    glVertex2i(x + w, y + h);
//    glVertex2i(x, y + h);
//    glEnd();
//}
//
////the monitor on a desk
//void monitorOnDesk(int x, int y, int w, int h) {
//    //bcg
//    rectangle(x, y, x + SCREEN_WIDTH, y + SCREEN_HEIGHT, 224, 224, 224);
//    //desk
//    rectangle(x, y + SCREEN_HEIGHT / 5, x + SCREEN_WIDTH, y + SCREEN_HEIGHT / 5, 255, 204, 153);
//    //monitor
//    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 4, y + SCREEN_HEIGHT / 4, 96, 96, 96); //outerMonitor
//    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 / 2 + 5, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 / 2 + 5, x + SCREEN_WIDTH / 4 - 10, y + SCREEN_HEIGHT / 4 - 10, 16, 16, 16); //innerMonitor
//    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 20 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 25 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 20, y + SCREEN_HEIGHT / 25, 128, 128, 128); //monitorLeg
//    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 10 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 25 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 10, SCREEN_HEIGHT / 100, 120, 120, 120); //monitorBase
//}
//
//void zoomInMonitor(int x, int y, int w, int h) {
//    int monitorCenterX = SCREEN_WIDTH / 2; // X-coordinate of the center of the outer monitor
//    int monitorCenterY = SCREEN_HEIGHT / 2; // Y-coordinate of the center of the outer monitor
//
//    glPushMatrix(); // Push current matrix onto stack
//    glTranslatef(monitorCenterX, monitorCenterY, 0); // Translate to the center of the outer monitor
//    glScalef(scaleX, scaleY, 1.0f); // Scale the monitor
//    glTranslatef(-monitorCenterX, -monitorCenterY, 0); // Translate back to the original position
//    monitorOnDesk(0, 0, 0, 0);
//    glPopMatrix(); // Pop matrix from stack, restoring previous state
//}
//
//void displayScene1() {
//    glClear(GL_COLOR_BUFFER_BIT); //display background colour
//    zoomInMonitor(0, 0, 0, 0);
//    glutSwapBuffers();
//}
//
//void animateScene1(int value) {
//    // Update scale factors
//    scaleX += scaleSpeed;
//    scaleY += scaleSpeed;
//
//    // Stop scaling when the outer monitor size is equal to or greater than the screen size
//    if (SCREEN_WIDTH / 4 * scaleX >= SCREEN_WIDTH && SCREEN_HEIGHT / 4 * scaleY >= SCREEN_HEIGHT) {
//        scaleX = SCREEN_WIDTH / (float)(SCREEN_WIDTH / 4); // Ensure scaleX is exactly the screen width
//        scaleY = SCREEN_HEIGHT / (float)(SCREEN_HEIGHT / 4); // Ensure scaleY is exactly the screen height
//        glutPostRedisplay(); // Redraw to update the display
//        return; // Exit the function
//    }
//
//    // Redraw
//    glutPostRedisplay();
//
//    // Call update function again after a delay
//    glutTimerFunc(1000 / FPS, animateScene1, 0);
//}
//
//// Function to handle animation of the introduction scene
//void animateIntro(int value) {
//    frame++;
//    if (frame == FPS * delaySecondsBB) {
//        firstTextDisplayed = true;
//    }
//    if (frame == FPS * delaySecondsMonitor) {
//        glutDisplayFunc(displayScene1);
//        glutTimerFunc(delay, animateScene1, 0);
//        return; // Exit the function after transitioning to the monitor scene
//    }
//    glutPostRedisplay();
//    glutTimerFunc(delay, animateIntro, 0);
//}
//
//
//void initGL() {
//    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); // Set up orthographic projection
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Set window size
//    glutInitWindowPosition(100, 100); // Set window position
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutCreateWindow("Test");
//    glutDisplayFunc(displayIntro);
//
//    initGL();
//
//    glutTimerFunc(delay, animateIntro, 0);
//
//    glutMainLoop();
//    return 0;
//}
