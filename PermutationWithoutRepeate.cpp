// C++ program to print all the permutation
// of the given string.
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// count of total permutations
int total = 0;

void permute(int i, string &s)
{
	// base case
	if (i == (s.length() - 1)) {
		cout << s << endl;
		total++;
		return;
	}


	// loop from j = 1 to length of string
	for (int j = i; j < s.length(); j++) {
		if (j>i && s[i] == s[j])
			continue;
		if (j>i && s[j-1] == s[j]) {
			continue;
		}
	
		// swap the elements
		swap(s[i], s[j]);
	
		// recursion call
		permute(i + 1, s);
	
		//backtrack
		swap(s[i], s[j]);
	}
}

// Driver code
int main()
{
	string s = "abca";
	
	// sort
	sort(s.begin(), s.end());

	// Function call
	permute(0, s);
	cout << "Total distinct permutations = " << total
		<< endl;
	return 0;
}

// This code is contributed by risingStark.
