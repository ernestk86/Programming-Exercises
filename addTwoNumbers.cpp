/*
Ernest Kim
10/25/20
1 hour
Memory usage: 71.5mb
*/

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 
0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//Helper function to assign listnode's value to temp variable
void _assignValue (int & value, ListNode* & pointer) {
    if (pointer != nullptr) {
        value = pointer->val;

        if (pointer->next != nullptr) {
            pointer = pointer->next;
        } else {
            pointer = nullptr;
        }
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //Initialize variables
    ListNode* temp = new ListNode;
    ListNode* result = temp; //Need to return pointer to first node
    ListNode* tracker1 = l1;
    ListNode* tracker2 = l2;
    bool carryTheOne = false;
    int x, y, sum;
    
    //Keep going until there are no nodes left
    while ((tracker1 != nullptr) || (tracker2 != nullptr)) {
        //Assign Values
        _assignValue(x, tracker1);
        _assignValue(y, tracker2);
        
        //If previous sum was over 9
        if (carryTheOne) {
            sum = 1 + x + y;
            carryTheOne = false;
        } else {
            sum = x + y;
        }
        
        //Reset variables
        x = 0; 
        y = 0;
        
        //If current sum is over 9
        if (sum > 9) {
            carryTheOne = true;
            sum -= 10;
        }
        
        //Assign node value
        temp->val = sum;
        
        //Create new node if necessary
        if ((tracker1 != nullptr) || (tracker2 != nullptr)) {
            temp->next = new ListNode;
            temp = temp->next;
        } else { //New node is 1 from carrying
            if (carryTheOne) {
                temp->next = new ListNode;
                temp = temp->next;
                temp->val = 1;
            }
        }
    }
    
    return result;
}