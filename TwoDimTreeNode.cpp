//
//  TwoDimTreeNode.cpp
//  quad_tree
//
//  Created by Bahadır on 11.11.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include "TwoDimTreeNode.hpp"


TwoDimTreeNode::TwoDimTreeNode() {
    
}

TwoDimTreeNode::TwoDimTreeNode(Rectangle E) {
    Extent = E;
    TopRight = NULL;
    TopLeft = NULL;
    BottomLeft = NULL;
    BottomRight = NULL;
}


// Check if a point is on the axis. and add it to linked.
// regions 1-topLeft, 2-bottomLeft, 3-bottomRigth, 4-topRight
// 5 --> error
int TwoDimTreeNode::is_rec_on_axis(Rectangle R) {
    
    int y = (Extent.Left + Extent.Right) / 2;
    int x = (Extent.Top + Extent.Bottom) / 2;
    
    if (y < R.Right && y >= R.Left) {
        Vertical.push_back(R);
        return 0;
    }
    
    else if (x < R.Bottom && x >= R.Top) {
        Horizontal.push_back(R);
        return 0;
    }
    
    else if (y >= R.Right && x >= R.Bottom) return 1;
    else if (y >= R.Right && x < R.Top) return 2;
    else if (y < R.Left && x < R.Top) return 3;
    else if (y < R.Left && x >= R.Bottom) return 4;
    else return 5;
}

















