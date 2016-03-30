//
//  CGGeometry.hpp
//  GLUTGraphApplication
//  Helper structs and methods for 2D drawing in OpenGL
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef CGGeometry_hpp
#define CGGeometry_hpp

#include <stdio.h>
#include <string>

// Simple struct for a rectangle area represented by x,y and width and height
typedef struct CGRect {
    float x;
    float y;
    float width;
    float height;
} CGRect;

// Returns a rectangle with the coordinate and size
CGRect CGRectMake(float x, float y, float width, float height);

// struct to represent a coordinate
typedef struct CGPoint {
    float x;
    float y;
} CGPoint;

CGPoint CGPointMake(float x, float y);

// Simple struct for color rgba values
typedef struct CGColor {
    float r;
    float g;
    float b;
    float a;
} CGColor;

// Convenience Constructor with rgb
CGColor CGColorMakeWithRGB(int r,int g,int b);

// Sets OpenGL current color to CGColor values
void setContextColor(CGColor color);

// Convenience Init for colors
// Basic colors
CGColor CGColorRed();
CGColor CGColorBlue();
CGColor CGColorGreen();
CGColor CGColorBlack();
CGColor CGColorWhite();

CGColor statusBarColor();
// Colors for main color scheme
CGColor CGColorSimpleCyan();
CGColor CGColorSimpleYellow();
CGColor CGColorSimpleOrange();
CGColor CGColorSimpleGreen();
CGColor CGColorSimpleRed();
CGColor CGColorSimpleBlue();

// Converts degrees to radians
float degreesToRadians(float degree);

CGPoint getCenter(CGRect rect);

// Moves rect to center on its original origin
CGRect offsetRectToCenterOnOrigin(CGRect rect);

// Draw Helper Methods
void drawLine(CGPoint fromPoint, CGPoint toPoint, float lineWidth);
// Draws Circle within rect with color
void drawCircle(CGRect rect, CGColor color);
// Draws rectangle of color within the coordinate and size
void drawRect(CGRect rect, CGColor color);
// Draws string at x,y with font
void renderBitmapString(int x, int y, std::string *string, void *font);

CGRect centerAtPoint(CGPoint center, CGRect rect) ;


#endif /* CGGeometry_hpp */
