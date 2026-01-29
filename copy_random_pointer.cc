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



// O(N) | O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = new Node(-1);
        Node* new_curr = new_head;
        Node* curr = head;

        // copy each node side-by-side
        while(curr) {
            Node* next_node = curr->next;

            Node* new_node = new Node(curr->val);
            curr->next = new_node;
            new_node->next = next_node;

            curr = next_node;
        }

        // assign random pointers for newly added nodes
        curr = head;
        while(curr) {
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // restore the original list
        curr = head;
        Node* pseudo_head = new Node(-1);
        Node* copy_iter = pseudo_head;

        while(curr) {
            Node* curr_next = curr->next->next;

            copy_iter->next = curr->next;
            copy_iter = copy_iter->next;

            curr->next = curr_next;
            curr = curr_next;
        }


        return pseudo_head->next;;
    }
};
