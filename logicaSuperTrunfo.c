#include <stdio.h>

int main() {
    // Informações carta 1
    char carta[4] = ""; // Código da carta (ex: A01) + '\0'
    char estado[30];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;

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
    float superPoder2;

 /*     Exemplos de dados
   Digite os dados da carta 1
--------------------------------
Digite o código da carta (ex: C03; F01): C07
Digite o estado: Minas Gerais
Digite a cidade: Belo Horizonte
Digite a população: 2530701
Digite a área (em km²): 331.40
Digite o PIB (em bilhões de reais): 93.5
Digite o número de pontos turísticos: 120

Digite os dados da carta 2
--------------------------------
Digite o código da carta (ex: C03; F01): D12
Digite o estado: Bahia
Digite a cidade: Salvador
Digite a população: 2900319
Digite a área (em km²): 693.80
Digite o PIB (em bilhões de reais): 68.4
Digite o número de pontos turísticos: 180
*/

    // Solicitar os dados da carta 1
    printf("Digite os dados da carta 1\n");
    printf("--------------------------------\n");
    printf("Digite o código da carta (ex: C03; F01): ");
    scanf("%3s", carta); // Lê apenas 3 caracteres

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado); // %[^\n] lê até a quebra de linha

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade);

    printf("Digite a população: ");
    scanf("%lu", &populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos);

    // Calcular densidade populacional e PIB per capita
    densidadePopulacional = (float)populacao / area;
    pibPerCapita = (float)(pib * 1000000000) / populacao;

    // Calcular Super Poder para carta 1
    // Inverso da densidade populacional (quanto menor a densidade, maior o poder)
    float inversoDensidade = 1.0 / densidadePopulacional;
    superPoder = (float)populacao + area + pib + pontosTuristicos + pibPerCapita + inversoDensidade;

    printf("A Densidade populacional é: %.2f habitantes por km²\n", densidadePopulacional);
    printf("O PIB per capita é: R$ %.2f\n", pibPerCapita); 
    printf("O Super Poder é: %.2f\n", superPoder);

    /* informações necessárias para teste, referente a carta 1.
        
    Código da carta: A01
    Estado: Paraná
    Cidade: Curitiba
    População: 1774000 de habitantes
    Área: 432 KM²
    PIB: R$98 bilhões
    Pontos turísticos: 70 pontos
    */

    // Solicitar os dados da carta 2
    printf("\nDigite os dados da carta 2\n");
    printf("--------------------------------\n");
    printf("Digite o código da carta (ex: C03; F01): ");
    scanf("%3s", carta2);

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado2);

    printf("Digite a cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: "); //Digite somente os numeros sem pontos ou virgulas
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

    // Calcular Super Poder para carta 2
    float inversoDensidade2 = 1.0 / densidadePopulacional2;
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + inversoDensidade2;

    printf("A Densidade populacional é: %.2f habitantes por km²\n", densidadePopulacional2);
    printf("O PIB per capita é: R$ %.2f\n", pibPerCapita2);
    printf("O Super Poder é: %.2f\n", superPoder2);

    /* informações necessárias para teste, referente a carta 2.
        
    Código da carta: B03
    Estado: São Paulo
    Cidade: São Paulo
    População: 12396372 de habitantes
    Área: 1521,11 km²
    PIB: R$829,3 bilhões 
    Pontos turísticos: 760 pontos
    */

    // Exibir os dados da cartas
    printf("\n####  DADOS DA CARTA 1  ####\n");
    printf("--------------------------------\n");
    printf("🃏  O código da carta é: %s\n", carta);
    printf("📍 O estado é: %s\n", estado);
    printf("🏙️  A cidade é: %s\n", cidade);
    printf("👤 A população é: %lu de habitantes\n", populacao);
    printf("📏 A área é: %.2f km²\n", area);
    printf("📈 O PIB é: R$ %.2f bilhões\n", pib);
    printf("⛲ A quantidade de pontos turísticos é: %d pontos\n", pontosTuristicos);
    printf("📊 Densidade populacional: %.2f hab/km²\n", densidadePopulacional);
    printf("💰 PIB per capita: R$ %.2f\n", pibPerCapita);
    printf("💪 Super Poder: %.2f\n", superPoder);

    // Exibir os dados da carta 2
    printf("\n####  DADOS DA CARTA 2  ####\n");
    printf("--------------------------------\n");
    printf("🃏  O código da carta é: %s\n", carta2);
    printf("📍 O estado é: %s\n", estado2);
    printf("🏙️  A cidade é: %s\n", cidade2);
    printf("👤 A população é: %lu de habitantes\n", populacao2);
    printf("📏 A área é: %.2f km²\n", area2);
    printf("📈 O PIB é: R$ %.2f bilhões\n", pib2);
    printf("⛲ A quantidade de pontos turísticos é: %d pontos\n", pontosTuristicos2);
    printf("📊 Densidade populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("💰 PIB per capita: R$ %.2f\n", pibPerCapita2);
    printf("💪 Super Poder: %.2f\n", superPoder2);

    /* Comparação das cartas com PRINTF de acordo com o desafio anterior
    printf("\n####  COMPARAÇÃO DAS CARTAS  ####\n");
    printf("0 - perdeu\n1 - venceu\n");
    printf("--------------------------------\n");
    printf("População: Carta 1 %s (%d)\n", (populacao > populacao2) ? "venceu" : "perdeu", (populacao > populacao2));
    printf("Área: Carta 1 %s (%d)\n", (area > area2) ? "venceu" : "perdeu", (area > area2));
    printf("PIB: Carta 1 %s (%d)\n", (pib > pib2) ? "venceu" : "perdeu", (pib > pib2));
    printf("Pontos Turísticos: Carta 1 %s (%d)\n", (pontosTuristicos > pontosTuristicos2) ? "venceu" : "perdeu", (pontosTuristicos > pontosTuristicos2));
    printf("Densidade Populacional: Carta 1 %s (%d)\n", (densidadePopulacional < densidadePopulacional2) ? "venceu" : "perdeu", (densidadePopulacional < densidadePopulacional2));
    printf("PIB per Capita: Carta 1 %s (%d)\n", (pibPerCapita > pibPerCapita2) ? "venceu" : "perdeu", (pibPerCapita > pibPerCapita2));
    printf("Super Poder: Carta 1 %s (%d)\n", (superPoder > superPoder2) ? "venceu" : "perdeu", (superPoder > superPoder2));
*/
    // Comparação das cartas com IF e ELSE de acordo com o desafio atual
    printf("\n####  COMPARAÇÃO DAS CARTAS  ####\n");
    printf("--------------------------------\n");
    printf("População: ");
    if (populacao > populacao2) {
        printf("Carta 1 venceu\n");
    } else if (populacao < populacao2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n"); // coloquei empate, pois pode haver empate dependendo dos dados.
    }
    printf("Área: ");
    if (area > area2) {
        printf("Carta 1 venceu\n");
    } else if (area < area2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }
    printf("PIB: ");
    if (pib > pib2) {
        printf("Carta 1 venceu\n");
    } else if (pib < pib2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }
    printf("Pontos Turísticos: ");
    if (pontosTuristicos > pontosTuristicos2) {
        printf("Carta 1 venceu\n");
    } else if (pontosTuristicos < pontosTuristicos2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }
    printf("Densidade Populacional: ");
    if (densidadePopulacional < densidadePopulacional2) {
        printf("Carta 1 venceu\n");
    } else if (densidadePopulacional > densidadePopulacional2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }
    printf("PIB per Capita: ");
    if (pibPerCapita > pibPerCapita2) {
        printf("Carta 1 venceu\n");
    } else if (pibPerCapita < pibPerCapita2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }
    printf("Super Poder: ");
    if (superPoder > superPoder2) {
        printf("Carta 1 venceu\n");
    } else if (superPoder < superPoder2) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate entre as cartas\n");
    }

    return 0;
}