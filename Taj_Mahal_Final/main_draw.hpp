#ifndef main_draw_hpp
#define main_draw_hpp
#include "draw_compo.hpp"

//float z=0.0;


float sx=1.0f,sy=1.0f,sz=1.0f;

float xRot, yRot, zRot;
int flags;

void drawfix()
{
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    
    glVertex3f(2*r,0.35f,3*r);
    glVertex3f(3*r,0.35f,2*r);
    glVertex3f(3*r,0.35f,-2*r);
    glVertex3f(2*r,0.35f,-3*r);
    glVertex3f(-2*r,0.35f,-3*r);
    glVertex3f(-3*r,0.35f,-2*r);
    glVertex3f(-3*r,0.35f,2*r);
    glVertex3f(-2*r,0.35f,3*r);
    
    
    
    glEnd();
    
    
    
    
}



void draw()
{
    float gx=47.0f/256.0f, gy=79.0f/256.0f,gz=79.0f/256.0f;
//    glRotatef(_angle,0.0f,1.0f,0.0f);
//    glScalef(sx,sy,sz);

   //draws the various faces
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    draw_face(1);
    //glPopMatrix();
    
    //glPushMatrix();
    //glColor3f(0,1,0);
    draw_smallface(1,0);
    //glPopMatrix();
    
    //	glPushMatrix();
    //	glTranslatef(-0.5f,0,0);
    //	glColor3f(0,0,1);
    draw_smallface(1,1);
    //	glPopMatrix();
    
    //	glPushMatrix();
    //	glTranslatef(0,0,-1.0f);
    //	glColor3f(1,0,0);
    draw_face(-1);
    //glPopMatrix();
    
    
    //glPushMatrix();
    
    //glColor3f(0,1,0);
    //    glTranslatef(0,0,-1.0f);
    draw_smallface(-1,0);
    //glPopMatrix();
    
    //glPushMatrix();
    //glTranslatef(-0.5f,0,-1.0f);
    //glColor3f(0,0,1);
    draw_smallface(-1,1);
    //glPopMatrix();
    
    //	glPushMatrix();
    //glRotatef(-90,0,0,1);
    //glColor3f(1,0,0);
    draw_facey(1);
    //glPopMatrix();
    
    //glPushMatrix();
    //glColor3f(0,1,0);
    //glRotatef(-90,0,0,1);
    draw_smallfacey(1,0);
    //glPopMatrix();
    
    //glPushMatrix();
    //glRotatef(-90,0,0,1);
    //glTranslatef(0,0,-0.5f);
    //glRotatef(90,0,0,1);
    //	glColor3f(0,0,1);
    draw_smallfacey(1,1);
    //glPopMatrix();
    
    //glPushMatrix();
    //glRotatef(-90,0,0,1);
    //glColor3f(1,0,0);
    //	 glTranslatef(-1.0f,0,0);
    draw_facey(-1);
    //glPopMatrix();
    
    //glPushMatrix();
    //glColor3f(0,1,0);
    // glTranslatef(-1.0f,0,0);
    //glRotatef(-90,0,0,1);
    draw_smallfacey(-1,0);
    //glPopMatrix();
    
    //glPushMatrix();
    //glRotatef(-90,0,0,1);
    //	glTranslatef(-1.0f,0,-0.5f);
    //glRotatef(90,0,0,1);
    //	glColor3f(0,0,1);
    draw_smallfacey(-1,1);
    //glPopMatrix();
    
    
    //	glPushMatrix();
    //	glColor3f(1,1,0);
    draw_slnt(1,1);
    //	glPopMatrix();
    
    //	glPushMatrix();
    //	glColor3f(1,1,0);
    draw_slnt(1,-1);
    //	glPopMatrix();
    
    //	glPushMatrix();
    //	glColor3f(1,1,0);
    draw_slnt(-1,1);
    //	glPopMatrix();
    
    //	glPushMatrix();
    //	glColor3f(1,1,0);
    draw_slnt(-1,-1);
    glPopMatrix();
    
    glPushMatrix();
    drawBase();
    glPopMatrix();
    
    
    //draws minaret
    glPushMatrix();
    glTranslatef(0.7f,0,0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();
    
    
    // draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.6f,0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();
    // glPopMatrix();
    
    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    
    glPopMatrix();
    
    //complete minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(0.7f,0.65f,0.7f);
    draw_hemisphere(r/4,0.01f);
    
    glPopMatrix();
    
    //draws minaret
    glPushMatrix();
    glTranslatef(0.7f,0,-0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();
    
    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.6f,-0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();
    
    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,-0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,-0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    
    glPopMatrix();
    
    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(0.7f,0.65f,-0.7f);
    draw_hemisphere(r/4,0.01f);
    
    glPopMatrix();
    
    
    //draws minaret
    glPushMatrix();
    glTranslatef(-0.7f,0,0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();
    
    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.6f,0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();
    
    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    
    glPopMatrix();
    
    
    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(-0.7f,0.65f,0.7f);
    draw_hemisphere(r/4,0.01f);
    
    glPopMatrix();
    
    //draws minaret
    glPushMatrix();
    glTranslatef(-0.7f,0,-0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();
    
    
    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.6f,-0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();
    
    //draws disc along minaret
    
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,-0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,-0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    
    glPopMatrix();
    
    
    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(-0.7f,0.65f,-0.7f);
    draw_hemisphere(r/4,0.01f);
    
    glPopMatrix();
    
    
    //draw  dome
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0,0.35f,0);
    draw_cylinder(r-0.033,r-0.033,0.2f);
    glPopMatrix();
    
    ////draw  dome
    glPushMatrix();
    glTranslatef(0,0.55f,0);
    glTranslatef(0,0.11f,0);
    draw_hemisphere(r,0.08f);
    glPopMatrix();
  
    ////draw  dome
    glPushMatrix();
    glTranslatef(0,0.55f,0);
    if(flags)
    glColor3f(gx,gy,gz);
    draw_cylinder(r-0.031,r-0.031,0.08f);
    
    glPopMatrix();
    
    
    
    //draws guldasta
    
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    
    ////draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-1*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-1*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(2*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-2*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(2*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-2*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,-1*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,2*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,-2*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,-1*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,2*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws guldasta
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,-2*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    
    glPopMatrix();
    
    //draws chhatri
    
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.35f,0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.3f,0.45f,0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.50f,0.3f);
    draw_hemisphere(0.046,0.1f);
    
    glPopMatrix();
    
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.35f,0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.3f,0.45f,0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.50f,0.3f);
    draw_hemisphere(0.046,0.1f);
    
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.35f,-0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();
    
    //draws chhatri
    
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.3f,0.45f,-0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.50f,-0.3f);
    draw_hemisphere(0.046,0.1f);
    
    glPopMatrix();
    
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.35f,-0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.3f,0.45f,-0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();
    
    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.50f,-0.3f);
    draw_hemisphere(0.046,0.1f);
    
    glPopMatrix();
    
    //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
