//
//  CGGeometry.hpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef CGGeometry_hpp
#define CGGeometry_hpp

#include <stdio.h>
#include <string>

typedef struct CGRect {
    float x;
    float y;
    float width;
    float height;
} CGRect;


typedef struct CGColor {
    float r;
    float g;
    float b;
    float a;
} CGColor;

typedef struct CGPoint {
    float x;
    float y;
} CGPoint;


CGRect CGRectMake(float x, float y, float width, float height);
CGColor CGColorRed();
CGColor CGColorBlue();
CGColor CGColorGreen();
CGColor CGColorBlack();
CGColor CGColorWhite();

CGColor CGColorSimpleCyan();

CGColor CGColorMakeWithRGB(int r,int g,int b);

CGColor CGColorSimpleYellow();

CGColor CGColorSimpleOrange();
CGColor CGColorSimpleGreen();
CGColor CGColorSimpleRed();


CGColor CGColorSimpleBlue();
float degreesToRadians(float degree);
CGPoint CGPointMake(float x, float y);
CGPoint getCenter(CGRect rect);

CGRect offsetRectToCenterOnOrigin(CGRect rect);

void drawLine(CGPoint fromPoint, CGPoint toPoint, float lineWidth);
void drawCircle(CGRect rect, CGColor color);
void drawRect(CGRect rect, CGColor color);
void renderBitmapString(int x, int y, std::string *string, void *font);
void setContextColor(CGColor color);
CGRect centerAtPoint(CGPoint center, CGRect rect) ;


#endif /* CGGeometry_hpp */
