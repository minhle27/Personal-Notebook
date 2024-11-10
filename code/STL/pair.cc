// pair<type1, type2> p: Creates a pair p with two elements with the first one being of type1 and the second one being of type2.
// make_pair(a, b): Returns a pair with values a, b.
// {a, b}: With C++11 and above, this can be used as to create a pair, which is easier to write than make_pair(a, b).
// pair.first: The first value of the pair.
// pair.second: The second value of the pair.

#include <iostream>
#include <vector>

using namespace std;

/**
 * Output:
 * Testing 123
 * It is possible to edit pairs after declaring them 123
 * Testing curly braces
 */
int main() {
	pair<string, int> pair1 = make_pair("Testing", 123);
	cout << pair1.first << " " << pair1.second << endl;

	pair1.first = "It is possible to edit pairs after declaring them";
	cout << pair1.first << " " << pair1.second << endl;

	pair<string, string> pair2{"Testing", "curly braces"};
	cout << pair2.first << " " << pair2.second << endl;
}