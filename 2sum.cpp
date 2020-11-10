#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

EXAMPLE
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
*/

vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        
        for(int i = 0; i < nums.size(); i++) {
            
            //If value is found, map.find returns map.end if not found
            if(m.find(target - nums[i]) != m.end()) {
                //Push index stored in map
                v.push_back(m[target - nums[i]]);
                //Push back current index
                v.push_back(i);
                return v;
            }
            
            //Otherwise add index to map, key is value in array index
            m[nums[i]]=i;
        }
        
        return v;
    }

/*
BCR:        O()
Runtime:    O()
Space:      O()
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    return 0;
}