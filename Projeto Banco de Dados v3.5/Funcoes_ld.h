//Defini��o de Dados
struct ld_no{   //struct de um n� de uma lista dinamica
    char rg[13];    //id da struct
    char nome[51];
    char telefone[11];
    char idade[4];
};
//Defini��o de Dados

//Vari�veis Globais
struct ld_no *ld_lista;
int ld_tamanho = 4;
int ld_posicao = 0;
//Vari�veis Globais

//Fun��es Globais
void ld_adicionar(int posicao, char dado[]);
int ld_quantidade();
int ld_IndiceValido(int indice);
void ld_excluir(int indice);
void ld_ExpandirLista();
void ld_finalizar();
//Fun��es Globais
