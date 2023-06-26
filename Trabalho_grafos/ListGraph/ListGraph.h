#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <limits>
#include "Edge.h"
using std::list;
using std::vector;
using std::numeric_limits;

/**
 * Classe que especifica um TAD ListGraph que implementa um 
 * grafo como uma lista de adjacencias.
 * Um grafo é um conjunto de vertices e um conjunto de arestas.
 * Vertices sao representados pelos inteiros 0 a n-1.
 * Arestas sao pares ordenados de vertices.
*/
class ListGraph {
private:
    int _num_v;               // numero de vertices
    int _num_e;               // numero de arestas
    bool _directed;           // flag para indicar se eh direcionado
    vector<list<Edge>> _adj;  // listas de adjacencias

public:
    /**
     * Construtor. Constroi o grafo
     * @param n O numero de vertices
     * @param d True se esse eh um grafo direcionado
    */
    ListGraph(int n, bool d){
        _num_v = n;
        _num_e = 0;
        _directed = d;
        _adj.resize(n);
    }

    // Destrutor
    ~ListGraph() = default;

    /**
     * Retorna o numero de vertices
     * @param O numero de vertices
     */
    int get_num_v() const { return _num_v; }

    /**
     * Retorna o numero de arestas
     * @param O numero de arestas
     */
    int get_num_e() const { return _num_e; }

    /**
     * Determina se esse eh um grafo direcionado
     * @return true se e somente se esse eh um grafo direcionado
     */
    bool is_directed() const { return _directed; }

    /**
     * Insere uma nova aresta no grafo
     * @param edge A nova aresta
     */
    void insert(const Edge& edge){
        // criando o inicio da aresta
        int source = edge.get_source();
        // criando o fim da aresta
        int dest = edge.get_dest();
        // inserindo a aresta na lista de adjacencias
        _adj[source].push_back(edge);
        // checando se eh direcionado
        if(_directed == true){
            // criando a aresta reversa
            Edge reverse_edge(dest, source, edge.get_weight());
            // inserindo a aresta reversa na lista de adjacencias
            _adj[dest].push_back(reverse_edge);
        }
        // incrementando o número de aresta
        _num_e++;
    }

    /**
     * Determina se uma aresta existe
     * @param source O vertice de origem
     * @param dext O vertice de destino
     * @return true se existe uma aresta de source para dest
    */
    bool is_edge(int source, int dest) const{
        // percorrendo a lista de adjacencias
        for(auto it = _adj[source].begin(); it != _adj[source].end(); it++){
            // checando se o vertice de destino eh igual ao vertice de destino da aresta
            if(it->get_dest() == dest){
                return true;
            }
        }
        return false;
    }

    /** Obtem a aresta entre dois vertices
     * @param source O vertice origem
     * @param dest O vertice destino
     * @return A aresta entre os dois vertices ou uma aresta
     * com peso igual a numeric_limits<double>::infinity() se nao existe nenhuma aresta
     */
    Edge get_edge(int source, int dest) const{
        for(auto it = _adj[source].begin(); it != _adj[source].end();it++){
            if(it->get_dest() == dest){
                return *it;
            }
        }
    }

    /**
     * Retorna uma referencia para a lista de adjacencias de um vertice
     * @param source O vertice origem
     * @return Uma const reference para a lista de adjacencias de um vertice
    */
    list<Edge>& neighbors(int source){
        return _adj[source];
    }
    const list<Edge>& neighbors(int source) const{
        return _adj[source];
    }

    /** 
     * Retorna um iterator para a primeira aresta adjacent ao vertice especificado.
     * @param source O vertice origem
     * @return Um iterador para as arestas adjacentes a source
    */
    list<Edge>::iterator begin(int source){
        return _adj[source].begin();
    }
    list<Edge>::const_iterator begin(int source) const{
        return _adj[source].begin();
    }

    /** Retorna um iterador uma posicao apos a ultima aresta 
     * adjacente ao vertice especificado
     * @param source O vertice origem
     */
    list<Edge>::iterator end(int source){
        return _adj[source].end();
    }
    list<Edge>::const_iterator end(int source) const{
        return _adj[source].end();
    }

   
    // ListGraph(const ListGraph&){
    //     // nao faz nada
    // }

    // ListGraph& operator=(const ListGraph&){
    //     // nao faz nada
    // }

};


#endif