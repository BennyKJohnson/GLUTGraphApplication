//
//  CGGeometry.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "CGGeometry.hpp"

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


CGColor CGColorMakeWithRGB(int r,int g,int b) {
    
    CGColor color;
    color.r = r / 255.0;
    color.b = b / 255.0;
    color.g = g / 255.0;
    color.a = 1;
    
    return color;
}


CGColor CGColorSimpleYellow()
{
    return CGColorMakeWithRGB(255,244,127);
}

CGColor CGColorSimpleGreen() {
    return CGColorMakeWithRGB(190,255,129);
}


CGColor CGColorSimpleBlue() {
    return CGColorMakeWithRGB(128,232,255);
}

CGColor CGColorRed() {
    CGColor color;
    color.r = 1;
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

CGColor CGColorSimpleOrange() {
    return CGColorMakeWithRGB(255,205,129);
}