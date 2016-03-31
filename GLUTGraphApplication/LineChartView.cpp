//
//  LineChartView.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 20/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "LineChartView.hpp"
#include <iostream>

#ifdef __APPLE__
#include <GLUT/GLUT.h> //GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h> //OpenGL Library
#elif defined _WIN32 || defined _WIN64
#    include <glut.h>
#endif


void LineChartView::drawCircles() {
    
}

LineChartView::~LineChartView() {
    
    // Delete axis labels
    for(int i = 0; i < xVals.size(); ++i)
        delete xVals[i];
    
}


void drawDataPoint(CGRect rect, CGColor color, int innerBorder) {
    
    // Draw Color Circle
    drawCircle(rect, color);
    CGRect innerCircle = CGRectMake(0, 0, rect.width - innerBorder, rect.height - innerBorder);
    innerCircle = centerAtPoint(getCenter(rect), innerCircle);
    
    drawCircle(innerCircle, CGColorWhite());
}

LineChartView::LineChartView(std::vector<std::string*> xVals, std::vector<std::vector<int>*> yVals) {
    this->xVals = xVals;
    this->dataSets = yVals;
    
    colors.push_back(CGColorSimpleOrange());
    colors.push_back(CGColorSimpleBlue());
    colors.push_back(CGColorSimpleCyan());
    colors.push_back(CGColorSimpleRed());
    colors.push_back(CGColorSimpleYellow());
    colors.push_back(CGColorSimpleGreen());
    
    // Set default offsets
    graphXOffset = 40;
    graphYOffset = 0;
}
/*
void LineChartView::drawYAxis(CGRect rect) {
    
}
*/

void LineChartView::drawLegend(CGRect rect) {
    
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

        CGPoint circleCenter = getCenter(rect);
        drawLine(CGPointMake(rect.x - 5, circleCenter.y), CGPointMake(rect.x + rect.width + 5, circleCenter.y), 4);

        drawDataPoint(rect, labelColor, 5);
        
        
        
        
        // Draw Label
        glColor4f(0, 0,0, 1.0);
        renderBitmapString(xOffset + 20, yOffset + 10, myString, GLUT_BITMAP_HELVETICA_12);
        
        yOffset += 20;
        colorIterator++;
    }
    
}


void LineChartView::drawYAxis(CGRect rect) {
    // Get the largest Value
    int maxValue = maximumValue();
    
    int step = 50;
    
    int numberOfHorizontalLines = (maxValue / step);
    int yStep = rect.height / numberOfHorizontalLines;
   // std::vector<std::string*>::iterator axisIterator = xVals.begin();
    int yAxisValue = 0;
    
    glColor3f(0, 0, 0);

    for (int i = 0; i <= numberOfHorizontalLines; i++) {
        // Get next y position
        float yPosition = (rect.y + rect.height) - graphYOffset - i * yStep;
        
        // Draw Axis Label
        std::string yAxisString = std::to_string(yAxisValue);
        renderBitmapString(0, yPosition + 5, &yAxisString, GLUT_BITMAP_HELVETICA_12);
        
        // Draw Axis Line
        drawLine(CGPointMake(graphXOffset, yPosition), CGPointMake(rect.width, yPosition), 1);
        yAxisValue += step;
    }
    
}

void LineChartView::drawXAxis(CGRect rect) {
    
    int numberOfVerticalLines = static_cast<int>(xVals.size());
    
    int xStep =  (rect.width - graphXOffset) / numberOfVerticalLines;
    
    for (int i = 0; i < numberOfVerticalLines; i++) {
        std::string *axisString = xVals[i];
        
        float xPosition =  graphXOffset + i * xStep;
        renderBitmapString(xPosition, rect.height + rect.y + 15, axisString, GLUT_BITMAP_HELVETICA_12);
        if (i == 0) {
             drawLine(CGPointMake(xPosition, rect.y), CGPointMake(xPosition, rect.y + rect.height + 5), 1);
        }
        drawLine(CGPointMake(xPosition,rect.y + rect.height), CGPointMake(xPosition, rect.y + rect.height + 5), 1);
    }
}



void LineChartView::drawDataSet(std::vector<int> dataSet, CGRect rect, CGColor color) {

    // Get required Steps
    // Get Y Step
    int maxValue = maximumValue();
    
    //int numberOfHorizontalLines = (maxValue / step);
    float yRatio = (rect.height - graphYOffset) / maxValue;
    
    // Get X Step
    int numberOfVerticalLines = static_cast<int>(xVals.size());
    int xStep =  (rect.width - graphXOffset) / numberOfVerticalLines;
    
    
    // Get ratio
    
    // Draw Lines
    int currentXValue = 0;
    for (std::vector<int>::iterator dataSetIterator = dataSet.begin(); dataSetIterator != dataSet.end(); dataSetIterator++) {
        
        // Get Values
        int value1 = *dataSetIterator;
        dataSetIterator++;
        
        int value2 = *dataSetIterator;
        dataSetIterator--;
        
        // Calculate X,Y Position for value1
        float xPosition =  graphXOffset + currentXValue * xStep + (xStep / 2);
        float yPosition =  (rect.height + rect.y - graphYOffset) - value1 * yRatio;
        
        // Calculate X,Y Position for value2
        float x2Position =  graphXOffset + (currentXValue + 1) * xStep + (xStep / 2);
        float y2Position =  (rect.height + rect.y - graphYOffset) - value2 * yRatio;
        currentXValue++;
        
        CGRect circleRect = offsetRectToCenterOnOrigin(CGRectMake(xPosition, yPosition, 12, 12));
        
        // Draw Line
        if (currentXValue < dataSet.size()) {
            setContextColor(color);
            drawLine(CGPointMake(xPosition, yPosition), CGPointMake(x2Position, y2Position), 3);

        }
        drawDataPoint(circleRect, color, 5);

        

    }
    
    
}

void LineChartView::draw(CGRect rect) {
    
    drawYAxis(rect);
    drawXAxis(rect);
    
    // Iterate through datasets
    int i = 0;
    for (std::vector<std::vector<int>*>::iterator dataSetIterator = dataSets.begin(); dataSetIterator != dataSets.end(); dataSetIterator++) {
        
        drawDataSet(**dataSetIterator, rect, colors[i]);
        i++;
    }
    
    drawLegend(CGRectMake(rect.width + 10, (rect.height + rect.y) / 2, 100, 100));
}
