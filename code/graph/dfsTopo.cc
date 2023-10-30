/**
 * Description: using DFS to find one valid Topo Sort of a give DAG
 */

/*
Every DAG has at least one (a Singly Linked List-like DAG), 
possibly more than one topological sorts, and up to n! topological sorts 
(a DAG with n vertices and 0 edge). There is no possible topological ordering of a non DAG.
*/
int n, m;
const int maxn = 1e5 + 7;
vector<vi> g(maxn);
vector<bool> visited(maxn, false);
vi res;

void dfs(int s) {
    visited[s] = true;
    for (auto u : g[s]) { 
        if (!visited[u]) dfs(u); 
    }
    res.PB(s);
}

bool toposort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    reverse(res.begin(), res.end());

    // check if the graph is actually a DAG
    vi ind(n + 3);
    for (int i = 0; i < n; i++) ind[res[i]] = i + 1;
    for (int i = 1; i <= n; i++) {
        for (auto u : g[i]) {
            if (ind[u] < ind[i]) return false;
        }
    }
    return true;
}

// return true if graph is a DAG, valid topo order is stored in res
