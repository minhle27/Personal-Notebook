/**
 * Description: DP on DAG
 */

// Extending Dijkstra algorithm
/*
A by product of Dijkstra algorithm is a directed, acyclic graph that indicates
for each node of the original graph the possible ways to reach the node using a
shortest path from the starting node. Dynamic programming can be applied to
that graph. For example: calculate the number of shortest paths from node 1
to node 5 using dynamic programming
*/

/*
 If we process the states in topological order, it is guaranteed that dp[u]
 will already have been computed before computing dp[v]
*/

// Example: ordering of node to be processed

vi order = toposort();
dp[1] = 1;
for (auto city : order) {
    for (auto prev : rev_g[city]) {
        ckmax(dp[city], dp[prev] + 1);
    }
}
cout << dp[n] << endl;
