//Defini��o de dados
struct ldl_no{  //struct de um n� de uma lista duplamente ligada
    struct ldl_no *anterior;
    //char rg[13];    //id da struct
    char nome[51];
    int posicao;
    struct ldl_no *proximo;
};
//Defini��o de dados

//Vari�veis Globais
struct ldl_no *ldl_inicio;
struct ldl_no *ldl_aux;
struct ldl_no *ldl_novo;
struct ldl_no *ldl_antes;
//Vari�veis Globais

//Fun��es Globais
struct ldl_no *ldl_novo_no(char dado[], char dado2[], int pos);
int menorRG(char nome1[], char nome2[]);
void ldl_adicionar_no_inicio();
void ldl_adicionar_no_meio();
void ldl_adicionar_no_fim();
void ldl_adicionar_no(char dado[], char dado2[], int posi);
void ldl_excluir_no_inicio();
void ldl_excluir_no_meio();
void ldl_excluir_no_fim();
void ldl_excluir_no(char dado[], int Indice);
void ldl_listar();
void ldl_listar_reverso();
void ldl_finalizar();
void ldl_finalizar_elemento(struct lista *elemento);
//Fun��es Globais
