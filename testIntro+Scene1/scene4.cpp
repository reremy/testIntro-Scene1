//#include <GL/glut.h>
//#include <cmath>
//
//#define SCREEN_WIDTH 1000
//#define SCREEN_HEIGHT 600
//#define PI 3.1415926535897932384626433832795
//
//double byteY = -150; // Initial y-coordinate of "Byte"
//double bitY = -150;  // Initial y-coordinate of "Bit"
//
//void drawCircle(double centerX, double centerY, double radius) {
//    glBegin(GL_POLYGON);
//    for (int i = 0; i <= 360; i++) {
//        double angle = i * PI / 180.0;
//        double x = centerX + radius * cos(angle);
//        double y = centerY + radius * sin(angle);
//        glVertex2d(x, y);
//    }
//    glEnd();
//}
//
//void drawBody(double centerX, double centerY, double bodyRadius, double holeRadius) {
//    // Circle
//    drawCircle(centerX, centerY, bodyRadius);
//
//    // Holes
//    glColor3ub(0, 0, 0);
//    drawCircle(centerX, centerY, holeRadius + 5);
//}
//
//void drawEye(double centerX, double centerY, double eyeRadius) {
//    // White part of the eye
//    glColor3f(1.0, 1.0, 1.0);
//    drawCircle(centerX, centerY, eyeRadius);
//
//    // Black pupil
//    glColor3f(0.0, 0.0, 0.0);
//    drawCircle(centerX, centerY, eyeRadius / 3);
//}
//
//void drawByte(int x, int y, int w, int h) {
//    // Draw the character "Byte"
//    glColor3ub(0, 255, 255);
//    glBegin(GL_POLYGON);
//    glVertex2i(x, y);
//    glVertex2i(x + w, y);
//    glVertex2i(x + w, y + h);
//    glVertex2i(x, y + h);
//    glEnd();
//
//    // Draw the body
//    drawBody((x + w * 1.23), (y + h / 3), 50, 15);
//    glColor3ub(0, 255, 255);
//    drawBody((x + w * 1.23) - 5, (y + h / 3) + 60, 40, 10);
//
//    // Draw the eyes
//    drawEye((x + w / 3), (y + h / 1.3), 18);      // Draw eye 1
//    drawEye((x + 3 * w / 2), (y + h / 1.3), 18);  // Draw eye 2
//}
//
//void drawBit(int x, int y, int w, int h) {
//    // Draw the character "Bit"
//    glColor3ub(255, 0, 255);
//    glBegin(GL_POLYGON);
//    glVertex2i(x, y);
//    glVertex2i(x + w, y);
//    glVertex2i(x + w, y + h);
//    glVertex2i(x, y + h);
//    glEnd();
//
//    // Draw the body
//    drawBody((x + w * 1.23) - 5, (y + h / 3) - 10, 40, 10);
//
//    // Draw the eyes
//    drawEye((x + w / 5), (y + h / 1.3), 15);  // Draw eye 1
//    drawEye((x + w), (y + h / 1.3), 15);     // Draw eye 2
//}
//
//void displayBitsAndByte() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Update y-coordinates for animation
//    if (byteY < 200) {
//        byteY += 1;
//    }
//    if (bitY < 200) {
//        bitY += 1;
//    }
//
//    // Draw "Byte" and "Bit" with updated coordinates
//    drawByte((SCREEN_WIDTH - 200) / 2 - 50, byteY, 40, 150); // Centered and shifted to the left
//    drawBit((SCREEN_WIDTH + 200) / 2 + 50, bitY, 40, 150);  // Centered and shifted to the right
//
//    glFlush();
//    if (byteY < 200 || bitY < 200) {
//        glutPostRedisplay(); // Continue animation until y-coordinate reaches 200
//    }
//}
//
//void initGL() {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
//    glPointSize(10.0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
//    glutCreateWindow("Test");
//    glutDisplayFunc(displayBitsAndByte);
//    initGL();
//    glutMainLoop();
//    return 0;
//}
