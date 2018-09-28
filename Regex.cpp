#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	regex num_regex("[1][0]+");
	string s("110000000");
	cout<<regex_match(s, num_regex)<<endl;
	return 1;
}