// C++ Program to convert decimal to any given base
#include <bits/stdc++.h>
using namespace std;

// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

// Function to convert a given decimal number
// to a base 'base' and
string fromDeci(string& res, int base, int inputNum)
{
	int index = 0; // Initialize index of result

	// Convert input number is given base by repeatedly
	// dividing it by base and taking remainder
	while (inputNum > 0) {
		res.push_back(reVal(inputNum % base));
		index++;
		inputNum /= base;
	}

	// Reverse the result
	reverse(res.begin(), res.end());

	return res;
}

// Driver program
int main()
{
	int inputNum = 282, base = 16;
	string res;
	cout << "Equivalent of " << inputNum << " in base "
		<< base << " is " << fromDeci(res, base, inputNum)
		<< endl;

	return 0;
}

// The code is contributed by Gautam goel (gautamgoel962)
