/*Integrantes: Anna Luisa, Helena e Rafael*/

/*Integrantes: Anna Luisa, Helena e Rafael*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EQUIPES 40
#define MAX_PARTIDAS 1560
#define MAX_NOME 31
#define MAX_SIGLA 4
#define MAX_ESTADO 3

typedef struct {
    char nome[MAX_NOME];
    char sigla[MAX_SIGLA];
    char estado[MAX_ESTADO];
    int vitorias;
    int empates;
    int derrotas;
    int golsMarcados;
    int golsSofridos;
    int pontos;
    int saldoGols;
} Equipe;

typedef struct {
    char mandante[MAX_SIGLA];
    char visitante[MAX_SIGLA];
    int golsMandante;
    int golsVisitante;
} Partida;

typedef struct {
    Equipe equipes[MAX_EQUIPES];
    Partida partidas[MAX_PARTIDAS];
    int numEquipesCadastradas;
    int numPartidasCadastradas;
} Sistema;

//---LIMPA O BUFFER---
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//---TRANSFORMA TUDO EM MAIUSCULO---
void para_maiusculo(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

//---Bubble Sort para ordenar a lista de equipes em ordem alfabetica---
void troca(Equipe lista[], int pos1, int pos2) {
    Equipe provisorio = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = provisorio;
}

void sort_alfabetico(Equipe lista[], int tam) {
    for (int topo = tam - 1; topo > 0; topo--) {
        int max_troca = 0;
        bool trocou = false;
        for (int p_bolha = 0; p_bolha < topo; p_bolha++) {
            if (strcmp(lista[p_bolha].nome, lista[p_bolha + 1].nome) > 0) {
                troca(lista, p_bolha, p_bolha + 1);
                trocou = true;
                max_troca = p_bolha + 1;
            }
        }
        topo = max_troca;
        if (!trocou) break;
    }
}

//-----------------VERIFICA SE JÁ EXISTE ESSE NOME CADASTRADO-----------------
bool nomeExiste(Equipe lista[], int total, char nomeProcurado[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(lista[i].nome, nomeProcurado) == 0) {
            return true;
        }
    }
    return false;
}

//-----------------VERIFICA SE JÁ EXISTE ESSA SIGLA CADASTRADA-----------------
bool siglaExiste(Equipe lista[], int total, char siglaProcurada[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(lista[i].sigla, siglaProcurada) == 0) {
            return true;
        }
    }
    return false;
}

//-----------------VERIFICA SE ESSE ESTADO EXISTE-----------------
bool estadoExiste(char sigla[]) {
    char estados[27][3] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO",
        "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
        "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"
    };

    for (int i = 0; i < 27; i++){
        if (strcmp(sigla, estados[i]) == 0){
            return true;
        }
    }
    return false;
}

//================== CADASTRAR EQUIPES ================
Sistema cadastroEquipe(Sistema sistema) {
    if (sistema.numEquipesCadastradas >= MAX_EQUIPES) {
        printf("Erro: Limite maximo de equipes atingido.\n");
        return sistema;
    }

    Equipe nova;
    printf("=============================\nCadastro de Equipe\n=============================\n");

    //-----------------NOME-----------------
    printf("Digite o nome da equipe:\n");
    fgets(nova.nome, MAX_NOME, stdin);
    int tam_nome = strlen(nova.nome);
    if (nova.nome[tam_nome - 1] == '\n') {
        nova.nome[tam_nome - 1] = '\0';
    } else {
        limpar_buffer();
    }

    while (nomeExiste(sistema.equipes, sistema.numEquipesCadastradas, nova.nome)) {
        printf("Erro: Esse nome de equipe ja esta cadastrado.\n");
        printf("Digite o nome da equipe:\n");
        fgets(nova.nome, MAX_NOME, stdin);
        tam_nome = strlen(nova.nome);
        if (nova.nome[tam_nome - 1] == '\n') {
            nova.nome[tam_nome - 1] = '\0';
        } else {
            limpar_buffer();
        }
    }

    //-----------------SIGLA-----------------
    printf("Digite a sigla da equipe:\n");
    fgets(nova.sigla, MAX_SIGLA, stdin);

    while (true) {
        int tam_sigla = strlen(nova.sigla);
        if (nova.sigla[tam_sigla - 1] == '\n') {
            nova.sigla[tam_sigla - 1] = '\0';
            tam_sigla = strlen(nova.sigla);
        } else {
            limpar_buffer();
        }

        para_maiusculo(nova.sigla);

        if (tam_sigla != 3) {
            printf("Erro: A sigla precisa ter EXATAMENTE 3 letras.\n");
            printf("Digite a sigla da equipe:\n");
        } else if (siglaExiste(sistema.equipes, sistema.numEquipesCadastradas, nova.sigla)) {
            printf("Erro: Essa sigla ja esta em uso por outra equipe. Tente de novo:\n");
            printf("Digite a sigla da equipe:\n");
        } else {
            break;
        }
        fgets(nova.sigla, MAX_SIGLA, stdin);
    }

    //-----------------ESTADO-----------------
    printf("Digite o UF da equipe:\n");
    fgets(nova.estado, MAX_ESTADO, stdin);

    while (true) {
        int tam_estado = strlen(nova.estado);
        if (nova.estado[tam_estado - 1] == '\n') {
            nova.estado[tam_estado - 1] = '\0';
            tam_estado = strlen(nova.estado);
        } else {
            limpar_buffer();
        }

        para_maiusculo(nova.estado);

        if (estadoExiste(nova.estado)) {
            break;
        } else {
            printf("Erro: Esse estado nao existe!\n");
            printf("Digite o UF da equipe:\n");
        }
        fgets(nova.estado, MAX_ESTADO, stdin);
    }

    // Inicializa estatísticas
    nova.vitorias = 0;
    nova.empates = 0;
    nova.derrotas = 0;
    nova.golsMarcados = 0;
    nova.golsSofridos = 0;
    nova.pontos = 0;
    nova.saldoGols = 0;
    
    sistema.equipes[sistema.numEquipesCadastradas] = nova;
    sistema.numEquipesCadastradas++;

    sort_alfabetico(sistema.equipes, sistema.numEquipesCadastradas);

    printf("\nEquipe [%s, %s, %s] cadastrada.\n", nova.nome, nova.sigla, nova.estado);
    return sistema;
}

//================== BUSCA POR ESTADO ===================
void buscarPorEstado(Sistema sistema) {
    char estado[MAX_ESTADO];
    bool encontrou = false;

    printf("Digite a UF do estado: \n");
    scanf("%2s", estado);
    limpar_buffer();

    para_maiusculo(estado);

    if (!estadoExiste(estado)) {
        printf("Esse estado nao existe!\n");
        return;
    }

    for(int i = 0; i < sistema.numEquipesCadastradas; i++) {
        if(strcmp(estado, sistema.equipes[i].estado) == 0) {
            printf("Nome: %s | Sigla: %s \n", sistema.equipes[i].nome, sistema.equipes[i].sigla);
            encontrou = true;
        }
    }

    if (!encontrou) {
        printf("Nenhuma equipe cadastrada nesse estado.\n");
    }
}

//================== REGISTRAR PARTIDA ==================
Sistema registrarPartida(Sistema sistema) {
    if (sistema.numPartidasCadastradas >= MAX_PARTIDAS) {
        printf("Erro: Limite máximo de partidas atingido.\n");
        return sistema;
    }
    
    if (sistema.numEquipesCadastradas < 2) {
        printf("Erro: É necessário ter pelo menos 2 equipes cadastradas.\n");
        return sistema;
    }

    char entrada[100];
    char siglaMandante[MAX_SIGLA], siglaVisitante[MAX_SIGLA];
    int golsMandante, golsVisitante;
    
    printf("=============================\n");
    printf("Registro de Partida\n");
    printf("=============================\n");
    printf("Digite a partida no formato: MMM X-Y VVV\n");
    printf("Exemplo: FLA 3-1 PAL\n");
    fgets(entrada, sizeof(entrada), stdin);
    
    entrada[strcspn(entrada, "\n")] = '\0';
    
    int itensLidos = sscanf(entrada, "%3s %d-%d %3s", 
                            siglaMandante, &golsMandante, &golsVisitante, siglaVisitante);
    
    if (itensLidos != 4) {
        printf("Erro: Formato inválido! Use: AAA X-Y BBB\n");
        return sistema;
    }
    
    para_maiusculo(siglaMandante);
    para_maiusculo(siglaVisitante);
    
    int posMandante = -1, posVisitante = -1;
    for (int i = 0; i < sistema.numEquipesCadastradas; i++) {
        if (strcmp(sistema.equipes[i].sigla, siglaMandante) == 0) {
            posMandante = i;
        }
        if (strcmp(sistema.equipes[i].sigla, siglaVisitante) == 0) {
            posVisitante = i;
        }
    }
    
    if (posMandante == -1) {
        printf("Erro: Equipe mandante '%s' não está cadastrada.\n", siglaMandante);
        return sistema;
    }
    if (posVisitante == -1) {
        printf("Erro: Equipe visitante '%s' não está cadastrada.\n", siglaVisitante);
        return sistema;
    }
    
    if (strcmp(siglaMandante, siglaVisitante) == 0) {
        printf("Erro: Uma equipe não pode jogar contra si mesma.\n");
        return sistema;
    }
    
    if (golsMandante < 0 || golsVisitante < 0) {
        printf("Erro: Gols não podem ser negativos.\n");
        return sistema;
    }
    
    // Registra a partida
    strcpy(sistema.partidas[sistema.numPartidasCadastradas].mandante, siglaMandante);
    strcpy(sistema.partidas[sistema.numPartidasCadastradas].visitante, siglaVisitante);
    sistema.partidas[sistema.numPartidasCadastradas].golsMandante = golsMandante;
    sistema.partidas[sistema.numPartidasCadastradas].golsVisitante = golsVisitante;
    
    // Atualiza estatísticas do mandante
    sistema.equipes[posMandante].golsMarcados += golsMandante;
    sistema.equipes[posMandante].golsSofridos += golsVisitante;
    sistema.equipes[posMandante].saldoGols = sistema.equipes[posMandante].golsMarcados - 
                                             sistema.equipes[posMandante].golsSofridos;
    
    // Atualiza estatísticas do visitante
    sistema.equipes[posVisitante].golsMarcados += golsVisitante;
    sistema.equipes[posVisitante].golsSofridos += golsMandante;
    sistema.equipes[posVisitante].saldoGols = sistema.equipes[posVisitante].golsMarcados - 
                                              sistema.equipes[posVisitante].golsSofridos;
    
    // Determina resultado
    if (golsMandante > golsVisitante) {
        sistema.equipes[posMandante].vitorias++;
        sistema.equipes[posMandante].pontos += 3;
        sistema.equipes[posVisitante].derrotas++;
        printf("Resultado: %s venceu!\n", siglaMandante);
    } else if (golsMandante < golsVisitante) {
        sistema.equipes[posVisitante].vitorias++;
        sistema.equipes[posVisitante].pontos += 3;
        sistema.equipes[posMandante].derrotas++;
        printf("Resultado: %s venceu!\n", siglaVisitante);
    } else {
        sistema.equipes[posMandante].empates++;
        sistema.equipes[posMandante].pontos += 1;
        sistema.equipes[posVisitante].empates++;
        sistema.equipes[posVisitante].pontos += 1;
        printf("Resultado: Empate!\n");
    }
    
    sistema.numPartidasCadastradas++;
    printf("Partida registrada com sucesso: %s %d-%d %s\n", 
           siglaMandante, golsMandante, golsVisitante, siglaVisitante);
    
    return sistema;
}

//================== EXIBIR PLACAR ==================
void exibirPlacar(Sistema sistema) {
    if (sistema.numEquipesCadastradas == 0) {
        printf("Nenhuma equipe cadastrada.\n");
        return;
    }
    
    Equipe copia[MAX_EQUIPES];
    for (int i = 0; i < sistema.numEquipesCadastradas; i++) {
        copia[i] = sistema.equipes[i];
    }
    
    // Ordenação por pontos (decrescente) com critérios de desempate
    for (int i = 1; i < sistema.numEquipesCadastradas; i++) {
        Equipe chave = copia[i];
        int j = i - 1;
        
        while (j >= 0) {
            int comparar = 0;
            
            // Critério 1: Pontos (maior é melhor)
            if (copia[j].pontos < chave.pontos) {
                comparar = 1;
            } else if (copia[j].pontos == chave.pontos) {
                // Critério 2: Vitórias (maior é melhor)
                if (copia[j].vitorias < chave.vitorias) {
                    comparar = 1;
                } else if (copia[j].vitorias == chave.vitorias) {
                    // Critério 3: Saldo de gols (maior é melhor)
                    if (copia[j].saldoGols < chave.saldoGols) {
                        comparar = 1;
                    } else if (copia[j].saldoGols == chave.saldoGols) {
                        // Critério 4: Gols marcados (maior é melhor)
                        if (copia[j].golsMarcados < chave.golsMarcados) {
                            comparar = 1;
                        } else if (copia[j].golsMarcados == chave.golsMarcados) {
                            // Critério 5: Ordem alfabética
                            if (strcmp(copia[j].nome, chave.nome) > 0) {
                                comparar = 1;
                            }
                        }
                    }
                }
            }
            
            if (comparar) {
                copia[j + 1] = copia[j];
                j--;
            } else {
                break;
            }
        }
        copia[j + 1] = chave;
    }
    
    printf("\n================================= PLACAR =================================\n");
    printf("Pos | Equipe                 |  P |  V |  E |  D | GM | GS |  SG\n");
    printf("----|------------------------|----|----|----|----|----|----|-----\n");
    
    for (int i = 0; i < sistema.numEquipesCadastradas; i++) {
        printf("%3d | %-22s | %3d | %3d | %3d | %3d | %3d | %3d | %4d\n",
               i + 1,
               copia[i].nome,
               copia[i].pontos,
               copia[i].vitorias,
               copia[i].empates,
               copia[i].derrotas,
               copia[i].golsMarcados,
               copia[i].golsSofridos,
               copia[i].saldoGols);
    }
    printf("=======================================================================\n");
}

//-----------------MENU PRINCIPAL-----------------
Sistema menu(Sistema sistema) {
    int opcao;
    
    do {
        printf("\n=============================\n");
        printf("Menu principal\n");
        printf("=============================\n");
        printf("1. Cadastrar Equipe\n");
        printf("2. Buscar por Estado\n");
        printf("3. Registrar Partida\n");
        printf("4. Exibir Placar\n");
        printf("0. Finalizar Programa\n");
        printf("=============================\n");
        printf("Digite a sua escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();
        
        switch (opcao) {
            case 0:
                printf("Programa finalizado.\n");
                break;
            case 1:
                sistema = cadastroEquipe(sistema);
                break;
            case 2:
                buscarPorEstado(sistema);
                break;
            case 3:
                sistema = registrarPartida(sistema);
                break;
            case 4:
                exibirPlacar(sistema);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
    
    return sistema;
}

//-----------------MAIN-----------------
int main() {
    Sistema sistema;
    sistema.numEquipesCadastradas = 0;
    sistema.numPartidasCadastradas = 0;
    
    sistema = menu(sistema);
    
    return 0;
}
