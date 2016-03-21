//
//  Zoo.cpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 20/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include "Zoo.hpp"


Zoo::Zoo(std::string title, std::vector<int> bannanas) {
    
    this->title = title;
    this->bannanas = bannanas;

}

void Zoo::incrumentBannanasAtIndex(int index) {
    bannanas[index] += 100;
}

void Zoo::decreaseBannanasAtIndex(int index) {
    bannanas[index] -= 100;
}
