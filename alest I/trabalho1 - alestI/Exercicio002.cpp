#include <iostream>

using namespace std;

void bubbleSort(int *dados, int tam) 
{
    int trocou;
    do 
    {
        trocou = 0;
        for (int i = 0; i < tam - 1; ++i) 
        {
            if (dados[i] < dados[i + 1]) 
            {
                int aux = dados[i];
                dados[i] = dados[i + 1];
                dados[i + 1] = aux;
                trocou = 1;
            }
        }

        for (int i = 0; i < tam; i++) 
        {
            cout << dados[i];
            if (i != tam - 1)
                cout << " "; 
            
        }
        cout << "\n";

    } while (trocou);
}

int main() 
{
    int tam;
    cin >> tam;
    int dados[tam];

    for (int j = 0; j < tam; j++) 
    {
        cin >> dados[j];
    }
    
    cout << "\n";
    bubbleSort(dados, tam);
   
    return 0;
}
