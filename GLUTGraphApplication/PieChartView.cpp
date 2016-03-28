//
//  PieChartView.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "PieChartView.hpp"
#include "CGGeometry.hpp"
#include <math.h>
#include <string>
#include <iostream>

#ifdef __APPLE__
#include <GLUT/GLUT.h> //GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h> //OpenGL Library
#elif defined _WIN32 || defined _WIN64
#    include <GL\glut.h>
#endif


void drawArc(float x, float y, float radius, float startAngleOuter, float sweepAngleOuter, CGColor color) {
    
    setContextColor(color);
    
    glPushMatrix();
    glTranslatef(x, y,0);
    
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(0, 0);
    
    for (int i = startAngleOuter; i <= sweepAngleOuter; i++) {
        float x = radius * cosf(degreesToRadians(i));
        float y = radius * sinf(degreesToRadians(i));
        glVertex2f(x,y);//output vertex
    }
    
    glEnd();
    glPopMatrix();
    
}

void PieChartView::drawLegend(CGRect rect) {
  
    std::vector<std::string*>::iterator axisIterator = xVals.begin();
    std::vector<CGColor>::iterator colorIterator = colors.begin();
    
    int yOffset = rect.y;
    int xOffset = rect.x;
    
    for (axisIterator = xVals.begin(); axisIterator != xVals.end(); axisIterator++) {
        // Print String
        std::string *myString = *axisIterator;
        
        // Draw Rect for color label
        CGColor labelColor = *colorIterator;
        CGRect rect = CGRectMake(xOffset, yOffset, 10, 10);
        drawRect(rect, labelColor);
        
        // Draw Label
        glColor4f(0, 0,0, 1.0);
        renderBitmapString(xOffset + 20, yOffset + 10, myString, GLUT_BITMAP_HELVETICA_12);

        yOffset += 20;
        colorIterator++;
    }
  
}


void PieChartView::drawPieChartInRect(CGRect rect, std::vector<int> values) {
    
    float radius = fmin(rect.height, rect.width) / 2;
    
    glPushMatrix();
    glTranslatef(rect.x + rect.width / 2, rect.y + rect.height / 2, 0);
    
    float currentAngle = 0;
    
    float totalValue = 0;
     for (int i = 0; i < values.size(); i++) {
         totalValue += values[i];
     }
    
    std::cout << "Total Value: " << totalValue << std::endl;
    for (int i = 0; i < values.size(); i++) {
        float startAngle = currentAngle;
        int currentValue = values[i];
        CGColor currentColor = colors[i];
        int sweepAngle = (currentValue / totalValue) * 360;
       // int sweepAngleOld = (currentValue * 360) /100;
        //std::cout << "Sweep Angle: " << sweepAngle << " Old: " << sweepAngleOld << std::endl;
        float angle = startAngle + sweepAngle;
        
        drawArc(0, 0, radius, startAngle, angle, currentColor);
        currentAngle = angle;
    }
    
    glPopMatrix();
    
}



void PieChartView::draw() {
    
    CGRect rect = CGRectMake(0, 0, 250, 250);
    drawPieChartInRect(rect,values);
    drawLegend(CGRectMake(300, 125, 200, 200));
    
}



PieChartView::PieChartView(std::vector<std::string*> vals, std::vector<int> yVals) {
    colors = std::vector<CGColor>();
    
    // Setup Default Color Scheme
    colors.push_back(CGColorSimpleBlue());
    colors.push_back(CGColorSimpleYellow());
    colors.push_back(CGColorSimpleOrange());
    colors.push_back(CGColorSimpleGreen());
    colors.push_back(CGColorSimpleRed());
    colors.push_back(CGColorSimpleBlue());
    colors.push_back(CGColorSimpleYellow());
    
  //  this->xVals =  std::vector<std::string *>();
    this->xVals = vals;
    this->values = yVals;
}
