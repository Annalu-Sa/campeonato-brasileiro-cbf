/*Integrantes: Anna Luisa, Helena e Rafael*/

#include <stdio.h>
#include <string.h>

#define MAX_EQUIPES 40
#define MAX_PARTIDAS 1560 //cada equipe joga 1x contra cada adversário (40*39)
struct Equipe {
    char nome[31];      //+1 devido ao espaço reservado ao '\0'
    char sigla[4];      
    char estado[3];     
    int vitorias;       
    int empates;        
    int derrotas;       
    int golsMarcados;   
    int golsSofridos;   
    int pontos;         
    int saldoGols;      
};

struct Partida {
    char mandante[4];
    char visitante[4];
    int golsMandante;
    int golsVisitante;
};

struct Sistema {
    Equipe equipes[MAX_EQUIPES];
    Partida partidas[MAX_PARTIDAS];
    //Equipes e partidas cadastradas evita varredura de células vazias:
    int numEquipesCadastradas; 
    int numPartidasCadastradas;
};

int main() {
	int a, b, c;
}