#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif


#include <cmath>
#include <queue>
#include <utility>
#include <bits/stdc++.h>
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 5

float _angle=44.0f;
//float z=0.0;
float r =(100.0f/600.0f);
float rx=(70.0f/600.0f);
float sx=1.0f,sy=1.0f,sz=1.0f;
float lx = 0.0, lz = -1.0;
float x = 0.0, z = 5.0, xRot, yRot, zRot;
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

void drawpoints(float centerx,float centery,float xc,float yc,int zz,int xx,float cons)
{
	if(zz==1)
	{
		//for(int i=centerx-x;i<=centerx+x;i++)	
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex3f(centerx+xc,centery+yc,cons);
		glVertex3f(centerx-xc,centery+yc,cons);
		glEnd();
	}
	else if(xx==1)
	{
		//for(int i=centerx-x;i<=centerx+x;i++)
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex3f(cons,centery+yc,centerx+xc);
		glVertex3f(cons,centery+yc,centerx-xc);
		glEnd();
	
	}


}

void displayCIRCLE(float centerx,float centery,float R ,int zz,int xx,float cons)
{  
  float xc=0,yc=0;
  for(int i=0;i<=90;i++)
  {
    xc=R*Cos(i);
    yc=R*Sin(i);
   
    drawpoints(centerx,centery,xc,yc,zz,xx,cons);
    }
 // glEnd();             
  
  }

void draw_door_z(int zz)
{  
   glColor3f(0,0,0);
	
	glBegin(GL_LINES);
   // glNormal3f(0.0f, 0.0f, zz*1.0f);
   
    for(float i=-1*rx;i<=rx;i+=0.001f)
   { glVertex3f(i, 0, zz*0.5f);
    glVertex3f(i, 0.25f,zz* 0.5f);}
    
    glEnd();
    
    glBegin(GL_LINES);
    for(float i=0;i<=0.25f;i+=0.001f)
    {
       glVertex3f(rx,i,zz*0.5f);
       glVertex3f(-1*rx,i,zz*0.5f);
	}
	glEnd();    



    displayCIRCLE(0,0.25f,rx,1,0,zz*0.5f);

}


void draw_door_y(int yy)
{  
   glColor3f(0,0,0);
	
	glBegin(GL_LINES);
   // glNormal3f(0.0f, 0.0f, zz*1.0f);
   	for(float i=0;i<=0.25f;i+=0.001f){
    glVertex3f(yy*0.5f, i, rx);
    glVertex3f(yy*0.5f,i,-1*rx);}
    glEnd();
    
    glBegin(GL_LINES);
    for(float i=-1*rx;i<=rx;i+=0.001f){
    glVertex3f(yy*0.5f, 0, i);
     glVertex3f(yy*0.5f, 0.25f,i);}
    glEnd();

    displayCIRCLE(0,0.25f,rx,0,1,yy*0.5f);

}


