#include <iostream>
#include"common.h"
#include <cmath>
#include <queue>
#include <utility>


int value;
float _angle=42.0f;
float z=0.0;
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 5
using namespace std;
void drawbase(int xx1,int xx2,int zz1,int zz2)
{
	//glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(xx1*0.75f, 0, 0.75f*zz1);
    glVertex3f(xx1*0.75f, -0.15f, 0.75f*zz1);
    glVertex3f(-0.75f*xx2, -0.15f, 0.75f*zz2);
    glVertex3f(-0.75f*xx2, 0, 0.75f*zz2);
    


}

void drawBase()
{
    glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f);
    //Front
    drawbase(1,1,1,1);
 
    //Right
    glNormal3f(1.0f, 0.0f, 0.0f);
   drawbase(1,-1,1,-1);
 
    //Back
    glNormal3f(0.0f, 0.0f, -1.0f);
    drawbase(1,1,-1,-1);
    //Left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    drawbase(-1,1,1,-1);
    glEnd();  


}

void draw_hemisphere(){

GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};


   glColor3f (1.0, 1.0, 1.0);
 //  glPushMatrix();
   glTranslatef (0.0, 0.0, 0.0);
   glClipPlane (GL_CLIP_PLANE0, eqn);
   glEnable (GL_CLIP_PLANE0);
//  glRotatef (90.0, 1.0, 0.0, 0.0);
   glutSolidSphere(1.0, 20, 16);
  // glPopMatrix();
 //  glFlush ();

}

void draw_smallfacey()
{
	glBegin(GL_QUADS);
  // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0, r);
    glVertex3f(0.5f,0.35f, r);
    glVertex3f(0.5f, 0.35f, 2*r);
    glVertex3f(0.5f, 0, 2*r);
    glEnd();


}


void draw_smallface()
{
	glBegin(GL_QUADS);
  // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(r, 0, 0.5f);
    glVertex3f(r,0.35f, 0.5f);
    glVertex3f(2*r, 0.35f, 0.5f);
    glVertex3f(2*r, 0, 0.5f);
    glEnd();


}

void draw_face()
{
	glBegin(GL_QUADS);
  // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1*r, 0, 0.5f);
    glVertex3f(-1*r, 0.45f, 0.5f);
    glVertex3f(r, 0.45f, 0.5f);
    glVertex3f(r, 0, 0.5f);
    glEnd();
}


void draw_facey()
{
	glBegin(GL_QUADS);
  // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0, r);
    glVertex3f(0.5f, 0.45f, r);
    glVertex3f(0.5f, 0.45f, -1*r);
    glVertex3f(0.5f, 0, -1*r);
    glEnd();
}

void draw_slnt(int xx,int yy)
{
glBegin(GL_QUADS);
        glVertex3f(2*r*xx, 0, 0.5f*yy);
        glVertex3f(2*r*xx, 0.35f, 0.5f*yy);
        glVertex3f(0.5f*xx, 0.35f, 2*r*yy);
       glVertex3f(0.5f*xx, 0, r*yy);
        glEnd();


}

