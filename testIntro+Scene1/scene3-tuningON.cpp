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
//float screenOpacity = 0.0f; // Initial opacity value
//int loadingTime = 0; // Variable to track loading time
//int loadingComplete = 0; // Flag to indicate if loading is complete
//
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
	//void folderIcon(int x, int y) {
	//    glBegin(GL_POLYGON);
	//    glColor3ub(247, 238, 159);
	//    glVertex2i(x, y);
	//    glVertex2i(x, y + 40);
	//    glVertex2i(x + 5, y + 45);
	//    glVertex2i(x + 15, y + 45);
	//    glVertex2i(x + 30, y + 40);
	//    glVertex2i(x + 50, y + 40);
	//    glVertex2i(x + 50, y);
	//    glEnd();
	//}
//
//void renderText(float x, float y, void* font, const char* string) {
//    glColor3ub(0, 0, 0);
//    glRasterPos2f(x, y);
//    while (*string) {
//        glutBitmapCharacter(font, *string);
//        string++;
//    }
//}
//
//void monitor(int x, int y, int w, int h) {
//    //outer monitor
//    rectangle(x, y, w, h, 0, 0, 0);
//
//    //screen
//    //desktop bcg color - teal
//    rectangle(x + 20, y + 20, w - 40, h - 40, 85, 128, 129);
//
//    //task bar
//    rectangle(x + 20, y + 20, w - 40, 48, 192, 192, 192);
//    rectangle(x + 20, y + 66, w - 40, 1, 220, 220, 220); //highlightTaskbar
//
//    //start button
//    glColor3ub(190, 190, 190);
//    rectangle(x + 25, y + 25, 80, 38, 186, 187, 189); //startButton
//    rectangle(x + 26, y + 23, 80, 2, 145, 145, 145); //shadowBottom
//    rectangle(x + 106, y + 23, 2, 38, 145, 145, 145); //shadowLeft
//    rectangle(x + 25, y + 60, 80, 2, 220, 220, 220); //highlightTop
//    rectangle(x + 25, y + 25, 2, 36, 220, 220, 220); //highlightRight
//    renderText(x + 40, y + 35, GLUT_BITMAP_TIMES_ROMAN_24, "Start");
//
//    //clock
//    glColor3ub(0, 0, 0);
//    rectangle(x + 860, y + 28, 110, 30, 188, 189, 191); //clockBox
//    rectangle(x + 860, y + 27, 110, 2, 220, 220, 220); //highlightBottom
//    rectangle(x + 970, y + 27, 2, 31, 220, 220, 220); //highlightLeft
//    rectangle(x + 860, y + 29, 2, 30, 145, 145, 145); //shadowTop
//    rectangle(x + 860, y + 58, 110, 2, 145, 145, 145); //shadowRight
//    renderText(x + 870, y + 35, GLUT_BITMAP_TIMES_ROMAN_24, "9:00 AM");
//
//    //icon1
//    folderIcon(40, 520);
//    renderText(x + 40, y + 500, GLUT_BITMAP_TIMES_ROMAN_10, "GRAPHICS");
//
//    //icon2
//    folderIcon(40, 420);
//    renderText(x + 55, y + 400, GLUT_BITMAP_TIMES_ROMAN_10, "OOP");
//
//    //icon3
//    folderIcon(40, 320);
//    renderText(x + 50, y + 300, GLUT_BITMAP_TIMES_ROMAN_10, "CODE");
//}
//
//void loadingString(int x, int y) {
//    renderText(x + 40, y + 200, GLUT_BITMAP_TIMES_ROMAN_24, "Loading....");
//}
//
//void loadingScreen(int x, int y, int w, int h, int colorR, int colorG, int colorB) {
//    rectangle(x + 20, y + 20, w - 40, h - 40, colorR, colorG, colorB);
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
//
//    if (!loadingComplete) {
//        loadingScreen(0, 0, 1000, 600, (loadingTime % 2 == 0) ? 0 : 255, (loadingTime % 2 == 0) ? 0 : 255, (loadingTime % 2 == 0) ? 0 : 255);
//        loadingString(0, 0);
//    }
//    else {
//        monitor(0, 0, 1000, 600);
//    }
//
//    glFlush(); // Flush the OpenGL pipeline
//}
//
//void initGL() {
//    glClearColor(0.0, 0.0, 0.0, 0.0); //background colour
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
//    glPointSize(10.0);
//}
//
//void timer(int value) {
//    loadingTime++;
//    if (loadingTime >= 15 * 2) { // 2 seconds with 30 FPS
//        loadingComplete = 1;
//    }
//    glutPostRedisplay();
//    glutTimerFunc(1000 / FPS, timer, 0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
//    glutCreateWindow("Test");
//    glutDisplayFunc(display);
//
//    initGL();
//
//    glutTimerFunc(0, timer, 0); // Start the timer immediately
//
//    glutMainLoop();
//    return 0;
//}
