#ifndef AVL_H
#define AVL_H

#include "node.h"
#include "pessoa.h"
#include <iostream>
#include <string>
#include <vector>

// TODO: criar uma função que transforme um vetor em uma arvore AVL

template <typename T>
class AVL_tree
{
public:
    //* Metodos

    // construtor
    AVL_tree()
    {
        this->root = nullptr;
    }

    // adiciona um novo no na arvore
    void add(T key, Pessoa *pessoa)
    {
        root = _add(root, key, pessoa);
    }

    // remove um no da arvore
    void remove(T key)
    {
        root = _remove(root, key);
    }

    // remove todos os nos da arvore
    void clear()
    {
        root = _clear(root);
    }

    void bshow() const
    {
        _bshow(root, "");
    }

    // destrutor
    ~AVL_tree()
    {
        clear();
    }

    // acessa as chaves do nó em ordem
    void access_keys_inorder(void (*f)(int &key))
    {
        inorder_rec(root, f);
    }

    void keys_as_vector(std::vector<int> &v) const
    {
        inorder_rec(root, v);
    }

    void _vector_to_tree(std::vector<T> v)
    {
        root =  vector_to_tree_rec(v, 0, v.size() - 1);
    }

private:
    //* Atributos
    // raiz da arvore
    Node<T> *root;

    //* Metodos
    // retorna a altura de um no
    int height(Node<T> *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    // retorna o fator de balanceamento de um no
    int balance(Node<T> *node)
    {
        return height(node->right) - height(node->left);
    }

    // rotacao a direita
    Node<T> *rightRotation(Node<T> *p)
    {
        Node<T> *u = p->left;
        p->left = u->right;
        u->right = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->left), height(p->right));
        u->height = 1 + std::max(height(u->left), height(u->right));
        return u;
    }

    // rotacao a esquerda
    Node<T> *leftRotation(Node<T> *p)
    {
        Node<T> *u = p->right;
        p->right = u->left;
        u->left = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->right), height(p->left));
        u->height = 1 + std::max(height(u->left), height(u->right));
        return u;
    }

    // balancea o nó
    Node<T> *fixup_node(Node<T> *p, T key)
    {
        // recalcula a altura de p
        p->height = 1 + std::max(height(p->left), height(p->right));

        // calcula o balanço do p
        int bal = balance(p);

        if (bal >= -1 && bal <= 1)
        {
            return p;
        }

        if (bal < -1 && key < p->left->key)
        {
            p = rightRotation(p);
        }
        else if (bal < -1 && key > p->left->key)
        {
            p->left = leftRotation(p->left);
            p = rightRotation(p);
        }
        else if (bal > 1 && key > p->right->key)
        {
            p = leftRotation(p);
        }
        else if (bal > 1 && key < p->right->key)
        {
            p->right = rightRotation(p->right);
            p = leftRotation(p);
        }
        return p;
    }

    // balancea a arvore com o nó retirado
    Node<T> *fixup_deletion(Node<T> *node)
    {
        node->height = 1 + std::max(height(node->left), height(node->right));

        int bal = balance(node);

        // node pode estar desregulado, ha 4 casos a considerar
        if (bal > 1 && balance(node->right) >= 0)
        {
            return leftRotation(node);
        }
        else if (bal > 1 && balance(node->right) < 0)
        {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
        else if (bal < -1 && balance(node->left) <= 0)
        {
            return rightRotation(node);
        }
        else if (bal < -1 && balance(node->left) > 0)
        {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        return node;
    }

    // remove sucessor
    Node<T> *remove_successor(Node<T> *root, Node<T> *node)
    {
        if (node->left != nullptr)
            node->left = remove_successor(root, node->left);
        else
        {
            root->key = node->key;
            Node<T> *aux = node->right;
            delete node;
            return aux;
        }
        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node);
        return node;
    }

    //* Funções recursivas para adicionar, mostrar ,remover
    //* e limpar a arvore

    // adiciona um novo no na arvore recursivamente
    Node<T> *_add(Node<T> *p, T key, Pessoa *pessoa)
    {
        if (p == nullptr)
        {
            Node<T> *new_node = new Node<T>();
            new_node->key = key;
            new_node->pessoa = pessoa;
            new_node->height = 1;
            new_node->left = nullptr;
            new_node->right = nullptr;
            return new_node;
        }

        if (key == p->key)
        {
            return p;
        }

        if (key < p->key)
            p->left = _add(p->left, key, pessoa);
        else
            p->right = _add(p->right, key, pessoa);

        p = fixup_node(p, key);
        return p;
    }

    // mostra a arvore recursivamente
    void _bshow(Node<T> *node, std::string heranca) const
    {
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->right, heranca + "r");
        for (int i = 0; i < (int)heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if (heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if (node == nullptr)
        {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << node->key;
        std::cout << std::endl;
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->left, heranca + "l");
    }

    // remove um no da arvore recursivamente
    Node<T> *_remove(Node<T> *node, T key)
    {
        if (node == nullptr) // node nao encontrado
            return nullptr;  /*L\pauseL*/
        if (key < node->key)
            node->left = _remove(node->left, key);
        else if (key > node->key)
            node->right = _remove(node->right, key); /*L\pauseL*/
        // encontramos no node
        else if (node->right == nullptr)
        { // sem filho direito
            Node<T> *child = node->left;
            delete node;
            return child;
        }
        else                                                   // tem filho direito: troca pelo sucessor
            node->right = remove_successor(node, node->right); /*L\pauseL*/

        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node);
        return node;
    }

    // remove todos os nos da arvore recursivamente
    Node<T> *_clear(Node<T> *node)
    {

        if (node != nullptr)
        {
            node->next = _clear(node->next);
            node->left = _clear(node->left);
            node->right = _clear(node->right);
            delete node;
        }
        return nullptr;
    }

    void inorder_rec(Node<T> *node, void (*f)(int &key))
    {
        if (node != nullptr)
        {
            inorder_rec(node->left, f);
            f(node->key);
            inorder_rec(node->right, f);
        }
    }

    void inorder_rec(Node<T> *node, std::vector<int> &v)
    {
        if (node != nullptr)
        {
            inorder_rec(node->left, v);
            v.push_back(node->key);
            inorder_rec(node->right, v);
        }
    }

    //? cria as árvores, entretanto não trata os nós iguais
    Node<T> * vector_to_tree_rec(std::vector<T> &v, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Node<T> *node = new Node<T>();
        node->key = v[mid];
        node->left = vector_to_tree_rec(v, start, mid - 1);
        node->right = vector_to_tree_rec(v, mid + 1, end);
        node->height = 1 + std::max(height(node->left), height(node->right));
        return node;
    }

    /*Node<T> * vector_to_tree_rec(std::vector<T> &v, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Node<T> *node = new Node<T>();
        node->key = v[mid];
        node->left = vector_to_tree_rec(v, start, mid - 1);
        node->right = vector_to_tree_rec(v, mid + 1, end);
        node->height = 1 + std::max(height(node->left), height(node->right));

        // Procura por um nó com a mesma chave e anexa ao ponteiro next, caso exista
        Node<T> *current = node;
        while(v[mid+1] == v[mid]){
            while (current != nullptr) {
                if (current->key == node->key && current != node) {
                    current->next = node;
                    break;
                }
                if (current->key > node->key) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }

        return node;
    }*/


    /*void TrataArvore(Node<T> *node)
    {
    }*/
};

#endif