void draw()
{
         glRotatef(_angle,0.0f,1.0f,0.0f);
         glScalef(sx,sy,sz);
        glPushMatrix();
	glColor3f(1,0,0);
	draw_face();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,1,0);
	draw_smallface();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.5f,0,0);
	glColor3f(0,0,1);
	draw_smallface();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,-1.0f);
	glColor3f(1,0,0);
	draw_face();
	glPopMatrix();
	
	
	glPushMatrix();
	
	glColor3f(0,1,0);
        glTranslatef(0,0,-1.0f);
	draw_smallface();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.5f,0,-1.0f);
	glColor3f(0,0,1);
	draw_smallface();
	glPopMatrix();
	
	glPushMatrix();
	//glRotatef(-90,0,0,1);
	glColor3f(1,0,0);
	draw_facey();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,1,0);
	//glRotatef(-90,0,0,1);
	draw_smallfacey();
	glPopMatrix();
	
	glPushMatrix();
	//glRotatef(-90,0,0,1);
	glTranslatef(0,0,-0.5f);
	//glRotatef(90,0,0,1);
	glColor3f(0,0,1);
	draw_smallfacey();
	glPopMatrix();

	glPushMatrix();
	//glRotatef(-90,0,0,1);
	glColor3f(1,0,0);
	 glTranslatef(-1.0f,0,0);
	draw_facey();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,1,0);
	 glTranslatef(-1.0f,0,0);
	//glRotatef(-90,0,0,1);
	draw_smallfacey();
	glPopMatrix();
	
	glPushMatrix();
	//glRotatef(-90,0,0,1);
	glTranslatef(-1.0f,0,-0.5f);
	//glRotatef(90,0,0,1);
	glColor3f(0,0,1);
	draw_smallfacey();
	glPopMatrix();
	
	
	glPushMatrix();
	glColor3f(1,1,0);
	draw_slnt(1,1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,0);
	draw_slnt(1,-1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,0);
	draw_slnt(-1,1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,0);
	draw_slnt(-1,-1);
	glPopMatrix();
	
	 glPushMatrix();
        drawBase();
        glPopMatrix();

}


void draw_gon()
{
    
    glPushMatrix();
    glTranslatef(0,0,0.7f);
    glColor3f(1,1,1);
    draw_face();
    glColor3f(1,1,1);
    
    glTranslatef(0.8,0,0.0);
    //glScalef(1,0.8,1);
    draw_smallface();
    glTranslatef(-0.8,0,0);
    glTranslatef(-0.8,0,0);
    glColor3f(1,1,1);
    draw_smallface();
    
    glPopMatrix();
    // glScalef(1,1,1);
    
    /*  glTranslatef(0,0,-0.7f);
     draw_face();
     //  glScalef(1,0.8,1);
     glTranslatef(0.8,0,-0.7f);
     draw_smallface();
     glTranslatef(-0.8,0,-0.7f);
     draw_smallface();
     //   glScalef(1,1,1);
     
     
     glRotatef(90,0,1,0);
     glTranslatef(0,0,0.7f);
     draw_face();
     glTranslatef(0.8,0,0.7);
     //glScalef(1,0.8,1);
     draw_smallface();
     glTranslatef(-0.8,0,0.7);
     draw_smallface();
     //  glScalef(1,1,1);
     
     glTranslatef(0,0,-0.7f);
     draw_face();
     glScalef(1,0.8,1);
     // glTranslatef(0.8,0,-0.7f);
     draw_smallface();
     glTranslatef(-0.8,0,-0.7f);
     draw_smallface();
     //   glScalef(1,1,1);
     
     glRotatef(-90,0,1,0);*/
    
    glPushMatrix();
    glTranslatef(0,0,-0.7f);
    glColor3f(1,1,1);
    draw_face();
    glColor3f(1,1,1);
    
    glTranslatef(0.8,0,0.0);
    //glScalef(1,0.8,1);
    draw_smallface();
    glTranslatef(-0.8,0,0);
    glTranslatef(-0.8,0,0);
    glColor3f(1,1,1);
    draw_smallface();
    
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.4,0,0);
    glRotatef(90,0,1,0);
    glTranslatef(0,0,0.7f);
    glColor3f(1,1,1);
    draw_face();
    glColor3f(1,1,1);
    
    glTranslatef(0.8,0,0.0);
    //glScalef(1,0.8,1);
    draw_smallface();
    glTranslatef(-0.8,0,0);
    glTranslatef(-0.8,0,0);
    glColor3f(1,1,1);
    draw_smallface();
    
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.4,0,0);
    glRotatef(-90,0,1,0);
    glTranslatef(0,0,0.7f);
    glColor3f(1,1,1);
    draw_face();
    glColor3f(1,1,1);
    
    glTranslatef(0.8,0,0.0);
    //glScalef(1,0.8,1);
    draw_smallface();
    glTranslatef(-0.8,0,0);
    glTranslatef(-0.8,0,0);
    glColor3f(1,1,1);
    draw_smallface();
    
    glPopMatrix();
    
    
    
    
}



