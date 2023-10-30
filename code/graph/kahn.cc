/**
 * Description: Kahn Algorithm for Topo sort
 */

vi toposort() {
    vi order;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur); 
        for (auto v : g[cur]) {
            indeg[v]--; 
            if (indeg[v] == 0) q.push(v);   
        }
    }
    return order;
}

// if there isn't a valid topological sorting
if (order.size() != n) {
    
}

/*
We can also use Kahn's algorithm to extract the lexicographically minimum 
topological sort by breaking ties lexographically. Simply replace the queue 
with a priority_queue to implement this extension.
*/
