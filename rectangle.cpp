//
//  rectangle.cpp
//  quad_tree
//
//  Created by Bahadır on 11.11.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include "rectangle.hpp"

Rectangle::Rectangle() {
    Top = 0;
    Left = 0;
    Bottom = 0;
    Right = 0;
}

Rectangle::Rectangle(int top, int left, int bottom, int right) {
    Top = top;
    Left = left;
    Bottom = bottom;
    Right = right;
}
