/**
 * Description: General about tree
 */

/*
Tree traversal is easier to implement than a general graph, There are no cycles in the 
tree and it is not possible to reach a node from multiple directions.

A general way to approach many tree problems is to first root the tree arbitrarily.
After this, we can try to solve the problem separately for each subtree.

An important observation is that every path in a rooted tree has a highest
point: the highest node that belongs to the path.
*/

void dfs(int s, int e) {
    res[s] = 1; // calculate some information during a tree traversal
    for (auto u : g[s]) {
        if (u == e) continue;
        dfs(u, s);
        res[s] += res[u];
    }
}

dfs(x, 0); // first node
