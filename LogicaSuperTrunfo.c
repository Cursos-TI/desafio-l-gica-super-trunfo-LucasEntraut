#include <stdio.h>

/*
 * SUPER TRUNFO - COMPARAÇÃO DE CARTAS
 * Regras:
 * - Compara duas cartas com base em um atributo pré-definido no código.
 * - Densidade populacional: menor valor vence.
 * - Demais atributos: maior valor vence.
 */

int main() {
    // Informações carta 1
    char carta[4] = ""; // Código da carta (ex: A01) + '\0'
    char estado[30];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;

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
    scanf("%3s", carta);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade);

    printf("Digite a população: ");
    scanf("%d", &populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos);

    // Calcular densidade populacional e PIB per capita
    densidadePopulacional = (float)populacao / area;
    pibPerCapita = (float)(pib * 1000000000) / populacao;

    printf("A Densidade populacional é: %.2f habitantes por km²\n", densidadePopulacional);
    printf("O PIB per capita é: R$ %.2f\n", pibPerCapita);

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

    /*
     * COMPARAÇÃO DE ATRIBUTOS
     * Escolha o atributo para comparação modificando o valor abaixo:
     * 1 = População
     * 2 = Área
     * 3 = PIB
     * 4 = Densidade Populacional
     * 5 = PIB per capita
     * 6 = Pontos Turísticos
     */
    const int ATRIBUTO_COMPARACAO = 3; // Atributo PIB escolhido para comparação, conforme a lista acima

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    switch(ATRIBUTO_COMPARACAO) {
        case 1: // População
            printf("Atributo: População\n");
            printf("Carta 1 - %s (%s): %d\n", cidade, estado, populacao);
            printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);
            
            if(populacao > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade); 
            } else if(populacao2 > populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("Carta 1 - %s (%s): %.2f km²\n", cidade, estado, area);
            printf("Carta 2 - %s (%s): %.2f km²\n", cidade2, estado2, area2);
            
            if(area > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if(area2 > area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1 - %s (%s): R$ %.2f bilhões\n", cidade, estado, pib);
            printf("Carta 2 - %s (%s): R$ %.2f bilhões\n", cidade2, estado2, pib2);
            
            if(pib > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if(pib2 > pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Densidade Populacional (MENOR valor vence)
            printf("Atributo: Densidade Populacional\n");
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade, estado, densidadePopulacional);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
            
            if(densidadePopulacional < densidadePopulacional2) {
                printf("Resultado: Carta 1 (%s) venceu! (menor densidade)\n", cidade);
            } else if(densidadePopulacional2 < densidadePopulacional) {
                printf("Resultado: Carta 2 (%s) venceu! (menor densidade)\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // PIB per capita
            printf("Atributo: PIB per capita\n");
            printf("Carta 1 - %s (%s): R$ %.2f\n", cidade, estado, pibPerCapita);
            printf("Carta 2 - %s (%s): R$ %.2f\n", cidade2, estado2, pibPerCapita2);
            
            if(pibPerCapita > pibPerCapita2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if(pibPerCapita2 > pibPerCapita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 - %s (%s): %d pontos\n", cidade, estado, pontosTuristicos);
            printf("Carta 2 - %s (%s): %d pontos\n", cidade2, estado2, pontosTuristicos2);
            
            if(pontosTuristicos > pontosTuristicos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if(pontosTuristicos2 > pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        return 0; // Finaliza o programa
    }

    return 0;
}