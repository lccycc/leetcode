/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        vector<UndirectedGraphNode *> h;
        unordered_map<int, UndirectedGraphNode *> visit;
        h.push_back(node);
        visit[node->label] = new UndirectedGraphNode(node->label);
        for (int i = 0; i<h.size(); i++){
            UndirectedGraphNode *x = visit[h[i]->label];
            for (int j = 0; j<h[i]->neighbors.size(); j++){
                UndirectedGraphNode *nei = h[i]->neighbors[j];
                if (visit.find(nei->label) == visit.end()){
                    visit[nei->label] = new UndirectedGraphNode(nei->label);
                    h.push_back(nei);
                }
                x->neighbors.push_back(visit[nei->label]);
            }
        }
        return visit[node->label];
    }
};

