#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/******************************
 * Definicao do struct Node
 ******************************/
struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;

    // Construtor
    Node(int k, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
        this->parent = p;
    }
    // Destrutor
    ~Node() {
        cout << "Node removed: " << this->key << endl;
    }
};

/***********************************
 * Declaracao da classe
 ***********************************/
class BST {
public:
    BST();
    BST(int k);
    void bshow();
    bool add(int k);
    void preorder();  // --> Implementar
    void inorder();   // --> Implementar
    void clear();     // --> Implementar
    ~BST();
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
};

/***********************************
 * Implementacao da classe
 ***********************************/
BST::BST() {
    root = nullptr;
}
 
BST::BST(int k) {
    root = new Node(k);
}

void BST::bshow(){
    bshow(root, "");
}

void BST::bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heranca + "l");
}

BST::~BST() {
    clear();
}

// Funcao publica 'add'
// Esta funcao deve obrigatoriamente ser iterativa.
// Esta funcao adiciona um no com chave k na arvore e: 
// (1) devolve true em caso de sucesso;
// (2) devolve false caso contrario.
// Lembre-se que nao podem haver chaves repetidas na nossa arvore.
bool BST::add(int k) {
   if (root == nullptr) { // Se a árvore estiver vazia, insere o nó como raiz
        root = new Node(k);
        return true;
    }
    
    if(root->key == k){
        return false;
    }

    Node* aux = root;
    Node* parent = nullptr;
    
    // esse laço deixa o aux em nullptr e parent para o no pai
    while (aux != nullptr) {
       parent = aux;
       
       if(k > aux->key) aux = aux->right;
       else if(k < aux->key) aux = aux->left;
       else return false;
       
    }

    Node* newNode = new Node(k,nullptr,nullptr,parent);
    
    if(newNode->key > parent->key) parent->right = newNode;
    else parent->left = newNode;
    
    return true;
}

// Funcao publica 'preorder'
// Percorre os nos da arvore em pre-ordem imprimindo os 
// valores das chaves. Dica: use a estrutura de dados pilha (stack)
// lembrando que existe um ponteiro para o pai do nó
void BST::preorder() {
    Node *aux = root;
    std::stack<Node*> p;
    //p.push(aux);
    while(aux != nullptr || !p.empty()) {
        
        while(aux != nullptr) {
            cout << aux->key << " ";
            p.push(aux);
            aux = aux->left;
        }
        
        aux = p.top();
        p.pop();
        aux = aux->right;
    }
}


// Funcao publica 'inorder'
// Percorre os nos da arvore em ordem simetrica imprimindo os 
// valores das chaves. Dica: use a estrutura de dados pilha (stack)

void BST::inorder() {
    if (root == nullptr) {

        return;
    }

    stack<Node*> p; 
    Node* aux = root;

    while (aux != nullptr || !p.empty()) {
        
        while (aux != nullptr) {
            p.push(aux);
            aux = aux->left;
        }

        
        aux = p.top();
        p.pop();
        cout << aux->key << " ";

       
        aux = aux->right;
    }

    //cout << endl;
}

// Funcao publica 'clear'
// Libera todos os nos da arvore deixando ela vazia.
// Dica: use a estrutura de dados pilha (stack)

void BST::clear() {
   if (root == nullptr) return;


    stack<Node*> p; 
    Node* aux = root;

    while (aux != nullptr || !p.empty()) {
        
        while (aux != nullptr) {
            p.push(aux);
            aux = aux->left;
        }

        
        aux = p.top();
        p.pop();
        Node* newNodeDelete = aux;
        delete aux;
        aux = newNodeDelete;
        aux = aux->right;

       
    }
    
    root = nullptr;

    //cout << endl;
    
}

#endif 