void draw_window_z(int zz)
{





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


void draw_cylinder(float r1 , float r2, float h)
{

glRotatef(-90.0f,1,0,0);

GLUquadricObj *quadric=gluNewQuadric();
gluQuadricNormals(quadric, GLU_SMOOTH);
gluQuadricOrientation(quadric,GLU_OUTSIDE);
gluCylinder(quadric,r1,r2,h,50,50);
gluDeleteQuadric(quadric);
}

void draw_hemisphere(float r1,float r2){

glPushMatrix();

GLdouble eqn[4] = {0.0, 1.0, 0.0,r2};
   /*    clip lower half -- y < 0          */
   glClipPlane (GL_CLIP_PLANE0, eqn);
   glEnable (GL_CLIP_PLANE0);
   glRotatef (90.0, 1.0, 0.0, 0.0);
   glutSolidSphere(r1, 40, 40);
   glDisable(GL_CLIP_PLANE0);
glPopMatrix();
 //  glFlush ();

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
        
        glPushMatrix();
        glTranslatef(0.7f,0,0.7f);
        glColor3f(1,0,1);
        draw_cylinder(r/4,r/5,0.6f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.5,1.0,0);
        glTranslatef(0.7f,0.6f,0.7f);
        draw_cylinder(r/4,r/4,0.035f);
        glPopMatrix();
       // glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.5,1.0,0.5);
        glTranslatef(0.7f,0.65f,0.7f);
        draw_hemisphere(r/4,0.01f);
        
        glPopMatrix();
        
        
         glPushMatrix();
        glTranslatef(0.7f,0,-0.7f);
        glColor3f(1,0,1);
        draw_cylinder(r/4,r/5,0.6f);
        glPopMatrix();
        
         glPushMatrix();
        glColor3f(0.5,1.0,0);
        glTranslatef(0.7f,0.6f,-0.7f);
        draw_cylinder(r/4,r/4,0.035f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.5,1.0,0.5);
        glTranslatef(0.7f,0.65f,-0.7f);
        draw_hemisphere(r/4,0.01f);
        
        glPopMatrix();
        
        
         glPushMatrix();
        glTranslatef(-0.7f,0,0.7f);
        glColor3f(1,0,1);
        draw_cylinder(r/4,r/5,0.6f);
        glPopMatrix();
        
         glPushMatrix();
        glColor3f(0.5,1.0,0);
        glTranslatef(-0.7f,0.6f,0.7f);
        draw_cylinder(r/4,r/4,0.035f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.5,1.0,0.5);
        glTranslatef(-0.7f,0.65f,0.7f);
        draw_hemisphere(r/4,0.01f);
        
        glPopMatrix();
        
         glPushMatrix();
        glTranslatef(-0.7f,0,-0.7f);
        glColor3f(1,0,1);
        draw_cylinder(r/4,r/5,0.6f);
        glPopMatrix();
        
         glPushMatrix();
        glColor3f(0.5,1.0,0);
        glTranslatef(-0.7f,0.6f,-0.7f);
        draw_cylinder(r/4,r/4,0.035f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(0.5,1.0,0.5);
        glTranslatef(-0.7f,0.65f,-0.7f);
        draw_hemisphere(r/4,0.01f);
        
        glPopMatrix();


	 glPushMatrix();
         glColor3f(0,1,1);
         glTranslatef(0,0.35f,0);
        draw_cylinder(r-0.033,r-0.033,0.27f);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(0,0.62f,0);
        glTranslatef(0,0.1f,0);
        draw_hemisphere(r,0.15f);
        glPopMatrix();
        
        
              
        glPushMatrix();
        glColor3f(0,0.5,0);
        glTranslatef(0.3f,0.35f,0.3f);
        draw_cylinder(0.045,0.045,0.14f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(1.0,0,1.0);
        glTranslatef(0.3f,0.45f,0.3f);
        draw_cylinder(0.047,0.047,0.04f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(4,4,4);
        glTranslatef(0.3f,0.50f,0.3f);
        draw_hemisphere(0.046,0.1f);
        
        glPopMatrix();
        
        
                      
        glPushMatrix();
        glColor3f(0,0.5,0);
        glTranslatef(-0.3f,0.35f,0.3f);
        draw_cylinder(0.045,0.045,0.14f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(1.0,0,1.0);
        glTranslatef(-0.3f,0.45f,0.3f);
        draw_cylinder(0.047,0.047,0.04f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(4,4,4);
        glTranslatef(-0.3f,0.50f,0.3f);
        draw_hemisphere(0.046,0.1f);
        
        glPopMatrix();
        
                      
        glPushMatrix();
        glColor3f(0,0.5,0);
        glTranslatef(0.3f,0.35f,-0.3f);
        draw_cylinder(0.045,0.045,0.14f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(1.0,0,1.0);
        glTranslatef(0.3f,0.45f,-0.3f);
        draw_cylinder(0.047,0.047,0.04f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(4,4,4);
        glTranslatef(0.3f,0.50f,-0.3f);
        draw_hemisphere(0.046,0.1f);
        
        glPopMatrix();
        
        
                      
        glPushMatrix();
        glColor3f(0,0.5,0);
        glTranslatef(-0.3f,0.35f,-0.3f);
        draw_cylinder(0.045,0.045,0.14f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(1.0,0,1.0);
        glTranslatef(-0.3f,0.45f,-0.3f);
        draw_cylinder(0.047,0.047,0.04f);
        glPopMatrix();
        
        glPushMatrix();
        glColor3f(4,4,4);
        glTranslatef(-0.3f,0.50f,-0.3f);
        draw_hemisphere(0.046,0.1f);
        
        glPopMatrix();
        
         glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH);
        glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
   glDisable(GL_LIGHT2);
        draw_door_z(1);
        glPopMatrix();
        
          glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH);
        draw_door_z(-1);
        glPopMatrix();
        
         glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH);
        draw_door_y(1);
        glPopMatrix();
        
          glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH);
        draw_door_y(-1);
        glPopMatrix();
        
        
             
}





void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(0.0,0.0,1.0,1.0);
	glLoadIdentity();
	 gluLookAt( x, 0.0, z,
              x + lx, 0.0, z + lz,
              0.0, 1.0, 0.0);
	   //  gluLookAt(0.0f, 0.0f,5.0f , 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	  //  glRotatef(_angle,0.0f,1.0f,0.0f);
      //  drawBase();
             
        glPushMatrix();
         //  glTranslatef(0,0.2f,0);
        //    glColor3f(1.0,0.0,0.0);
         //   draw_cylinder();
      //   draw_gon();
     //    draw_cyl()
     //;
     
     draw();
    // draw_hemisphere();
      glPopMatrix(); 
           
          
           glFlush();
        glutSwapBuffers();     


}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearDepth(1.0f);
   glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
   glEnable(GL_LIGHT2);
    glEnable(GL_NORMALIZE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
}


float frc=0.5f;
void specialkeyboard(int key, int xx, int yy){
    float frc = 0.1;
    switch(key){
        case(GLUT_KEY_LEFT):
            _angle -= 0.05;
            lx = sin(_angle);
            lz = -cos(_angle);
            break;
            
        case(GLUT_KEY_RIGHT):
            _angle += 0.05;
            lx = sin(_angle);
            lz = -cos(_angle);
            break;
            
        case(GLUT_KEY_UP):
            x += lx*frc;
            z += lz*frc;
            break;
            
        case(GLUT_KEY_DOWN):
            x -= lx*frc;
            z -= lz*frc;
            break;
            
        default: break;
    }
    glutPostRedisplay();
}

void handleResize(int w, int h) {
   // glViewport(0, 0, w, h);
   double w2h = (h>0) ? (double)w/h:1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
   // glOrtho(-dim*w2h,+dim*w2h, -dim,+dim, -dim,+dim);
    glLoadIdentity();
    gluPerspective(45.0f, (double)w / (double)h, 1.0f, 200.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);						
	glLoadIdentity();
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho( -500, 500, -500, 500,-500 , 500);
    //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    //    glShadeModel(GL_SMOOTH)
    
    
    
   // gluPerspective(45.0, 2, 1.0, 800.0);
}

void windowMenu(int value)
{
  specialkeyboard((unsigned char)value, 0, 0);
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
	 	
    glutSpecialFunc(specialkeyboard);
    glutCreateMenu(windowMenu);
    glutAddMenuEntry("INcrease angle ",GLUT_KEY_LEFT);
     glutAddMenuEntry("Decrease angle ",GLUT_KEY_RIGHT);
      glutAttachMenu(GLUT_RIGHT_BUTTON);
   
    
	 	glutMainLoop();
		return 0;
}

