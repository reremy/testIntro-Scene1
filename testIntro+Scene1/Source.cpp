#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define PI 3.141592653
#define FPS 30

// Animation states
enum AnimationState {
    INTRO,
    TURN_ON_MONITOR,
    SCENE_1,
    BITS_AND_BYTES_SCREEN

};

// Global variables
int frame = 0;
int delay = 1000 / FPS; // Delay between frames in milliseconds
float scaleX = 1.0f;
float scaleY = 1.0f;
float scaleSpeed = 0.05f; // adjust this for desired speed
int delaySecondsBB = 3; // Delay before transitioning to monitor scene (in seconds)
int delaySecondsMonitor = 5; // Delay before scaling monitor (in seconds)
int delayBeforeZoom = 3; // Delay before starting the zoom animation (in seconds)

bool firstTextDisplayed = false;
bool loadingComplete = 0; //0=false
int loadingTime = 0;
AnimationState currentState = INTRO;

double byteY = -150; // Initial y-coordinate of "Byte"
double bitY = -150;  // Initial y-coordinate of "Bit"

bool moveCharacter = true;



// Function prototypes
void renderText(float x, float y, void* font, const char* string, int r, int g, int b);
void rectangle(int x, int y, int w, int h, int r, int g, int b);
void monitorOnDesk(int x, int y, int w, int h);
void zoomInMonitor(int x, int y, int w, int h);
void drawBBStudio();
void drawBitsBytes();
void displayIntro();
void displayMonitorScene();
void displayLoadingScreen();
void displayScene1();
void animateScene1(int value);
void animateIntro(int value);
void timer(int value);
void initGL();
void display();





// BIT&BYTES

void drawCircle(double centerX, double centerY, double radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * PI / 180.0;
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);
        glVertex2d(x, y);
    }
    glEnd();
}

void drawBody(double centerX, double centerY, double bodyRadius, double holeRadius) {
    // Circle
    drawCircle(centerX, centerY, bodyRadius);

    // Holes
    glColor3ub(0, 0, 0);
    drawCircle(centerX, centerY, holeRadius + 5);
}

void drawEye(double centerX, double centerY, double eyeRadius) {
    // White part of the eye
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(centerX, centerY, eyeRadius);

    // Black pupil
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(centerX, centerY, eyeRadius / 3);
}

void drawByte(int x, int y, int w, int h) {
    // Draw the character "Byte"
    glColor3ub(0, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

    // Draw the body
    drawBody((x + w * 1.23), (y + h / 3), 50, 15);
    glColor3ub(0, 255, 255);
    drawBody((x + w * 1.23) - 5, (y + h / 3) + 60, 40, 10);

    // Draw the eyes
    drawEye((x + w / 3), (y + h / 1.3), 18);      // Draw eye 1
    drawEye((x + 3 * w / 2), (y + h / 1.3), 18);  // Draw eye 2
}

void drawBit(int x, int y, int w, int h) {
    // Draw the character "Bit"
    glColor3ub(255, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

    // Draw the body
    drawBody((x + w * 1.23) - 5, (y + h / 3) - 10, 40, 10);

    // Draw the eyes
    drawEye((x + w / 5), (y + h / 1.3), 15);  // Draw eye 1
    drawEye((x + w), (y + h / 1.3), 15);     // Draw eye 2
}

void displayBitsAndBytes() {
    printf("Printing Bits and Bytes");
    glClear(GL_COLOR_BUFFER_BIT);

    if (moveCharacter) {
        // Update y-coordinates for animation
        if (byteY < 200) {
            byteY += 1;
        }
        if (bitY < 200) {
            bitY += 1;
        }

        // Draw "Byte" and "Bit" with updated coordinates
        drawByte((SCREEN_WIDTH - 200) / 2 - 50, byteY, 40, 150); // Centered and shifted to the left
        drawBit((SCREEN_WIDTH + 200) / 2 + 50, bitY, 40, 150);  // Centered and shifted to the right

        glutSwapBuffers();
        if (byteY < 200 || bitY < 200) {
            glutPostRedisplay(); // Continue animation until y-coordinate reaches 200
        }
    }
    else {
        // Update y-coordinates for animation
        if (byteY < 200) {
            byteY += 1;
        }
        if (bitY < 200) {
            bitY += 1;
        }

        // Draw "Byte" and "Bit" with updated coordinates
        drawByte((SCREEN_WIDTH - 200) / 2 - 50, byteY, 40, 150); // Centered and shifted to the left
        drawBit((SCREEN_WIDTH + 200) / 2 + 50, bitY, 40, 150);  // Centered and shifted to the right

        glFlush();
        if (byteY < 200 || bitY < 200) {
            glutPostRedisplay(); // Continue animation until y-coordinate reaches 200
        }
    }
}


// BIT&BYTES







// Function to draw text
void renderText(float x, float y, void* font, const char* string, int r, int g, int b) {
    glColor3ub(r, g, b);
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

// Function to draw a rectangle
void rectangle(int x, int y, int w, int h, int r, int g, int b) {
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();
}

// Function to draw the monitor on a desk
void monitorOnDesk(int x, int y, int w, int h) {
    // Background
    rectangle(x, y, x + SCREEN_WIDTH, y + SCREEN_HEIGHT, 224, 224, 224);
    // Desk
    rectangle(x, y + SCREEN_HEIGHT / 5, x + SCREEN_WIDTH, y + SCREEN_HEIGHT / 5, 255, 204, 153);
    // Monitor
    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 4, y + SCREEN_HEIGHT / 4, 96, 96, 96); // Outer monitor
    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 / 2 + 5, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 / 2 + 5, x + SCREEN_WIDTH / 4 - 10, y + SCREEN_HEIGHT / 4 - 10, 16, 16, 16); // Inner monitor
    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 20 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 25 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 20, y + SCREEN_HEIGHT / 25, 128, 128, 128); // Monitor leg
    rectangle(x + SCREEN_WIDTH / 2 - SCREEN_WIDTH / 10 / 2, y + SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 25 - SCREEN_HEIGHT / 4 / 2, x + SCREEN_WIDTH / 10, SCREEN_HEIGHT / 100, 120, 120, 120); // Monitor base
}

