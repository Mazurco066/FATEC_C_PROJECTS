#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5
#define esc 27

//menu
int sair = 0;
int pos = 1;
//menu

int fila[TAMANHO];
int inicio = 0;
int fim = 0;

void adicionar(int numero){

    if(fim==TAMANHO)
    {
        printf("\n A fila esta cheia!\n\n ");
        system("pause");
    }
    else
    {
        fila[fim] = numero;
        fim++;
    }
}

int retirar(){

    int valorParaRetorno = -1;

    if(inicio == fim)
    {
        printf("\n Fila vazia!\n\n ");
    }
    else
    {
        valorParaRetorno = fila[inicio];
        inicio++;
    }
    return valorParaRetorno;
}

void enter(int posicao_m){

    int numero;

    if (posicao_m == 1){

        printf("\n Digite o numero: ");
        scanf("%d",&numero);
        adicionar(numero);
    }
    else if (posicao_m == 2){
        numero = retirar();
            if(numero != -1)
                printf("\n Retirado o numero %d da fila\n\n ", numero);
        system("pause");
    }
    else{
        sair = 1;
    }
}

void inicios(){

    if (pos == 1){
        system("cls");
        printf("\t\tMenu");
        printf("\n -> Adicionar a fila");
        printf("\n    Ir para proximo da fila");
        printf("\n    Sair");

    }
    else if (pos == 2){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a fila");
        printf("\n -> Ir para proximo da fila");
        printf("\n    Sair");
    }
    else if (pos == 3){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a fila");
        printf("\n    Ir para proximo da fila");
        printf("\n -> Sair");
    }
}

void menu_principal(){

    int ch;
    ch=getch();
    if (ch== esc){  //esc
        sair = 1;
    }
    else if (ch==13){   // enter
        enter(pos);
    }
    if (ch==72){    //acima
        pos--;
        if (pos < 1){
            pos = 3;
        }
    }
    else if (ch==80){   //abaixo
        pos++;
        if(pos > 3){
            pos = 1;
        }
    }

    //impressão
    inicios();
}

int main(){

    inicios();

    do{
        menu_principal();
    }while (sair != 1);

    printf("\n\n ");
    system("pause");
    return 0;
}
