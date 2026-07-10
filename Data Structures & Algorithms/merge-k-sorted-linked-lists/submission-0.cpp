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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }
        vector<int> ans;
        ListNode* temp = lists[0];
        for(int i=0; i<n; i++){
            temp = lists[i];
            if(temp == NULL){
                continue;
            }
            while(temp != NULL){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(ans.begin(), ans.end());

        ListNode* AnsNode = new ListNode(0);
        temp = AnsNode;
        n = ans.size();
        if(n == 0){
            return nullptr;
        }
        for(int i =0; i<n; i++){
            ListNode* newNode = new ListNode(ans[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return AnsNode->next;
    }
};