#include <stdio.h>
#include <stdlib.h>
#define esc 27

char opcoes[4][25] = {"Novo Elemento","Excluir Elemento","Buscar Elementos","Sair"};

//definindo tipo de dado
struct lista{
    struct lista *esquerda;     //ponteiro para posi��o do lado esquerdo
    int dado;                   //dado da struct (indice)
    struct lista *direita;      //ponteiro para posi��o do lado direito
};
//definindo tipo de dado

//Vari�veis globais
struct lista *inicio;
struct lista *novo;
struct lista *anterior;
struct lista *auxiliar;
char ultimo_movimento = ' ';

//Vari�veis do menu
int sair = 0;       //Vari�vel de sa�da do sistema
int pos = 1;        //Vari�vel de impress�o do menu
//Vari�veis do menu
//Vari�veis globais

//Fun��es Globais
struct lista *novo_no(int dado){  //ok aloca uma nova posi��o na memoria para a lista

    struct lista *n;
    n = malloc(sizeof(struct lista));   //aloca memoria do tamanho da struct lista
    if(!n)                              //lista n�o foi alocada
    {
        printf("Nao consegui alocar memoria!\n");   //mensagem de erro
        exit(-1);                                   //sa�da do programa
    }

    n->esquerda = 0;    //setando posi��o esquerda para inativa
    n->direita = 0;     //setando posi��o direita para inativa
    n->dado = dado;     //setando o indice para o dado informado

    return n;
}

void adicionar(struct lista *aux, struct lista *add){   //ok parametros = posi��o inicial e a nova posi��o alocada

    if(inicio == 0){    //primeira vez inserindo um elemento

        inicio = add;   //inicia a lista
    }
    else{

        if (aux->esquerda == 0 && add->dado < aux->dado){ //verifica se posi��o esquerda esta vazia

            aux->esquerda = add;    //se sim posi��o esquerda recebe nova aloca��o
            return;
        }
        if (aux->direita == 0 && add->dado > aux->dado){  //verifica se posi��o direita esta vazia

            aux->direita = add;     //se sim posi��o direita recebe nova aloca��o
            return;
        }

        if (add->dado < aux->dado){    //verifica se dado vai pra esquerda
            aux = aux->esquerda;       //variavel auxiliar recebe proxima posi��o para refazer as verifca��es
            adicionar(aux, add);       //chamada recursiva da fun��o adicionar ate achar uma posi��o vazia
        }

        if (add->dado > aux->dado){    //verifica se dado vai pra direita
            aux = aux->direita;
            adicionar(aux, add);
        }
    }
}

struct lista *busca(struct lista *aux, int dado){ //ok parametros = posicao inicial e o dado a ser buscado

    if (inicio == 0){   //quando n�o ha nada cadastrado

        printf("\n N�o ha elementos na lista para se buscar!\n\n ");    //mensagem de erro
        system("pause");
        return 0;  //sa�da da fun��o
    }
    else{

        if (dado == aux->dado){ //dado encontrado

            return aux;   //retornando dado
        }
        else{

            if (aux->esquerda != 0 && dado < aux->dado){    //caso n�o seja o dado procurar para esquerda

                anterior = aux; //v�ri�vel para uso na fun��o excluir
                ultimo_movimento = 'E'; //vari�vel para uso na fun��o excluir
                aux = aux->esquerda;    //setando posi��o para esquerda
                return busca(aux, dado);    //chamada recursiva da fun��o
            }

            if (aux->direita != 0 && dado > aux->dado){ //caso n�o seja o dado procurar para direita

                anterior = aux; //vari�vel para uso na fun��o excluir
                ultimo_movimento = 'D'; //vari�vel para uso na fun��o excluir
                aux = aux->direita; //setando posi��o para esquerda
                return busca(aux, dado);    //chamada recursiva da fun��o
            }

        }

        return 0;   //caso n�o encontre o dado

    }
}

