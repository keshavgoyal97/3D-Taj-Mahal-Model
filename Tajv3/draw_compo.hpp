//
//  draw_compo.hpp
//  
//
//  Created by keshav goyal on 04/04/18.
//
//

#ifndef draw_compo_hpp
#define draw_compo_hpp
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define PI 3.1415926535898

float rx=(70.0f/600.0f);



void drawpoints(float centerx,float centery,float xc,float yc,int zz,int xx,float cons)
{
    if(zz==1)
    {
        //for(int i=centerx-x;i<=centerx+x;i++)
        glColor3f(0.2,0.2,0.2);
        glBegin(GL_LINES);
        glVertex3f(centerx+xc,centery+yc,cons);
        glVertex3f(centerx-xc,centery+yc,cons);
        glEnd();
    }
    else if(xx==1)
    {
        //for(int i=centerx-x;i<=centerx+x;i++)
        glColor3f(0.2,0.2,0.2);
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

void draw_door_y(int yy)
{
    glColor3f(0.2,0.2,0.2);
    
    glBegin(GL_LINES);
    // glNormal3f(0.0f, 0.0f, zz*1.0f);
   	for(float i=0;i<=0.25f;i+=0.001f){
        glVertex3f(yy*0.52f, i, rx);
        glVertex3f(yy*0.52f,i,-1*rx);}
    glEnd();
    
    glBegin(GL_LINES);
    for(float i=-1*rx;i<=rx;i+=0.001f){
        glVertex3f(yy*0.52f, 0, i);
        glVertex3f(yy*0.52f, 0.25f,i);}
    glEnd();
    
    displayCIRCLE(0,0.25f,rx,0,1,yy*0.52f);
    
}

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
//    glColor3f(1.0f, 1.0f, 1.0f);
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


#endif /* draw_compo_hpp */
