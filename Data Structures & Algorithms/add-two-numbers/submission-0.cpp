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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum = 0;
        int curr = 0;
        int carry = 0;

        ListNode* AnsNode = new ListNode(0);
        ListNode* temp = AnsNode;

        while(temp1 != NULL || temp2 != NULL){
            if(temp1 == NULL){
                sum = 0 + temp2->val + carry;
            }
            else if(temp2 == NULL){
                sum = temp1->val + 0 + carry;
            }
            else{
                sum = temp1->val + temp2->val +carry;
            }
            
            if(sum >= 10){
                curr = sum % 10;
                carry = 1;
            }
            else{
                curr = sum;
                carry = 0;
            } 
            ListNode* newNode = new ListNode(curr);

            temp->next = newNode;
            temp = temp->next; 
            if(temp1 != NULL){
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                temp2 = temp2->next;
            }   
        }
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
        }
        return AnsNode->next;
    }
};