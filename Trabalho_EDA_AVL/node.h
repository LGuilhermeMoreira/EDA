#ifndef NODE_H
#define NODE_H

#include "pessoa.h"

template <typename T>
struct Node
{
    // dado guardado
    T key;
    // ponteiro para o próximo nó com mesma key
    Node<T> *next;
    // ponteiros para direita e esquerda (árvore)
    Node<T> *left;
    Node<T> *right;
    // altura do nó (árvore)
    int height;
    // ponetiro para a pessoa
    Pessoa *pessoa;

    // construtor
    Node()
    {
        this->key;
        this->next = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
        this->pessoa = nullptr;
    }
};

#endif