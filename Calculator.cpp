1. Sum
// C++ program to find sum of two large numbers.
#include<bits/stdc++.h>
using namespace std;
 
// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
 
// Driver code
int main()
{
    string str1 = "12";
    string str2 = "198111";
    cout << findSum(str1, str2);
    return 0;
}

2. Sub

// C++ program to find difference of two large numbers.
#include <bits/stdc++.h>
using namespace std;

// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
	// Calculate lengths of both string
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;

	for (int i = 0; i < n1; i++)
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;

	return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
	// Before proceeding further, make sure str1
	// is not smaller
	if (isSmaller(str1, str2))
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	// Run loop till small string length
	// and subtract digit of str1 to str2
	for (int i = 0; i < n2; i++) {
		// Do school mathematics, compute difference of
		// current digits

		int sub
			= ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less than zero
		// we add then we add 10 into sub and
		// take carry as 1 for calculating next step
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

// Driver code
int main()
{
	string str1 = "978";
	string str2 = "12977";

	// Function call
	cout << findDiff(str1, str2) << endl;

	string s1 = "100";
	string s2 = "1000000";

	// Function call
	cout << findDiff(s1, s2);

	return 0;
}
3. Multi

// C++ program to multiply two numbers represented
// as strings.
#include<bits/stdc++.h>
using namespace std;

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0 || len2 == 0)
	return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(len1 + len2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;
	
	// Go from right to left in num1
	for (int i=len1-1; i>=0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;
		
		// Go from right to left in num2			
		for (int j=len2-1; j>=0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum/10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
	return "0";

	// generate the result string
	string s = "";
	
	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

// Driver code
int main()
{
	string str1 = "1235421415454545454545454544";
	string str2 = "1714546546546545454544548544544545";
	
	if((str1.at(0) == '-' || str2.at(0) == '-') &&
		(str1.at(0) != '-' || str2.at(0) != '-' ))
		cout<<"-";


	if(str1.at(0) == '-')
		str1 = str1.substr(1);

	if(str2.at(0) == '-')
		str2 = str2.substr(1);

	cout << multiply(str1, str2);
	return 0;
}
4. Div
// C++ program to implement division with large
// number
#include <bits/stdc++.h>
using namespace std;

// A function to perform division of large numbers
string longDivision(string number, int divisor)
{
	// As result can be very large store it in string
	string ans;

	// Find prefix of number that is larger
	// than divisor.
	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < divisor)
		temp = temp * 10 + (number[++idx] - '0');

	// Repeatedly divide divisor with temp. After
	// every division, update temp to include one
	// more digit.
	while (number.size() > idx) {
		// Store result in answer i.e. temp / divisor
		ans += (temp / divisor) + '0';

		// Take next digit of number
		temp = (temp % divisor) * 10 + number[++idx] - '0';
	}

	// If divisor is greater than number
	if (ans.length() == 0)
		return "0";

	// else return ans
	return ans;
}

// Driver program to test longDivision()
int main()
{
	string number = "1248163264128256512";
	int divisor = 125;
	cout << longDivision(number, divisor);
	return 0;
}
