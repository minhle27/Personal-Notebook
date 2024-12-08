struct MinDeque {
    deque<pi> q;
    int end = 0;
    int front = 0;
    int getMin() {
        return q.front().first;
    }
    void enqueue(int num) {
        while (!q.empty() && q.back().first > num) {
            q.pop_back();
        }
        q.push_back({num, end});
        end++;
    }
    void popFront() {
        if (!q.empty() && q.front().second == front) q.pop_front();
        front++;
    }
};
