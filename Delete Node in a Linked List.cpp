class Solution {
public:
void deleteNode(ListNode* node) {
node->val=node->next->val;
node->next=node->next->next;
//break the link between the the node we want to delete and the node before that
}
};
