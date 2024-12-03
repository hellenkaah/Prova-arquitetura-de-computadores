#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Nome do sistema
void exibir_nome_sistema() {
    printf("\n===============================================================================\n");
    printf("               ######  S M A R T   C P U   S Y S T E M  ######\n");
    printf("===============================================================================\n");
    printf("               Bem-vindo ao sistema de recomendacao de CPUs       \n");
    printf("            A solucao inteligente para suas necessidades de TI    \n");
    printf("===============================================================================\n");
    printf("              Por favor, siga as instrucoes abaixo               \n");
    printf("           para receber a recomendacao personalizada de CPU.     \n");
    printf("===============================================================================\n\n");
}

struct CPU {
    char modelo[30];
    char arquitetura[10];
    int cacheL1;
    int cacheL2;
    float frequencia;
    int nucleos;
    int threads;
    int tdp;
    char aplicacao[20];
    int custo;
    int tamanho;
    int resfriamento;
    int multitarefa;
    int so;
    int desempenho;
    int energia;
};

// Prototipos das funcoes
void receber_criterios(char *nome_usuario, int *energia, int *desempenho, int *custo, char *aplicacao, int *tamanho, int *resfriamento, int *os, int *multitarefa);
struct CPU recomendar_CPU(struct CPU cpus[], int n, int desempenho, int custo, char *aplicacao, int tamanho, int resfriamento, int os, int multitarefa, int energia);
void exibir_recomendacao(struct CPU cpu, char *nome_usuario);
void justificar_escolha(struct CPU cpu);
int validar_entrada(int min, int max);
void reiniciar_programa();

// Funcao principal
int main() {
    setlocale(LC_ALL, ""); // Define a codificacao para o padrao do sistema
    reiniciar_programa();
    return 0;
}

// Funcao para reiniciar o programa
void reiniciar_programa() {
    exibir_nome_sistema();

    struct CPU cpus[] = {
        {"AMD Ryzen 9 5950X", "CISC", 64, 512, 3.4, 16, 32, 105, "trabalho", 3, 3, 2, 3, 1, 3, 0},
        {"Intel Core i9-12900K", "CISC", 64, 1280, 3.2, 16, 24, 125, "jogos", 3, 3, 2, 3, 1, 3, 0},
        {"Apple M1", "RISC", 128, 128, 3.2, 8, 8, 15, "escritorio", 2, 1, 1, 2, 2, 2, 0},
        {"AMD Ryzen 5 3600", "CISC", 32, 512, 3.6, 6, 12, 65, "jogos", 2, 2, 2, 2, 1, 2, 0},
        {"Intel Core i5-11400F", "CISC", 32, 256, 2.6, 6, 12, 65, "escritorio", 1, 2, 1, 2, 1, 2, 0},
        {"Intel Core i3-10100", "CISC", 16, 256, 3.6, 4, 8, 65, "estudos", 1, 2, 1, 2, 1, 1, 0},
        {"AMD Ryzen 7 5800X", "CISC", 64, 512, 3.8, 8, 16, 105, "trabalho", 3, 3, 2, 3, 1, 3, 0},
        {"Intel Core i7-12700H", "CISC", 64, 768, 2.3, 14, 20, 45, "jogos", 3, 2, 2, 3, 1, 3, 0},
        {"Qualcomm Snapdragon 8cx", "RISC", 64, 128, 3.0, 8, 8, 7, "escritorio", 2, 1, 1, 2, 2, 2, 0},
        {"AMD Athlon 3000G", "CISC", 16, 192, 3.5, 2, 4, 35, "estudos", 1, 1, 1, 1, 1, 1, 0}
    };

    int n = sizeof(cpus) / sizeof(cpus[0]);

    char nome_usuario[50];
    int energia, desempenho, custo, tamanho, resfriamento, os, multitarefa;
    char aplicacao[20];

    receber_criterios(nome_usuario, &energia, &desempenho, &custo, aplicacao, &tamanho, &resfriamento, &os, &multitarefa);

    struct CPU recomendada = recomendar_CPU(cpus, n, desempenho, custo, aplicacao, tamanho, resfriamento, os, multitarefa, energia);

    exibir_recomendacao(recomendada, nome_usuario);
    justificar_escolha(recomendada);

    printf("\nDeseja realizar outra recomendacao? (1: Sim, 2: Nao): ");
    int opcao = validar_entrada(1, 2);

    if (opcao == 1) {
        reiniciar_programa();
    } else {
        printf("\nObrigado por usar o Smart CPU System, %s! Ate logo.\n", nome_usuario);
    }
}

