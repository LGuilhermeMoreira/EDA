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
  AVL_tree<Nome>* tree = build_tree_nome(string_to_vector("data.csv"));

  tree->bshow();
}