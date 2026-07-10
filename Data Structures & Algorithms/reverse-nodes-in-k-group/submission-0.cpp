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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        vector<int> nums;
        vector<int> sortnums;
        if (temp == NULL) {
            return nullptr;
        }
        while (temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int curr = 1;
        int n = nums.size();
        while ((curr * k) <= n) {
            for (int i = (curr * k) - 1; i >= (curr * k) - k; i--) {
                sortnums.push_back(nums[i]);
            }
            curr++;
        }
        if (((curr - 1) * k) != n) {
            for (int i = ((curr - 1) * k); i < n; i++) {
                sortnums.push_back(nums[i]);
            }
        }

        ListNode* AnsNode = new ListNode(0);
        temp = AnsNode;
        for (int i = 0; i < n; i++) {
            ListNode* newNode = new ListNode(sortnums[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return AnsNode->next;
    }
};