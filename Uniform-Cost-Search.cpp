/*
===============================================
Uniform Cost Search (UCS) Algorithm
===============================================

===============================================
Time Complexity Analysis
===============================================
- The algorithm is similar to Dijkstra’s algorithm as it uses a **priority queue**.
- The main operations and their complexities:
  1. Inserting a node into the priority queue → O(log V)
  2. Extracting the node with the lowest cost → O(log V)
  3. Updating distances for each edge → O(E log V)
- Final time complexity:

  O((V + E) log V)

===============================================
Space Complexity Analysis
===============================================
- **Priority Queue**: O(V)
- **Cost Map**: O(V)
- **Graph Representation (Adjacency List)**: O(V + E)
- Final space complexity:

  O(V + E)

===============================================
*/



#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int vertex;
    int cost;

    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

void uniformCostSearch(unordered_map<int, vector<pair<int, int>>> &graph, int start, int goal) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    unordered_map<int, int> cost;

    pq.push({start, 0});
    cost[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.vertex == goal) {
            cout << "Goal reached with cost: " << current.cost << endl;
            return;
        }

        for (auto &neighbor : graph[current.vertex]) {
            int nextVertex = neighbor.first;
            int edgeCost = neighbor.second;
            int newCost = current.cost + edgeCost;

            if (!cost.count(nextVertex) || newCost < cost[nextVertex]) {
                cost[nextVertex] = newCost;
                pq.push({nextVertex, newCost});
            }
        }
    }

    cout << "Goal not reachable" << endl;
}

int main() {
    unordered_map<int, vector<pair<int, int>>> graph;
    graph[0] = {{1, 2}, {2, 5}};
    graph[1] = {{3, 1}};
    graph[2] = {{3, 2}};
    graph[3] = {{4, 3}};

    int start = 0, goal = 4;
    uniformCostSearch(graph, start, goal);

    return 0;
}


