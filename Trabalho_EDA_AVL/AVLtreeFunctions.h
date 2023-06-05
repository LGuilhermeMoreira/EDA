#ifndef AVL_TREE_FUNCTIONS_H
#define AVL_TREE_FUNCTIONS_H

#include "functions.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include "pessoa.h"
#include "avl.h"
#include <iostream>
#include <vector>
using namespace std;

//Arquivo destinado a criação das arvores e funções para auxiliar na criação das mesmas

vector<Pessoa*> string_to_vector(string path){
   vector<Pessoa*> v;
    //passo 1: ler arquivo
    string file = file_to_string(path);
    //passo 2: separar as linhas
    vector<string> lines = split(file, '\n');
    //passo 3: separar as palavras por virgula
    for(int i = 0; i < lines.size(); i++){
        //cout << "linha: " << lines[i] << endl;
        vector<string> words = split(lines[i], ',');
        //passo 4: criar um objeto pessoa
         Pessoa* p = new Pessoa(words[0], words[1], words[2], words[3], words[4]);
        //passo 5: adicionar o objeto pessoa no vetor
        v.push_back(p);
    }
    return v;
}

// construindo uma arvore de CPF de acordo com um vector de pessoas
AVL_tree<CPF>* build_tree_cpf(vector<Pessoa*> v){
    AVL_tree<CPF>* tree = new AVL_tree<CPF>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->cpf, v[i]);
    }
    return tree;
}

// construindo uma arvore de Data de acordo com um vector de pessoas
AVL_tree<Data>* build_tree_data(vector<Pessoa*> v){
    AVL_tree<Data>* tree = new AVL_tree<Data>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->nascimento, v[i]);
    }
    return tree;
}

// construindo uma arvore de Nome de acordo com um vector de pessoas
AVL_tree<Nome>* build_tree_nome(vector<Pessoa*> v){
    AVL_tree<Nome>* tree = new AVL_tree<Nome>();
    for(int i = 0; i < v.size(); i++){
        tree->add(v[i]->nome, v[i]);
    }
    return tree;
}

#endif