#include <stdio.h>
#include <stdlib.h>
#define esc 27

//definindo tipo de dado
struct lista{
    int dado;
    struct lista *proximo;
};
//definindo tipo de dado

//Variáveis globais
struct lista *inicio;
struct lista *aux;
struct lista *novo;
struct lista *anterior;

int sair = 0;
int pos  = 1;
//Variáveis globais

//Funções Globais
struct lista *novo_no(int dado){    //ok

    struct lista *n;
    n = malloc(sizeof(struct lista));
    if(!n)
    {
        printf("\n não foi possivel alocar memoria!\n\n ");
        system("pause");
        exit(-1);
    }

    n->proximo = 0;
    n->dado = dado;

    return n;
}

void adicionar_no_inicio(){ //ok

    novo->proximo = inicio;
    inicio = novo;

    printf("\n Adicionado com Sucesso caso INICIO!\n\n ");
    system("pause");
}

void adicionar_no_meio(){   //ok

    novo->proximo = aux;
    anterior->proximo = novo;

    printf("\n Adicionado com Sucesso caso MEIO!\n\n ");
    system("pause");
}

void adicionar_no_fim(){    //ok

    aux->proximo = novo;

    printf("\n Adicionado com Sucesso caso FIM!\n\n ");
    system("pause");
}

void adicionar_no(int dado){

    novo = novo_no(dado);

    if(inicio == 0){
        inicio = novo;
    }
    else{
        // decisao para chamadas de funções de inserção de dados
        if(inicio->dado >= dado){

            adicionar_no_inicio();
            }
            else{

            aux = inicio;
            anterior = inicio;

            while(aux->proximo != 0 && aux->dado < dado){

                anterior = aux;
                aux = aux->proximo;
            }
            if(aux->proximo == 0 && dado > aux->dado){

                adicionar_no_fim();
            }
            else{

                adicionar_no_meio();
            }
        }
    }
    //decisao para chamadas de funções de inserção de dados
}

void excluir_no_inicio(){   //ok

    if (inicio->proximo ==0){

        free(inicio);
        inicio=0;
    }
    else{

        aux = inicio->proximo;
        free(inicio);
        inicio=aux;
    }


    printf("\n Excluido com Sucesso caso INICIO! \n\n ");
    system("pause");
}

void excluir_no_meio(){ //ok

    anterior->proximo = aux->proximo;
    free(aux);

    printf("\n Excluido com Sucesso caso MEIO! \n\n ");
    system("pause");
}

void excluir_no_fim(){  //ok

    free(aux);
    aux = anterior;
    aux->proximo = 0;

    printf("\n Excluido com Sucesso caso FIM! \n\n ");
    system("pause");
}

void excluir_no(int dado){  //ok

    if (inicio == 0){

        printf("\n Nao ha nada para excluir!\n\n ");
        system("pause");
        return;
    }

    if(inicio->dado >= dado){

            excluir_no_inicio();
            }
            else{

            aux = inicio;
            anterior = inicio;

            while(aux->proximo != 0 && aux->dado < dado){

                anterior = aux;
                aux = aux->proximo;
                if (aux->dado == dado){
                    break;
                }
            }
            if(aux->proximo == 0 && dado == aux->dado){

                excluir_no_fim();
            }
            else{

                excluir_no_meio();
            }
        }
}

void listar(){  //ok

    printf("\n\n    ");

    if(inicio != 0){

        aux = inicio;
        while(aux->proximo != 0){

            printf("%d -> ", aux->dado);
            aux = aux->proximo;
        }
        printf("%d\n", aux->dado);
    }
    else{
        printf("Lista vazia!\n");
    }

    printf("\n\n ");
}

void finalizar(){   //ok

    if(inicio != 0)
    {
        finalizar_elemento(inicio);
        inicio = 0;
    }
}

void finalizar_elemento(struct lista *elemento){    //ok

    if(elemento->proximo != 0)
        finalizar_elemento(elemento->proximo);
    free(elemento);
}
//Funções Globais

int main(){

    inicio = 0;

    //Menu
    void enter(int posicao);
    void inicios();
    void menu_principal();
    //Menu

    inicios();

    do{
        menu_principal();
    }while (sair != 1);


    finalizar();
    printf("\n\n ");

    system("pause");
    return 0;
}

void enter(int posicao){    //menu ao pressionar a tecla enter

    if (posicao == 1){

            int num;

            if (inicio == 0){

                printf("\n Entre com um numero -> ");
                scanf("%d", &num);

                adicionar_no(num);

                printf("\n Lista iniciada . . . .\n\n ");
                system("pause");
            }
            else{

            printf("\n Entre com um numero -> ");
            scanf("%d", &num);

            adicionar_no(num);
            }
    }
    else if(posicao == 2){

            int num;

            printf("\n Entre com um numero para excluir-> ");
            scanf("%d", &num);

            excluir_no(num);

    }
    else if(posicao == 3){

            listar();
            system("pause");
    }
    else if(posicao == 4){
        sair = 1;
    }

}

void inicios(){ //possibilidades do menu

    if(pos == 1){
        system("cls");
        printf("\t\t Menu Principal");
        printf("\n -> Novo Elemento");
        printf("\n    Excluir Elemento");
        printf("\n    Listar Elementos");
        printf("\n    Sair");
    }
    else if(pos == 2){
        system("cls");
        printf("\t\t Menu Principal");
        printf("\n    Novo Elemento");
        printf("\n -> Excluir Elemento");
        printf("\n    Listar Elementos");
        printf("\n    Sair");
    }
    else if(pos == 3){
        system("cls");
        printf("\t\t Menu Principal");
        printf("\n    Novo Elemento");
        printf("\n    Excluir Elemento");
        printf("\n -> Listar Elementos");
        printf("\n    Sair");
    }
    else if(pos == 4){
        system("cls");
        printf("\t\t Menu Principal");
        printf("\n    Novo Elemento");
        printf("\n    Excluir Elemento");
        printf("\n    Listar Elementos");
        printf("\n -> Sair");
    }
}

void menu_principal(){  //captura de teclas

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
