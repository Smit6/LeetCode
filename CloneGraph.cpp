// Time: O(V + E)
// Space : O(V)

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
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        if (original_copy.find(node) != original_copy.end())
            return original_copy[node];
        
        Node* copy = new Node(node->val);
        original_copy[node] = copy;

        for (auto& neighbor : node->neighbors)
            (copy->neighbors).push_back(cloneGraph(neighbor));

        return copy;
    }
private:
    unordered_map<Node*, Node*> original_copy;
};