void draw_cylinder()
{
    
    //glMatrixMode(GL_MODELVIEW);
    
    //glColor3f(0.0f,1.0f,0.0f);
    glRotatef(90,0,1,0);
    //glBegin(GL_POLYGON);
    GLUquadricObj *quadric=gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    
    //renderCylinder(x1,y1,z1,x2,y2,z2,radius,subdivisions,quadric);
    /*glBegin(GL_LINES);
     glVertex3f(-0.75f, -0.15f, -0.75f);
     glVertex3f(-0.75f, 0.15f, -0.75f);
     glEnd();*/
    
    gluCylinder(quadric,0.04f,0.02f,0.4f,1,1);
    //glEnd();
    //glFlush();
    gluDeleteQuadric(quadric);
}



void draw_cyl()
{
    
    glScalef( 0.1f,1,0.1f);
    glBegin(GL_QUAD_STRIP);
    for (int j=0;j<=360;j+=DEF_D) {
        glColor3f(1.0,0.0,0.0);
        glVertex3f(Cos(j),1.5f,Sin(j));
        glColor3f(1.0,0.0,0.0);
        glVertex3f(Cos(j),0.0f,Sin(j));
    }
    glEnd();
    
    /* top and bottom circles */
    /* reuse the currentTexture on top and bottom) */
    /*   for (int i=1;i>=-1;i-=2) {
     glBegin(GL_TRIANGLE_FAN);
     glColor3f(0.0,0.0,1.0);
     glVertex3f(0,i,0);
     for (int k=0;k<=360;k+=DEF_D) {
     glColor3f(1.0,0.0,0.0);
     glVertex3f(i*Cos(k),i,Sin(k));
     }
     glEnd();
     }*/
    
    
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -8.0f);
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    
    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {3.0f, 0.0f, 0.3f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    
    GLfloat lightColor1[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos1[] = {-5.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    
    GLfloat lightColor2[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos2[] = {3.0f, 0.0f, 0.5f, 1.0f}; //Positioned at (300, 0, 100)
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
    
    gluLookAt(0.0f, 0.0f,5.0f+z , 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-1*_angle,0.0f,1.0f,0.0f);
    glPushMatrix();
    glTranslatef(0,0.2f,0);
    //    glColor3f(1.0,0.0,0.0);
    //   draw_cylinder();
    draw();
    //    draw_cyl();
    glPopMatrix();
    glPushMatrix();
    drawBase();
    glPopMatrix();
    //glPushAttrib(GL_CURRENT_BIT);
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 1.0, 1.0);
//    glNormal3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(-0.5f, -1.0f, -0.0f);
//    glVertex3f(0.5f, -1.0f, -0.0f);
//    glVertex3f(0.5f, 1.0f, -0.0f);
//    glVertex3f(-0.5f, 1.0f, -0.0f);
//    glEnd();
//    glPushMatrix();
//    glTranslatef(0.0f, 0.5f, 0.01f);
//    glBegin(GL_QUADS);
//    glColor3f(0.2f,0.6f,0.1f);
//    glNormal3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(-0.4f, -0.4f, 0.0f);
//    glVertex3f(0.4f, -0.4f, 0.0f);
//    glVertex3f(0.4f, 0.4f, 0.0f);
//    glVertex3f(-0.4f, 0.4f, 0.0f);
//    glEnd();
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0.0f, -0.5f, 0.01f);
//    // glPopMatrix();
//    // glPushMatrix();
//    //glTranslatef(0.0f, 0.5f, 0.0f);
//    glBegin(GL_QUADS);
//    glColor3f(0.2f,0.6f,0.1f);
//    glNormal3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(-0.4f, -0.4f, 0.0f);
//    glVertex3f(0.4f, -0.4f, 0.0f);
//    glVertex3f(0.4f, 0.4f, 0.0f);
//    glVertex3f(-0.4f, 0.4f, 0.0f);
//    glPopMatrix();
//    glEnd();
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(2.0, 0.0, 0.0);
//    glRotatef(-90.0f, 0.0, 2.0, 0.0);
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 1.0, 1.0);
//    glNormal3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(-2.5f, -2.0f, -0.0f);
//    glVertex3f(2.5f, -2.0f, -0.0f);
//    glVertex3f(2.5f, 2.0f, -0.0f);
//    glVertex3f(-2.5f, 2.0f, -0.0f);
//    glEnd();
//    glPopMatrix();
//    glBegin(GL_LINES);
//    glColor3d(1, 0, 0);
//    glVertex3f(0.0f, 0.0f,0.0f);
//    glVertex3f(4.0f, 0.0f, 0.0f);
//    glColor3d(0, 1.0 , 0.0);
//    glVertex3f(0.0f, 0.0f,0.0f);
//    glVertex3f(0.0f, 4.0f, 0.0f);
//    glColor3d(0, 0, 1);
//    glVertex3f(0.0f, 0.0f,0.0f);
//    glVertex3f(0.0f, 0.0f, 4.0f);
//    glEnd();
    //    glBegin(GL_QUADS);
    //
    //    glColor3d(1.0f, 1.0f, 1.0f);
    //    glNormal3f(0.0f, 1.0f, 0.0f);
    //    glVertex3f(-1.5f, 1.0f, 1.5f);
    //    glVertex3f(1.5f, 1.0f, 1.5f);
    //    glVertex3f(1.5f, 1.0f, -1.5f);
    //    glVertex3f(-1.5f, 1.0f, -1.5f);
    //  //  Front
    //   // glNormal3f(0.0f, 0.0f, 01.0f);
    //    glNormal3f(-1.0f, 0.0f, 1.0f);
    //   // glColor3f(0.4f, 0.3f, 0.5f);
    //    glVertex3f(-1.50f, -1.000f, 1.500f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(1.50f, -1.00f, 1.50f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(1.50f, 1.0f, 1.50f);
    //    //glNormal3f(-1.0f, 0.0f, 1.0f);
    //    glVertex3f(-1.50f, 1.0f, 1.50f);
    //
    //
    //
    //    //Right
    //    glNormal3f(0.10f, 0.0f, 0.0f);
    //    //glNormal3f(1.0f, 0.0f, -1.0f);
    // //   glColor3f(0.4f, 0.6f, 0.7f);
    //    glVertex3f(1.50f, -1.0f, -1.50f);
    //    //glNormal3f(1.0f, 0.0f, -1.0f);
    //    glVertex3f(1.50f, 1.0f, -1.50f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(1.50f, 1.0f, 1.50f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(1.50f, -1.0f, 1.50f);
    //
    //    //Back
    //      glNormal3f(0.0f, 0.0f, -0.10f);
    //    //glNormal3f(-1.0f, 0.0f, -1.0f);
    // //   glColor3f(0.3f, 0.6f, 0.1f);
    //    glVertex3f(-1.50f, -1.0f, -1.50f);
    //    //glNormal3f(-1.0f, 0.0f, -1.0f);
    //    glVertex3f(-1.50f, 1.0f, -1.50f);
    //    //glNormal3f(1.0f, 0.0f, -1.0f);
    //    glVertex3f(1.50f, 1.0f, -1.50f);
    //    //glNormal3f(1.0f, 0.0f, -1.0f);
    //    glVertex3f(1.50f, -1.0f, -1.50f);
    //
    //    //Left
    //      glNormal3f(-0.10f, 0.0f, 0.0f);
    //    //glNormal3f(-1.0f, 0.0f, -1.0f);
    //   // glColor3f(0.8f, 0.4f, 0.5f);
    //    glVertex3f(-1.50f, -1.0f, -1.50f);
    //    //glNormal3f(-1.0f, 0.0f, 1.0f);
    //    glVertex3f(-1.50f, -1.0f, 1.50f);
    //    //glNormal3f(-1.0f, 0.0f, 1.0f);
    //    glVertex3f(-1.50f, 1.0f, 1.50f);
    //    //glNormal3f(-1.0f, 0.0f, -1.0f);
    //    glVertex3f(-1.50f, 1.0f, -1.50f);
    //
    //
    //
    //    glEnd();
    //
    //    //glColor3f(1.0f, 1.0f, 1.0f);
    //    //glPopAttrib();
    //    glBegin(GL_QUADS);
    //    glVertex3f(-0.20f, -0.10f, 1.51f);
    //    glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.20f, -0.10f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.20f, -1.0f, 1.51f);
    //    //glNormal3f(-1.0f, 0.0f, 1.0f);
    //    glVertex3f(-0.20f, -1.0f, 1.51f);
    //
    //   // glColor3f(.4f, .50f, .70f);
    //    glVertex3f(-0.80f, -0.40f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(-0.50f, -0.40f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(-0.50f, -1.0f, 1.51f);
    //    glVertex3f(-0.80f, -1.0f, 1.51f);
    //    //glNormal3f(-1.0f, 0.0f, 1.0f);
    //
    //    glVertex3f(0.80f, -0.40f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.50f, -0.40f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.50f, -1.0f, 1.51f);
    //    glVertex3f(0.80f, -1.0f, 1.51f);
    //
    //
    //    glVertex3f(-0.80f, 0.0f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(-0.50f, 0.0f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(-0.50f, 0.60f, 1.51f);
    //    glVertex3f(-0.80f, 0.60f, 1.51f);
    //
    //
    //    glVertex3f(0.80f, 0.0f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.50f, 0.0f, 1.51f);
    //    //glNormal3f(1.0f, 0.0f, 1.0f);
    //    glVertex3f(0.50f, 0.60f, 1.51f);
    //    glVertex3f(0.80f, 0.60f, 1.51f);
    //
    //
    //    glEnd();
    //
    
    glutSwapBuffers();
    
    
}


