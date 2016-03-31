//
//  Chart.hpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 21/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef Chart_hpp
#define Chart_hpp

#include <stdio.h>
#include "CGGeometry.hpp"
#include <vector>

class Chart {

public:
    int maximumValue();
    Chart();
    std::vector<CGColor> colors;

};



#endif /* Chart_hpp */
