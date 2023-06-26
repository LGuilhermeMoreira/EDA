#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <iostream>
#include <limits>
#include <sstream>

class Edge {
private:
    int _source;      // o vertice de origem da aresta
    int _dest;        // o vertice de destino da aresta
    double _weight;   // o peso da aresta

public:
    // Constroi uma aresta de source para dest com peso w
    // Se w nao for especificado ele eh setado para 1.0
    Edge(int source, int dest, double w = 1.0){
        _source = source;
        _dest = dest;
        _weight = w;
    }

    // Constroi uma aresta falsa com source e dest igual a -1 e 
    // weight igual a infinito
    Edge(){
        _source = -1;
        _dest = -1;
        _weight = std::numeric_limits<double>::infinity();
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
        if(this->_dest == other._dest && this->_source == other._source){
            return true;
        }
        return false;
    }

    int get_dest() const // retorna o destino
    {
        return _dest;
    }

    int get_source() const // retorna a origem
    {return _source;}

    double get_weight() const // retorna o peso
    {return _weight;}
    std::string to_string() const // retorna uma representacao de string da aresta
    {
        std::stringstream ss;
        ss << "(" << _source << ", " << _dest << ", " << _weight << ")";
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        return os << "(" << edge._source << ", " << edge._dest << ", " << edge._weight << ")";
    }

};

#endif