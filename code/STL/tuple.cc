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
     