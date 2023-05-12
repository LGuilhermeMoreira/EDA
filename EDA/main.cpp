#include "avl.h"
#include "functions.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include "AVLtreeFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<Pessoa*> v = string_to_vector("data.csv");
   AVL_tree<CPF>* tree_data = build_tree_cpf(v);
   tree_data->bshow();
}