#include <iostream>

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead(nullptr);
        while (head != nullptr){
            ListNode* tmp = new ListNode(head->val, newhead); // Creates node pointing to the new head
            newhead = tmp; // Moves new head back to the new node
            head = head->next; 
        }

        return newhead;
    }

    ListNode* recursive_revereList(ListNode* head){
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* tmp = head;
        ListNode* newTail = tmp->next;

        ListNode* result = recursive_revereList(newTail);

        newTail->next = tmp;
        tmp->next = nullptr;

        return result;
    }
};








int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* current = head;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Solution s;
    ListNode* newhead = s.reverseList(head);

    current = newhead;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;



}