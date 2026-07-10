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
    void reorderList(ListNode* head) {

        if (head != NULL) {
            ListNode* temp = head;
            vector<int> vals;
            while (temp != NULL) {
                vals.push_back(temp->val);
                temp = temp->next;
            }
            vector<int> finval;
            int l = 0;
            int r = vals.size()-1;

            while (l <= r) {
                finval.push_back(vals[l]);
                finval.push_back(vals[r]);
                l++;
                r--;
            }
            r = vals.size();
            temp = head;
            for (int i = 0; i < r; i++) {
                temp->val = finval[i];
                temp = temp->next;
            }
        }
    }
};