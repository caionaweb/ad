#include <stdio.h>
#include <stdlib.h>
/**************************************
    Fun��o: calcula a velocidade M�dia
    Autor: Edkallenn
    Data: 31/03/2016
    Observa��es:
 **************************************/
float velocidadeMedia(float distancia, float tempo);     //prot�tipo
main(){
    float distancia, tempo;
    printf("  ==== Programa que calcula a Velocidade Media de um percurso ====\n");
    printf("Digite a distancia em Km: ");
    scanf("%f", &distancia);
    printf("Digite o tempo em horas: ");
    scanf("%f", &tempo);
    printf("\nA velocidade media = %g km/h", velocidadeMedia(distancia, tempo));
    getch();
}
float velocidadeMedia(float distancia, float tempo){
    return distancia/tempo;
}
