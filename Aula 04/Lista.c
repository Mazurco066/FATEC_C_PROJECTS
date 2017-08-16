#define esc 27
#include <stdio.h>
#include <stdlib.h>

//Variáveis Globais
int pos = 1;
int Tamanho = 10;
int posicao = 0;
int *lista;
int sair = 0;
//Variáveis Globais

//Funções Globais
void Adicionar(int valor){

    if (posicao == Tamanho){
        printf("\n Lista Cheia! \n\n ");
        system("pause");
    }
    else{
        printf("\n Numero -> ");
        scanf("%d", &lista[valor]);
        posicao++;
    }
}

int QuantidadeElementos(){

    return posicao;
}

int IndiceValido(int indice){

    if(indice > 0 && indice < posicao){

        return 1;
    }
    else{

        return 0;
    }
}

void BuscaIndice(int indice){

    int i;
    int cont = 0;

    for (i = 0; i < posicao; i++){

        if(indice == i){
            printf("\n\t\tIndice Encontrado");
            printf("\n Indice = %d \n Valor = %d", indice, lista[i]);
            printf("\n\n ");
            system("pause");
        }
        else{
            cont++;
        }

    }

    if(cont == posicao){
        printf("\n Indice nao encontrado! \n\n ");
        system("pause");
    }
}

void BuscaValor(int Valor){

    int i;
    int cont = 0;

    for (i = 0; i < posicao; i++){

        if(Valor == lista[i]){
            printf("\n\t\tNumero Encontrado");
            printf("\n Indice = %d \n Valor = %d", i, lista[i]);
            printf("\n\n ");
            system("pause");
        }
        else{
            cont++;
        }


    }

    if(cont == posicao){
        printf("\n Numero nao encontrado! \n\n ");
        system("pause");
    }
}

void Excluir(int indice){

    int i;

    for (i = indice; i < posicao; i++){

        lista[i] = lista[i + 1];
    }
    posicao--;
}

void Ordenar(){

    int i, j;
    int maior;

    for (i = 0; i< posicao; i++){

        for (j = i; j< posicao; j++){

            if (lista[j] < lista[i]){

                maior = lista[i];
                lista[i] = lista[j];
                lista[j] = maior;
            }
        }
    }

    printf("\n Lista Ordenada Com Sucesso! \n\n ");
    system("pause");
}

void Expandir(int backup[], int expansao){

    int i;

    lista = malloc((Tamanho + expansao) * sizeof(int));
    if (!lista){
        printf("\n Erro na Alocacao de Memoria!\n\n ");
        system("pause");
        exit(-1);
    }

    for(i = 0; i < posicao; i++){
        lista[i] = backup[i];
    }

    Tamanho += expansao;


}

void ExpandirLista(){

    int i;
    int *l2;
    int Tam;

    Tam = Tamanho + (Tamanho/2);

    l2 = malloc(Tam* sizeof(int));
    if (!l2){
        printf("\n Nao foi possivel alocar a memoria!\n\n ");
        system("pause");
        exit(-1);
    }

    for (i = 0; i < posicao; i++){
        l2[i] = lista[i];
    }

    free(lista);
    lista = l2;

    Tamanho = Tam;

    printf("\n Lista expandida com sucesso!\n\n ");
}

