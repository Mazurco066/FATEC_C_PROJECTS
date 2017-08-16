#include <stdio.h>
#include <stdlib.h>
#define esc 27

char opcoes[4][25] = {"Novo Elemento","Excluir Elemento","Buscar Elementos","Sair"};

//definindo tipo de dado
struct lista{
    struct lista *esquerda;     //ponteiro para posição do lado esquerdo
    int dado;                   //dado da struct (indice)
    struct lista *direita;      //ponteiro para posição do lado direito
};
//definindo tipo de dado

//Variáveis globais
struct lista *inicio;
struct lista *novo;
struct lista *anterior;
struct lista *auxiliar;
char ultimo_movimento = ' ';

//Variáveis do menu
int sair = 0;       //Variável de saída do sistema
int pos = 1;        //Variável de impressão do menu
//Variáveis do menu
//Variáveis globais

//Funções Globais
struct lista *novo_no(int dado){  //ok aloca uma nova posição na memoria para a lista

    struct lista *n;
    n = malloc(sizeof(struct lista));   //aloca memoria do tamanho da struct lista
    if(!n)                              //lista não foi alocada
    {
        printf("Nao consegui alocar memoria!\n");   //mensagem de erro
        exit(-1);                                   //saída do programa
    }

    n->esquerda = 0;    //setando posição esquerda para inativa
    n->direita = 0;     //setando posição direita para inativa
    n->dado = dado;     //setando o indice para o dado informado

    return n;
}

void adicionar(struct lista *aux, struct lista *add){   //ok parametros = posição inicial e a nova posição alocada

    if(inicio == 0){    //primeira vez inserindo um elemento

        inicio = add;   //inicia a lista
    }
    else{

        if (aux->esquerda == 0 && add->dado < aux->dado){ //verifica se posição esquerda esta vazia

            aux->esquerda = add;    //se sim posição esquerda recebe nova alocação
            return;
        }
        if (aux->direita == 0 && add->dado > aux->dado){  //verifica se posição direita esta vazia

            aux->direita = add;     //se sim posição direita recebe nova alocação
            return;
        }

        if (add->dado < aux->dado){    //verifica se dado vai pra esquerda
            aux = aux->esquerda;       //variavel auxiliar recebe proxima posição para refazer as verifcações
            adicionar(aux, add);       //chamada recursiva da função adicionar ate achar uma posição vazia
        }

        if (add->dado > aux->dado){    //verifica se dado vai pra direita
            aux = aux->direita;
            adicionar(aux, add);
        }
    }
}

struct lista *busca(struct lista *aux, int dado){ //ok parametros = posicao inicial e o dado a ser buscado

    if (inicio == 0){   //quando não ha nada cadastrado

        printf("\n Não ha elementos na lista para se buscar!\n\n ");    //mensagem de erro
        system("pause");
        return 0;  //saída da função
    }
    else{

        if (dado == aux->dado){ //dado encontrado

            return aux;   //retornando dado
        }
        else{

            if (aux->esquerda != 0 && dado < aux->dado){    //caso não seja o dado procurar para esquerda

                anterior = aux; //váriável para uso na função excluir
                ultimo_movimento = 'E'; //variável para uso na função excluir
                aux = aux->esquerda;    //setando posição para esquerda
                return busca(aux, dado);    //chamada recursiva da função
            }

            if (aux->direita != 0 && dado > aux->dado){ //caso não seja o dado procurar para direita

                anterior = aux; //variável para uso na função excluir
                ultimo_movimento = 'D'; //variável para uso na função excluir
                aux = aux->direita; //setando posição para esquerda
                return busca(aux, dado);    //chamada recursiva da função
            }

        }

        return 0;   //caso não encontre o dado

    }
}

void excluir(int dado){  //ok parametros = dado a ser encontrado

    auxiliar = busca(inicio, dado); //variável equivalente ao dado encontrado
    if(auxiliar == 0){  //caso o dado não seja encontrado

        printf("\n Impossivel excluir, registro nao existe!\n\n "); //mensagem de erro!
    }
    else{   //caso encontre corretamente

        if(auxiliar == inicio)  //caso de dado ser igual ao dado inicial da arvore binária
        {
            inicio = 0; //desabilitando inicio da arvore
            if(auxiliar->esquerda != 0){    //inserindo novamente ramificação esquerda

                adicionar(inicio, auxiliar->esquerda);  //chamada recursiva da função
            }
            if(auxiliar->direita != 0){ //inserindo novamente ramificação direita

                adicionar(inicio, auxiliar->direita);   //chamada recursiva da função
            }
            free(auxiliar); //desalocando a posição equivalente ao dado encontrado

            printf("\n Excluido com Sucesso!\n\n ");    //mensagem de sucesso!
        }
        else
        {
            if(ultimo_movimento == 'D'){    //verificação do lado da ramificação equivalente

                anterior->direita = 0;  //desabilitando posição para reinserção de dados
            }
            else{

                anterior->esquerda = 0;     //desabilitando posição para reinserção de dados
            }

            if(auxiliar->esquerda != 0){    //caso posição esquerda tenha dados

                adicionar(inicio, auxiliar->esquerda);  //reinserindo posição esquerda
            }
            if(auxiliar->direita != 0){ //caso posição direita tenha dados

                adicionar(inicio, auxiliar->direita);   //reinserindo ramificação direita
            }
            free(auxiliar); //desalocando a posição equivalente ao dado encontrado

            printf("\n Excluido com Sucesso!\n\n ");    //mensagem de sucesso!
        }
    }
}

void finalizar(struct lista *aux){  //ok parametros = posição inicial da desalocação de memória

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
//Funções Globais

int main(){

    inicio = 0;

    //Menu
    void enter(int posicao);    //função local de decisão
    void inicios();             //função local de inicios possíveis
    void menu_principal();      //função local de captação de teclas
    //Menu

    inicios();  //impressão do menu do sistema

    do{
        menu_principal();   //loop principal do programa
    }while (sair != 1);


    finalizar(inicio);  //liberação da memória alocada anteriormente
    printf("\n\n ");

    system("pause");
    return 0;
}

void enter(int posicao){    //menu ao pressionar a tecla enter / decisão

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

    //impressão
    inicios();
}