// Function to zoom in on the monitor
void zoomInMonitor(int x, int y, int w, int h) {
    int monitorCenterX = SCREEN_WIDTH / 2; // X-coordinate of the center of the outer monitor
    int monitorCenterY = SCREEN_HEIGHT / 2; // Y-coordinate of the center of the outer monitor

    glPushMatrix(); // Push current matrix onto stack
    glTranslatef(monitorCenterX, monitorCenterY, 0); // Translate to the center of the outer monitor
    glScalef(scaleX, scaleY, 1.0f); // Scale the monitor
    glTranslatef(-monitorCenterX, -monitorCenterY, 0); // Translate back to the original position
    monitorOnDesk(0, 0, 0, 0);
    glPopMatrix(); // Pop matrix from stack, restoring previous state
}

// Function to draw "B&B Studio Animation presents"
void drawBBStudio() {
    renderText(SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2, GLUT_BITMAP_TIMES_ROMAN_24, "B&B Studio Animation presents", 255, 255, 255);
}

// Function to draw "Bits & Bytes"
void drawBitsBytes() {
    renderText(SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2, GLUT_BITMAP_TIMES_ROMAN_24, "'Bits & Bytes'", 255, 255, 255);
}

void folderIcon(int x, int y) {
    glBegin(GL_POLYGON);
    glColor3ub(247, 238, 159);
    glVertex2i(x, y);
    glVertex2i(x, y + 40);
    glVertex2i(x + 5, y + 45);
    glVertex2i(x + 15, y + 45);
    glVertex2i(x + 30, y + 40);
    glVertex2i(x + 50, y + 40);
    glVertex2i(x + 50, y);
    glEnd();
}

void renderText(float x, float y, void* font, const char* string) {
    glColor3ub(0, 0, 0);
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void monitor(int x, int y, int w, int h) {
    //outer monitor
    rectangle(x, y, w, h, 0, 0, 0);
    
    //screen
    //desktop bcg color - teal
    rectangle(x + 20, y + 20, w - 40, h - 40, 85, 128, 129);
    
    //task bar
    rectangle(x + 20, y + 20, w - 40, 48, 192, 192, 192);
    rectangle(x + 20, y + 66, w - 40, 1, 220, 220, 220); //highlightTaskbar
    
    //start button
    glColor3ub(190, 190, 190);
    rectangle(x + 25, y + 25, 80, 38, 186, 187, 189); //startButton
    rectangle(x + 26, y + 23, 80, 2, 145, 145, 145); //shadowBottom
    rectangle(x + 106, y + 23, 2, 38, 145, 145, 145); //shadowLeft
    rectangle(x + 25, y + 60, 80, 2, 220, 220, 220); //highlightTop
    rectangle(x + 25, y + 25, 2, 36, 220, 220, 220); //highlightRight
    renderText(x + 40, y + 35, GLUT_BITMAP_TIMES_ROMAN_24, "Start");
    
    //clock
    glColor3ub(0, 0, 0);
    rectangle(x + 860, y + 28, 110, 30, 188, 189, 191); //clockBox
    rectangle(x + 860, y + 27, 110, 2, 220, 220, 220); //highlightBottom
    rectangle(x + 970, y + 27, 2, 31, 220, 220, 220); //highlightLeft
    rectangle(x + 860, y + 29, 2, 30, 145, 145, 145); //shadowTop
    rectangle(x + 860, y + 58, 110, 2, 145, 145, 145); //shadowRight
    renderText(x + 870, y + 35, GLUT_BITMAP_TIMES_ROMAN_24, "9:00 AM");
    
    //icon1
    folderIcon(40, 520);
    renderText(x + 40, y + 500, GLUT_BITMAP_TIMES_ROMAN_10, "GRAPHICS");
    
    //icon2
    folderIcon(40, 420);
    renderText(x + 55, y + 400, GLUT_BITMAP_TIMES_ROMAN_10, "OOP");
    
    //icon3
    folderIcon(40, 320);
    renderText(x + 50, y + 300, GLUT_BITMAP_TIMES_ROMAN_10, "CODE");
}

// Function to handle display of the introduction scene
void displayIntro() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (!firstTextDisplayed) {
        drawBBStudio();
    }
    else {
        drawBitsBytes();
    }
    glutSwapBuffers();
}

