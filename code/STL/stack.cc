/**
 * Description: Stack
 */

stack<int> s;
s.push(2); // [2]
s.push(5); // [2,5]
cout << s.top() << "\n"; // 5 
s.pop(); // [2]
cout << s.top() << "\n"; // 2