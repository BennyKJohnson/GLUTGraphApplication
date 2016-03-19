//
//  PieChartView.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "PieChartView.hpp"
#include "CGGeometry.hpp"
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / float(num_segments);
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;
    
    float x = r;//we start at angle = 0
    float y = 0;
    glColor3f(1, 0, 0);
    
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex
        
        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
}




void drawPieSegmentInRect(CGRect rect, float percentage) {
    // Get maximum radius to fit rect
    float radius = fmin(rect.height, rect.width) / 2;
    int numVectices = percentage * 360;
    glColor3f(1, 0, 0);
    
    glPushMatrix();
    glTranslatef(rect.x + rect.width / 2, rect.y + rect.height / 2, 0);
    
    glBegin(GL_TRIANGLE_FAN);
    
    // Add origin vertex
    glVertex2f(0, 0);
    
    for (int i = 0; i < numVectices /2; i++) {
        float x = radius * cosf(degreesToRadians(i));
        float y = radius * sinf(degreesToRadians(i));
        glVertex2f(x,y);//output vertex
    }
    
    glEnd();
    
    
    glPopMatrix();
    
    
    
}

void drawRect(CGRect rect, CGColor color) {
    
    glColor4f(color.r, color.g,color.b,  color.a);
    
    glPushMatrix();
    glTranslatef(rect.x, rect.y, 0);
    
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
    //Trapezoid
    glVertex2i(0, 0); //Upper left
    
    
    glVertex2i(0, rect.height); //Lower left
    
    glVertex2i(rect.width, rect.height); //Lower right
    
    glVertex2i(rect.width, 0); //Upper Right
    
    glEnd(); //End quadrilateral coordinates
    
    
    //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glPopMatrix();
    
}




void drawArc(float x, float y, float radius, float startAngleOuter, float sweepAngleOuter, CGColor color) {
    
    glColor4f(color.r, color.g,color.b,  color.a);
    
    glPushMatrix();
    glTranslatef(x, y,0);
    
    glBegin(GL_TRIANGLE_FAN);
    int numVectices = sweepAngleOuter - startAngleOuter;
    
    glVertex2f(0, 0);
    
    for (int i = startAngleOuter; i <= sweepAngleOuter; i++) {
        float x = radius * cosf(degreesToRadians(i));
        float y = radius * sinf(degreesToRadians(i));
        glVertex2f(x,y);//output vertex
    }
    
    
    
    glEnd();
    
    
    
    glPopMatrix();
    
}


void PieChartView::drawPieChartInRect(CGRect rect, std::vector<int> values) {
    
   
    CGColor colors[] = {CGColorSimpleBlue(), CGColorSimpleYellow(), CGColorSimpleOrange(), CGColorSimpleGreen()};
    float radius = fmin(rect.height, rect.width) / 2;
    
    glPushMatrix();
    glTranslatef(rect.x + rect.width / 2, rect.y + rect.height / 2, 0);
    
    int currentAngle = 0;
    
    for (int i = 0; i < values.size(); i++) {
        int startAngle = currentAngle;
        int currentPercentage = values[i];
        CGColor currentColor = colors[i];
        int angle = startAngle + (currentPercentage * 360) /100;
        
        drawArc(0, 0, radius, startAngle, angle, currentColor);
        currentAngle = angle;
    }
    
    glPopMatrix();
    
}



void PieChartView::draw() {
    
   
    
    CGRect rect = CGRectMake(0, 0, 250, 250);
    drawPieChartInRect(rect,values);
    
}



PieChartView::PieChartView(std::vector<std::string*> xVals, std::vector<int> yVals) {
    
    this->xVals = xVals;
    this->values = yVals;
}
