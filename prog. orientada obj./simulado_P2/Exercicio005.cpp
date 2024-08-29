#include <iostream>
using namespace std;

int a;     // &a = 0xf180
int b;     // &b = 0xf184
int *ptr;  // &c = 0xf188
int v[4];  // &v[0] = 0xf190 / &v[1] = 0xf194 / &v[2] = 0xf198 / &v[3] = 0xf19c

int main() {
  a=4; b=4;
  ptr = &v[3];
  cout << ptr << endl; // IMPRIMIR -- 0xf19c
  *ptr = b; // ptr[3] = 4
  ptr = ptr-1; // ptr[ptr[3] -1] = ptr[2] 
  *ptr = 9; // ptr[2] = 9
  ptr[a-5] = 12; // ptr[4 - 5] = ptr[1] = 12
  v[0] = *(ptr+1); // v[0] = ptr[ptr[1] + 1] = ptr[2]
  cout << *ptr << endl; // (ptr[2]) IMPRIMIR -- 9
  ptr = &v[0]; // ptr = 0xf190
  ptr[1] = 3; // estava armazenando 12, agora passa a armazenaro valor 3
  for (int i=0; i<4; i++) {
      cout << *ptr << endl;
      /*
      ptr[0] = v[0] = 4 ?
      ptr[1] = v[1] = 3
      ptr[2] = v[2] = 9
      ptr[3] = v[3] = 4
      */
      ptr++;
  }
  return 0;
}

/*SAIDA

Memória:                         Saída do programa:
========                         ==================
0xf180 | a    | 4                0xf19c
0xf184 | b    | 4                9
0xf188 | ptr  | 0xf190           4 
0xf190 | v[0] | 4                3
0xf194 | v[1] | 3                9
0xf198 | v[2] | 9                4
0xf19c | v[3] | 4

*/