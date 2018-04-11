#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include<iostream>
using namespace std;

unsigned int texture[1];

struct Image{
    long SizeX;
    long SizeY;
    char *data;
};
typedef struct Image Image;

void LoadBMP(char *filename, Image *image){
    FILE *file;
    short int bpp;
    short int planes;
    long i;
    long size;
    char temp;
    
    file = fopen(filename, "rb");
    fseek(file, 18, SEEK_CUR);
    i = fread(&image->SizeX, 4, 1, file);
    i = fread(&image->SizeY, 4, 1, file);
    size = image->SizeX * image->SizeY * 3;
    i = fread(&bpp, 2, 1, file);
    i = fread(&planes, 2, 1, file);
    fseek(file, 24, SEEK_CUR);
    image->data = (char *)malloc(size);
    i = fread(image->data, size, 1, file);
    for(i = 0; i < size; i+=3){
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }
    fclose(file);
    free(image);
}

void LoadTextures(void){
    Image *image1;
    
    image1 = (Image *)malloc(sizeof(Image));
    LoadBMP("obs.bmp", image1);
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->SizeX, image1->SizeY, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
}


void display()
{
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
    
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
    
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glutSwapBuffers();
}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_NORMALIZE);
}

//Called when the window is resized
void handleResize(int w, int h) {
    // glViewport(0, 0, w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (double)w / (double)h, 1.0f, 200.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    //    glOrtho( -500, 500, -500, 500,-500 , 500);
    //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    //    glShadeModel(GL_SMOOTH)
    
    
    
    // gluPerspective(45.0, 2, 1.0, 800.0);
}

//void update(int value) {
//    _angle += 1.5f;
//    if (_angle > 360) {
//        _angle -= 360;
//    }
//    
//    glutPostRedisplay(); //Tell GLUT that the display has changed
//    
//    //Tell GLUT to call update again in 25 milliseconds
//    glutTimerFunc(25, update, 0);
//}


int main(int argc, char **argv){
    glutInit(&argc,argv);        //used to initialize the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400 );       /* A x A pixel screen window  */
    // userinput();
    glutCreateWindow("Polygon drawn"); /* window title                   */
    initRendering();
    
    //Set handler functions
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);//    glutDisplayFunc(redraw);
//    glutMouseFunc(mouse);
//    glutMotionFunc(motion);
//    glutIdleFunc(idle);
//    glutKeyboardFunc(normalKeyboard);
//    //    glutSpecialFunc(specialkeyboard);
//    
//    polygonOffsetVersion = 2;
//    glPolygonOffset(-2.0, -1.0);
//    
//    Lighting();
//    gluLookAt(0.0, 8.0, 40.0,
//              0, 8, 0.0,
//              0.0, 1.0, 0);
//    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
}
