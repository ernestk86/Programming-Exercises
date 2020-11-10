#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

EXAMPLE
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by 
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) 
are being trapped.

Input: height = [4,2,0,3,2,5]
Output: 9
*/

int trapWater(vector<int>& height) {
        int left_max = 0, right_max = 0, result = 0;
        int leftPtr = 0, rightPtr = height.size() - 1;
        
        while(leftPtr < rightPtr) {
            if(height[leftPtr] < height [rightPtr]) {
                if(height[leftPtr] >= left_max) {
                    left_max = height[leftPtr];
                } else {
                    result += left_max - height[leftPtr];
                }
                leftPtr++;
            } else {
                if(height[rightPtr] >= right_max) {
                    right_max = height[rightPtr];
                } else {
                    result += right_max - height[rightPtr];
                }
                rightPtr--;
            }
        }
        
        return result;
    }

/*
BCR:        O(n)
Runtime:    O(n)
Space:      O(1)
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    return 0;
}