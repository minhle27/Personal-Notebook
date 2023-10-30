/**
 * Description: String
 */

/*
size()/length() : return size
empty() : check empty string
clear() : delete string
insert(pos, string) 
erase(pos, len)
find(string)
substr(pos, len)
append(string, pos, len)
*/

int result = isalpha(char c)
int result = isdigit(char c)
int result = islower(char c)
int result = isupper(char c)

string s("12");
// atof(char *str)
int number = atoi(s.c_str()); // turn string into integer. For double, use atof
s = to_string(number);
char c = toupper(s[2]); // tolower is the same