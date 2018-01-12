//
//  rectangle.hpp
//  quad_tree
//
//  Created by Bahadır on 11.11.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>


class Rectangle {
    
public:
    Rectangle();
    Rectangle(int top, int left, int bottom, int right);
    
    int Top; // y coordinate of the upper edge
    int Left; // x coordinate of the left edge
    int Bottom; // y coordinate of the bottom edge
    int Right; // x coordinate of the right edge
};


#endif /* rectangle_hpp */
