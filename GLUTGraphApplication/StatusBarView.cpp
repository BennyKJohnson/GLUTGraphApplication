//
//  StatusBarView.cpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 29/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "StatusBarView.hpp"
#ifdef __APPLE__
#include <GLUT/GLUT.h> //GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h> //OpenGL Library
#elif defined _WIN32 || defined _WIN64
#    include <glut.h>
#endif


void StatusBarView::draw(CGRect rect) {

    drawRect(rect, statusBarColor());
    
    // Draw Text
    if(text != NULL) {
        setContextColor(CGColorBlack());
        renderBitmapString(rect.x, rect.y + 14, text, GLUT_BITMAP_HELVETICA_12);
    }

    // Once drawn the text is no longer required. So cleanup memory
}

StatusBarView::StatusBarView() {
    text = NULL;
}

void StatusBarView::setText(std::string *newText) {
    if (text != NULL) {
       // Cleanup allocated memory
        delete text;
    }
 
    text = newText;
}
