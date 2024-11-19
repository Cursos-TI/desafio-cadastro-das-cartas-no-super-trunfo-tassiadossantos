#include <stdio.h>

int main() {
    // Variáveis para os atributos de cada cidade
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    printf("=== Cadastro de Cartas do Super Trunfo ===\n");

    // Cadastro das cartas
    for (estado = 'A'; estado <= 'H'; estado++) { // Loop para os estados de A a H
        for (int cidade = 1; cidade <= 4; cidade++) { // Loop para as cidades de 1 a 4
            // Gera o código da carta (ex.: A01, B02)
            codigo[0] = estado;
            codigo[1] = '0' + cidade / 10; // Primeiro dígito do número da cidade
            codigo[2] = '0' + cidade % 10; // Segundo dígito do número da cidade
            codigo[3] = '\0'; // Finaliza a string do código

            printf("\n=== Cadastro da Carta %s ===\n", codigo);

            // Entrada de dados
            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]s", nome); // Lê a string com espaços

            printf("Digite a população da cidade: ");
            scanf("%d", &populacao);

            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area);

            printf("Digite o PIB da cidade (em bilhões): ");
            scanf("%f", &pib);

            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &pontos_turisticos);

            // Exibição dos dados cadastrados
            printf("\n--- Dados da Carta %s ---\n", codigo);

            printf("Estado: %c\n", estado);

            printf("Código da Carta: %s\n", codigo);

            printf("Nome da Cidade: %s\n", nome);

            printf("População: %d habitantes\n", populacao);

            printf("Área: %.2f km²\n", area);

            printf("PIB: %.2f bilhões de reais\n", pib);

            printf("Pontos Turísticos: %d\n", pontos_turisticos);
            
        }
    }

    printf("\n=== Cadastro Finalizado ===\n");

    return 0;
}
