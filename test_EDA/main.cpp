#include "avl.h"
#include "functions.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include "AVLtreeFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

// montar o sistema de busca 
int main()
{
    //system.cls("")
    AVL_tree<Nome>* Nome_tree = build_tree_nome(string_to_vector("data.csv"));
    Nome_tree->search(Nome("Ju"),'n');
}