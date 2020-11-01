#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::min;

/*
Function prints last K lines of an input file.

EXAMPLE
Input:
Out:
*/

void lastLines(string fileName, int number) {
    ifstream file(fileName);
    string buffer;

    //Get linecount of file
    int lineCount = 0;

    while(getline(file, buffer)) {
        lineCount++;
    }

    file.close();    
    lineCount -= number;

    //Error handling
    if (lineCount < 0) {
        cout << "There are not enough lines in that file!\n";
    } else {
        //Reset pointer in file to start
        file.open(fileName);

        //Bring pointer to beginning of place to print
        for (int i = 0; i < lineCount; i++) {
            getline(file, buffer);
        }

        //Print till EOF
        while(getline(file, buffer)) {
            cout << buffer << endl;
        }

        file.close();
    }
}

/*
BCR:        O(Lines in file)
Runtime:    O(2 * lines in file) = O(Lines in file)
Space:      O(1)
*/

//Book solution
//Function lacks flexibility to adjust how many lines to print
void printLast10Lines(string fileName) {
    const int K = 10;
    ifstream file(fileName);
    string L[K];
    int size = 0;

    while (file.peek() != EOF) {
        getline(file, L[size % K]);
        size++;
    }

    int start = size > K ? (size % K) : 0;
    int count = min(K,size);

    for (int i = 0; i < count; i ++) {
        cout << L[(start + i) % K] << endl;
    }
}

int main(int argc, char* argv[]) {
    string test = argv[1];
    int test1 = atoi(argv[2]);

    cout << "Testing lastLines(" << argv[1] << "," << argv[2] << ")" << endl;
    lastLines(test, test1);

    cout << "Testing printLast10Lines(" << argv[1] << ")" << endl;
    printLast10Lines(test);

    return 0;
}