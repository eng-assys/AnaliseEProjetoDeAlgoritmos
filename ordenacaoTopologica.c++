// UNIVERSIDADE ESTADUAL DE FEIRA DE SANTANA
// ALUNO: LUCAS VINICIUS DOS SANTOS ASSIS
// DISCIPLINA: ANALISE E PROJETOS DE ALGORITMOS
// IMPLENTACAO DO ALGORITMO DE ORDENACAO TOPOLOGICA
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;


struct vertice
{
	vector<int> listaAdjacencias;
};

struct grafo{
	int qtdVertices;
	vector<vertice> listaVertices;
};

void imprimeLista (vector<int> f){
	for(int i = 0; i < f.size(); i++){
		cout << f[i] << " ";
	}	
	cout << "\n";
}

// Funcao para imprimir cada vertice do grafo seguido de suas respectivas adjacencias
void imprimeGrafo(grafo g){
	for(int i = 0; i < g.qtdVertices; i++){
		cout << i+1 << "º vértice: \n";
		for(int j = 0; j < g.listaVertices[i].listaAdjacencias.size(); j++){
			cout << j+1 << "ª adjacencia: " << g.listaVertices[i].listaAdjacencias[j] << "\n";
		}
		cout << "\n";
	}
}

bool todosZero(vector<int> v){
	for (int i = 0; i < v.size(); i++){
		if(v[i] != 0)
			return false;
	}
	return true;
}

void ordenacaoTopologica(grafo g){
	// Quando um vertice tem 0 dependencias entra na fila para suas adjacencias serem analisadas
	vector<int> fila;
	// Guarda a quantidade de dependencias ainda existentes para cada vertice
	vector<int> qtdDependencias(g.qtdVertices);
	// Guarda a lista de vertices ordenados topologicamente
	vector<int> resultado;
	// Indica que o grafo nao tem nenhum vertice e que nao pode ser feita a ordenacao topologica
	if (g.qtdVertices == 0){
		cout << "Grafo sem vertices\n\n";
		return;
	}

	// Contando a quantidade de dependencias de cada vertice ao inicio do algoritmo
	for(int i = 0; i < g.qtdVertices; i++){
		for (int j = 0; j < g.listaVertices[i].listaAdjacencias.size(); j++){
			qtdDependencias[g.listaVertices[i].listaAdjacencias[j]]++;
		}
	}
	// Imprime lista de dependencias
	// cout << "Lista de dependencias\n";
	// imprimeLista(qtdDependencias);

	// Colocando vertice sem dependencias na fila
	for(int i = 0; i < qtdDependencias.size(); i++){
		if(qtdDependencias[i] == 0){
			fila.push_back(i);
		}
	}

	// Imprime fila
	// cout << "Fila\n";
	// imprimeLista(fila);

	// Indica a posicao na fila do vertice a ser analisado
	int posDaVez = 0;
	// Guarda o valor presente na posicao posDaVez da fila
	int valorDaVez;

	// O algoritmo termina somente quando todos os elementos nao possuem mais dependencias
	while(!todosZero(qtdDependencias)){
		valorDaVez = fila[posDaVez];
		vector<int> adj = g.listaVertices[valorDaVez].listaAdjacencias;
		for(int i = 0; i < adj.size(); i++){
			qtdDependencias[adj[i]] = qtdDependencias[adj[i]] - 1;
			if(qtdDependencias[adj[i]] == 0)
				fila.push_back(adj[i]);
		}	
		posDaVez++;
		if(posDaVez >= fila.size()){ // Vendo se o grafo eh digrafo aciclico
			cout << "Ordenacao topologica nao permite grafos ciclicos\n\n";
			return;
		}
	}
	// ETAPA 4 - IMPRIMIR LISTA DOS VERTICES APOS A REALIZACAO DA ORDENACAO TOPOLOGICA
	imprimeLista(fila);
	cout << "\n";
}

int main(){
	int tamanhoGrafo;
	while(scanf("%d", &tamanhoGrafo) == 1){
		// ETAPA 1 - LER O GRAFO
		// Criacao do grafo
		grafo g;
		// Quando seu valor eh igual a -1 nenhuma aresta a mais eh inserida no grafo
		int nAdj;
		// Lendo a quantidade de vertices que o grafo possuirah
		g.qtdVertices = tamanhoGrafo;
		// Inserindo elementos no grafo (vertices e suas adjacencias)
		for(int i = 0; i < g.qtdVertices; i++){
			// Criando um vertice
			vertice v;		
			cin >> nAdj;
			while (nAdj > -1){
				v.listaAdjacencias.push_back(nAdj);
				cin >> nAdj;
			}
			g.listaVertices.push_back(v);
		}
		// imprimeGrafo(g);

		// ETAPA 2 - REALIZAR ORDENACAO TOPOLOGICA
		ordenacaoTopologica(g);
	}
	return 0;
}
