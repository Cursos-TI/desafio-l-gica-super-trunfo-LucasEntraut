#include <stdio.h>
#include <stdbool.h> //adiciona a biblioteca para usar o tipo bool/ mais eficiencia e com mais funcionalidades

// Função para exibir o menu e obter a escolha do usuário
int exibirMenu(bool opcoesDisponiveis[]) {
    int escolha;
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("Escolha um atributo para comparação:\n");
    
    if(opcoesDisponiveis[0]) printf("1 - População\n");
    if(opcoesDisponiveis[1]) printf("2 - Área\n");
    if(opcoesDisponiveis[2]) printf("3 - PIB\n");
    if(opcoesDisponiveis[3]) printf("4 - Densidade Populacional\n");
    if(opcoesDisponiveis[4]) printf("5 - PIB per capita\n");
    if(opcoesDisponiveis[5]) printf("6 - Pontos Turísticos\n");
    printf("0 - Cancelar\n");
    
    printf("Opção: ");
    scanf("%d", &escolha);
    
    // Verifica se a opção escolhida está disponível
    if(escolha > 0 && escolha <= 6 && !opcoesDisponiveis[escolha-1]) {
        printf("Opção inválida ou já selecionada. Tente novamente.\n");
        return -1; // Código de erro
    }
    
    return escolha;
}

// Função para comparar um único atributo
int compararAtributo(int atributo, float valor1, float valor2, bool menorVence) {
    if(menorVence) {
        if(valor1 < valor2) return 1;
        if(valor2 < valor1) return 2;
    } else {
        if(valor1 > valor2) return 1;
        if(valor2 > valor1) return 2;
    }
    return 0; // Empate
}

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

    // Mensagem de boas-vindas e instruções 
    printf("Bem-vindo ao Super Trunfo!\n");
    printf("\n");
    printf("Para que o jogo funcione corretamente, você deve inserir os dados de duas cartas.\n");
    printf("As cartas devem conter os seguintes atributos:\n");
    printf("================================\n");
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

    // Menu principal do jogo 
    int opcao;
    do {
        printf("\n=== SUPER TRUNFO - MENU PRINCIPAL ===\n");
        printf("1 - Comparar cartas usando dois atributos\n"); // Opção para comparar cartas
        printf("0 - Sair\n"); // Opção para sair do jogo
        printf("Opção: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            bool opcoesDisponiveis[6] = {true, true, true, true, true, true}; // Array para controlar quais opções estão disponíveis
            int atributos[2] = {0};
            int numAtributos = 0;
            
            // Selecionar dois atributos diferentes
            while(numAtributos < 2) {
                int escolha = exibirMenu(opcoesDisponiveis);
                
                if(escolha == 0 && numAtributos == 0) {
                    break; // Cancelar operação
                }
                else if(escolha == -1) {
                    continue; // Opção inválida
                }
                else if(escolha == 0 && numAtributos > 0) {
                    numAtributos--; // Desfazer última escolha
                    opcoesDisponiveis[atributos[numAtributos]-1] = true;
                    printf("Atributo %d desmarcado.\n", atributos[numAtributos]);
                    atributos[numAtributos] = 0;
                }
                else if(escolha >= 1 && escolha <= 6) {
                    atributos[numAtributos] = escolha;
                    opcoesDisponiveis[escolha-1] = false;
                    numAtributos++;
                    printf("Atributo %d selecionado.\n", escolha);
                }
            }
            
            if(numAtributos == 2) {
                printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
                printf("Carta 1: %s (%s)\n", cidade1, estado1);
                printf("Carta 2: %s (%s)\n", cidade2, estado2);
                
                // Arrays para armazenar valores e nomes dos atributos
                float valores1[2], valores2[2];
                char* nomesAtributos[2];
                bool menorVence[2] = {false, false};
                int resultados[2];
                float soma1 = 0, soma2 = 0;
                
                // Processar cada atributo selecionado
                for(int i = 0; i < 2; i++) {
                    switch(atributos[i]) {
                        case 1: // População
                            valores1[i] = populacao1;
                            valores2[i] = populacao2;
                            nomesAtributos[i] = "População";
                            menorVence[i] = false;
                            break;
                        case 2: // Área
                            valores1[i] = area1;
                            valores2[i] = area2;
                            nomesAtributos[i] = "Área";
                            menorVence[i] = false;
                            break;
                        case 3: // PIB
                            valores1[i] = pib1;
                            valores2[i] = pib2;
                            nomesAtributos[i] = "PIB";
                            menorVence[i] = false;
                            break;
                        case 4: // Densidade Populacional
                            valores1[i] = densidadePopulacional1;
                            valores2[i] = densidadePopulacional2;
                            nomesAtributos[i] = "Densidade Populacional";
                            menorVence[i] = true;
                            break;
                        case 5: // PIB per capita
                            valores1[i] = pibPerCapita1;
                            valores2[i] = pibPerCapita2;
                            nomesAtributos[i] = "PIB per capita";
                            menorVence[i] = false;
                            break;
                        case 6: // Pontos Turísticos
                            valores1[i] = pontosTuristicos1;
                            valores2[i] = pontosTuristicos2;
                            nomesAtributos[i] = "Pontos Turísticos";
                            menorVence[i] = false;
                            break;
                    }
                    
                    // Comparar o atributo atual
                    resultados[i] = compararAtributo(atributos[i], valores1[i], valores2[i], menorVence[i]);
                    
                    // Exibir resultados da comparação para este atributo
                    printf("\nAtributo %d: %s\n", i+1, nomesAtributos[i]);
                    printf("Carta 1: ");
                    if(atributos[i] == 1 || atributos[i] == 6) {
                        printf("%.0f\n", valores1[i]); // Inteiros sem casas decimais
                    } else {
                        printf("%.2f\n", valores1[i]); // Floats com 2 casas decimais
                    }
                    
                    printf("Carta 2: ");
                    if(atributos[i] == 1 || atributos[i] == 6) {
                        printf("%.0f\n", valores2[i]);
                    } else {
                        printf("%.2f\n", valores2[i]);
                    }
                    
                    // Usando operador ternário para exibir quem venceu
                    printf("Resultado: %s\n", 
                        resultados[i] == 0 ? "Empate!" : 
                        resultados[i] == 1 ? "Carta 1 vence neste atributo" : 
                        "Carta 2 vence neste atributo");
                    
                    // Acumular para soma total
                    soma1 += valores1[i];
                    soma2 += valores2[i];
                }
                
                // Resultado final baseado na soma dos atributos
                printf("\n=== RESULTADO FINAL ===\n");
                printf("Soma dos atributos para Carta 1: %.2f\n", soma1);
                printf("Soma dos atributos para Carta 2: %.2f\n", soma2);
                
                if(soma1 > soma2) {
                    printf("Carta 1 (%s) venceu a rodada!\n", cidade1);
                } else if(soma2 > soma1) {
                    printf("Carta 2 (%s) venceu a rodada!\n", cidade2);
                } else {
                    printf("Empate! As cartas têm a mesma soma de atributos.\n");
                }
            }
        } else if(opcao != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
    
    printf("Obrigado por jogar Super Trunfo!\n");
    return 0;
}