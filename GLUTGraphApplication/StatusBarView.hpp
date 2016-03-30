//
//  StatusBarView.hpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 29/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef StatusBarView_hpp
#define StatusBarView_hpp

#include <stdio.h>
#include "CGGeometry.hpp"
#include <string.h>

class StatusBarView {
    std::string *text;
public:

    void setText(std::string *text);
    StatusBarView();
    void draw(CGRect rect);
};



#endif /* StatusBarView_hpp */
