#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
Write a function that checks if a given string is a permutation of any palindrome.

EXAMPLE
Input: Tact Coa
Out: True ("taco cat", "atcocta")
*/

bool palinPerm(string input) {
    int charCount [26] = {0};
    int index;
    int oddCount = 0;

    //Go through string
    for (int i = 0; i < input.length(); i++) {
        //Count character after conversion
        if ((input[i] > 64) && (input[i] < 91)) {
            index = input[i] - 65;
            charCount[index]++;
        } else if ((input[i] > 96) && (input[i] < 123)) {
            index = input[i] - 97;
            charCount[index]++;
        }

        //Check how many odd counts there are
        if (charCount[index] % 2 == 1) {
            oddCount++;
        } else {
            oddCount--;
        }
    }

    return (oddCount <= 1);
}

/*
BCR:        O(length)
Runtime:    O(length)
Space:      O(1)
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    cout << "Test: " << test << endl 
        << "Output: " << palinPerm(test) << endl;

    return 0;
}