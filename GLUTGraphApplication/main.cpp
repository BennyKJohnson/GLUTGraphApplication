//
//  main.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 13/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h> //GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h> //OpenGL Library
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

void keyboardHandler(unsigned char c, int x, int y) {
    // Escape
    cout << "Key pressed: " << c << endl;
    if (c == 27) {
        // Exit program
        deinit();
        exit(0);
        
    // 1 - 7
    } else if(c > 48 && c < 56) {
        int normalizedDataIndex = c - 48 - 1;
        int selectedYearIndex = c - 48 - 1 + 2005;
        selectedYearIndex = normalizedDataIndex;
        
        cout << selectedZoo->title << " year: " << selectedYearIndex << endl;
    }
}

void windowShouldRedraw() {
    glutSetWindow(mainWindow);
    glutPostRedisplay();
}


void specialKeyboardHandler(int c, int x, int y) {
    
    if(c == GLUT_KEY_F1) {
        cout << "Selected Taronga Zoo";
        selectedZoo = mogoZoo;
        
    } else if (c == GLUT_KEY_F2) {
        cout << "Selected Mogo Zoo";
        selectedZoo = tarongaZoo;
    } else if (c == GLUT_KEY_UP) {
        
        selectedZoo->incrumentBannanasAtIndex(selectedYearIndex);
        windowShouldRedraw();
        cout << "Incrument bannanas" << endl;
    } else if (c == GLUT_KEY_DOWN) {
        selectedZoo->decreaseBannanasAtIndex(selectedYearIndex);
        windowShouldRedraw();
        cout << "Decrease bannanas" << endl;

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

void mouseHandler(int button, int state, int x, int y) {
    /*
    if(button == GLUT_RIGHT_BUTTON) {
        // Create Menu
        
        
        exit(0);
    }
     */
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
    mogoZoo = getMogoZoo();
    tarongaZoo = getTarongaZoo();
    
    selectedZoo = mogoZoo;
    selectedYearIndex = 0;
    
    //
    dataSetTitles.push_back(&mogoZoo->title);
    dataSetTitles.push_back(&tarongaZoo->title);

    dataSets.push_back(mogoZoo->bannanas);
    dataSets.push_back(tarongaZoo->bannanas);

  //  dataSets.push_back(yVals);
    barChart = new BarChartView(xVals, dataSets);
    barChart->dataSetTitles = dataSetTitles;
    
    lineChart = new LineChartView(xVals,dataSets);
    lineChart->dataSetTitles = dataSetTitles;
    
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
    mainWindow = glutCreateWindow("Zoo Graphs");
    glutDisplayFunc(render);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboardHandler);
    glutSpecialFunc(specialKeyboardHandler);
    
  //  glutSpecialFunc(keyboardHandler);
    createContextMenu();

    // setupSubViews(mainWindow);
   
    //Start the main loop running, nothing after this will execute for all eternity (right now)
    glutMainLoop();
    
    return 0;
}