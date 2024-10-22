#include <stdio.h>

int main() {
    // Definindo o array x com os valores fornecidos
    int x[] = {1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143, 
               161, 179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 
               449, 479, 511, 543, 577, 611, 647, 683, 721, 759, 799, 839, 
               881, 923, 967, 1011, 1057, 1103, 1151, 1199, 1249, 1299};
    
    int t, index;  // Variáveis para a quantidade de testes e o índice
    
    // Lendo o número de testes
    scanf("%d", &t);

    // Loop para cada teste
    for (int i = 0; i < t; i++) {
        scanf("%d", &index);  // Lendo o índice
        printf("%d\n", x[index - 1]);  // Imprimindo o valor correspondente
    }

    return 0;
}