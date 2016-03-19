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
#include <math.h>









void BarChartView::draw() {
    //CGRect rect = CGRectMake(100, 0, 250, 250);
    //drawPieChartInRect(rect);
    
    
    /*
    CGRect rect = CGRectMake(0,0,100,100);
    drawRect(rect, CGColorRed());
    
    CGRect rect2 = CGRectMake(100,0,100,100);
    drawRect(rect2, CGColorBlue());
    
    CGRect rect3 = CGRectMake(200,0,100,100);
    drawRect(rect3, CGColorGreen());

     */


    //drawPieSegmentInRect(CGRectMake(0, 0, 100, 100), 100);
   // drawCircle(250, 250, 100, 10);
    /*
    
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
    //Trapezoid
    glColor3f(1, 0, 0);

    glVertex2f(-0.7f, -1.5f);
    glColor3f(0, 1, 0);

    glVertex2f(0.0f, -1.5f);
    glColor3f(0, 1, 0);
    
    glVertex2f(-0.7f, -0.5f);
    glColor3f(0, 1, 0);

    glVertex2f(0.0f, -0.5f);
     
    glEnd(); //End quadrilateral coordinates
    */
    
}


BarChartView::BarChartView(std::vector<std::string*> xVals, std::vector<double> yVals) {
    this->xVals = xVals;
    this->yVals = yVals;
}


