/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    vector<Node*> clone;
    Node* utility(Node* node) {
        Node* c = new Node(node->val);
        clone[node->val] = c;
        auto& ref = node->neighbors;
        int n = ref.size();
        for (int i = 0; i < n; i++) {
            if (clone[ref[i]->val] == nullptr) {
                c->neighbors.push_back(utility(ref[i]));
            } else {
                c->neighbors.push_back(clone[ref[i]->val]);
            }
        }
        return c;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        clone.resize(101, nullptr);
        return utility(node);
    }
};