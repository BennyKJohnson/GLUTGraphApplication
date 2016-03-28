//
//  main.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 13/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include <iostream>

#include <string>

#ifdef __APPLE__
#include <GLUT/GLUT.h> //GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h> //OpenGL Library
#elif defined _WIN32 || defined _WIN64
#    include <GL\glut.h>
#endif

#include "PieChartView.hpp"
#include "LineChartView.hpp"
#include "BarChartView.hpp"

#include "CGGeometry.hpp"
#include "Zoo.hpp"

using namespace std;

#define WIDTH 800;
#define HEIGHT 600;
#define BORDER 0;

// Chart Views
PieChartView *pieChart;
LineChartView *lineChart;
BarChartView *barChart;


Zoo *mogoZoo;
Zoo *tarongaZoo;
// Pointer to the active zoo currently selected by user
Zoo *selectedZoo;

int selectedYearIndex;
int mainWindow;

enum MenuOption {
    Add = 1,
    Edit = 2
};

void deinit() {
    delete mogoZoo;
    delete tarongaZoo;
}

void keyboardHandler(unsigned char key, int x, int y) {
    // Escape
    cout << "Key pressed: " << key << endl;
    if (key == 27) {
        // Exit program
        deinit();
        exit(0);
        
    // 1 - 7
    } else if(key > 48 && key < 56) {
        int normalizedDataIndex = key - 48 - 1;
        int selectedYearIndex = key - 48 - 1 + 2005;
        selectedYearIndex = normalizedDataIndex;
        
        cout << selectedZoo->title << " year: " << selectedYearIndex << endl;
    }
}

void windowShouldRedraw() {
    glutSetWindow(mainWindow);
    glutPostRedisplay();
}


void specialKeyboardHandler(int key, int x, int y) {
    
    switch (key) {
        case GLUT_KEY_F1:
            cout << "Selected Taronga Zoo";
            selectedZoo = mogoZoo;
            break;
        case GLUT_KEY_F2:
            cout << "Selected Mogo Zoo";
            selectedZoo = tarongaZoo;
        case GLUT_KEY_DOWN:
            selectedZoo->decreaseBannanasAtIndex(selectedYearIndex);
            windowShouldRedraw();
            cout << "Decrease bannanas" << endl;
        case GLUT_KEY_UP:
            selectedZoo->incrumentBannanasAtIndex(selectedYearIndex);
            windowShouldRedraw();
            cout << "Incrument bannanas" << endl;
        default:
            break;
    }
}

void contextMenuHandler(int value) {
    cout << value;
}

void createContextMenu() {
    int startYear = 2005;
    int endYear = 2011;
    
    int menuCounter = 1;
    glutAddMenuEntry("Exit", 0);
    
    // Create year submenu
    int yearSubMenu = glutCreateMenu(contextMenuHandler);
    
    for (int i = startYear; i <= endYear; i++) {
        string label = to_string(i);
        glutAddMenuEntry(label.c_str(), menuCounter);
        menuCounter++;
    }
    
    // Create main menu
    glutCreateMenu(contextMenuHandler);
    
    // Add submenus
    glutAddSubMenu(mogoZoo->title.c_str(), yearSubMenu);
    glutAddSubMenu(tarongaZoo->title.c_str(), yearSubMenu);

    // Add option menu items
    glutAddMenuEntry("Randomise data", menuCounter);
    glutAddMenuEntry("Change Colors", menuCounter);

    // Set the menu to right click
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void render(void){
    
    // Set background color to white and opaque
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    // Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw graphs
    lineChart->draw(CGRectMake(0, 10, 350, 250));
    barChart->draw(CGRectMake(450, 10, 250, 250));
   
    glFlush();
}

void zooMenuClicked(int i) {
    
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

// Create Mogo Zoo and populate it with data
Zoo* getMogoZoo() {
    
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
    
    return new Zoo(title, bannanas);
}

// Create Taronga Zoo and populate it with data
Zoo* getTarongaZoo() {
    
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
    
    return new Zoo(title, bannanas);
}

void initOpenGL() {
    
    glutDisplayFunc(render);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboardHandler);
    glutSpecialFunc(specialKeyboardHandler);
    
    //  Setup Menu
    createContextMenu();
    
}

void setupGraphs() {
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
    mogoZoo = getMogoZoo();
    tarongaZoo = getTarongaZoo();
    
    selectedZoo = mogoZoo;
    selectedYearIndex = 0;
    
    dataSetTitles.push_back(&mogoZoo->title);
    dataSetTitles.push_back(&tarongaZoo->title);
    
    dataSets.push_back(mogoZoo->bananas);
    dataSets.push_back(tarongaZoo->bananas);
    
    barChart = new BarChartView(xVals, dataSets);
    barChart->dataSetTitles = dataSetTitles;
    
    lineChart = new LineChartView(xVals,dataSets);
    lineChart->dataSetTitles = dataSetTitles;

}

int main(int argc, char * argv[]) {
    
    
    #ifdef __APPLE__
        //Init glut passing some args
        glutInit(&argc, argv);
    #endif
    
    //Specify the Display Mode, this one means there is a single buffer and uses RGB to specify colors
   // glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE |GLUT_RGB);
    
    //Set the window size
    glutInitWindowSize(800, 600);
    
    //Where do we want to place the window initially?
    glutInitWindowPosition(100,100);
    
    //Name the window and create it
    mainWindow = glutCreateWindow("Zoo Graphs");
    setupGraphs();
    initOpenGL();
    
   
    //Start the main loop running, nothing after this will execute for all eternity (right now)
    glutMainLoop();
    
    return 0;
}