// Function to handle display of the monitor scene
void displayMonitorScene() {
    monitorOnDesk(0, 0, 0, 0);
    glutSwapBuffers();
}

void loadingString(int x, int y) {
    renderText(x + 40, y + 200, GLUT_BITMAP_TIMES_ROMAN_24, "Loading....", 255, 255,255);
}

void loadingScreen(int x, int y, int w, int h, int colorR, int colorG, int colorB) {
    rectangle(x + 20, y + 20, w - 40, h - 40, colorR, colorG, colorB);
}

// Function to handle display of the loading screen
void displayLoadingScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (loadingComplete) { // Display loading screen for the first 4 seconds (assuming 30 FPS)
        loadingScreen(0, 0, 1000, 600, (loadingTime % 2 == 0) ? 0 : 42, (loadingTime % 2 == 0) ? 0 : 42, (loadingTime % 2 == 0) ? 0 : 42);
        loadingString(0, 0);

        monitor(0, 0, 1000, 600);

        printf("Displaying loading screen\n");
    }
    else {
        printf("if masuk false\n");
        monitor(0, 0, 1000, 600);
    }
    currentState = BITS_AND_BYTES_SCREEN;
    glutSwapBuffers();

}


// Function to handle display of the first scene
void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    int monitorX = SCREEN_WIDTH / 2 - SCREEN_WIDTH / 4 / 2; // X-coordinate of the monitor
    int monitorY = SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 / 2; // Y-coordinate of the monitor
    int monitorWidth = SCREEN_WIDTH / 4; // Width of the monitor
    int monitorHeight = SCREEN_HEIGHT / 4; // Height of the monitor
    zoomInMonitor(monitorX, monitorY, monitorWidth, monitorHeight);
    glutSwapBuffers();
}


// Function to animate the first scene
void animateScene1(int value) {
    // Update scale factors
    scaleX += scaleSpeed;
    scaleY += scaleSpeed;

    // Stop scaling when the outer monitor size is equal to or greater than the screen size
    if (SCREEN_WIDTH / 4 * scaleX >= SCREEN_WIDTH && SCREEN_HEIGHT / 4 * scaleY >= SCREEN_HEIGHT) {
        scaleX = SCREEN_WIDTH / (float)(SCREEN_WIDTH / 4); // Ensure scaleX is exactly the screen width
        scaleY = SCREEN_HEIGHT / (float)(SCREEN_HEIGHT / 4); // Ensure scaleY is exactly the screen height
        glutPostRedisplay(); // Redraw to update the display
        currentState = TURN_ON_MONITOR;
        return; // Exit the function
    }

    // Redraw
    //glutPostRedisplay();

    // Call update function again after a delay
    glutTimerFunc(1000 / FPS, animateScene1, 0);
}

// Function to handle animation of the introduction scene
void animateIntro(int value) {
    frame++;
    if (frame == FPS * delaySecondsBB) {
        firstTextDisplayed = true;
    }
    if (frame == FPS * delaySecondsMonitor) {
        currentState = SCENE_1;
        glutTimerFunc(delay, animateScene1, 0);
        return; // Exit the function after transitioning to the monitor scene
    }
    glutPostRedisplay();
    glutTimerFunc(delay, animateIntro, 0);
}


// Function to handle the timer for the loading screen animation
void timer(int value) {
    loadingTime++;
    printf("Loading time: %d\n", loadingTime);
    if (loadingTime >= 5 * FPS) { // 3 seconds with 30 FPS
        printf("Loading complete\n");
        loadingComplete = false;
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer, 0);
}



// Function to initialize OpenGL
void initGL() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); // Set up orthographic projection
}

// Main display function
void display() {
    switch (currentState) {
    case INTRO:
        displayIntro();
        break;
    case SCENE_1:
        displayScene1();
        break;
    case TURN_ON_MONITOR:
        displayLoadingScreen();
        break;
    case BITS_AND_BYTES_SCREEN:
        displayBitsAndBytes();
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Test");

    initGL();

    // Set the initial display function and start animation
    glutDisplayFunc(displayBitsAndBytes);
    glutTimerFunc(delay, animateIntro, 0);
    glutTimerFunc(0, timer, 0); // Start the timer immediately
    glutDisplayFunc(display);


    glutMainLoop();
    return 0;
}
