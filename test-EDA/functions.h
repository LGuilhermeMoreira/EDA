#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include "pessoa.h"
#include "avl.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"

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
    ss << "\n";
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
#endif