#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <iostream>
#include <limits>
#include <sstream>

template <typename T,typename U>
class Edge {
private:
    T _source;      // o vertice de origem da aresta
    T _dest;        // o vertice de destino da aresta
    U _weight;   // o peso da aresta

public:
    // Constroi uma aresta de source para dest com peso w
    // Se w nao for especificado ele eh setado para 1.0
    Edge(T source, T dest, U w = 1.0){
        _source = source;
        _dest = dest;
        _weight = w;
    }

    // Constroi uma aresta falsa com source e dest igual a -1 e 
    // weight igual a infinito
    Edge(){
        _source = -1;
        _dest = -1;
        _weight = std::numeric_limits<U>::infinity();
    }

    // Constroi uma aresta que eh uma copia de outra
    Edge(const Edge& other){
        _source = other._source;
        _dest = other._dest;
        _weight = other._weight;
    }

    // Compara se duas arestas sao iguais. Duas arestas sao iguais se 
    // seus vertices de origem e destino sao iguais. O peso eh desconsiderado.
    bool operator==(const Edge& other) const{
        return _source == other._source && _dest == other._dest;
    }

    T get_dest() const{
        return _dest;
    } // retorna o destino

    T get_source() const{
        return _source;
    } // retorna a origem

    U get_weight() const{
        return _weight;
    } // retorna o peso

    std::string to_string() const{
        std::stringstream ss;
        ss << "(" << _source << "," << _dest << "," << _weight << ")";
        return ss.str();
    } // retorna uma representacao de string da aresta

    //obrecarga do operador de insercao
    friend std::ostream& operator<<(std::ostream& os, const Edge& e){
        return os << e.to_string();
    }
};

#endif