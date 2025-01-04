#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES_POR_ESTADO 4

//Definição da estrutura para representar cada cidade
typedef struct {
    char codigo[4];             //Código da cidade
    int populacao;              //População
    float area;                 //Área
    float pib;                  //PIB
    int pontosTuristicos;       //Número de pontos turísticos
} Cidade;

//Função para cadastrar uma cidade
void cadastrarCidade(Cidade* cidade, char estado, int numero) {
    //Definir o código da cidade
    sprintf(cidade->codigo, "%c%02d", estado, numero);

    //Solicitar os dados ao usuário
    printf("Cadastro da cidade %s:\n", cidade->codigo);
    printf("População: ");
    scanf("%d", &cidade->populacao);

    printf("Área (em km²): ");
    scanf("%f", &cidade->area);

    printf("PIB (em milhões): ");
    scanf("%f", &cidade->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);
    printf("\n");
}

//Função para exibir os dados de uma cidade
void exibirCidade(const Cidade* cidade) {
    printf("Cidade %s:\n", cidade-> codigo);
    printf(" População: %d\n", cidade->populacao);
    printf("Área: %.2f km²\n", cidade->area);
    printf("PIB: %.2f milhões\n", cidade->pib);
    printf("Pontos turísticos: %d\n\n", cidade->pontosTuristicos);
}

//Função para comparar duas cidades e exibir o resultado
void compararCidades(const Cidade* cidade1, const Cidade* cidade2){
    printf("Comparando as cidades %s e %s:\n", cidade1->codigo, cidade2->codigo);

    if (cidade1->populacao > cidade2->populacao){
        printf("%s tem maior população.\n", cidade1-> codigo);
    } else if (cidade1->populacao < cidade2->populacao){
        printf("%s tem maior população.\n", cidade2->codigo);
    } else {
        printf("Ambas as cidades tem a mesma população.\n");
    }

    if (cidade1->area > cidade2->area) {
        printf("%s tem maior área.\n", cidade1->codigo);
    } else if (cidade1->area < cidade2->area) {
        printf("%s tem maior área.\n", cidade2->codigo);
    } else {
        printf("Ambas as cidades tem a mesma área.\n");
    }

    if (cidade1->pib > cidade2->pib) {
        printf("%s tem maior PIB.\n", cidade1->codigo);
    } else if (cidade1->pib < cidade2->pib) {
        printf("%s tem maior PIB.\n", cidade2->codigo);
    } else {
        printf("Ambas as cidades tem o mesmo PIB.\n");
    }

    if (cidade1->pontosTuristicos > cidade2->pontosTuristicos) {
        printf("%s tem mais pontos turísticos.\n", cidade1->codigo);
    } else if (cidade1->pontosTuristicos < cidade2->pontosTuristicos) {
        printf("%s tem mais pontos turísticos.\n", cidade2->codigo);
    } else {
        printf("Ambas as cidades tem o mesmo número de pontos turísticos.\n");
    }

    printf("\n");

}

int main() {
    //Vetor para armazenar todas as cidades
    Cidade cidades[NUM_ESTADOS * NUM_CIDADES_POR_ESTADO];
    int index = 0;

    //Cadastro das cidades
    for (char estado = 'A'; estado <= 'H'; estado++){
        for (int numero = 1; numero <= NUM_CIDADES_POR_ESTADO; numero++){
            cadastrarCidade(&cidades[index], estado, numero);
            index++;
        }
    }

    //Exibição dos dados cadastrados
    printf("Dados cadastrados:\n\n");
    for (int i = 0; i < NUM_ESTADOS * NUM_CIDADES_POR_ESTADO; i++){
        exibirCidade(&cidades[i]);
    }

    //Comparação entre duas cidades
    int cidade1Index, cidade2Index;
    printf ("Digite o índice da primeira cidade para comparar (0 a %d): ", NUM_ESTADOS * NUM_CIDADES_POR_ESTADO -1);
    scanf("%d", &cidade1Index);
    printf("Digite o índice da segunda cidade para comparar (0 a %d): ", NUM_ESTADOS * NUM_CIDADES_POR_ESTADO - 1);
    scanf("%d", &cidade2Index);

    if (cidade1Index >= 0 && cidade1Index < NUM_ESTADOS * NUM_CIDADES_POR_ESTADO &&
        cidade2Index >= 0 && cidade2Index < NUM_ESTADOS * NUM_CIDADES_POR_ESTADO) {
            compararCidades(&cidades[cidade1Index], &cidades[cidade2Index]);
        } else {
            printf("Índices inválidos.\n");
        }

  

    return 0;
}
