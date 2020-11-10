#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.
Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

EXAMPLE
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with 
nums = [2,2,3,3] or nums = [2,3,0,0], your answer will be accepted.

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
Explanation: Your function should return length = 5, with the first five elements of nums 
containing 0, 1, 3, 0, and 4. Note that the order of those five elements can be arbitrary. 
It doesn't matter what values are set beyond the returned length.
*/

int removeElement(vector<int>& nums, int val) {
    int length = nums.size();
    
    //Search through array for a match
    for(int n = 0; n < nums.size(); n++) {
        if(nums[n] == val) {
            
            //Shift values back
            for(int i = n; i < nums.size() - 1; i++) {
                nums[i] = nums[i + 1];
            }
            
            //Reassign dummy value and update new length
            nums[nums.size() - 1] = -1;
            length--;
            //Move index back
            n--;
        }
    }
    return length;
}

/*
BCR:        O(length of array)
Runtime:    O(length of array)
Space:      O(1)

Leetcode
runtime: 0ms
memory: 9.2mb
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    return 0;
}