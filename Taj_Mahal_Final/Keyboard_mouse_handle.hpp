#ifndef Keyboard_mouse_handle_hpp
#define Keyboard_mouse_handle_hpp

 /* draw_compo_hpp */
//float x = 0.0, z = 0.0;
//float lx0 = 0.0, lz0 = -1.0;
//float _angle=44.0f;
static float lightAngle = 0.0, lightHeight = 20;
GLfloat angle = -150;
GLfloat angle2 = 30;

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;
//void specialkeyboard(int key, int xx, int yy){
//    float frac = 0.1;
//    switch(key){
//        case(GLUT_KEY_LEFT):
//            _angle -= 0.05;
//            lx0 = sin(_angle);
//            lz0 = -cos(_angle);
//            break;
//            
//        case(GLUT_KEY_RIGHT):
//            _angle += 0.05;
//            lx0 = sin(_angle);
//            lz0 = -cos(_angle);
//            break;
//            
//        case(GLUT_KEY_UP):
//            x += lx0*frac;
//            z += lz0*frac;
//            break;
//            
//        case(GLUT_KEY_DOWN):
//            x -= lx0*frac;
//            z -= lz0*frac;
//            break;
//            
//        default: break;
//    }
//    glutPostRedisplay();
//}
//
//void handleResize(int w, int h) {
//    // glViewport(0, 0, w, h);
//    if (h == 0)
//        h = 1;
//    float ratio = w * 1.0 / h;
//    glMatrixMode(GL_PROJECTION);
//    
//    glLoadIdentity();
//    glViewport(0, 0, w, h);
////    glMatrixMode(GL_PROJECTION);
////    // glOrtho(-dim*w2h,+dim*w2h, -dim,+dim, -dim,+dim);
////    glLoadIdentity();
//    gluPerspective(45.0f, (double)w / (double)h, 1.0f, 200.0f);
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glMatrixMode(GL_MODELVIEW);
//
////    glMatrixMode(GL_MODELVIEW);
////    glLoadIdentity();
//    //    glMatrixMode(GL_PROJECTION);
//    //    glLoadIdentity();
//    //    glOrtho( -500, 500, -500, 500,-500 , 500);
//    //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//    //    glShadeModel(GL_SMOOTH)
//    // gluPerspective(45.0, 2, 1.0, 800.0);
//}

//void windowMenu(int value)
//{
//    specialkeyboard((unsigned char)value, 0, 0);
//}

static void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving =0.0;
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            lightMoving = 1;
            lightStartX = x;
            lightStartY = y;
        }
        if (state == GLUT_UP) {
            lightMoving = 0.0;
        }
    }
}

static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
    if (lightMoving) {
        lightAngle += (x - lightStartX)/40.0;
        lightHeight += (lightStartY - y)/20.0;
        lightStartX = x;
        lightStartY = y;
        glutPostRedisplay();
    }
}

static void idle(void)
{
    if (!lightMoving) {
        lightAngle += 0.02;
    }
    glutPostRedisplay();
}

static void normalKeyboard(unsigned char c, int x, int y){
    if (c == 27) {
        exit(0);
    }
    glutPostRedisplay();
}


#endif
