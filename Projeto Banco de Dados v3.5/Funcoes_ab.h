//Defini��o de Dados
struct ab_no{   //struct de um n� de uma arvore binaria
    struct ab_no *esquerda;
    char rg[13];    //id da struct
    int posicao;
    struct ab_no *direita;
};
//Defini��o de Dados

//Vari�veis globais
struct ab_no *inicio;
struct ab_no *novo;
struct ab_no *anterior;
struct ab_no *auxiliar;
char ab_ultimo_movimento = ' ';
//Vari�veis Globais

//Fun��es Globais
struct ab_no *ab_novo_no(char dado[], int posicao);
void ab_adicionar(struct ab_no *aux, struct ab_no *add);
struct ab_no *ab_busca(struct ab_no *aux, int dado);
void ab_excluir(char dado[]);
void ab_finalizar(struct ab_no *aux);
//Fun��es Globais
