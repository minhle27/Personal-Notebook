/**
 * Description: FloodFill
 */

// const int dx[8]{1,0,-1,0,-1,1,-1,1}, dy[8]{0,1,0,-1,-1,1,1,-1}; 
// const int dx[4]{1,0,-1,0}, dy[8]{0,1,0,-1}; 
bool isValid(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}

int bfs(pi c){
    int size = 1;
    visited[c.f][c.s] = true;
    queue<pi> q;
    q.push(c);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int u = x + dx[i];
            int v = y + dy[i];
            if (isValid(u, v) && a[u][v] == 1 && !visited[u][v]){
                q.push({u, v});
                size++;
                visited[u][v] = true;
            }
        }
    }
    return size;
}
