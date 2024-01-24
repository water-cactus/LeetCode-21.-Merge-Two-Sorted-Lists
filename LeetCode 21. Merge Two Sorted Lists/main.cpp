#include <iostream>
struct ListNode * mergeTwoLists(ListNode* L, ListNode* R);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
int main() {
    ListNode L1(3);
    ListNode L2(2,&L1);
    ListNode L3(1, &L2);

    ListNode R1(6);
    ListNode R2(5, &R1);
    ListNode R3(4, &R2);
    ListNode * ANS = mergeTwoLists(&L3, &R3);

	return 0;
}

struct ListNode * mergeTwoLists(ListNode * L, ListNode * R) {
    ListNode* head, * temp;
    head = new ListNode();
    temp = head;


    while (L && R) {
        if (L->val < R->val) {
            temp->next = L;
            L = L->next;
        }
        else {
            temp->next = R;
            R = R->next;
        }
        temp = temp->next;
    }
    if (L) { temp->next = L; }
    if (R) { temp->next = R; }
    return head->next;
}



