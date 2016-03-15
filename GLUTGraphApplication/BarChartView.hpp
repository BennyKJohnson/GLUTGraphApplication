//
//  BarChartView.hpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 14/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef BarChartView_hpp
#define BarChartView_hpp

#include <stdio.h>
#include <string.h>
#include <vector>


class BarChartView {
public:
    
    std::vector<std::string*> xVals;
    std::vector<double> yVals;
    
    BarChartView(std::vector<std::string*> xVals, std::vector<double> yVals);
    
    void draw();
};

#endif /* BarChartView_hpp */
