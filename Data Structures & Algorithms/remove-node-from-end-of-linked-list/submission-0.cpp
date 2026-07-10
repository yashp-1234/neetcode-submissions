class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Count total nodes (start from head)
        int total = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            total++;
            temp = temp->next;
        }

        // Position from start (1-based index)
        int posFromStart = total - n + 1;

        // Special case: remove head
        if (posFromStart == 1) {
            ListNode* newHead = head->next;
            delete head;  
            return newHead;
        }

        // Traverse to the node before the one we delete
        temp = head;
        for (int i = 1; i < posFromStart - 1; i++) {
            temp = temp->next;
        }

        // Delete the target node
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
