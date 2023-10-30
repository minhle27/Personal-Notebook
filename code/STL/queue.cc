/**
 * Description: Queue
 */

queue<int> q;
q.push(2); // [2]
q.push(5); // [2,5]
cout << q.front() << "\n"; // 2 
q.pop(); // [5]
cout << q.back() << "\n"; // 5