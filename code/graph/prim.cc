/**
 * Description: Prim Algo
 * Time: O(ElogV)
 * Status: 
 */

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order

void process(int u) { // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, -v});                         // sort by non-dec weight
}                                                // then by inc id

int main() {
    int V, E; scanf("%d %d", &V, &E);
    AL.assign(V, vii());
    for (int i = 0; i < E; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);  // read as (u, v, w)
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }
    taken.assign(V, 0);                            // no vertex is taken
    process(0);                                    // take+process vertex 0
    int mst_cost = 0, num_taken = 0;               // no edge has been taken
    while (!pq.empty()) {                          // up to O(E)
        auto [w, u] = pq.top(); pq.pop();            // C++17 style
        w = -w; u = -u;                              // negate to reverse order
        if (taken[u]) continue;                      // already taken, skipped
        mst_cost += w;                               // add w of this edge
        process(u);                                  // take+process vertex u
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == V-1) break;                 // optimization
    }
    printf("MST cost = %d (Prim's)\n", mst_cost);

}
