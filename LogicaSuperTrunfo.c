#include <stdio.h>

int main() {
    // Informações carta 1
    char carta1[4] = ""; // Código da carta (ex: A01) + '\0'
    char estado1[30];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // Informações carta 2
    char carta2[4] = "";
    char estado2[30];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // Solicitar os dados da carta 1
    printf("Digite os dados da carta 1\n");
    printf("--------------------------------\n");
    printf("Digite o código da carta (ex: C03; F01): ");
    scanf("%3s", carta1);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado1);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a população: ");
    scanf("%d", &populacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Calcular densidade populacional e PIB per capita
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (float)(pib1 * 1000000000) / populacao1;

    printf("A Densidade populacional é: %.2f habitantes por km²\n", densidadePopulacional1);
    printf("O PIB per capita é: R$ %.2f\n", pibPerCapita1);

    // Solicitar os dados da carta 2
    printf("\nDigite os dados da carta 2\n");
    printf("--------------------------------\n");
    printf("Digite o código da carta (ex: C03; F01): ");
    scanf("%3s", carta2);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado2);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: ");
    scanf("%d", &populacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Calcular densidade populacional e PIB per capita para a carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (float)(pib2 * 1000000000) / populacao2;

    printf("A Densidade populacional é: %.2f habitantes por km²\n", densidadePopulacional2);
    printf("O PIB per capita é: R$ %.2f\n", pibPerCapita2);

    // Menu interativo para comparação de cartas de 1 à 6
    int opcao;
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade Populacional\n");
        printf("5 - PIB per capita\n");
        printf("6 - Pontos Turísticos\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

        switch(opcao) {
            case 1: // População
                printf("Atributo: População\n");
                printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
                printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);
                
                if(populacao1 > populacao2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if(populacao2 > populacao1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 2: // Área
                printf("Atributo: Área\n");
                printf("Carta 1 - %s (%s): %.2f km²\n", cidade1, estado1, area1);
                printf("Carta 2 - %s (%s): %.2f km²\n", cidade2, estado2, area2);
                
                if(area1 > area2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if(area2 > area1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 3: // PIB
                printf("Atributo: PIB\n");
                printf("Carta 1 - %s (%s): R$ %.2f bilhões\n", cidade1, estado1, pib1);
                printf("Carta 2 - %s (%s): R$ %.2f bilhões\n", cidade2, estado2, pib2);
                
                if(pib1 > pib2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if(pib2 > pib1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 4: // Densidade Populacional (MENOR valor vence)
                printf("Atributo: Densidade Populacional\n");
                printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
                printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
                
                if(densidadePopulacional1 < densidadePopulacional2) {
                    printf("Resultado: Carta 1 (%s) venceu! (menor densidade)\n", cidade1);
                } else if(densidadePopulacional2 < densidadePopulacional1) {
                    printf("Resultado: Carta 2 (%s) venceu! (menor densidade)\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 5: // PIB per capita
                printf("Atributo: PIB per capita\n");
                printf("Carta 1 - %s (%s): R$ %.2f\n", cidade1, estado1, pibPerCapita1);
                printf("Carta 2 - %s (%s): R$ %.2f\n", cidade2, estado2, pibPerCapita2);
                
                if(pibPerCapita1 > pibPerCapita2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if(pibPerCapita2 > pibPerCapita1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 6: // Pontos Turísticos
                printf("Atributo: Pontos Turísticos\n");
                printf("Carta 1 - %s (%s): %d pontos\n", cidade1, estado1, pontosTuristicos1);
                printf("Carta 2 - %s (%s): %d pontos\n", cidade2, estado2, pontosTuristicos2);
                
                if(pontosTuristicos1 > pontosTuristicos2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if(pontosTuristicos2 > pontosTuristicos1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}