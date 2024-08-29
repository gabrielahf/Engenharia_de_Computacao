#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vetor;
    int valor;
    
    while (true)
    {
        cin >> valor;
        if(valor < 0)break; 
        vetor.push_back(valor);
    }
    cout << endl;
    for (int i = 0; i < vetor.size(); i++){ cout << vetor[i] << endl; }

    cout << endl;
    for(vector<int>::const_iterator it = vetor.begin(); it != vetor.end(); it++){ cout << *it << endl;}
   return 0; 
}