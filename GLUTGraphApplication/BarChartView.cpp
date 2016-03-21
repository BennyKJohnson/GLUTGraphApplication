//
//  BarChartView.cpp
//  GLUTGraphApplication
//
//  Created by Ben Johnson on 14/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "BarChartView.hpp"
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library
#include <iostream>

void BarChartView::drawLegend(CGRect rect) {
    
    std::vector<std::string*>::iterator axisIterator = xVals.begin();
    std::vector<CGColor>::iterator colorIterator = colors.begin();
    
    int yOffset = rect.y;
    int xOffset = rect.x;
    
    for (axisIterator = dataSetTitles.begin(); axisIterator != dataSetTitles.end(); axisIterator++) {
        // Print String
        std::string *myString = *axisIterator;
        
        // Draw Rect for color label
        CGColor labelColor = *colorIterator;
        CGRect rect = CGRectMake(xOffset, yOffset, 12, 12);
        setContextColor(labelColor);
        
        drawRect(rect, labelColor);
        
        // Draw Label
        glColor4f(0, 0,0, 1.0);
        renderBitmapString(xOffset + 20, yOffset + 10, myString, GLUT_BITMAP_HELVETICA_12);
        
        yOffset += 20;
        colorIterator++;
    }
    
}

void BarChartView::drawXAxis(CGRect rect) {
    
    // Get the largest Value
    int maxValue = 500;
    /*
     for (int i = 0; i < dataSet.size(); i++) {
     maxValue = std::max(maxValue, dataSet[i]);
     }
     */
    
    int step = 100;
    
    int numberOfHorizontalLines = (maxValue / step);
    int xStep =  (rect.width - graphXOffset) / numberOfHorizontalLines;
    int xAxisValue = 0;

    for (int i = 0; i <= numberOfHorizontalLines; i++) {
        
        float xPosition =  rect.x + graphXOffset + i * xStep;
        std::string xAxisString = std::to_string(xAxisValue);

        renderBitmapString(xPosition - 10, rect.height + rect.y + 15, &xAxisString, GLUT_BITMAP_HELVETICA_12);
       
        drawLine(CGPointMake(xPosition, rect.y), CGPointMake(xPosition, rect.y + rect.height + 5), 1);
     
        xAxisValue += step;

    }
}

void BarChartView::drawYAxis(CGRect rect) {
    
    int numberOfHorizontalLines = static_cast<int>(xVals.size());
    int yStep = rect.height / numberOfHorizontalLines;
  
    // Set color to black for axis lines and text
    setContextColor(CGColorBlack());
    
    for (int i = 0; i < numberOfHorizontalLines; i++) {
        // Get next y position
        float yPosition = (rect.y + rect.height) - graphYOffset - i * yStep;
        
        // Draw Axis Label
        std::string *axisString = xVals[i];
        
        renderBitmapString(rect.x, yPosition - (yStep / 2) + 5, axisString, GLUT_BITMAP_HELVETICA_12);
        
        // Draw Axis Line
        if (i == 0) {
            drawLine(CGPointMake(graphXOffset + rect.x, yPosition), CGPointMake(graphXOffset + rect.x  + rect.width, yPosition), 1);
        } else {
            drawLine(CGPointMake(graphXOffset + rect.x - 5, yPosition), CGPointMake(graphXOffset + rect.x, yPosition), 1);

        }
    }
}

void BarChartView::drawDataSet(std::vector<int> dataSet, CGRect rect, CGColor color) {
    
    // Get required Steps
    // Get Y Step
    int maxValue = 500;
    
    int numberOfHorizontalLines = static_cast<int>(xVals.size());
    float yRatio = (rect.height - graphYOffset) / numberOfHorizontalLines;
    
    // Get X Step
   // int numberOfVerticalLines =  (maxValue / step);
    float xRatio =  (rect.width - graphXOffset) / maxValue;
    int width = yRatio / 2 - 5;

    
    // Get ratio
    
    // Draw Lines
    int currentYValue = 0;
    for (std::vector<int>::iterator dataSetIterator = dataSet.begin(); dataSetIterator != dataSet.end(); dataSetIterator++) {
        
        // Get Values
        int value1 = *dataSetIterator;
        // Calculate X,Y Position for value1
        float xPosition =  (xRatio * value1);
        float yPosition =  (rect.height + rect.y - graphYOffset) - currentYValue - width;
        
        
        // Set bar color
        setContextColor(color);
        // Set bar coordinate and size
        CGRect bar = CGRectMake(graphXOffset + rect.x, yPosition - currentDataSet * width, xPosition, width);
        // Draw bar
        drawRect(bar, color);
        
        // incrument y value
        currentYValue += yRatio;
    }
}

void BarChartView::draw(CGRect rect) {
   
    // Draw XY axis
    drawYAxis(rect);
    drawXAxis(rect);
    
    
    // Iterate through datasets
    currentDataSet = 0;
    for (std::vector<std::vector<int>>::iterator dataSetIterator = dataSets.begin(); dataSetIterator != dataSets.end(); dataSetIterator++) {
        
        drawDataSet(*dataSetIterator, rect, colors[currentDataSet]);
        // Incrument current dataset, important for drawDataSet
        currentDataSet++;
    }
    
    // Draw Legend for graph
    drawLegend(CGRectMake(rect.x + rect.width + 10, (rect.height + rect.y) / 2, 100, 100));
    
}

BarChartView::BarChartView(std::vector<std::string*> xVals, std::vector<std::vector<int>> yVals) {
    this->xVals = xVals;
    this->dataSets = yVals;
    
    // set default color scheme
    colors.push_back(CGColorSimpleCyan());
    colors.push_back(CGColorSimpleBlue());
    
    // Set default offsets
    graphXOffset = 50;
    graphYOffset = 0;
}