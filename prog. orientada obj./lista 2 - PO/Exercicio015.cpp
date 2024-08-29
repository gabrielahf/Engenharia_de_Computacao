#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int l, c; 

    cin >> l;

    cin >> c;

    int matriz[10][10]; 

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
 
            cin >> matriz[i][j];

            
            if (matriz[i][j] < 0)
            {
                matriz[i][j] = abs(matriz[i][j]);
            }
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
