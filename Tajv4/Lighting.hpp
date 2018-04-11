#ifndef Lighting_hpp
#define Lighting_hpp
static GLfloat lightPosition[4];
static GLfloat lightColor[] = {0.8, 1.0, 0.8, 1.0};
void Lighting()
{
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
  
}
void Ediffuselight()
{
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
void Especularlight()
{
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
}
#endif
