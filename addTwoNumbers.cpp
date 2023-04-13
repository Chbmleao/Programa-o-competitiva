#include <string>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1;
        ListNode* current2 = l2;

        ListNode* first;
        int carryOn = 0;
        if(current1->val + current2->val > 9) {
            first = new ListNode((current1->val + current2->val) % 10);
            carryOn = 1;
        } else {
            first = new ListNode(current1->val + current2->val);
        }

        current1 = current1->next;
        current2 = current2->next;

        ListNode* previous = first;
        ListNode* current3 = first;

        while (current1 != NULL || current2 != NULL || carryOn) {
            int sum = carryOn;
            if (current1 != NULL) { 
                sum += current1->val;
                current1 = current1->next;
            }
            if(current2 != NULL) {
                sum += current2->val;
                current2 = current2->next;
            }
        
            carryOn = 0;

            if(sum > 9)
                carryOn = 1;

            current3 = new ListNode(sum % 10);
            previous->next = current3;
            previous = current3;  
        }

        return first;
    }
};

int main(int argc, char const *argv[])
{
    ListNode node1 = ListNode(5);
    

    ListNode node4 = ListNode(5);
    

    Solution sol;

    ListNode* current = sol.addTwoNumbers(&node1, &node4);

    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    


    return 0;
}
