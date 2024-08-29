#include <stdio.h>

int op_seculo(double ano)
{
    int sec = (ano - 1) / 100 + 1;
    return sec;
}

int main()
{
    double ano;

    printf("  ");
    scanf("%lf", &ano);

    int sec = op_seculo(ano);

    printf("\n %d \n", sec);

    return 0;
}
