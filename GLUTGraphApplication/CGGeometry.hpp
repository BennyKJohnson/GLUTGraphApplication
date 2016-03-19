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

CGRect CGRectMake(float x, float y, float width, float height);
CGColor CGColorRed();
CGColor CGColorBlue();
CGColor CGColorGreen();
CGColor CGColorMakeWithRGB(int r,int g,int b);

CGColor CGColorSimpleYellow();

CGColor CGColorSimpleOrange();
CGColor CGColorSimpleGreen();

CGColor CGColorSimpleBlue();
float degreesToRadians(float degree);

#endif /* CGGeometry_hpp */
