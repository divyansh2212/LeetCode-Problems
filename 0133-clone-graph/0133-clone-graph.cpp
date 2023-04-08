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
        
        if(node == NULL)
            return NULL;
        
        unordered_map<int, Node*> clonedNodes;
        set<pair<int, int>> edges;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            clonedNodes[front->val] = new Node(front->val);
            
            for(auto &child : front->neighbors)
            {
                edges.insert({child->val, front->val});
                edges.insert({front->val, child->val});
                if(visited.find(child) == visited.end())
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        
        for(auto &it : edges)
        {
            int x1 = it.first, x2 = it.second;
            clonedNodes[x1]->neighbors.push_back(clonedNodes[x2]);
            // clonedNodes[x2]->neighbors.push_back(clonedNodes[x1]);
        }
        
        return clonedNodes[node->val];
    }
};
