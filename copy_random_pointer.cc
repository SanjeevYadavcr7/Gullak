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
        Node* curr = head;
        unordered_map<Node*, Node*> nodes_map;

        while(curr) {
            nodes_map[curr] = new Node(curr->val);
            curr = curr->next; 
        }

        curr = head;
        while(curr) {
            Node* node = nodes_map[curr];
            node->next = nodes_map[curr->next];
            node->random = nodes_map[curr->random];
            curr = curr->next;
        }

        return nodes_map[head];
    }
};
