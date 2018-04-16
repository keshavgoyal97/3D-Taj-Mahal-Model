#ifndef draw_face_hpp
#define draw_face_hpp
float r =(100.0f/600.0f);

//draw main face along xy plane
void draw_face(int zz)
{
    glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(0.0f, 0.0f, zz*1.0f);
    glVertex3f(-1*r, 0, zz*0.5f);
    glVertex3f(-1*r, 0.45f, zz*0.5f);
    glVertex3f(r, 0.45f, zz*0.5f);
    glVertex3f(r, 0, zz*0.5f);
    glEnd();
}

//draw main face along yz plane

void draw_facey(int yy)
{
    glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    glNormal3f(yy*1.0f, 0.0f, 0.0f);
    glVertex3f(yy*0.5f, 0, r);
    glVertex3f(yy*0.5f, 0.45f, r);
    glVertex3f(yy*0.5f, 0.45f, -1*r);
    glVertex3f(yy*0.5f, 0, -1*r);
    glEnd();
}

//draw face with less height along yz plane . 

void draw_smallfacey(int yy, int xy)
{
    
    float cc=(xy==0?0:-0.5f);
    glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    
    glNormal3f(yy*1.0f, 0.0f, 0.0f);
    glVertex3f(yy*0.5f, 0, r+cc);
    glVertex3f(yy*0.5f,0.35f, r+cc);
    glVertex3f(yy*0.5f, 0.35f, 2*r+cc);
    glVertex3f(yy*0.5f, 0, 2*r+cc);
    glEnd();
    
    
}

//draw face with less height along xy plane .

void draw_smallface(int zz,int xy)
{
    glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f);
    //Front
    
    float cc=(xy==0?0:-0.5f);
    glNormal3f(0.0f, 0.0f, zz*1.0f);
    glVertex3f(r+cc, 0, zz*0.5f);
    glVertex3f(r+cc,0.35f, zz*0.5f);
    glVertex3f(2*r+cc, 0.35f, zz*0.5f);
    glVertex3f(2*r+cc, 0, zz*0.5f);
    glEnd();
    
    
}


//used to draw face joining the faces in xy and yz planes.

void draw_slnt(int xx,int yy)
{
    glBegin(GL_QUADS);
    glVertex3f(2*r*xx, 0, 0.5f*yy);
    glVertex3f(2*r*xx, 0.35f, 0.5f*yy);
    glVertex3f(0.5f*xx, 0.35f, 2*r*yy);
    glVertex3f(0.5f*xx, 0, r*yy);
    glEnd();
    
    
}

#endif /* draw_compo_hpp */



