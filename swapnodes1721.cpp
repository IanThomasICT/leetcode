#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int i = 1;
        ListNode* tmp = head;       
        ListNode* tmp2 = head;
        ListNode* n1;
        ListNode* prev1;
        ListNode* next1;
        ListNode* n2;
        ListNode* prev2;
        ListNode* next2;

        // Empty list or list with only one value
        if (!head || head->next == nullptr){
            return head;
        }

        // Identify nodes
        while (tmp->next != nullptr){
            i++;

            // First node
            if (i == k){
                prev1 = tmp;
                n1 = tmp->next;
                next1 = n1->next;
            } 

            // Second node
            if (tmp->next->next == nullptr){
                prev2 = tmp2;
                n2 = tmp2->next;
                next2 = n2->next;
            }

            // Traverse linked list
            if (i <= k)
                tmp = tmp->next;
            else {
                tmp = tmp->next;
                tmp2 = tmp2->next;
            }
        }

        // Swapped value is greater than the size of the list
        if (k > i){
            return head;
        }

        // Special case: If k is in the middle of a list with an odd number of integers
        if (i % 2 == 1 && k == (i/2)+1){
            return head;
        }

        // Swap first and last nodes
        if (k == 1 || k == i){
            // Special case: List consists of two nodes
            if (i == 2){
                n1 = head;
                n2 = head->next;
                n2->next = head;
                n1->next = nullptr;
                head = n2;
                return n2;
            }

            if (k == 1) {
                n1 = head;
                next1 = head->next;
                prev2->next = n1;
                n2->next = next1;
                n1->next = nullptr;
                head = n2;
                return head;
            } else {
                n2 = head;
                next2 = head->next;
                prev1->next = n2;
                n1->next = next2;
                n2->next = nullptr;
                head = n1;
                return head;
            }
        } 
        
        // Swap nodes between first and last nodes
        else {
            // k is right of the middle of the list (First and second node are flipped)
            if (k > i/2){
                // Nodes are adjacent 
                if (k-1 == i/2 && i % 2 == 0){
                    prev2->next = n1;
                    n2->next = n1->next;
                    n1->next = n2;
                } else {
                    prev2->next = n1;
                    prev1->next = n2;
                    n2->next = n1->next;
                    n1->next = next2;
                }
            } else {  
                // Adjacent nodes
                if (k == i/2 && i % 2 == 0){
                    prev1->next = n2;
                    n1->next = n2->next;
                    n2->next = n1;
                } else {
                    prev1->next = n2;
                    prev2->next = n1;
                    n1->next = n2->next;
                    n2->next = next1;
                }
            }   
        }

        return head;
    }    
};



// int main() {
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);
//     head->next->next->next->next->next = new ListNode(6);
//     head->next->next->next->next->next->next = new ListNode(7);
//     // head->next->next->next->next->next->next->next = new ListNode(8);

//     int size = 0;
//     ListNode* current = head;
//     while (current != nullptr){
//         std::cout << current->val << " ";
//         current = current->next;
//         size++;
//     }
//     std::cout << std::endl;

//     int input;
//     cout << "Enter the numbers you would like to swap: ";
//     std::cin >> input;
    
//     ListNode* newhead;
//     Solution s;
//     if (input > size){
//         std::cerr << "Error: invalid input." << endl;
//         return -1;
//     } else {
//         newhead = s.swapNodes(head,input);
//     }
    

//     current = newhead;
//     while (current != nullptr){
//         std::cout << current->val << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;



// }