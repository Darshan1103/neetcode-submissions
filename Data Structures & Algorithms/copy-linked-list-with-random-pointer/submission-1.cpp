/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node* nhead = new Node(head->val);
        Node* ncur = nhead;
        Node* cur = head;
        unordered_map<Node*,Node*>mpp;

        while(cur != NULL){
            mpp[cur] = ncur;

            if(cur->next != NULL){
                ncur->next = new Node(cur->next->val);
            }
            cur = cur->next;
            ncur = ncur->next;
        }

        cur = head;
        ncur = nhead;

        while (cur != NULL){
            if(cur->random != NULL){
                ncur->random = mpp[cur->random];
            }

            cur = cur->next;
            ncur = ncur->next;
        }
        return nhead;
    }
};
