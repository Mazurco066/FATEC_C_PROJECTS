#define esc 27
#include <stdio.h>
#include <stdlib.h>

//menu
int pos = 1;
int sair = 0;
//menu

//fila
int fila[5];
int inicio = 0;
int fim = 0;
int vazia = 1;
//fila

void adicionar(int num){

    if(vazia==1)
    {
        fila[fim] = num;
        fim++;
        if(fim == 5)
            fim = 0;
        vazia = 0;
    }
    else
    {
        if(inicio == fim)
        {
            printf("\n Fila cheia!\n\n ");
            system("pause");
        }
        else
        {
            fila[fim] = num;
            fim++;
            if(fim == 5)
                fim = 0;
        }
    }
}

int retirar(){

    int valorParaRetornar = -1;

    if(vazia == 1)
    {
        printf("\n Fila vazia!\n\n ");
    }
    else
    {
        valorParaRetornar = fila[inicio];
        inicio++;
        if(inicio == 5)
            inicio = 0;
        if(inicio == fim)
            vazia = 1;
    }

    return valorParaRetornar;
}

void imprimir(){

    int i;
    int a = 0;
    i = inicio;
    if(vazia == 0)
    {
        while(a==0)
        {
            printf("%d - ",fila[i]);
            i++;
            if(i==5)
                i=0;
            if(i==fim)
                a=1;
        }
        printf("\n\n ");
    }
}

int main(){

    //funções menu
    void enter(int posicao_m);
    void inicios();
    void menu_principal();
    //funções menu

    inicios();

    do{
        menu_principal();
    }while (sair != 1);

    printf("\n\n ");

    system("pause");
    return 0;
}

void enter(int posicao_m){

    if (posicao_m == 1){

            int n;

            printf("\n Digite um numero -> ");
            scanf("%d", &n);
            adicionar(n);
    }
    else if (posicao_m == 2){

            int n;

            n = retirar();
            if(n != -1)
               printf("\n Retirado o numero %d da fila\n\n ", n);
            system("pause");
    }
    else if (posicao_m == 3){

            printf("\n\n ");
            imprimir();
            system("pause");
    }
    else{
        sair = 1;
    }
}

void inicios(){

    if(pos == 1){
        system("cls");
        printf("\t\tMenu");
        printf("\n -> Adicionar a fila");
        printf("\n    Ir para proximo da fila");
        printf("\n    Imprimir");
        printf("\n    Sair");
    }
    else if(pos == 2){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a fila");
        printf("\n -> Ir para proximo da fila");
        printf("\n    Imprimir");
        printf("\n    Sair");
    }
    else if(pos == 3){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a fila");
        printf("\n    Ir para proximo da fila");
        printf("\n -> Imprimir");
        printf("\n    Sair");
    }
    else if(pos == 4){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a fila");
        printf("\n    Ir para proximo da fila");
        printf("\n    Imprimir");
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
            pos = 4;
        }
    }
    else if (ch==80){   //abaixo
        pos++;
        if(pos > 4){
            pos = 1;
        }
    }

    //impressão
    inicios();
}
