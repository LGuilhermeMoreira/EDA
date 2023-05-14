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
   vector<CPF> v = string_to_cpf("data.csv");
   cout << cpf_in_vector(v, CPF("388.624.732-57")) << endl;
}