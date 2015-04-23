// UNIVERSIDADE ESTADUAL DE FEIRA DE SANTANA
// ALUNO: LUCAS VINICIUS DOS SANTOS ASSIS
// DISCIPLINA: ANALISE E PROJETOS DE ALGORITMOS
// IMPLENTACAO DO ALGORITMO DE FLOYD WARSHALL

#include <iostream>
#include <values.h>

const int INF = MAXINT/2;

using namespace std;

int min(int, int);

/*
 * A representacao da matriz de adjacencia deve levar em consideracao
 * o numero -1 para dizer que nao existe caminho entre o vertice con-
 * siderado.
 * 
 * */

int main(){
	int nos_grafo;
	cin >> nos_grafo; 							 // Quantidade de nos no grafo
	int matriz_adjacencia[nos_grafo][nos_grafo]; // Criacao da matriz para representacao do grafo
										
	for (int i = 0; i < nos_grafo; i++){		// Lendo a matriz de adjacencia
		for (int j = 0; j < nos_grafo; j++){
			cin >> matriz_adjacencia[i][j];
			if(matriz_adjacencia[i][j] == -1){
				matriz_adjacencia[i][j] = INF;
			}
		}
	}
	
	for(int k = 0; k < nos_grafo; k++){			// Executando o algoritmo
		for(int i = 0; i < nos_grafo; i++){
			for(int j = 0; j < nos_grafo; j++){
				if (matriz_adjacencia[k][j] != INF && matriz_adjacencia[i][k] != INF){
					matriz_adjacencia[i][j] = min(matriz_adjacencia[i][j], (matriz_adjacencia[i][k] + matriz_adjacencia[k][j]));	
				}
			}
		}
	}
	
	for (int i = 0; i < nos_grafo; i++){		// Mostrando ao usuario a resposta
		for (int j = 0; j < nos_grafo; j++){
			if(matriz_adjacencia[i][j] == INF){
				cout << " INF ";
			}
			else{
				cout << " " << matriz_adjacencia[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}

int min (int i, int j){
	if(i <= j){
		return i;
	}
	return j;
}
