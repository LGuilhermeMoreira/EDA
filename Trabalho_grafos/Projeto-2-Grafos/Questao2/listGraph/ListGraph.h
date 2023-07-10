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
template <typename T, typename U>
class ListGraph {
private:
    int _num_v;               // numero de vertices
    int _num_e;               // numero de arestas
    bool _directed;           // flag para indicar se eh direcionado
    vector<list<Edge<T,U>>> _adj;  // listas de adjacencias

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
    ~ListGraph(){
        _adj.clear();
    }

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
    void insert(const Edge<T,U>& edge){
        if(!_directed){
            _adj[edge.get_source()].push_back(edge);
            _adj[edge.get_dest()].push_back(Edge<T,U>(edge.get_dest(),edge.get_source(),edge.get_weight()));
        }
        else{
            _adj[edge.get_source()].push_back(edge);
        }
        _num_e++;
    }

    /**
     * Determina se uma aresta existe
     * @param source O vertice de origem
     * @param dext O vertice de destino
     * @return true se existe uma aresta de source para dest
    */
    bool is_edge(T source, T dest) const{
        for(auto e : _adj[source]){
            if(e.get_dest() == dest){
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
    Edge<T,U> get_edge(T source, T dest) const{
        for(auto e : _adj[source]){
            if(e.get_dest() == dest){
                return e;
            }
        }
        // retorna arestas falsas
        return Edge<T,U>();
    }

    /**
     * Retorna uma referencia para a lista de adjacencias de um vertice
     * @param source O vertice origem
     * @return Uma const reference para a lista de adjacencias de um vertice
    */

    // std::list<Edge<T,U>>& neighbors(T source){
    //     return _adj[source];
    // }


    // const std::list<Edge<T,U>>& neighbors(T source) const{
    //     return _adj[source];
    // }


    // typename std::list<Edge<T,U>>::iterator begin(T source){
    //     return _adj[source].begin();
    // }


    // typename std::list<Edge<T,U>>::const_iterator begin(T source) const{
    //     return _adj[source].begin();
    // }


    // typename std::list<Edge<T,U>>::iterator end(T source){
    //     return _adj[source].end();
    // }


    // typename std::list<Edge<T,U>>::const_iterator end(T source) const{
    //     return _adj[source].end();
    // }

    std::list<Edge<T,U>>& neighbors(int source){
        return _adj.at(source);
    }

    const std::list<Edge<T,U>>& neighbors(int source) const{
        return _adj.at(source);
    }

    typename std::list<Edge<T,U>>::iterator begin(int source){
        return _adj.at(source).begin();
    }

    typename std::list<Edge<T,U>>::const_iterator begin(int source) const{
        return _adj.at(source).begin();
    }

    typename std::list<Edge<T,U>>::iterator end(int source){
        return _adj.at(source).end();
    }

    typename std::list<Edge<T,U>>::const_iterator end(int source) const{
        return _adj.at(source).end();
    }


};


#endif