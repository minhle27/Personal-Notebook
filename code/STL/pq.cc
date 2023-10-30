/**
 * Description: A priority queue (or heap) supports the following operations: insertion
 * of elements, deletion of the element considered highest priority, and retrieval
 * of the highest priority element, all in O(logN), retrieval takes O(1) time.
 */

priority_queue<int> pq;
pq.push(7);                // [7]
pq.push(2);                // [2, 7]
pq.push(1);                // [1, 2, 7]
pq.push(5);                // [1, 2, 5, 7]
cout << pq.top() << endl;  // 7
pq.pop();                  // [1, 2, 5]
pq.pop();                  // [1, 2]
pq.push(6);                // [1, 2, 6]

priority_queue<int,vector<int>,greater<int>> q; // min heap

// Note: Priority queue is about five times faster than a multiset.