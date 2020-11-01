#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
Function that reverses a given string

EXAMPLE
Input: Hello
Out: olleh
*/

string reverseString(string s) {
    char temp;
    for(int i = 0; i < s.size() / 2; i++) {
        temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
    return s;
}

/*
BCR:        O(length of string / 2)
Runtime:    O(length of string / 2)
Space:      O(1)
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    cout << reverseString(test);

    return 0;
}