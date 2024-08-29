#include <stdio.h>

int imprimirPadrao(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

int main() {
    
   int n;

    printf("    ");
    scanf("%d", &n);
    
    imprimirPadrao(n);
    

    return 0;
}
