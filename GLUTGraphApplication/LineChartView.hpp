//
//  LineChartView.hpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 20/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef LineChartView_hpp
#define LineChartView_hpp

#include <stdio.h>
#include "CGGeometry.hpp"
#include <string.h>
#include <vector>
#include "Chart.hpp"

class LineChartView: public Chart {
    
    void drawCircles();
    void drawYAxis(CGRect rect);
    void drawXAxis(CGRect rect);
    void drawLegend(CGRect rect);
    void drawDataSet(std::vector<int> dataSet, CGRect rect, CGColor color);

public:
    
    std::vector<std::string*> xVals;
    std::vector<std::vector<int>*> dataSets;
    std::vector<std::string*> dataSetTitles;
    
    std::string *title;

    LineChartView(std::vector<std::string*> xVals, std::vector<std::vector<int>*> yVals);
    void draw(CGRect rect);
    
    int graphYOffset;
    int graphXOffset;
    ~LineChartView();
};



#endif /* LineChartView_hpp */
