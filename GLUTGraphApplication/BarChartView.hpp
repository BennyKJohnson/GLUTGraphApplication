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
#include "CGGeometry.hpp"

class BarChartView {
    
    void drawYAxis(CGRect rect);
    void drawXAxis(CGRect rect);
    void drawLegend(CGRect rect);
    void drawDataSet(std::vector<int> dataSet, CGRect rect, CGColor color);

    
public:
    
    std::vector<std::string*> xVals;
    std::vector<std::vector<int>> dataSets;
    std::vector<CGColor> colors;
    std::vector<std::string*> dataSetTitles;
    
    
    BarChartView(std::vector<std::string*> xVals, std::vector<std::vector<int>> dataSets);
    int graphYOffset;
    int graphXOffset;
    int currentDataSet;
    
    void draw(CGRect rect);
};

#endif /* BarChartView_hpp */
