#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    float num;
    printf("Digite um numero: ")
    scanf(" %f", &num);
    printf("A raiz quadrada de %.2f é %.2f", num, sqrt(num));
    system("pause");
}