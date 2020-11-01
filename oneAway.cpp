#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::abs;

/*
Write function that checks if a given string is one edit away from another string

EXAMPLE
Input:  pale, ple
Out:    true
Input:  pale, bae
Out:    false
*/

bool oneReplace(string one, string two) {
    bool foundDifference = false;
    
    for (int i = 0; i < one.length(); i++) {
        if (one[i] != two[i]) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }

    return true;
}

bool oneInsert(string one, string two) {
    int index1 = 0;
    int index2 = 0;

    //Go thorugh both strings
    while (index2 < two.length() && index1 < one.length()) {

        //Check differences and indices
        if (one[index1] != two[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;

        //Increment
        } else {
            index1++;
            index2++;
        }
    }

    return true;
}

bool oneAway(string input1, string input2) {
    //Check lengths and determine which edit it would require
    if (input1.length() == input2.length()) {
         return oneReplace(input1, input2);
    } else if (input1.length() + 1 == input2.length()) {
        return oneInsert(input1, input2);
    } else if (input1.length() - 1 == input2.length()) {
        return oneInsert(input2, input1);
    }
}

/*
BCR:        O(N)
Runtime:    O(N)
Space:      O(1)
*/

int main(int argc, char* argv[]) {
    string test = argv[1];
    string test1 = argv[2];

    cout << "Tests: " << test << ", " << test1 << endl
    << "Output: " << oneAway(test, test1) << endl;

    return 0;
}