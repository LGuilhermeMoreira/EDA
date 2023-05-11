#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "pessoa.h"
#include "avl.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

// lê o arquivo csv e transforma em uma string
string file_to_string(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

//divide a string de acordo com o delimitador e retorna uma lista dividida
vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

/*
vector<Pessoa*> string_to_vector(string path){
    //lendo o arquivo
    string file = file_to_string(path);
    //dividindo o arquivo em linhas
    vector<string> allPeople = split(file, '\n');
    //dividindo as linhas em "colunas"
    vector<string> lineAllPeople;
    vector<Pessoa*> pessoas;
    for (int i = 0; i < allPeople.size(); i++){
        lineAllPeople = split(allPeople[i], ',');
        Pessoa *pessoa = new Pessoa(lineAllPeople[0], lineAllPeople[1], lineAllPeople[2], lineAllPeople[3], lineAllPeople[4]);
        pessoas.push_back(pessoa);
        //delete pessoa; 
    }
    
    return pessoas;
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
        tree->add(v[i]->nome + v[i]->sobrenome, v[i]);
    }
    return tree;
}


*/

#endif