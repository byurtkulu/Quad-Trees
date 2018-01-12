//
//  main.cpp
//  quad_tree
//
//  Created by Bahadır on 10.11.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "TwoDimTreeNode.hpp"
using namespace std;

// Find the point by checking the axis rectangles.
//
void find(TwoDimTreeNode* &rootPtr, int x, int y) {
    TwoDimTreeNode* temp = rootPtr;
    vector<Rectangle> intersect; // Store the intersected rectangles.
    int count = 0;
    while (temp != NULL) {
        
        // Check horizontal axis first
        for (int i = 0; i < temp->Horizontal.size(); i++) {
            int top = temp->Horizontal[i].Top;
            int left = temp->Horizontal[i].Left;
            int bottom = temp->Horizontal[i].Bottom;
            int right = temp->Horizontal[i].Right;
            
            if (x < bottom && x >= top && y < right && y >= left) {
                Rectangle temp(top, left, bottom, right);
                intersect.push_back(temp);
                count++;
            }
        }
        
        // Now check vertical axis
        for (int i = 0; i < temp->Vertical.size(); i++) {
            int top = temp->Vertical[i].Top;
            int left = temp->Vertical[i].Left;
            int bottom = temp->Vertical[i].Bottom;
            int right = temp->Vertical[i].Right;
            
            if (x < bottom && x >= top && y < right && y >= left) {
                Rectangle temp(top, left, bottom, right);
                intersect.push_back(temp);
                count++;
            }
        }
        
        
        Rectangle T(x,y,x,y); // represent point in terms of rectangle object.
        int region = temp->is_rec_on_axis(T); // Use is_rec_on_axis function to get the region of the point.
        
        // Search the rectangles in that region.
        if (region == 1)
            temp = temp->TopLeft;
        else if (region == 2)
            temp = temp->BottomLeft;
        else if (region == 3)
            temp = temp->BottomRight;
        else if (region == 4)
            temp = temp->TopRight;
        
    }
    
    // Print the result.
    cout << count << endl;
    for (int i = 0; i < intersect.size(); i++) {
        int top = intersect[i].Top;
        int left = intersect[i].Left;
        int bottom = intersect[i].Bottom;
        int right = intersect[i].Right;
        cout << top << " " << left << " " << bottom << " " << right << endl;
    }
    
}


//////////
// MAIN //
//////////
int main() {
    
    ifstream file;
    file.open("rectdb.txt");
    
    int top, left, bottom, right;
    TwoDimTreeNode* rootPtr; // Points to the root
    
    file >> top >> left >> bottom >> right; // first rectangle, extent.
    Rectangle first_rec(top, left, bottom, right);
    TwoDimTreeNode Root(first_rec);
    rootPtr = &Root;
    
    // Rectangles ...
    while (file >> top && top >= 0 && file>> left >> bottom >> right) {
        Rectangle R(top, left, bottom, right);
        TwoDimTreeNode* temp = rootPtr;
        while (temp->is_rec_on_axis(R) != 0) {
            int region = temp->is_rec_on_axis(R);
            
            if (region == 1) {
                Rectangle T(temp->Extent.Top, temp->Extent.Left, (temp->Extent.Bottom + temp->Extent.Top)/2, (temp->Extent.Right + temp->Extent.Left)/2);
                if (temp->TopLeft == NULL)
                    temp->TopLeft = new TwoDimTreeNode(T);
                temp = temp->TopLeft;
            }
            else if (region == 2) {
                Rectangle T((temp->Extent.Top + temp->Extent.Bottom)/2, temp->Extent.Left, temp->Extent.Bottom, (temp->Extent.Left + temp->Extent.Right)/2);
                if (temp->BottomLeft == NULL)
                    temp->BottomLeft = new TwoDimTreeNode(T);
                temp = temp->BottomLeft;
            }
            else if (region == 3) {
                Rectangle T((temp->Extent.Top + temp->Extent.Bottom)/2, (temp->Extent.Left + temp->Extent.Right)/2, temp->Extent.Bottom, temp->Extent.Right);
                if (temp->BottomRight == NULL)
                    temp->BottomRight = new TwoDimTreeNode(T);
                temp = temp->BottomRight;
            }
            else if (region == 4) {
                Rectangle T(temp->Extent.Top, (temp->Extent.Left + temp->Extent.Right)/2, (temp->Extent.Bottom + temp->Extent.Top)/2, temp->Extent.Right);
                if (temp->TopRight == NULL)
                    temp->TopRight = new TwoDimTreeNode(T);
                temp = temp->TopRight;
            }
        }
    }
    
    int x, y;
    while (cin >> x && x != -1 && cin >> y) {
        find(rootPtr, x, y);
    }
    
    
    
    return 0;
}
