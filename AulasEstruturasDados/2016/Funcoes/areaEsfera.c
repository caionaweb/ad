#include <stdio.h>
#include <stdlib.h>
/*
    Fun��o: calcula a �rea da esfera
    Autor: Edkallenn
    Data: 31/03/2016
    Observa��es:
*/
float areaEsfera(float raio);     //prot�tipo
main(){
    float raio;
    printf("  ==== Programa que calcula a area da esfera ====\n");
    printf("Digite o raio: ");
    scanf("%f", &raio);
    printf("\nA area da esfera de raio = %.3f = %f", raio, areaEsfera(raio));
    getch();
}

float areaEsfera(float raio){
    return (4 * 3.141592 * raio * raio);
}
