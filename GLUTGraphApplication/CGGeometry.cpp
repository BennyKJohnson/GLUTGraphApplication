//
//  CGGeometry.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "CGGeometry.hpp"
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library
#include <string>
#include <math.h>

CGRect CGRectMake(float x, float y, float width, float height) {
    CGRect rect;
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    
    return rect;
}

float degreesToRadians(float degree) {
    return degree * 0.0174533;
    
}

CGPoint getCenter(CGRect rect) {
    return CGPointMake(rect.x + rect.width / 2, rect.y + rect.height / 2);
}

void setContextColor(CGColor color) {
    glColor4f(color.r, color.g,color.b,  color.a);
}

CGColor CGColorWhite() {
    CGColor color;
    color.r = 1;
    color.b = 1;
    color.g = 1;
    color.a = 1;
    
    return color;
}



// Modified code from http://slabode.exofire.net/circle_draw.shtml
void drawCircle(CGRect rect, CGColor color)
{
    setContextColor(color);
    
    float radius = fmin(rect.width, rect.height) / 2;
    CGPoint center = getCenter(rect);

    glPushMatrix();
    glTranslatef(center.x, center.y,0);
    
    glBegin(GL_TRIANGLE_FAN);
   // int numVectices = sweepAngleOuter - startAngleOuter;
    
    glVertex2f(0, 0);
    
    for (int i = 0; i <= 360; i++) {
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
    
    glPopMatrix();
    
}

// Helper function that returns a rect which origin will ensure that the rect is at the center of xy
CGRect offsetRectToCenterOnOrigin(CGRect rect) {
    CGRect newRect;
    newRect.width = rect.width;
    newRect.height = rect.height;
    newRect.x =  rect.x - (rect.width / 2);
    newRect.y =  rect.y - (rect.height / 2);
    return newRect;
}

// Returns new rect which is center point equals the center point of rect
CGRect centerAtPoint(CGPoint center, CGRect rect) {
    rect.x = center.x - (rect.width / 2);
    rect.y = center.y - (rect.height / 2);
    
    return rect;
}

void renderBitmapString(int x, int y, std::string *string, void *font) {
    // Set point to draw string
    glRasterPos2i(x, y);
    
    // Copy string into new CString
    char *c = new char[256];
    strcpy(c, string->c_str());
    
    // Iterate through each character of string
    while (*c != '\0') {
        // Draw individual character
        glutBitmapCharacter(font, *c);
        c++;
    }
}

CGPoint CGPointMake(float x, float y) {
    CGPoint point;
    point.x = x;
    point.y = y;
    
    return point;
}


void drawLine(CGPoint fromPoint, CGPoint toPoint, float width) {
    // Set line width
    glLineWidth(width);
    
    // Draw line
    glBegin(GL_LINES);
    glVertex2f(fromPoint.x, fromPoint.y);
    glVertex2f(toPoint.x, toPoint.y);
    glEnd();
}

CGColor CGColorMakeWithRGB(int r,int g,int b) {
    
    CGColor color;
    color.r = r / 255.0;
    color.b = b / 255.0;
    color.g = g / 255.0;
    color.a = 1;
    
    return color;
}


CGColor CGColorSimpleYellow() {
    return CGColorMakeWithRGB(255,244,127);
}

CGColor CGColorSimpleCyan() {
    return CGColorMakeWithRGB(190,255,129);
}

CGColor CGColorSimpleGreen() {
    return CGColorMakeWithRGB(96,241,163);
}


CGColor CGColorSimpleBlue() {
    return CGColorMakeWithRGB(128,232,255);
}

CGColor CGColorSimpleRed() {
    return  CGColorMakeWithRGB(255,131,145);
}

CGColor CGColorSimpleOrange() {
    return CGColorMakeWithRGB(255,205,129);
}

CGColor CGColorRed() {
    CGColor color;
    color.r = 1;
    color.b = 0;
    color.g = 0;
    color.a = 1;
    
    return color;
}

CGColor CGColorBlack() {
    CGColor color;
    color.r = 0;
    color.b = 0;
    color.g = 0;
    color.a = 1;
    
    return color;
}

CGColor CGColorGreen() {
    CGColor color;
    color.r = 0;
    color.b = 0;
    color.g = 1;
    color.a = 1;
    
    return color;
}

CGColor CGColorBlue() {
    CGColor color;
    color.r = 0;
    color.b = 1;
    color.g = 0;
    color.a = 1;
    
    return color;
}

