#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector<vector<int>>& grafo,vector<int>& padres, int nodo_actual, vector<bool>& visitados){
    
    
    visitados[nodo_actual] = true;
    

    for(int vecino : grafo[nodo_actual]){
        if(!visitados[vecino]){
            padres[vecino] = nodo_actual;
            dfs(grafo, padres, vecino, visitados);
        }
    }
    
}



int main() {
    
    int nodo = 0;
        
    int vertices = 5;

    vector<vector<int>> lista_adyacencia;
    lista_adyacencia = {
        {1,2,3},
        {0,2},
        {0,1,4},
        {0},
        {2}
    };

    vector<bool> visitados(vertices, false);
    vector<int> padres(vertices, -1);
    dfs(lista_adyacencia, padres, nodo, visitados);

    for(int i : padres){
        cout << i << " ";
    }


    return 0;
}