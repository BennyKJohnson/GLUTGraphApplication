//
//  main.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 13/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//


#include <iostream>
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library
#include <string>

#include "PieChartView.hpp"
#include "LineChartView.hpp"
#include "BarChartView.hpp"

#include "CGGeometry.hpp"
#include "Zoo.hpp"

using namespace std;

#define WIDTH 800;
#define HEIGHT 600;
#define BORDER 0;

PieChartView *pieChart;
LineChartView *lineChart;
BarChartView *barChart;


enum MenuOption {
    Add = 1,
    Edit = 2
};



void keyboardHandler(unsigned char c, int x, int y) {
    // Escape
    if (c == 27) {
        exit(0);
    }
}

void contextMenuHandler(int value) {

    cout << value;
    
}

void renderBitmapString(
                        float x,
                        float y,
                        float z,
                        void *font,
                        char *string) {
    
    char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void createContextMenu() {
    int startYear = 2005;
    int endYear = 2011;
    
    int years[] = {2005,2006,2007,2008,2009,2010,2011};
    
    int menu = glutCreateMenu(contextMenuHandler);
    int menuCounter = 1;
    
    for (int i = startYear; i <= endYear; i++) {
        string label = to_string(i);
       
        
        glutAddMenuEntry(label.c_str(), menuCounter);
        menuCounter++;
        
    }
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mouseHandler(int button, int state, int x, int y) {
    /*
    if(button == GLUT_RIGHT_BUTTON) {
        // Create Menu
        
        
        exit(0);
    }
     */
}

//Now, lets tell it to display some stuff
void render(void){

    
    /*

    */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);//Clear the buffer
   // barChart->draw();
    barChart->draw();
    
    //drawCircle(CGRectMake(50, 0, 100, 100), CGColorBlue());
    
    renderBitmapString(0, 0, 0, GLUT_BITMAP_HELVETICA_12, "Graph");
    
    glFlush();
}

void backgroundRender(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the buffer
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glFlush();

}

void initView() {
    
    //Set the callback function, will be called as needed
    glutDisplayFunc(render);
    
    // Setup Keyboard Handler
    glutKeyboardFunc(keyboardHandler);
    
    // Setup Mouse Handler
    glutMouseFunc(mouseHandler);
    
    // Create Context Menu for view
    createContextMenu();
    
}

void setOGLProjection(int width, int height) {
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0, width, height, 0, -1, 1);
    
    //Back to the modelview so we can draw stuff
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void resize(int width, int height) {
    
  //  int width = glutGet(GLUT_WINDOW_WIDTH);
   // int height = glutGet(GLUT_WINDOW_HEIGHT);
    
    setOGLProjection(width, height);
    
    
}


void setupSubViews(int mainWindow) {
    
    int width = 800;
    int height = 600;
    int border = 0;
    
    int subWindow1 = glutCreateSubWindow(mainWindow, border, border, width / 2, height / 2);
    initView();
    
    int subWindow2 = glutCreateSubWindow(mainWindow, width / 2, border, width / 2, height / 2);
    initView();
    
    int subWindow3 = glutCreateSubWindow(mainWindow, 0, height / 2, width / 2, height / 2);
    initView();
    
    int subWindow4 = glutCreateSubWindow(mainWindow, width / 2, height / 2, width / 2, height / 2);
    initView();
    
    
}

vector<string*> getAvailableYears() {
    
    vector<string*> xVals = vector<string*>();
    
    std::string year2005 = "2005";
    std::string year2006 = "2006";
    std::string year2007 = "2007";
    std::string year2008 = "2008";
    std::string year2009 = "2009";
    std::string year2010 = "2010";
    std::string year2011 = "2011";

    
    xVals.push_back(&year2005);
    xVals.push_back(&year2006);
    xVals.push_back(&year2007);
    xVals.push_back(&year2008);
    xVals.push_back(&year2009);
    xVals.push_back(&year2010);
    xVals.push_back(&year2011);

    return xVals;
    
}

Zoo getMogoZoo() {
    
    std::string title = "Mogo Zoo";
    
    // Set Values
    std::vector<int> bannanas;
    
    bannanas.push_back(150); // 2005
    bannanas.push_back(200); // 2006
    bannanas.push_back(350); // 2007
    bannanas.push_back(300); // 2008
    bannanas.push_back(400); // 2009
    bannanas.push_back(150); // 2010
    bannanas.push_back(200); // 2011
    
    return Zoo(title, bannanas);
    
}


Zoo getTarongaZoo() {
    
    std::string title = "Taronga Zoo";
    
    // Set Values
    std::vector<int> bannanas;
    bannanas.push_back(180); // 2005
    bannanas.push_back(300); // 2006
    bannanas.push_back(400); // 2007
    bannanas.push_back(300); // 2008
    bannanas.push_back(200); // 2009
    bannanas.push_back(240); // 2010
    bannanas.push_back(350); // 2011
    
    
    return Zoo(title, bannanas);
}


int main(int argc, char * argv[]) {
    
    vector<string*> xVals;
    
    std::string year2005 = "2005";
    std::string year2006 = "2006";
    std::string year2007 = "2007";
    std::string year2008 = "2008";
    std::string year2009 = "2009";
    std::string year2010 = "2010";
    std::string year2011 = "2011";
    xVals.push_back(&year2005);
    xVals.push_back(&year2006);
    xVals.push_back(&year2007);
    xVals.push_back(&year2008);
    xVals.push_back(&year2009);
    xVals.push_back(&year2010);
    xVals.push_back(&year2011);
    
    vector<vector<int>> dataSets;
    vector<std::string*> dataSetTitles;
    
    // Setup Zoos
    Zoo mogoZoo = getMogoZoo();
    Zoo tarongaZoo = getTarongaZoo();
    
    //
    dataSetTitles.push_back(&mogoZoo.title);
    dataSetTitles.push_back(&tarongaZoo.title);

    dataSets.push_back(mogoZoo.bannanas);
    dataSets.push_back(tarongaZoo.bannanas);

  //  dataSets.push_back(yVals);
    barChart = new BarChartView(xVals, dataSets);
    barChart->dataSetTitles = dataSetTitles;
    
  // barChart = new PieChartView(xVals, yVals);

    //Init glut passing some args, if you know C++ you should know we are just passing the args straight thru from main
    glutInit(&argc, argv);
    
    //Specify the Display Mode, this one means there is a single buffer and uses RGB to specify colors
   // glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE |GLUT_RGB);
    
    //Set the window size
    glutInitWindowSize(800, 600);
    
    //Where do we want to place the window initially?
    glutInitWindowPosition(100,100);
    
  //  glViewport(0, 0, 600, 600);   //This sets up the viewport so that the coordinates (0, 0) are at the top left of the window
    
    
    
    
    //Name the window and create it
    int mainWindow = glutCreateWindow("Zoo Graphs");
    glutDisplayFunc(render);
    glutReshapeFunc(resize);
    
    // setupSubViews(mainWindow);
   
    //Start the main loop running, nothing after this will execute for all eternity (right now)
    glutMainLoop();
    
    return 0;
}