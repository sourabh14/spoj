#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str,post;
		vector<char> stack;
		cin >> str;
		for (int i=0;i<str.length();i++) {
			switch (str[i]) {
				case '+' : stack.push_back(str[i]); 
					break;
				case '-' : stack.push_back(str[i]); 
					break;
				case '/' : stack.push_back(str[i]);
					break;	
				case '*' : stack.push_back(str[i]);
					break;
				case '^' : stack.push_back(str[i]);
					break;
				case '(' : 
					break;
				case ')' : post += stack[stack.size()-1];
						 stack.pop_back();
					break;					
				default : post += str[i];
					break;
			}
		}
		
		cout << post << endl;
	}
	return 0;
}					
