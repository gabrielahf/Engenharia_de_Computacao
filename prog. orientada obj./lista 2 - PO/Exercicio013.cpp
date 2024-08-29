#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int piramide = (n + 1) / 2;

    for (int i = 1; i <= piramide; i++)
    {
    
        for (int j = 1; j < i; j++)
        {
            cout << "    ";
        }

        for (int j = i; j <= n - i + 1; j++)
        {
            cout << setw(3) << j << " ";
        }

        cout << endl;
    }

    return 0;
}
