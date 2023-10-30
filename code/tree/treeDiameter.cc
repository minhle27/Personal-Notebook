/**
 * Description: Tree Diameter
 */

/*
Run a DFS from any node p. Let a be a node whose distance from node p is maximized. 
Run another DFS from node a. Let b be a node whose distance from node a is maximized. 
a -> b is a diameter.

the height of each component with root in the left half of the diameter 
(i.e., dist(a,d)<dist(d,b)) is at most the distance of the root of the component from 
the left end of the diameter. Same statement for the right half of the diameter

For each node i, let's find a node j such that dist(i,j) is maximum.
Claim: j = a or j = b always works.

Most of the times, spamming "the farthest node from each node is one end of the diameter" 
and "the height of each component is smaller than the distance to the closest end of the diameter" 
is enough to reduce the problem to something simpler. you may need to consider any path of the 
tree. There are two cases: the path intersects or doesn't intersect the diameter.
*/



pi dfs(int cur, int par) {
    pi res = {0, cur};
    for (auto u : g[cur]) {
        if (u == par) continue;
        pi tmp = dfs(u, cur);
        tmp.first++;
        ckmax(res, tmp);
    }
    return res;
}

int a = dfs(1, 0).second;
int b = dfs(a, 0).first; 