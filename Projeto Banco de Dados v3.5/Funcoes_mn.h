//Vari�veis Globais
char mn_opcoes[7][43] = {"Inserir Registro\t      |","Remover Registro\t      |","Buscar Registro por RG       |","Listar Todos os Registros    |","Listar Reverso\t\t      |","Documentacao\t\t      |","Sair do Programa\t      |"};
int mn_sair = 0;
int mn_pos = 1;
char MiniDecisao;
int MiniPos = 1;
int MiniSair = 0;
//Vari�veis Globais

//Menu
void documentacao();
void resolucao();
void enter(int posicao);    //fun��o local de decis�o
void inicios();             //fun��o local de inicios poss�veis
void menu_principal();      //fun��o local de capta��o de teclas
void MiniEnter(int posicao);
void MiniInicios(int posicao);
void MiniCaptura();
//Menu
