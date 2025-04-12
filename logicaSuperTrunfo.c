#include <stdio.h>

int main() {
    // Informações carta 1
    char carta1[4] = ""; // Código da carta (ex: A01) + '\0'
    char estado1[30];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // Informações carta 2
    char carta2[4] = "";
    char estado2[30];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // Solicitar os dados da carta 1
    printf("=== DADOS DA CARTA 1 ===\n");
    printf("Digite o código da carta (ex: C03): ");
    scanf("%3s", carta1);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado1);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Calcular densidade populacional e PIB per capita
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (float)(pib1 * 1000000000) / populacao1;

    // Solicitar os dados da carta 2
    printf("\n=== DADOS DA CARTA 2 ===\n");
    printf("Digite o código da carta (ex: F01): ");
    scanf("%3s", carta2);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado2);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Calcular densidade populacional e PIB per capita para a carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (float)(pib2 * 1000000000) / populacao2;

    // Menu de opções (apenas uma execução)
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - Comparar por População\n");
    printf("2 - Comparar por Área\n");
    printf("3 - Comparar por PIB\n");
    printf("4 - Comparar por Pontos Turísticos\n");
    printf("5 - Comparar por Densidade Demográfica\n");
    printf("6 - Comparar por PIB per Capita\n");
    printf("Escolha uma opção (1-6): ");
    
    int opcao;
    scanf("%d", &opcao);

    printf("\n=== RESULTADO ===\n");
    
    switch(opcao) {
        case 1: // População
            printf("Atributo: POPULAÇÃO\n");
            printf("%s (%s): %lu habitantes\n", cidade1, estado1, populacao1);
            printf("%s (%s): %lu habitantes\n", cidade2, estado2, populacao2);
            
            if(populacao1 > populacao2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(populacao2 > populacao1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: ÁREA\n");
            printf("%s (%s): %.2f km²\n", cidade1, estado1, area1);
            printf("%s (%s): %.2f km²\n", cidade2, estado2, area2);
            
            if(area1 > area2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(area2 > area1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s (%s): R$ %.2f bilhões\n", cidade1, estado1, pib1);
            printf("%s (%s): R$ %.2f bilhões\n", cidade2, estado2, pib2);
            
            if(pib1 > pib2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(pib2 > pib1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: PONTOS TURÍSTICOS\n");
            printf("%s (%s): %d pontos\n", cidade1, estado1, pontosTuristicos1);
            printf("%s (%s): %d pontos\n", cidade2, estado2, pontosTuristicos2);
            
            if(pontosTuristicos1 > pontosTuristicos2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(pontosTuristicos2 > pontosTuristicos1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 5: // Densidade Demográfica
            printf("Atributo: DENSIDADE DEMOGRÁFICA\n");
            printf("%s (%s): %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
            printf("%s (%s): %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
            
            if(densidadePopulacional1 < densidadePopulacional2) {
                printf("Vencedor: %s (menor densidade)\n", cidade1);
            } else if(densidadePopulacional2 < densidadePopulacional1) {
                printf("Vencedor: %s (menor densidade)\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 6: // PIB per Capita
            printf("Atributo: PIB PER CAPITA\n");
            printf("%s (%s): R$ %.2f\n", cidade1, estado1, pibPerCapita1);
            printf("%s (%s): R$ %.2f\n", cidade2, estado2, pibPerCapita2);
            
            if(pibPerCapita1 > pibPerCapita2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(pibPerCapita2 > pibPerCapita1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida! Por favor, execute o programa novamente e escolha uma opção de 1 a 6.\n");
    }

    return 0;
}