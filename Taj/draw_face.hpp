#ifndef draw_face_hpp
#define draw_face_hpp
float r =(100.0f/600.0f);
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




