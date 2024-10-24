#include <iostream>
#include <vector>
#include <set>


using namespace std;

/* void dfs(vector<vector<int>>& grafo,vector<int>& padres, int nodo_actual, vector<bool>& visitados){
    
    
    visitados[nodo_actual] = true;
    

    for(int vecino : grafo[nodo_actual]){
        if(!visitados[vecino]){
            padres[vecino] = nodo_actual;
            dfs(grafo, padres, vecino, visitados);
        }
    }
    
} */


bool dfs(vector<vector<int>>& grafo, int nodo_actual, vector<int>& grupo, int grupo_actual){
    
    grupo[nodo_actual] = grupo_actual;
    

    for(int vecino : grafo[nodo_actual]){
        if(grupo[vecino] == -1){
            if(dfs(grafo, vecino, grupo, 1-grupo_actual)){
                return false;
            }
        }else if(grupo[vecino] == grupo_actual){
            return false;
        }
    }
    
}


bool esBipartito(vector<vector<int>>& grafo,int vertices,set<int>& conj_A,set<int>& conj_B){
    // para ver si el grafo es bipartito necesito guardar los nodos en un dos conjuntos 
    vector<int> conjunto(vertices, -1);

    for(int i = 0; i < vertices; i++){
        if(conjunto[i] == -1){
            if(!dfs(grafo,0,conjunto,0)){
                return false;
            }
        }
    }
    for(int i = 0; i < vertices; i++){
        if(conjunto[i] == 0)
        {conj_A.insert(i);
        }else{conj_B.insert(i);}
    }

    return true;

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
    bool res = esBipartito(lista_adyacencia, nodo);

    
    //Una vez evaluado si el arbol es bipartito, podemos simplemente calcular
    //cuantas aristas le restan para llenar un grafo bipartito.
    // |A|x|B| - |A|




    return 0;
}