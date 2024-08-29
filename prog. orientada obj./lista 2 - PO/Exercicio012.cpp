#include <iostream>

using namespace std;

int main(){

    int size = 0, shortN, linha = 0;
    while(size <= 0 || size > 10){
        cin >> size;
    }
    
    int ** m = new int*[size];

    
   for (int i = 0; i < size; i++) {
        m[i] = new int[size];
   }

     for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            cin >> m[i][k];
        }
   }
     
    shortN = m[0][0];

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
           if(m[i][k] < shortN){
            linha = i;
           }
        }
   }

    cout << linha << endl;

   delete m;
   return 0;

}