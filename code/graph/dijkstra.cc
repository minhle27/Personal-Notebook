/**
 * Description: Dijkstra algorithm for finding SSSP
 * Time: O(Mlog N) 
 */

void dijkstra(int n, int s, vector<vector<Edge>> &E, vector<long long> &D, vector<int> &trace) {
    D.resize(n, INF);
    trace.resize(n, -1);
    vector<bool> P(n, 0);

    D[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != D[u]) continue; // node is already processed or equivalently processed[u] = true
        for (auto e : E[u]) {
            int v = e.v;
            long long w = e.w;

            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({v, D[v]});
                trace[v] = u;
            }
        }
    }
}

/*
Trick: To find all shortest paths of all nodes to a node A. Simply reverse 
the orginal graph and then run dijkstra from node A. Useful when finding shortest path
given the condition that an edge is fixed. 
*/