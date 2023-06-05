#ifndef AVL_H
#define AVL_H

#include "node.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include "pessoa.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
    
    //Mostra todos os nós da arvore
    void bshow() const
    {
        _bshow(root, "");
    }

    // destrutor
    ~AVL_tree()
    {
        clear();
    }

    // busca os nós de uma arvore
    void search(std::string key, char flag)
    {
        // busca por cpf
        if (flag == 'c')
        {
            //crio o objeto nó
            T cpf = T(key);
            Node<T> *node = root;
            //percorro a arvore ate achar um nó que contenha o objeto criado e printa ele
            while (node != nullptr)
            {
                if (node->key == key)
                {
                    node->pessoa->print();
                    Node<T> *aux = node->next;
                    while (aux != nullptr)
                    {
                        aux->pessoa->print();
                        aux = aux->next;
                    }
                    return;
                }
                else if (node->key > key)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
        // busca entre datas
        else if (flag == 'd')
        {
            std::vector<std::string> data = split(key, ' ');
            // criando o intervalo de datas
            T initial = T(data[0]);
            T final = T(data[1]);
            Node<T> *node = root;
            std::stack<Node<T> *> pilha;
            pilha.push(node);
            // percorrendo pra dentro do intervalo das datas
            while (!pilha.empty())
            {
                Node<T> *reference = pilha.top();
                pilha.pop();

                if (reference != nullptr)
                {
                    if (reference->key < initial)
                    {
                        pilha.push(reference->right);
                    }
                    else if (reference->key > final)
                    {
                        pilha.push(reference->left);
                    }
                    else
                    {
                        if (reference->key == initial)
                        {
                            reference->pessoa->print();
                            if(reference->next != nullptr){
                                Node <T> * aux  = reference->next;
                                while(aux != nullptr){
                                    aux->pessoa->print();
                                    aux = aux->next;
                                }
                            }
                            pilha.push(reference->right);
                        }
                        else if (reference->key == final)
                        {
                            reference->pessoa->print();
                            if(reference->next != nullptr){
                                Node <T> * aux  = reference->next;
                                while(aux != nullptr){
                                    aux->pessoa->print();
                                    aux = aux->next;
                                }
                            }
                            pilha.push(reference->left);
                        }
                        else
                        {
                            reference->pessoa->print();
                            if(reference->next != nullptr){
                                Node <T> * aux  = reference->next;
                                while(aux != nullptr){
                                    aux->pessoa->print();
                                    aux = aux->next;
                                }
                            }
                            pilha.push(reference->left);
                            pilha.push(reference->right);
                        }
                    }
                }
            }
        }

        else if (flag == 'n')
        {
            //busca por nomes
            /*Percorrer até o nó aceitavel e dps usa uma inorder para percorrer a sub arvore*/
            T nome = T(key);
            Node<T> *node = root;
            while (node != nullptr)
            {
                if (nome == node->key)
                {
                    inorder_rec(node, nome);
                    break;
                }
                else if (node->key > nome)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
        else if(flag == 'e'){
            // busca por uma data especifica
            // cria o obejto 
            T data = T(key);
            Node<T>* node = root;
            // pesquisa por ele na arvore
            while(node != nullptr){
                if (data == node->key)
                {
                    node->pessoa->print();
                    if(node->next != nullptr){
                        Node <T> * aux  = node->next;
                        while(aux != nullptr){
                            aux->pessoa->print();
                            aux = aux->next;
                        }
                    }
                    break;
                }
                else if (node->key > data)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
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
            if(p->next != nullptr){
                Node<T>* aux = p->next;
                while (aux->next != nullptr)
                {
                    aux = aux->next;
                }
                Node<T> *new_node = new Node<T>();
                new_node->key = key;
                new_node->pessoa = pessoa;
                new_node->height = p->height;
                new_node->left = nullptr;
                new_node->right = nullptr;
                aux->next = new_node;
                return p;
            }else{
                Node<T> *new_node = new Node<T>();
                new_node->key = key;
                new_node->pessoa = pessoa;
                new_node->height = p->height;
                new_node->left = nullptr;
                new_node->right = nullptr;
                p->next = new_node;
                return p;
            }
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
        if (node->next != nullptr)
        {
            Node<T> *aux = node->next;
            int cont = 1;
            while (aux != nullptr)
            {
                cont++;
                aux = aux->next;
            }
            std::cout << " (" << cont << "x)";
        }
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

    // função criada para printar todos os nomes de acordo com uma substring
    //essa funcão segue uma sequencia inorder da arvore
    void inorder_rec(Node<T> *node, T key)
    {
        if (node != nullptr)
        {
            inorder_rec(node->left, key);
            if (key == node->key)
            {
                node->pessoa->print();

                if (node->next != nullptr)
                {
                    Node<T> *aux = node->next;
                    while (aux != nullptr)
                    {
                        aux->pessoa->print();
                        aux = aux->next;
                    }
                }
            }
            inorder_rec(node->right, key);
        }
    }
};

#endif
