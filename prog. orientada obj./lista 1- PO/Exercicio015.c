#include <stdio.h>

void leitura(int num[], int tam) {
    for (int i = 0; i < 30; i++) {
        scanf("%d", &num[i]);
    }
}

int soma(int num[], int tam) {
    int op = 0;
    
    for (int i = 1; i < 29; i++) {
        if (num[i] + num[i + 1] == num[i + 2]) {
            op++;
        }
    }
    
    return op;
}

int main() {
    int num[30];
    int tam;
    
    leitura(num, tam);
    
    int total_op = soma(num, tam);
    
    printf("%d\n", total_op);
    
    return 0;
}
