#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if(s.size()==0)
			return true;
		int j = 0;
		for (int i = 0; i < t.size(); i++) {
			if (s[j] == t[i])
				j++;
			if (j == s.size())
				return true;
		}
		return false;
	}
};
int main() {
	string s = "abc";
	string t = "adebsc";
	if (Solution().isSubsequence(s, t))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}