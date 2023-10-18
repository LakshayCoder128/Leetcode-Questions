#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> startNodes; // An array to store the starting nodes (nodes with no incoming edges).
    std::vector<std::vector<int>> graph; // An adjacency list representation of the course prerequisites graph.
    std::vector<int> time; // An array to store the time required to complete each course.
    std::vector<bool> visited; // An array to track visited nodes during DFS.
    std::vector<int> ans; // An array to store the maximum time needed for each course.

public:
    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
        toGraph(relations, n); // Convert the input relations into a graph.
        this->time = time;
        ans = std::vector<int>(n, 0); // Initialize the ans array to store maximum times.
        visited = std::vector<bool>(n, false); // Initialize the visited array for DFS.
        int longest = 0;

        // For each starting node (no incoming edges), find the maximum time needed.
        for (int node : startNodes) {
            longest = std::max(longest, calculate(node));
        }
        return longest;
    }

    // Convert the input relations into an adjacency list graph.
    void toGraph(std::vector<std::vector<int>>& edges, int n) {
        std::vector<int> incoming(n, 0);
        std::vector<int> outgoing(n, 0);

        // Count incoming and outgoing edges for each node.
        for (std::vector<int> e : edges) {
            outgoing[e[0] - 1]++;
            incoming[e[1] - 1]++;
        }

        int startCnt = 0;

        // Count the number of starting nodes (nodes with no incoming edges).
        for (int i : incoming) {
            if (i == 0) {
                startCnt++;
            }
        }

        startNodes = std::vector<int>(startCnt, 0);

        // Populate the starting nodes array.
        for (int sni = 0, i = 0; sni < startNodes.size(); i++) {
            if (incoming[i] == 0) {
                startNodes[sni++] = i;
            }
        }

        // Create the adjacency list graph.
        graph = std::vector<std::vector<int>>(n);

        // Populate the graph with edges.
        for (std::vector<int> e : edges) {
            graph[e[0] - 1].push_back(e[1] - 1);
        }
    }

    // Recursively calculate the maximum time needed for a course using DFS.
    int calculate(int node) {
        if (ans[node] > 0) {
            return ans[node];
        }

        int worstPrereq = 0;
        visited[node] = true;

        // Visit each child (prerequisite) and find the maximum time.
        for (int child : graph[node]) {
            if (!visited[child]) {
                worstPrereq = std::max(calculate(child), worstPrereq);
            }
        }

        visited[node] = false;

        // Store the maximum time needed for the current course.
        return ans[node] = worstPrereq + time[node];
    }
};