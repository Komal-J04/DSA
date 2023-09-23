#include <iostream>
using namespace std;

int aPowB(int a, int b, int ans)
{
    if (b == 0)
        return ans;

    ans *= a;

    return aPowB(a, --b, ans);
}

int aPowB2(int a, int b) // a^b = (a^(b/2))^2 = ((a^(b/4))^2)^2
{
    if (b == 0)
        return 1; // a^0 = 1

    if (b == 1)
        return a; // a^1 = a

    int ans = aPowB2(a, b / 2); // we need a^(b/2)

    if (b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}

int main()
{
    int a, b;
    cout << "Enter 2 numbers" << endl;
    cin >> a >> b;

    int ans = 1;

    // Method 1
    cout << aPowB(a, b, ans) << endl;

    // Method 2
    cout << aPowB2(a, b) << endl;
}