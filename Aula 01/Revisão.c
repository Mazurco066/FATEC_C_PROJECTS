#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[10] = {0};
    int i;

    for (i = 0; i < 10; i++){

        printf("vetor %d = %d \n", i + 1, vetor[i]);
    }

    system("pause");
    return 0;
}
