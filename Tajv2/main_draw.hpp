#ifndef main_draw_hpp
#define main_draw_hpp
#include "draw_compo.hpp"

//float z=0.0;


float sx=1.0f,sy=1.0f,sz=1.0f;

float xRot, yRot, zRot;


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
    //    glRotatef(_angle,0.0f,1.0f,0.0f);
    //    glScalef(sx,sy,sz);
    glPushMatrix();
    //    glColor3f(1,1,1);
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
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_DEPTH);
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_LIGHT0);
    //    glDisable(GL_LIGHT1);
    //    glDisable(GL_LIGHT2);
    draw_door_z(1);
    glPopMatrix();
    
    glPushMatrix();
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_DEPTH);
    draw_door_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_DEPTH);
    draw_door_y(1);
    glPopMatrix();
    
    glPushMatrix();
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_DEPTH);
    draw_door_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    
    glPushMatrix();
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(-3*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0,0);
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0.175f,0);
    draw_window_z(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(-3*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0,0);
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5*r-3*r,0.175f,0);
    draw_window_z(-1);
    glPopMatrix();
    
    
    glPushMatrix();
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r);
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r);
    draw_window_y(1);
    glPopMatrix();
    
    
    glPushMatrix();
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r);
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0);
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r);
    draw_window_y(-1);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0,0,-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r-3*r);
    draw_window_y(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0,0,-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0.5*r-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.175f,0.5*r-3*r);
    draw_window_y(-1);
    glPopMatrix();
    
    
    glPushMatrix();
    draw_window_slnt(1,1,1);
    glPopMatrix();
    
    glPushMatrix();
    draw_window_slnt(-1,-1,-1);
    glPopMatrix();
    
    glPushMatrix();
    draw_window_slnt(-1,1,1);
    glPopMatrix();
    
    glPushMatrix();
    draw_window_slnt(1,-1,-1);
    glPopMatrix();
    
    glPushMatrix();
    drawfix();
    glPopMatrix();
}

#endif /* draw_compo_hpp */
