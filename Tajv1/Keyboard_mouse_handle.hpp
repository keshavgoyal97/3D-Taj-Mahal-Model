#ifndef Keyboard_mouse_handle_hpp
#define Keyboard_mouse_handle_hpp

 /* draw_compo_hpp */
float x = 0.0, z = 0.0;
float lx0 = 0.0, lz0 = -1.0;
float _angle=44.0f;
void specialkeyboard(int key, int xx, int yy){
    float frac = 0.1;
    switch(key){
        case(GLUT_KEY_LEFT):
            _angle -= 0.05;
            lx0 = sin(_angle);
            lz0 = -cos(_angle);
            break;
            
        case(GLUT_KEY_RIGHT):
            _angle += 0.05;
            lx0 = sin(_angle);
            lz0 = -cos(_angle);
            break;
            
        case(GLUT_KEY_UP):
            x += lx0*frac;
            z += lz0*frac;
            break;
            
        case(GLUT_KEY_DOWN):
            x -= lx0*frac;
            z -= lz0*frac;
            break;
            
        default: break;
    }
    glutPostRedisplay();
}

void handleResize(int w, int h) {
    // glViewport(0, 0, w, h);
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    // glOrtho(-dim*w2h,+dim*w2h, -dim,+dim, -dim,+dim);
//    glLoadIdentity();
    gluPerspective(45.0f, (double)w / (double)h, 1.0f, 200.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
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

#endif
