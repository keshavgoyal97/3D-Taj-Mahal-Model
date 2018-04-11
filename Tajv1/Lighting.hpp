#ifndef Lighting_hpp
#define Lighting_hpp

void Lighting()
{
    
    
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
    
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { -3.0, 4.0, 2.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightColor1);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
//    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1);
//    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
//    GLfloat lightColor2[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
//    GLfloat lightPos2[] = {3.0f, 0.0f, 0.5f, 1.0f}; //Positioned at (300, 0, 100)
//    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
//    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
    
    
}

#endif
