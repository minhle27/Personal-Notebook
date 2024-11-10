/**
 * Description: Tuple
 */

// tuple has built-in comparison function
typedef tuple<int, string, string> iss; // combine the 3 fields
auto &[ageA, lastA, firstA] = A; // decompose the tuple

vector<iii> EL(E);
for (auto &[w, u, v] : EL) // C++17 style

tuple <char, int, float> geek;
geek = make_tuple('a', 10, 15.5);
cout << get<0>(geek) << " " << get<1>(geek);
get<0>(geek) = 'b';
get<2>(geek) =  20.5;

int i_val;
char ch_val;
float f_val;   
    
// Initializing tuple
tuple<int,char,float> tup1(20,'g',17.5);

// Use of tie() without ignore
tie(i_val,ch_val,f_val) = tup1;
// ignores char value
tie(i_val,ignore,f_val) = tup1;

/**
 * tuple<type1, type2, ..., typeN> t: Creates a tuple with N elements, i'th one being of typei.
 * make_tuple(a, b, c, ..., d): Returns a tuple with values written in the brackets.
 * get<i>(t): Returns the i'th element of the tuple t. Can also be used to change the element of a tuple.
This operation only works for constant i.
 * tie(a, b, c, ..., d) = t : Assigns a, b, c, ..., d to the elements of the tuple t accordingly.
 */
/**
 * Output:
 * 3 4 5
 * 7 4 5
 * Hello world 100
 */
int main() {
	int a = 3, b = 4, c = 5;
	tuple<int, int, int> t = tie(a, b, c);
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	get<0>(t) = 7;
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

	tuple<string, string, int> tp2 = make_tuple("Hello", "world", 100);
	string s1, s2;
	int x;
	tie(s1, s2, x) = tp2;
	cout << s1 << " " << s2 << " " << x << endl;
}

     