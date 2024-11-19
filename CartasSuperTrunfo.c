#include <stdio.h>
int main() {
    // Variáveis para cada atributo da cidade
    char codigo[4];
    char nome[50];
    int populacao;
    int area;
    float pib;
    int pontos_turisticos;

    // Cadastro das Cartas:
    for (int i = 'A'; i <= 'H'; i++) { // Loop para os estados de A a H
        for (int j = 1; j <= 4; j++) { // Loop para as cidades de 1 a 4
            // Gera o código da carta
            codigo[0] = i;
            codigo[1] = '0';
            codigo[2] = j + '0';
            codigo[3] = '\0';
            printf("\nCarta %s:\n", codigo);
            printf("Digite o nome da cidade: ");
            scanf("%s", nome);

            printf("Digite a população da cidade: ");
            scanf("%d", &populacao);

            printf("Digite a área da cidade: ");
            scanf("%d", &area);

            printf("Digite o PIB da cidade: ");
            scanf("%f", &pib);
            
            printf("Digite o número de pontos turísticos da cidade: ");
            scanf("%d", &pontos_turisticos);

            // Exibição dos Dados das Cartas:
            printf("\nDados da cidade %s:\n", codigo);
            printf("Nome: %s\n", nome);
            printf("População: %d\n", populacao);
            printf("Área: %d\n", area);
            printf("PIB: %.2f\n", pib);
            printf("Pontos turísticos: %d\n", pontos_turisticos);
        }
    }
    return 0;
}