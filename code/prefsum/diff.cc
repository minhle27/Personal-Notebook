// Difference Array
// Source: VNOI

vector<int> buildDifferenceArray(const vector<int>& a) {
    int n = (int)a.size();

    vector<int> differenceArray(n - 1);

    for (int i = 0; i < n - 1; i++)
        differenceArray[i] = a[i + 1] - a[i];

    return differenceArray;
}

// Using STL
adjacent_difference(first, last, result, binary_op)

vector<int> a = {3, -1, -4, 1, 5, 9, -2, -6};
vector<int> diffTwo(n);
adjacent_difference(a.begin(), a.end(), diffTwo.begin());
printArray(diffTwo);
// 3 -4 -3 5 4 4 -11 -4


// Increment, Decrement Point Technique
int main() {

	int n = 4; // Size of array
	vector<int> elements{0, 1, 4, 6, 7}; // 1 based indexing
        // n+2 because we need are not using the 0-th index and we need one more element in the array.
	vector<int> diff(n + 2, 0);

	int updateValue = 10;
	int l = 1, r = 4;
	diff[l] += updateValue;
	diff[r + 1] -= updateValue;

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		elements[i] += diff[i];
	}
	for (int i = 1; i <= n; i++) cout << elements[i] << " "; // 11 14 16 17
	return 0;
}