//void myinit(void)
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
//    glClearDepth(1.0f);                   // Set background depth to farthest
//    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
//    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//    glShadeModel(GL_SMOOTH);/* gray background */
//    gluPerspective(45, 2, 0.1, 200);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    glOrtho( -250, 250, -250, 250,-250 , 250);
//
//}
//Called when a key is pressed
void handleKeypress(int key, int x, int y) {
    switch (key) {
        case(GLUT_KEY_LEFT):
            _angle=_angle+1.0f;
            cout<<"a"<<" ";
            if(_angle>360)
            _angle=_angle-360;
            break;
        case(GLUT_KEY_RIGHT):
            _angle=_angle-1.0f;
            cout<<"b"<<" ";
            if(_angle>=360)
            _angle=_angle+360;
            break;
        case GLUT_KEY_UP :
            z=z+0.1;
            cout<<"c"<<" ";
            break;
        case GLUT_KEY_DOWN :
            z=z-0.1;
            cout<<"d"<<" ";
            break;
        case 27: //Escape key
            cout<<"a"<<" ";
            exit(0);
    }
        glutPostRedisplay();
}

//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glEnable(GL_NORMALIZE);
    glEnable(GL_SMOOTH);
}

//Called when the window is resized
void handleResize(int w, int h) {
    // glViewport(0, 0, w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (double)w / (double)h, 0.1f, 200.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    //    glOrtho( -500, 500, -500, 500,-500 , 500);
    //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    //    glShadeModel(GL_SMOOTH)
    
    
    
    // gluPerspective(45.0, 2, 1.0, 800.0);
}

void update(int value) {
    _angle += 1.5f;
    if (_angle > 360) {
        _angle -= 360;
    }
    
    glutPostRedisplay(); //Tell GLUT that the display has changed
    
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

void windowMenu(int value)
{
  handleKeypress((unsigned char)value, 0, 0);
}

int main(int argc, char** argv)
{
		
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
		glutInitWindowSize(600,600);
		glutCreateWindow("Taj Mahal");
		initRendering();
		glutDisplayFunc(display);
	 	glutReshapeFunc(handleResize);
	 	
    glutSpecialFunc(handleKeypress);
    glutCreateMenu(windowMenu);
    glutAddMenuEntry("INcrease angle ",GLUT_KEY_LEFT);
     glutAddMenuEntry("Decrease angle ",GLUT_KEY_RIGHT);
      glutAttachMenu(GLUT_RIGHT_BUTTON);
   
    
	 	glutMainLoop();
		return 0;
}


