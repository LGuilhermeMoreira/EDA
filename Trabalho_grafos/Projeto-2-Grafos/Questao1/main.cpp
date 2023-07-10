#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//funcao para imprimir o grafo
void print(vector<vector<list<int>>> grafos){
    for(int a = 0; a < grafos.size(); a++){
        auto grafo = grafos[a];
        cout << "Grafo " << a << endl;
        for(int i = 0; i < grafo.size(); ++i) {
            cout << "v[" << i << "]: ";
            for(auto vizinho : grafo[i]) {
                cout << vizinho << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
} 

/*
A função a seguir realiza uma busca em largura
para determinar se existe algum vértice que tenha um
vizinho com a mesma cor. 
Se houver, ela retorna "NÃO"; caso contrário, retorna "SIM".
*/

string verify(vector<vector<list<int>>> grafos) {
    //criando a string de resultado
    string result = "";
    //percorrendo o vetor de grafos
    for(int a = 0; a < grafos.size(); a++){
        //vetor para armazenar as cores dos vertices
       vector<int> Colors(grafos[a].size());
        //flag para indicar se o grafo é valido ou invalido
        int flag = 0;
        //fila para a busca em largura(BFS)
        queue<int> fila;
        //atribuindo a cor 1 ao vertice inicial do grafo
        Colors[0] = 1;
        //inserindo o vertice inicial na fila
        fila.push(0);
        //referencia ao grafo atual
        auto grafo = grafos[a];
        //Fazendo a busca e comparando as cores
        while(!fila.empty()){
            //obtendo o proximo vertice da fila
            int u = fila.front();
            //desempilhando o vertice da fila
            fila.pop();
            //percorrendo os vertices adjacentes a u
            for(auto v : grafo[u]){
                //verificando se o vertice v ainda nao foi visitado(cor igual a 0)
                if(Colors[v] == 0){
                    //verificando se a cor do vertice u é igual a 1
                    if(Colors[u] == 1){
                        //atribuindo a cor 2 ao vertice v
                        Colors[v] = 2;
                    }else{
                        //atribuindo a cor 1 ao vertice v
                        Colors[v] = 1;
                    }
                    //inserindo o vertice v na fila para processamento posterior
                    fila.push(v);
                }
                //verificando se há conflito de cores entre u e v
                else{
                    if(Colors[u] == Colors[v]){
                        flag = 1;
                    }
                }
            }
        }
        //verificando o valor da flag após o processamento do grafo
        if(flag == 0){
            result += "SIM\n";
        }
        else{
            result += "NAO\n";
        }
    }
    return result;
}



int main() {
    // criando a string para ler o arquivo
    string path;
    cout << "Digite o caminho do arquivo: ";
    //lendo o caminho do arquivo
    getline(cin,path);
    //criando o vetor de grafos
    vector<vector<list<int>>> grafos;
    fstream file;
    //abrindo o arquivo
    file.open(path);
    //lendo o arquivo
    while(file.is_open()){
        //lendo o numero de vertices
        int n;
        file >> n;
        //verificando se o arquivo acabou
        if(!file) break;
        //criando o grafo
        vector<list<int>> grafo(n);
        //lendo o numero de arestas
        int m;
        file >> m;
        //lendo as arestas e adicionando no grafo
        for(int i = 0; i < m; ++i) {
            int v1,v2;
            file >> v1 >> v2;
            grafo[v1].push_back(v2);
            grafo[v2].push_back(v1);
        }
        //adicionando o grafo no vetor de grafos
        grafos.push_back(grafo);
    }
    //fechando o arquivo
    file.close();

    //chando a funcao para verificar se o grafo é aceito ou não pelo problema
    cout << verify(grafos) << endl;


}
