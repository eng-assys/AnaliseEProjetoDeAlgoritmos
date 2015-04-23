# algoritmoDeFloydWarshall
Trabalho de Graduação - implementação do algoritmo

As entradas serão entradas formatadas no estilo maratona de programação.

Explicando o algoritmo:

O algoritmo em questão resolve o problema de encontrar o menor caminho entre todos os pares de vértices de um grafo orientado e ponderado. Ele apenas encontra os valores a serem percorridos, e não a sequência de arestas.

	Dado um grafo G diferenciado e ponderado, deve-se encontrar para todo par u, v de vértices um caminho mínimo de u a v. O grafo pode conter arestas negativas. O grafo não pode conter ciclos negativos.

	=>A entrada consiste em uma matriz de adjacência representando os pesos das arestas de um grafo orientado que satisfaça a seguinte condição:

		Uj = 0, se i = j
		   = o peso da aresta orientada (i, j), se i != j
		   = infinito, caso contrário.

	=>A saída será uma matriz quadrada onde cada célula deve conter a distância mínima entre o vértice i e j. A entrada Dij contém o peso do camino mais curto do vértice i até o j.

	ALGORITMO

	func floyd-warshall (caminho[][])
		for k = 1 to n
			for i = 1 to n
				for j = 1 to n
					caminho[i][j] = min (caminho[i][j], caminho[i][k] + caminho [k][j])


Uma análise simples da complexidade do algoritmo pode ser feita da seguinte maneira:

O laço principal é executado n vezes e o laço secundário considera cada um dos O(n²) pares de vértices, realizando uma operação de tempo constante para cada par. Usando matriz de adjacência a complexidade é de O(n³).


	Fontes:

		http://pt.slideshare.net/JoaoSilva30/algoritmo-de-floydwarshall

