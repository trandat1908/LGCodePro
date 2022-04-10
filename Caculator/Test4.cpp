#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h> 

using namespace std;

int N;//the number of test cases 
int B;//number system 
char S[110];//first integer 
char D[110];//second integer 
void InputData() {
    cin >> B >> S >> D;
}

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())

        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);

        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);

        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }
    if (carry)

        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
    return str;
}
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)

    {
        int carry = 0;

        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)

        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;


            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;

        }
        if (carry > 0)

            result[i_n1 + i_n2] += carry;


        i_n1++;

    }

    int i = result.size() - 1;

    while (i >= 0 && result[i] == 0)

        i--;
    if (i == -1)

        return "0";
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}

int val(char c)
{
    if (c >= '0' && c <= '9')

        return (int)c - '0';

    else

        return (int)c - 'A' + 10;

}
string toDeci(string str, int base)
{
    int len = str.size();
    string power = "1";
    string resDeci = "";
    string baseStr = to_string(base);
    for (int i = len - 1; i >= 0; i--)

    {

        if (val(str[i]) >= base)

        {

            printf("Invalid Number");

            return NULL;

        }

        int num2 = val(str[i]);

        string num1 = to_string(num2);

        string num = multiply(num1, power);
        resDeci = findSum(num, resDeci);
        power = multiply(power, baseStr);

    }
    return resDeci;
}

string longDivision(string number, int divisor)
{
    string ans;
    int idx = 0;

    int temp = number[idx] - '0';

    while (temp < divisor)

        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx) {

        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0)

        return "0";
    return ans;
}

bool isSmaller(string str1, string str2)

{
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
string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
string fromDeci(int base, string inputNum)
{
    string res = "";
    string baseStr = to_string(base);
    while (inputNum != "0") {
        string div = longDivision(inputNum, base);
        string mul = multiply(div, baseStr);
        string sub = findDiff(inputNum, mul);
        int i_value = stoi(sub);
        res += reVal(i_value);
        inputNum = longDivision(inputNum, base);
    }
    reverse(res.begin(), res.end());
    return res;
}


string Solve(char* S, char* D, int& N, int& M)
{
    char R[110][1000] = { 0 };
    vector<char> vS(S, S + N);
    vector<char> vD(D, D + M);
    bool negative = false;
    if ((vS[0] == '-' && vD[0] != '-') || (vS[0] != '-' && vD[0] == '-')) negative = true;
    for (auto it = vD.begin(); it != vD.end(); it++)
    {
        if (*it == '0' || *it == '-')
        {
            vD.erase(it);
            it--;
        }
        else
            break;
    }
    for (auto it = vS.begin(); it != vS.end(); it++)
    {
        if (*it == '0' || *it == '-')
        {
            vS.erase(it);
            it--;
        }
        else
            break;
    }
    if (vS[0] == '0' || vD[0] == '0'||vS[0] == '\0'||vD[0] == '\0')
    {
        return "0";
    }
    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            R[i][j] = '0';
        }

    }
    string q = "";
    string p = "";
    for (int i = 0; i < vS.size(); i++)
    {
        q += vS[i];
    }
    for (int j = 0; j < vD.size(); j++)
    {
        p += vD[j];
    }
    if (B != 10)
    {
        q = toDeci(q, B);
        p = toDeci(p, B);
        vS.clear();
        vD.clear();


        for (int i = 0; i < q.size(); i++)
        {
            vS.push_back(q[i]);
        }
        for (int j = 0; j < q.size(); j++)
        {
            vD.push_back(p[j]);
        }
    }
    
    string res = multiply(q, p);
    if (B != 10)
    {
        res = fromDeci(B, res);
    }
    if (negative)
    {
        res = "-" + res;
    }
    return res;
}

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int main() {
    int i;
    freopen("in.txt", "r", stdin);
    scanf("%d", &N); 

    for (i = 0; i < N; i++) {
        InputData();
        int N = strlen(S);
        int M = strlen(D);
        string res = Solve(S, D, N, M);
        cout << res << endl;
    }
    return 0;
}

