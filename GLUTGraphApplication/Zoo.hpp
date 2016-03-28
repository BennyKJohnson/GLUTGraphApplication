//
//  Zoo.hpp
//  GLUTGraphApplication
//
//  Created by Benjamin Johnson on 20/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#ifndef Zoo_hpp
#define Zoo_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Zoo {
public:
    std::string title;
    std::vector<int> bananas;
    
    Zoo(std::string title, std::vector<int> bananas);
    void incrumentBannanasAtIndex(int index);
    void decreaseBannanasAtIndex(int index);
    void randomiseData();
};


#endif /* Zoo_hpp */