// Funcao para validar entrada numerica
int validar_entrada(int min, int max) {
    int entrada;
    do {
        scanf("%d", &entrada);
        if (entrada < min || entrada > max) {
            printf("Entrada invalida. Por favor, digite um valor entre %d e %d: ", min, max);
        }
    } while (entrada < min || entrada > max);
    return entrada;
}

// Funcao para receber os criterios do usuario
void receber_criterios(char *nome_usuario, int *energia, int *desempenho, int *custo, char *aplicacao, int *tamanho, int *resfriamento, int *os, int *multitarefa) {
    printf("Por favor, informe seu nome: ");
    scanf("%s", nome_usuario);

    printf("\nOla, %s! Vamos te ajudar a encontrar a CPU ideal. Responda as perguntas a seguir digitando o numero correspondente a sua escolha.\n", nome_usuario);

    printf("\n1. Qual e a sua prioridade em relacao ao consumo de energia da CPU?\n");
    printf("   [1] Baixo (foco em eficiencia energetica)\n");
    printf("   [2] Medio (equilibrio entre consumo e desempenho)\n");
    printf("   [3] Alto (prioridade para desempenho maximo)\n");
    printf("Digite sua escolha: ");
    scanf("%d", energia);

    printf("\n2. Qual e o nivel de desempenho que voce precisa?\n");
    printf("   [1] Basico (tarefas simples, como navegacao na internet)\n");
    printf("   [2] Medio (jogos leves e multitarefa moderada)\n");
    printf("   [3] Avancado (renderizacao, edicao pesada, jogos exigentes)\n");
    printf("Digite sua escolha: ");
    scanf("%d", desempenho);

    printf("\n3. Qual e o seu orcamento para a CPU?\n");
    printf("   [1] Baixo custo\n");
    printf("   [2] Medio custo\n");
    printf("   [3] Alto custo\n");
    printf("Digite sua escolha: ");
    scanf("%d", custo);

    printf("\n4. Qual sera a principal aplicacao da CPU?\n");
    printf("   [1] Jogos (prioridade para FPS e graficos)\n");
    printf("   [2] Trabalho (aplicacoes profissionais e multitarefa intensa)\n");
    printf("   [3] Escritorio (atividades basicas e de produtividade)\n");
    printf("   [4] Estudos (uso academico e aprendizado)\n");
    printf("Digite sua escolha: ");
    int aplicacao_opcao;
    scanf("%d", &aplicacao_opcao);
    if (aplicacao_opcao == 1) strcpy(aplicacao, "jogos");
    else if (aplicacao_opcao == 2) strcpy(aplicacao, "trabalho");
    else if (aplicacao_opcao == 3) strcpy(aplicacao, "escritorio");
    else if (aplicacao_opcao == 4) strcpy(aplicacao, "estudos");

    printf("\n5. Qual tamanho do computador?\n");
    printf("   [1] Pequeno (ex: mini PCs)\n");
    printf("   [2] Medio (ex: notebooks)\n");
    printf("   [3] Grande (ex: desktops full tower)\n");
    printf("Digite sua escolha: ");
    scanf("%d", tamanho);

    printf("\n6. Qual e o seu nivel de exigencia em relacao ao resfriamento da CPU?\n");
    printf("   [1] Baixo (foco em silencio)\n");
    printf("   [2] Medio (equilibrio entre desempenho e ruido)\n");
    printf("   [3] Alto (maximo desempenho, resfriamento avancado)\n");
    printf("Digite sua escolha: ");
    scanf("%d", resfriamento);

    printf("\n7. Qual e o sistema operacional que voce usara?\n");
    printf("   [1] Windows\n");
    printf("   [2] macOS\n");
    printf("   [3] Linux\n");
    printf("Digite sua escolha: ");
    scanf("%d", os);

    printf("\n8. O quanto voce pretende usar a CPU para multitarefa?\n");
    printf("   [1] Pouco (uma ou duas aplicacoes simultaneas)\n");
    printf("   [2] Moderado (ate quatro aplicacoes simultaneas)\n");
    printf("   [3] Intenso (varias aplicacoes simultaneas)\n");
    printf("Digite sua escolha: ");
    scanf("%d", multitarefa);
}

