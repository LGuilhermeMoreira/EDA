#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

/*****************************
 * Definicao do struct Node
 *****************************/
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

/************************
 * Declaracao da classe
 ************************/
class BST {
public:
    BST();
    BST(int k);
    void bshow();
    bool add(int k);
    int minimum();           // ---> Implementar
    int maximum();           // ---> Implementar
    int predecessor(int k);  // ---> Implementar
    int successor(int k);    // ---> Implementar
    ~BST();
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *minimum(Node *node);       // ---> Implementar
    Node *maximum(Node *node);       // ---> Implementar
    Node *successor(Node *node);     // ---> Implementar
    Node *predecessor(Node *node);     // ---> Implementar
    Node *clear(Node *node);
    Node *search(int k);
};

/*****************************
 * Implementacao da classe
 *****************************/
// Construtor 
BST::BST() {
    root = nullptr;
}

// Construtor 
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

Node *BST::clear(Node *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

BST::~BST() {
    root = clear(root);
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


// Funcao privada 'search'
// Esta funcao devolve o ponteiro para o no que 
// contem a chave k se ela existir na arvore;
// caso contrario, devolve nullptr;
Node *BST::search(int k) {
    Node *aux =root; 
    if(aux->key == k) return aux;
    
    while(aux != nullptr){
        if(aux->key == k) return aux;
        else if(k > aux->key) aux = aux->right;
        else aux = aux->left;
    }
    
    return nullptr;
}


// Funcao publica (obrigatoriamente iterativa)
// Devolve o menor valor de chave da arvore.
int BST::minimum() {
    Node* aux = root;
    Node* parent = nullptr;
    
    // esse laço deixa o aux em nullptr e parent para o no pai
    while (aux != nullptr) {
       parent = aux;
       aux = aux->left;
       
    }
    
    return parent->key;
}

// Funcao privada (obrigatoriamente iterativa)
// Recebe como argumento o ponteiro para a raiz de uma arvore
// e devolve o ponteiro para o no com a menor chave na arvore.
// Se a arvore for vazia, devolve nullptr
Node *BST::minimum(Node *node) {
    Node* aux = root;
    if(aux == nullptr) return aux;
    Node* parent = nullptr;
    
    // esse laço deixa o aux em nullptr e parent para o no pai
    while (aux != nullptr) {
       parent = aux;
       aux = aux->left;
       
    }
    
    return parent;
}

// Funcao publica (obrigatoriamente iterativa)
// Devolve o maior valor de chave da arvore
int BST::maximum() {
    Node* aux = root;
    Node* parent = nullptr;
    
    // esse laço deixa o aux em nullptr e parent para o no pai
    while (aux != nullptr) {
       parent = aux;
       aux = aux->right;
    }
    
    return parent->key;
}

// Funcao privada (obrigatoriamente iterativa)
// Recebe como argumento o ponteiro para a raiz de uma arvore
// e devolve o ponteiro para o no com a maior chave na arvore.
// Se a arvore for vazia, devolve nullptr
Node *BST::maximum(Node *node) {
     Node* aux = root;
    if(aux == nullptr) return aux;
    Node* parent = nullptr;
    
    // esse laço deixa o aux em nullptr e parent para o no pai
    while (aux != nullptr) {
       parent = aux;
       aux = aux->right;
       
    }
    
    return parent;
}

// Funcao publica (obrigatoriamente iterativa)
// Recebe um inteiro k como argumento e:
// (1) devolve INT_MAX se a chave k nao esta presente na arvore ou 
// se k esta presente na arvore mas nao tem sucessor
// (2) caso contrario, devolve o valor inteiro da 
// chave sucessora de k quando esta existe
int BST::successor(int k) {
   if (root == nullptr) return INT_MAX; 
    Node* current = root;
    Node* successor = nullptr; 
    while (current != nullptr) {
        if(current->key > k) {
            successor = current; 
            current = current->left; 
        } 
        else if(current->key < k) {
            current = current->right; 
        }
        else{
            if(current->right != nullptr) {
                
                current = current->right;
                while (current->left != nullptr) {
                    current = current->left;
                }
                return current->key;
            } 
            else{
               
                if(successor != nullptr) {
                    return successor->key;
                } 
                else return INT_MAX; 
            }
        }
    }
    return INT_MAX; 
}

// Funcao privada (obrigatoriamente iterativa)
// Recebe um ponteiro para um Node e:
// (1) devolve nullptr quando node nao tem sucessor; ou
// (2) caso contrario, devolve o ponteiro para o no sucessor de node.
Node *BST::successor(Node *node) {
    if (root == nullptr) return root; 
    Node* aux = root;
    Node* parent = nullptr; 
    while (aux != nullptr){
        if (aux->key > node->key){
            parent = aux; 
            aux = aux->left; 
        } else if (aux->key < node->key) aux = aux->right; 
         
        else {
            if (aux->right != nullptr){
                
                aux = aux->right;
                while (aux->left != nullptr){
                    aux = aux->left;
                }
                return aux;
            } 
            else{
               
                if (parent != nullptr) return parent;
                 
                else{
                    return nullptr; 
                }
            }
        }
    }
    return nullptr; 
}

// Funcao publica (obrigatoriamente iterativa)
// Recebe um inteiro k como argumento e:
// (1) devolve INT_MIN se a chave k nao esta presente na arvore ou 
// se k esta presente na arvore mas nao tem antecessor;
// (2) caso contrario, devolve o valor inteiro da chave 
// antecessora de k quando esta existe.
int BST::predecessor(int k) {
    Node* aux = root;
    int parents = INT_MIN; // Inicializa o antecessor com o valor mínimo possível de inteiros

    while (aux != nullptr) {
        //caso tenha encontrado o nó
        if (k == aux->key){
            if (aux->left != nullptr) {
                aux = aux->left;
                while (aux->right != nullptr) {
                    aux = aux->right;
                }
                return aux->key;
            } 
            else return parents;
        } 
        // perconrrendo a arvore até achar o nó
        else if (k < aux->key) aux = aux->left;
        // perconrrendo a arvore até achar o nó
        else{
            parents = aux->key;
            aux = aux->right;
        }
    }
    //caso não ache
    return INT_MIN;
}

// Funcao privada (obrigatoriamente iterativa)
// Recebe um ponteiro para um Node e:
// (1) devolve nullptr quando node nao tem antecessor; ou
// (2) caso contrario, devolve o ponteiro para o no antecessor de node.
Node *BST::predecessor(Node *node) {
    //caso seja nulo
    if (node == nullptr) {
        return nullptr; 
    }

    //se o no tem filho a esquerda
    if (node->left != nullptr) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // se o no tem filho a direita
    Node* aux = nullptr;
    Node* parent = root;
    while (parent != nullptr) {
        if (node->key == parent->key) {
            break; // Encontramos o nó, podemos parar a busca
        } else if (node->key < parent->key) {
            parent = parent->left; // Vamos para a subárvore esquerda
        } else {
            aux = parent; // Atualiza o antecessor para o nó atual
            parent = parent->right; // Vamos para a subárvore direita
        }
    }
    return aux;
}

#endif 