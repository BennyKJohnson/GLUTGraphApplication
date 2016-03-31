//
//  PieChartView.hpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 19/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef PieChartView_hpp
#define PieChartView_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include "CGGeometry.hpp"
#include "Chart.hpp"

class PieChartView: public Chart {
 
    void drawPieChartInRect(CGRect rect, std::vector<int>* values);
    void drawLegend(CGRect rect);
public:
    
    
    std::vector<std::string*> xVals;
    std::vector<int>* values;
    std::string *title;
    
    PieChartView(std::vector<std::string*> xVals, std::vector<int> *yVals);
    void draw(CGRect rect);
};
#endif /* PieChartView_hpp */
