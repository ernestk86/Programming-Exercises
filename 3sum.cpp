#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
Problem description

EXAMPLE
Input:
Out:
*/

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<vector<int>> combinations;
        vector<int> combo;
        vector<int> addThis;
        int zeroCount = 0;
        
        if (nums.size() < 3) {
            return result;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int n = j + 1; n < nums.size(); n++) {
                    //If combination is found
                    if(nums[i] + nums[j] + nums[n] == 0) {
                        addThis.push_back(nums[j]);
                        addThis.push_back(nums[i]);
                        addThis.push_back(nums[n]);
                        
                        if(combinations.empty()) {
                            result.push_back(addThis);
                            combo.push_back(j);
                            combo.push_back(i);
                            combo.push_back(n);
                            combinations.push_back(combo);
                            combo.clear();
                            addThis.clear(); 
                        } else {
                        //Check if it's already been added
                            for(int k = 0; k < combinations.size(); k++) {
                                if((j + i + n) != (combinations[k, 0] + combinations[k, 1] + combinations[k, 2])) {
                                    result.push_back(addThis);
                                    combo.push_back(j);
                                    combo.push_back(i);
                                    combo.push_back(n);
                                    combinations.push_back(combo);
                                    combo.clear();
                                    addThis.clear(); 
                                }
                            }
                        }
                    }
                }
            }
        }
//             //If value is not zero
//             if(nums[i] != 0) {
                
//                 if(zeroCount == 1) {
//                     //Search for it's opposite
//                     for(int j = i + 1; j < nums.size(); j++) {
//                         if(nums[j] == (nums[i] * -1)) {
//                             addThis.push_back(nums[j]);
//                             addThis.push_back(nums[i]);
//                             break;
//                         }
//                     }
//                 } else if(zeroCount == 0) {
//                     for(int j = i + 1; j < nums.size(); j++) {
//                         for(int n = j + 1; n < nums.size(); n++) {
//                             if(nums[i] + nums[j] + nums[n] == 0) {
//                                 addThis.push_back(nums[j]);
//                                 addThis.push_back(nums[i]);
//                                 addThis.push_back(nums[n]);
//                             }
//                         }
//                     }
//                 }
                
//             //If value is zero
//             } else {
//                 zeroCount++;
                
//                 //Array can only have 1 or 3 zeros
//                 if((addThis.size() == 2) || (addThis.size() == 0)){
//                     addThis.push_back(nums[i]);
//                 }
//             }
            
//             //Triple is complete
//             if(addThis.size() == 3) {
//                 result.push_back(addThis);
//                 addThis.clear();
//                 zeroCount = 0;
//             }
        // }
        
        return result;
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