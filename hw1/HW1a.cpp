// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2017 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2017
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
    -0.5f , -0.75f,
    -0.5f , -0.5f,
    -0.5f , -0.25f,
    -0.5f ,  0.0f,
    -0.5f ,  0.25f,
    -0.5f ,  0.5f,
    -0.25f,  0.75f,
    0.0f ,  0.75f,
    0.25f,  0.75f,
    0.5f ,  0.75f,
    0.75f,  0.5f,
    0.75f,  0.25f,
    0.5f ,  0.0f,
    0.25f,  0.0f,
    0.0f ,  0.0f,
    -0.25f,  0.0f
};

static int DrawModes[] = {
    GL_POINTS,
    GL_LINES,
    GL_LINE_STRIP,
    GL_LINE_LOOP,
    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_QUADS,
    GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);	// set background color
    glColor3f   (1.0, 1.0, 1.0);		// set foreground color
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
    m_winW = w;
    m_winH = h;
    
    // compute aspect ratio
    float ar = (float) w / h;
    
    // set xmax, ymax;
    float xmax, ymax;
    if(ar > 1.0) {		// wide screen
        xmax = ar;
        ymax = 1.;
    } else {		// tall screen
        xmax = 1.;
        ymax = 1 / ar;
    }
    
    // set viewport to occupy full canvas
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    // init viewing coordinates for orthographic projection
    glLoadIdentity();
    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
    // clear canvas with background values
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    for(int i = 0; i < sizeof(DrawModes) ; ++i) { // Loop through DrawModes
        for(int y = 0; y < 3; ++y) { // x and y are for scaling and selection of vertex drawing and drawmode.
            for(int x = 0; x < 3; ++x) {
                glBegin(DrawModes[3*y+x]);
                for(int vertex = 0; vertex < 16; vertex++) {
                    glVertex2f( (Vertices[vertex*2]/3 - 1 + x), Vertices[(vertex*2)+1]/3 - 0.67 + y*0.67);
                }
                glEnd();
                glFlush();
            }
        }
    }
    
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
    // init group box
    QGroupBox *groupBox = new QGroupBox("Homework 1a");
    groupBox->setStyleSheet(GroupBoxStyle);
    
    return(groupBox);
}
