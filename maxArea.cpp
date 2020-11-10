#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::max;

/*
Given n non-negative integers a1, a2, ..., an , where each represents a 
point at coordinate (i, ai). n vertical lines are drawn such that the two 
endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, 
together with the x-axis forms a container, such that the container 
contains the most water.

Notice that you may not slant the container.

EXAMPLE
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Input: height = [1,1]
Output: 1

Input: height = [4,3,2,1,4]
Output: 16

Input: height = [1,2,1]
Output: 2

Constraints:

n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104
*/

int maxArea(vector<int>& height) {
    int leftIndex = 0;
    int rightIndex = height.size() - 1;
    int maxVol = 0;
    
    while(leftIndex < rightIndex) {
        int realHeight = min(height[leftIndex], height[rightIndex]);
        maxVol = max(maxVol, realHeight * (rightIndex - leftIndex));
        if(height[leftIndex] < height[rightIndex]) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }
    
    return maxVol;
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