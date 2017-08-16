/*********************************************************************************************************************/

//Defini��o de Dados
extern struct ab_no{   //struct de um n� de uma arvore binaria
    struct ab_no *esquerda;
    char rg[13];    //id da struct
    int posicao;
    struct ab_no *direita;
};
//Defini��o de Dados

/*********************************************************************************************************************/

//Vari�veis globais
extern struct ab_no *inicio;
extern struct ab_no *novo;
extern struct ab_no *anterior;
extern struct ab_no *auxiliar;
extern char ab_ultimo_movimento;
//Vari�veis Globais

/*********************************************************************************************************************/

//Fun��es Globais
struct ab_no *ab_novo_no(char dado[], int posicao){  //ok - aloca uma nova posi��o na memoria para a lista

    struct ab_no *n;
    n = malloc(sizeof(struct ab_no));   //aloca memoria do tamanho da struct lista
    if(!n)                              //lista n�o foi alocada
    {
        printf("Nao consegui alocar memoria!\n");   //mensagem de erro
        exit(-1);                                   //sa�da do programa
    }

    n->esquerda = 0;    //setando posi��o esquerda para inativa
    n->direita = 0;     //setando posi��o direita para inativa
    strcpy(n->rg, dado);
    n->posicao = posicao;     //setando o indice para o dado informado

    return n;
}

/*********************************************************************************************************************/

void ab_adicionar(struct ab_no *aux, struct ab_no *add){   //ok - parametros = posi��o inicial e a nova posi��o alocada

    if(inicio == 0){    //primeira vez inserindo um elemento

        inicio = add;   //inicia a lista
    }
    else{

        if (aux->esquerda == 0 && atoi(add->rg) < atoi(aux->rg)){ //verifica se posi��o esquerda esta vazia

            aux->esquerda = add;    //se sim posi��o esquerda recebe nova aloca��o
            return;
        }
        if (aux->direita == 0 && atoi(add->rg) > atoi(aux->rg)){  //verifica se posi��o direita esta vazia

            aux->direita = add;     //se sim posi��o direita recebe nova aloca��o
            return;
        }

        if (atoi(add->rg) < atoi(aux->rg)){    //verifica se dado vai pra esquerda
            aux = aux->esquerda;       //variavel auxiliar recebe proxima posi��o para refazer as verifca��es
            ab_adicionar(aux, add);       //chamada recursiva da fun��o adicionar ate achar uma posi��o vazia
        }

        if (atoi(add->rg) > atoi(aux->rg)){    //verifica se dado vai pra direita
            aux = aux->direita;
            ab_adicionar(aux, add);
        }
    }
}

/*********************************************************************************************************************/

struct ab_no *ab_busca(struct ab_no *aux, char dado[]){ //ok - busca um registro na arvore bin�ria

    if (inicio == 0){   //quando n�o ha nada cadastrado

        printf("\n N�o ha elementos na lista para se buscar!\n\n ");    //mensagem de erro
        system("pause");
        return 0;  //sa�da da fun��o
    }
    else{

        if (strcmp(dado, aux->rg) == 0){ //dado encontrado

            return aux;   //retornando dado
        }
        else{

            if (aux->esquerda != 0 && atoi(dado) < atoi(aux->rg)){    //caso n�o seja o dado procurar para esquerda

                anterior = aux; //v�ri�vel para uso na fun��o excluir
                ab_ultimo_movimento = 'E'; //vari�vel para uso na fun��o excluir
                aux = aux->esquerda;    //setando posi��o para esquerda
                return ab_busca(aux, dado);    //chamada recursiva da fun��o
            }

            if (aux->direita != 0 && atoi(dado) > atoi(aux->rg)){ //caso n�o seja o dado procurar para direita

                anterior = aux; //vari�vel para uso na fun��o excluir
                ab_ultimo_movimento = 'D'; //vari�vel para uso na fun��o excluir
                aux = aux->direita; //setando posi��o para esquerda
                return ab_busca(aux, dado);    //chamada recursiva da fun��o
            }

        }

        return 0;   //caso n�o encontre o dado

    }
}

/*********************************************************************************************************************/

void ab_excluir(char dado[]){  //ok - Libera da mem�ria uma posi��o da estrutura

    auxiliar = ab_busca(inicio, dado); //vari�vel equivalente ao dado encontrado
    if(auxiliar == 0){  //caso o dado n�o seja encontrado

        printf("\n[+]Impossivel excluir, registro nao existe!\n\n"); //mensagem de erro!
        system("pause");
    }
    else{   //caso encontre corretamente

        if(auxiliar == inicio)  //caso de dado ser igual ao dado inicial da arvore bin�ria
        {
            inicio = 0; //desabilitando inicio da arvore
            if(auxiliar->esquerda != 0){    //inserindo novamente ramifica��o esquerda

                ab_adicionar(inicio, auxiliar->esquerda);  //chamada recursiva da fun��o
            }
            if(auxiliar->direita != 0){ //inserindo novamente ramifica��o direita

                ab_adicionar(inicio, auxiliar->direita);   //chamada recursiva da fun��o
            }
            free(auxiliar); //desalocando a posi��o equivalente ao dado encontrado

            printf("\n[+]Excluido com Sucesso!\n\n");    //mensagem de sucesso!
            system("pause");
        }
        else
        {
            if(ab_ultimo_movimento == 'D'){    //verifica��o do lado da ramifica��o equivalente

                anterior->direita = 0;  //desabilitando posi��o para reinser��o de dados
            }
            else{

                anterior->esquerda = 0;     //desabilitando posi��o para reinser��o de dados
            }

            if(auxiliar->esquerda != 0){    //caso posi��o esquerda tenha dados

                ab_adicionar(inicio, auxiliar->esquerda);  //reinserindo posi��o esquerda
            }
            if(auxiliar->direita != 0){ //caso posi��o direita tenha dados

                ab_adicionar(inicio, auxiliar->direita);   //reinserindo ramifica��o direita
            }
            free(auxiliar); //desalocando a posi��o equivalente ao dado encontrado

            printf("\n[+]Excluido com Sucesso!\n\n");    //mensagem de sucesso!
            system("pause");
        }
    }
}

/*********************************************************************************************************************/

void ab_finalizar(struct ab_no *aux){  //ok - desaloca todas posi��es da arvore bin�ria

    if(aux != 0){

            if (aux->esquerda != 0){

                ab_finalizar(aux->esquerda);
            }

            if (aux->direita != 0){

                ab_finalizar(aux->direita);
            }

            free(aux);
    }

}
//Fun��es Globais

/*********************************************************************************************************************/
