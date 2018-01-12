//
//  TwoDimTreeNode.hpp
//  quad_tree
//
//  Created by Bahadır on 11.11.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#ifndef TwoDimTreeNode_hpp
#define TwoDimTreeNode_hpp

#include <stdio.h>
#include <vector>
#include "rectangle.hpp"
using namespace std;


class TwoDimTreeNode {
    
public:
    
    TwoDimTreeNode();
    TwoDimTreeNode(Rectangle E);
    
    Rectangle Extent;
    vector<Rectangle> Vertical, Horizontal;
    TwoDimTreeNode *TopLeft, *TopRight, *BottomLeft, *BottomRight;
    
    int is_rec_on_axis(Rectangle R); // Check if the rectangle is on the axises. If not return the region.

    
};


#endif /* TwoDimTreeNode_hpp */
