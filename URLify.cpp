#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/*
Write a method that replaces all spaces with '%20'. You may assume that the string has
sufficient space at the end to hold all additional characters. Also you are given the
true length of the string.

EXAMPLE
Input:      "Mr John Smith  ", 13
Output:     "My%20John%20Smith"
*/

string urlify(string input, int length) {
    string result = "";
    
    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            result.append("%20");
        } else {
            result += input[i];
        }
    }

    return result;
}

/*
BCR:        O(length)
Runtime:    O(length)
Space:      O(length)
*/

int main() {
    string test = "Job searching sucks";
    int testLength = 20;

    cout << "Test: " << test << endl 
        << "Output: " << urlify(test, testLength) << endl;

    return 0;
}