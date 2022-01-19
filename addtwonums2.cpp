#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* curr = result;
    int v1, v2;
    bool carry = false, done1 = false, done2 = false;
    while (l1 != nullptr || l2 != nullptr){
        if (l1 == nullptr){
            v1 = 0;
            v2 = l2->val;
            done1 = true;
        } else if (l2 == nullptr){
            v1 = l1->val;
            v2 = 0;
            done2 = true;
        } else {
            v1 = l1->val;
            v2 = l2->val;
        }
        int carryint = carry ? 1 : 0;
        int total = v1 + v2 + carryint;
        curr->val = total % 10;
        total >= 10 ? (carry = true) : (carry = false);
        if (l1 != nullptr && l1->next != nullptr || l2 != nullptr && l2->next != nullptr){
            curr->next = new ListNode();
            curr = curr->next;
        }
        
        if      (done1){ l2 = l2->next;}        
        else if (done2){ l1 = l1->next;}   
        else {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    
    
    if (carry == true)
        curr->next = new ListNode(1);
    
    return result;
}


void print(ListNode* list){
    while (list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

void append(ListNode* &list, int val){
    ListNode* tmp = list;
    while (tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = new ListNode(val);
}

int main() {
    ListNode* l1 = new ListNode(9);
    append(l1,9);
    append(l1,9);
    append(l1,9);
    append(l1,9);
    append(l1,9);
    append(l1,9);
    print(l1);
    
    ListNode* l2 = new ListNode(9);
    append(l2,9);
    append(l2,9);
    append(l2,9);
    print(l2);

    ListNode* head = addTwoNumbers(l1,l2);
    print(head);
    
    return 0;
}