void excluir(int dado){  //ok parametros = dado a ser encontrado

    auxiliar = busca(inicio, dado); //vari�vel equivalente ao dado encontrado
    if(auxiliar == 0){  //caso o dado n�o seja encontrado

        printf("\n Impossivel excluir, registro nao existe!\n\n "); //mensagem de erro!
    }
    else{   //caso encontre corretamente

        if(auxiliar == inicio)  //caso de dado ser igual ao dado inicial da arvore bin�ria
        {
            inicio = 0; //desabilitando inicio da arvore
            if(auxiliar->esquerda != 0){    //inserindo novamente ramifica��o esquerda

                adicionar(inicio, auxiliar->esquerda);  //chamada recursiva da fun��o
            }
            if(auxiliar->direita != 0){ //inserindo novamente ramifica��o direita

                adicionar(inicio, auxiliar->direita);   //chamada recursiva da fun��o
            }
            free(auxiliar); //desalocando a posi��o equivalente ao dado encontrado

            printf("\n Excluido com Sucesso!\n\n ");    //mensagem de sucesso!
        }
        else
        {
            if(ultimo_movimento == 'D'){    //verifica��o do lado da ramifica��o equivalente

                anterior->direita = 0;  //desabilitando posi��o para reinser��o de dados
            }
            else{

                anterior->esquerda = 0;     //desabilitando posi��o para reinser��o de dados
            }

            if(auxiliar->esquerda != 0){    //caso posi��o esquerda tenha dados

                adicionar(inicio, auxiliar->esquerda);  //reinserindo posi��o esquerda
            }
            if(auxiliar->direita != 0){ //caso posi��o direita tenha dados

                adicionar(inicio, auxiliar->direita);   //reinserindo ramifica��o direita
            }
            free(auxiliar); //desalocando a posi��o equivalente ao dado encontrado

            printf("\n Excluido com Sucesso!\n\n ");    //mensagem de sucesso!
        }
    }
}

void finalizar(struct lista *aux){  //ok parametros = posi��o inicial da desaloca��o de mem�ria

    if(aux != 0){

            if (aux->esquerda != 0){

                finalizar(aux->esquerda);
            }

            if (aux->direita != 0){

                finalizar(aux->direita);
            }

            free(aux);
    }

}
//Fun��es Globais

int main(){

    inicio = 0;

    //Menu
    void enter(int posicao);    //fun��o local de decis�o
    void inicios();             //fun��o local de inicios poss�veis
    void menu_principal();      //fun��o local de capta��o de teclas
    //Menu

    inicios();  //impress�o do menu do sistema

    do{
        menu_principal();   //loop principal do programa
    }while (sair != 1);


    finalizar(inicio);  //libera��o da mem�ria alocada anteriormente
    printf("\n\n ");

    system("pause");
    return 0;
}

void enter(int posicao){    //menu ao pressionar a tecla enter / decis�o

    if (posicao == 1){

            int num;

            if (inicio == 0){

                printf("\n Entre com um numero -> ");
                scanf("%d", &num);

                adicionar(inicio, novo_no(num));

                printf("\n Lista iniciada . . . .\n\n ");
                system("pause");
            }
            else{

                printf("\n Entre com um numero -> ");
                scanf("%d", &num);

                adicionar(inicio, novo_no(num));
            }

    }
    else if(posicao == 2){

            int num;

            if (inicio == 0){

                printf("\n Nao ha nada para excluir!\n\n ");
                system("pause");
            }
            else{

                printf("\n Entre com um numero para exclusao -> ");
                scanf("%d", &num);

                if (busca(inicio, num) == 0){

                    printf("\n Dado nao encontrado!\n\n ");
                    system("pause");
                }
                else{

                    excluir(num);
                    system("pause");
                }
            }

    }
    else if(posicao == 3){

            int num;

            if (inicio == 0){

                printf("\n Nao ha nada para se buscar!\n\n ");
                system("pause");
            }
            else{

                printf("\n Entre com um numero para busca -> ");
                scanf("%d", &num);

                if (busca(inicio, num) == 0){

                    printf("\n Dado nao encontrado!\n\n ");
                    system("pause");
                }
                else{

                    printf("\n O dado %d foi encontrado!\n\n ", busca(inicio, num)->dado);
                    system("pause");
                }
            }

    }
    else if(posicao == 4){

        sair = 1;
    }

}

void inicios(){ //possibilidades do menu

    int i;

    system("cls");

    for (i = 1; i <=4; i++){

            if (pos == i){
                printf("-> %s \n", &opcoes[i - 1]);
            }
            else{
                printf("   %s \n", &opcoes[i - 1]);
            }

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

    //impress�o
    inicios();
}
