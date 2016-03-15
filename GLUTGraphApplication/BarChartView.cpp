//
//  BarChartView.cpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 14/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "BarChartView.hpp"
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library

void BarChartView::draw() {
    
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
    //Trapezoid
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -0.5f, -5.0f);
    glVertex3f(-0.7f, -0.5f, -5.0f);
    glEnd(); //End quadrilateral coordinates
    
}


BarChartView::BarChartView(std::vector<std::string*> xVals, std::vector<double> yVals) {
    this->xVals = xVals;
    this->yVals = yVals;
}


