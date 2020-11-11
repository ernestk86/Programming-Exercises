#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct
ways can you climb to the top?

EXAMPLE
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

1 <= n <= 45
*/

int climbStairs(int n) {
    if(n < 2) {
        return 1;
    }
    
    int first = 1;
    int second = 2;
    for(int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
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