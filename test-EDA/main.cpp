#include "avl.h"
#include "functions.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include <iostream>
#include <vector>
using namespace std;

// função ta certa
vector<Pessoa*> string_to_vector(string path){
    vector<Pessoa*> v;
    //passo 1: ler arquivo
    string file = file_to_string(path);
    //passo 2: separar as linhas
    vector<string> lines = split(file, '\n');
    //passo 3: separar as palavras por virgula
    for(int i = 0; i < lines.size(); i++){
        vector<string> words = split(lines[i], ',');
        //passo 4: criar um objeto pessoa
        for(int j = 0; j < words.size(); j++){
            Pessoa* p = new Pessoa(words[0], words[1], words[2], words[3], words[4]);
            v.push_back(p);
        }
    }
    return v;
}

AVL_tree<CPF>* build_tree_cpf(vector<Pessoa*> v){
    AVL_tree<CPF>* tree = new AVL_tree<CPF>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->cpf, v[i]);
    }
    return tree;
}

AVL_tree<Data>* build_tree_data(vector<Pessoa*> v){
    AVL_tree<Data>* tree = new AVL_tree<Data>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->nascimento, v[i]);
    }
    return tree;
}

AVL_tree<Nome>* build_tree_nome(vector<Pessoa*> v){
    AVL_tree<Nome>* tree = new AVL_tree<Nome>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->nome, v[i]);
    }
    return tree;
}




int main()
{
    vector<Pessoa*> v = string_to_vector("data.csv");

    for(int i = 0; i < v.size(); i++){
        cout << v[i]->nome << endl;
        cout << v[i]->cpf << endl;
    }
}