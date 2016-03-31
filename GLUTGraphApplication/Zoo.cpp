//
//  Zoo.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 20/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "Zoo.hpp"
#include <random>


Zoo::Zoo(std::string* title, std::vector<int> bannanas) {
    this->title = title;
    this->bananas = bannanas;
}

void Zoo::incrumentBannanasAtIndex(int index) {
    if (bananas[index] < 500) {
        bananas[index] += 1;
    }
}

void Zoo::decreaseBannanasAtIndex(int index) {
    if (bananas[index] >= 0) {
        bananas[index] = bananas[index] - 1;
    }
}

void Zoo::randomiseData() {
    bananas.clear();
    int min = 0;
    int max = 500;
    
    for (int i = 0; i < 7; i++) {
        int randomNumber = min + (rand() % (int)(max - min + 1));
        bananas.push_back(randomNumber);
    }
    // Generate random values
    
}

std::ostream& operator<<(std::ostream& os, const Zoo& zoo)
{
    os << zoo.title << std::endl;
    for (int i = 0; i < zoo.bananas.size(); i++) {
        os << i << ": " << zoo.bananas[i] << std::endl;
    }
    
    return os;
}
