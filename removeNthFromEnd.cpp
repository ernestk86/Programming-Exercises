#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

EXAMPLE
Input: head = [1,2,3,4,5], n = 2
Out: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* ptr = head;
    ListNode* deleteMe;
    int size = 1;
    
    //If single node
    if (ptr->next == nullptr) {
        delete ptr;
        ptr = nullptr;
        return ptr;
    }
    
    //Get list size
    while (ptr->next != nullptr) {
        size++;
        ptr = ptr->next;
    }
    
    //Reset ptr
    ptr = head;
    
    //If getting rid of first node in list
    if (n == size) {
        deleteMe = ptr;
        ptr = ptr->next;
        delete deleteMe;
        deleteMe = nullptr;
        return ptr;
    }

    //Figure out which node to delete
    size -= (n + 1);
    
    //Bring pointer to previous node from delete
    for (int i = 0; i < size; i++) {
        ptr = ptr->next;
    }
    
    //Reconnect links
    deleteMe = ptr->next;
    ptr->next = deleteMe->next;

    //Delete and free memory
    deleteMe->next = nullptr;
    delete deleteMe;
    deleteMe = nullptr;

    return head;
}

/*
BCR:        O(length of list)
Runtime:    O(length of list)
Space:      O(length of list)

Test runtime: 0ms
Test memory: 11mb
*/

int main(int argc, char* argv[]) {
    string test = argv[1];

    return 0;
}