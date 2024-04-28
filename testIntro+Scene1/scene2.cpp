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
//int frameCount = 0; // Counter for the number of frames rendered
//int maxFramesLoading = 100; // Maximum number of frames for the loading screen
//int maxFramesEffect = 200; // Maximum number of frames for the turning-on effect
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
//// Function to handle rendering the loading screen
//void renderLoadingScreen() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
//
//    // Calculate the brightness based on the frame count
//    float brightness = (float)frameCount / maxFramesLoading;
//
//    // Set the color to a bright shade based on the current brightness
//    glColor3f(brightness, brightness, brightness);
//
//    // Draw "Loading..." text
//    glRasterPos2f(100, 100);
//    const char* text = "Loading..."; // Corrected string type
//    for (int i = 0; text[i] != '\0'; ++i) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
//    }
//
//    glutSwapBuffers(); // Swap the front and back buffers
//}
//
//// Function to handle rendering the turning-on effect
//void displayScene2() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
//
//    // Calculate the brightness based on the frame count
//    float brightness = (float)(frameCount - maxFramesLoading) / maxFramesEffect;
//
//    // Set the color to a bright shade based on the current brightness
//    glColor3f(brightness, brightness, brightness);
//
//    // Draw a full-screen rectangle
//    glBegin(GL_QUADS);
//    glVertex2f(-1.0, -1.0);
//    glVertex2f(1.0, -1.0);
//    glVertex2f(1.0, 1.0);
//    glVertex2f(-1.0, 1.0);
//    glEnd();
//
//    glutSwapBuffers(); // Swap the front and back buffers
//}
//
//// Function to handle updating the frame count and redisplaying the scene
//void animateScene2(int value) {
//    frameCount++; // Increment the frame count
//
//    // If we are still rendering the loading screen
//    if (frameCount < maxFramesLoading) {
//        glutDisplayFunc(renderLoadingScreen); // Register the loading screen rendering function
//    }
//    // If loading is complete, switch to rendering the turning-on effect
//    else if (frameCount < maxFramesLoading + maxFramesEffect) {
//        glutDisplayFunc(displayScene2); // Register the turning-on effect rendering function
//    }
//
//    glutPostRedisplay();
//    glutTimerFunc(1000 / 60, animateScene2, 0); // Update at approximately 60 frames per second
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // Initialize GLUT
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set up the display mode
//    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Set the window size
//    glutCreateWindow("Turning On Screen Effect"); // Create the window
//    glEnable(GL_DEPTH_TEST); // Enable depth testing
//
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
//
//    glutTimerFunc(0, animateScene2, 0); // Start the update loop
//
//    glutMainLoop(); // Enter the GLUT main loop
//
//    return 0;
//}