// Funcao para recomendar a CPU com base nos criterios
struct CPU recomendar_CPU(struct CPU cpus[], int n, int desempenho, int custo, char *aplicacao, int tamanho, int resfriamento, int os, int multitarefa, int energia) {
    int melhor_pontuacao = -1;
    struct CPU recomendada;

    for (int i = 0; i < n; i++) {
        int pontuacao = 0;

        // Desempenho
        if (desempenho == 1 && cpus[i].desempenho == 1) pontuacao += 1;
        else if (desempenho == 2 && cpus[i].desempenho == 2) pontuacao += 2;
        else if (desempenho == 3 && cpus[i].desempenho == 3) pontuacao += 3;

        // Custo
        if (custo == 1 && cpus[i].custo == 1) pontuacao += 1;
        else if (custo == 2 && cpus[i].custo == 2) pontuacao += 2;
        else if (custo == 3 && cpus[i].custo == 3) pontuacao += 3;

        // Aplicacao
        if (strcmp(cpus[i].aplicacao, aplicacao) == 0) pontuacao += 3;

        // Tamanho
        if (tamanho >= cpus[i].tamanho) pontuacao += 2;

        // Resfriamento
        if (resfriamento == 3 && cpus[i].resfriamento == 3) pontuacao += 2;
        else if (resfriamento == 2 && cpus[i].resfriamento == 2) pontuacao += 1;

        // OS
        if (os == 1 && cpus[i].so == 1) pontuacao += 2;
        else if (os == 2 && cpus[i].so == 2) pontuacao += 1;
        else if (os == 3 && cpus[i].so == 3) pontuacao += 3;

        // Multitarefa
        if (multitarefa == 3 && cpus[i].multitarefa == 3) pontuacao += 2;

        // Energia
        if (energia == 1 && cpus[i].energia == 1) pontuacao += 1;
        else if (energia == 2 && cpus[i].energia == 2) pontuacao += 2;
        else if (energia == 3 && cpus[i].energia == 3) pontuacao += 3;

        if (pontuacao > melhor_pontuacao) {
            melhor_pontuacao = pontuacao;
            recomendada = cpus[i];
        }
    }
    return recomendada;
}

// Funcao para exibir a recomendacao
void exibir_recomendacao(struct CPU cpu, char *nome_usuario) {
    printf("\nRecomendacao para %s: \n", nome_usuario);
    printf("Modelo da CPU: %s\n", cpu.modelo);
    printf("Arquitetura: %s\n", cpu.arquitetura);
    printf("Cache L1: %d KB\n", cpu.cacheL1);
    printf("Cache L2: %d KB\n", cpu.cacheL2);
    printf("Frequencia: %.2f GHz\n", cpu.frequencia);
    printf("Nucleos: %d\n", cpu.nucleos);
    printf("Threads: %d\n", cpu.threads);
    printf("TDP: %d W\n", cpu.tdp);
}

// Funcao para justificar a escolha
void justificar_escolha(struct CPU cpu) {
    printf("\nJustificativa para a escolha:\n");
    printf("A CPU recomendada foi a %s devido ao seu excelente desempenho em tarefas de %s.\n", cpu.modelo, cpu.aplicacao);
    printf("Ela tambem oferece um bom equilibrio entre custo, desempenho e consumo de energia.\n");
}
