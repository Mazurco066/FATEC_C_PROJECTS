#include <stdio.h>
#include <stdlib.h>
#define tamanho 5

int vetor[5];
int bilada = 0;
int sair = 0;

int main(){

    void menu();

    do{
    menu();
    }while(sair != 1);

    printf("\n Ate mais ver!. . . . \n\n ");

    system("pause");
    return 0;
}

void menu(){

    int escolha;
    void push(int pos);
    void pop(int pos);

    printf("\n 1 - Push\n 2 - Pop\n 3 - Exit\n\n Escolha --> ");
    do{
    scanf("%d", &escolha);
    }while(escolha < 1 || escolha > 3);

    if (escolha == 1){

        push(bilada);
    }
    else if(escolha == 2){

        pop(bilada);
    }
    else if(escolha == 3){

        sair = 1;
    }


}

void push(int pos){

    if (pos == tamanho){

        printf("\nPilha ja esta cheia!!");

    }
    else{
        printf("\n Numero -->");
        scanf("%d",&vetor[pos]);
        bilada++;
    }
}

void pop(int pos){

    if (pos == 0){

            printf("\nPilha esta VAZIA!!");
            return -1;

    }
    else{

        bilada--;
    }
}
