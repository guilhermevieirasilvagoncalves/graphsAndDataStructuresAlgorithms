/*
    @author: Guilherme Vieira Silva Gonçalves
    @course: Ciência da Computação, 4th semester
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G; // Lista de adjacencia
vector<bool> cor; // cor, visitado ou não visitado
vector<int> distancia; // distancia entre os vertices
vector<int> pai; // guarda o vertice pai
queue<int> fila; // fila dos vertices

void BFS(int inicio){   
    fila.push(inicio); // primeiro vertice da fila
    distancia[inicio] = 0;
    cor[inicio] = true;

    while(!fila.empty()){ // só para quando todos os vertices forem acessados
        int vertice = fila.front();
        fila.pop();
        for(int i = 0; i < G[vertice].size();i++){
            if(!cor[G[vertice][i]]){//  se a cor for false
                cor[G[vertice][i]] = true; // setar que passou
                pai[G[vertice][i]] = vertice; // pai vai ser o anterior
                distancia[G[vertice][i]] = distancia[vertice] + 1; // distancia do anterior + 1
                fila.push(G[vertice][i]); // vai verificar o proximo
            }
        }
    }
}


int main(){
    setlocale(LC_ALL,"Portuguese_Brasil");
    int quantVertices,quantArestas,x,y;
    cin >> quantVertices >> quantArestas;
    G.resize(quantVertices); // define o tamanho do grafo
    for(int i = 0; i < quantArestas; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x); // x se conecta em y e y se conecta em x
    }

    // inicializa os vetores 
    distancia.resize(quantVertices,-1);
    pai.resize(quantVertices,-1);
    cor.resize(quantVertices,false);

    BFS(0);

    cout << "Distancias: " << endl;
    for(auto &x: distancia) cout << x << " ";
    cout << endl;

}