void Menu(){

    int escolha;

    system("cls");
    printf("\t\tMenu");
    printf("\n 1 - Adicionar a Lista");
    printf("\n 2 - Quantidade Elementos da Lista");
    printf("\n 3 - Buscar Indice");
    printf("\n 4 - Buscar Valor");
    printf("\n 5 - Excluir da Lista");
    printf("\n 6 - Ordenar Lista");
    printf("\n 7 - Expandir Lista");
    printf("\n 8 - Sair\n Escolha -> ");
    scanf("%d", &escolha);

    switch (escolha){

        case 1:{
            Adicionar(posicao);
            break;
        }

        case 2:{
            printf("\n A lista tem %d Elementos! \n\n ", QuantidadeElementos());
            system("pause");
            break;
        }

        case 3:{
            int pos;
            printf("\n Buscar Indice Numero -> ");
            scanf("%d", &pos);
            BuscaIndice(pos);
            break;
        }

        case 4:{
            int pos;
            printf("\n Buscar Numero na Lista -> ");
            scanf("%d", &pos);
            BuscaValor(pos);
            break;
        }

        case 5:{
            int pos;
            printf("\n Excluir Indice na Lista -> ");
            scanf("%d", &pos);
            if (IndiceValido(pos) == 1){
                Excluir(pos);
            }
            else{
                printf("\n Indice Especificado nao Existe!\n\n ");
                system("pause");
            }
            break;
        }

        case 6:{
            Ordenar();
            break;
        }

        case 7:{
            //Expandir(lista, pos); // Funciona porem gasta mais recursos computacionais
            ExpandirLista();
            system("pause");
            break;
        }

        case 8:{
            sair = 1;
            break;
        }

        default:{
            printf("\n Opcao Invalida! \n\n ");
            system("pause");
            break;
        }
    }
}
//Funções Globais

int main(){

    //Funções para uso no menu principal <>
    void enter(int posicao);
    void inicios();
    void menu_principal();
    //Funções para uso no menu principal </>

    inicios();

    lista = malloc(10 * sizeof(int));
    if(!lista){
        printf("\n Erro de Alocacao!\n\n ");
        exit(-1);
    }

    /* Menu Antigo
    do{
        Menu();
    }while (sair != 1);
    */

    do{
        menu_principal();
    }while (sair != 1);

    printf("\n Saiu com Sucesso!\n\n ");

    free(lista);

    system("pause");
    return 0;
}

void enter(int posicao_m){

    if (posicao_m == 1){
        Adicionar(posicao);
    }
    else if(posicao_m == 2){
        printf("\n A lista tem %d Elementos! \n\n ", QuantidadeElementos());
        system("pause");
    }
    else if(posicao_m == 3){
        int posi;
        printf("\n Buscar Indice Numero -> ");
        scanf("%d", &posi);
        BuscaIndice(posi);
    }
    else if(posicao_m == 4){
        int posi;
        printf("\n Buscar Numero na Lista -> ");
        scanf("%d", &posi);
        BuscaValor(posi);
    }
    else if(posicao_m == 5){
        int posi;
        printf("\n Excluir Indice na Lista -> ");
        scanf("%d", &posi);
        if (IndiceValido(posi) == 1){
            Excluir(posi);
        }
        else{
            printf("\n Indice Especificado nao Existe!\n\n ");
            system("pause");
        }
    }
    else if(posicao_m == 6){
        Ordenar();
    }
    else if(posicao_m == 7){
        ExpandirLista();
        system("pause");
    }
    else if(posicao_m == 8){
        sair = 1;
    }

}

void inicios(){

    if(pos == 1){
        system("cls");
        printf("\t\tMenu");
        printf("\n -> Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 2){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n -> Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 3){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n -> Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 4){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n -> Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 5){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n -> Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 6){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n -> Ordenar Lista");
        printf("\n    Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 7){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n -> Expandir Lista");
        printf("\n    Sair");
    }
    else if(pos == 8){
        system("cls");
        printf("\t\tMenu");
        printf("\n    Adicionar a Lista");
        printf("\n    Quantidade Elementos da Lista");
        printf("\n    Buscar Indice");
        printf("\n    Buscar Valor");
        printf("\n    Excluir da Lista");
        printf("\n    Ordenar Lista");
        printf("\n    Expandir Lista");
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
            pos = 8;
        }
    }
    else if (ch==80){   //abaixo
        pos++;
        if(pos > 8){
            pos = 1;
        }
    }

    //impressão
    inicios();
}