//    glDisable(GL_LIGHTING);
//    glDisable(GL_LIGHT0);
//    glDisable(GL_LIGHT1);
//    glDisable(GL_LIGHT2);
    draw_door_z(1);
    glPopMatrix();
    
      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_z(-1);
    glPopMatrix();
    
    
      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_y(1);
    glPopMatrix();
    
    
      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_y(-1);
    glPopMatrix();
    
      //draws window
    glPushMatrix();
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    draw_window_z(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(-3*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(-3*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    //draws window
    
    glPushMatrix();
    glTranslatef(-3*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
   
   //draws window 
    glPushMatrix();
    glTranslatef(-3*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    draw_window_y(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0,0.5*r);
    draw_window_y(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_y(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r);
    draw_window_y(1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r);
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r);
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0,-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0,0.5*r-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0,-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    
    //draws window
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    draw_window_slnt(1,1,1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    draw_window_slnt(-1,-1,-1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    draw_window_slnt(-1,1,1);
    glPopMatrix();
    
    //draws window
    glPushMatrix();
    draw_window_slnt(1,-1,-1);
    glPopMatrix();
    
    //draws an end
    glPushMatrix();
    drawfix();
    glPopMatrix();
    
    // glScalef(2,2,2);
}
#endif /* draw_compo_hpp */
