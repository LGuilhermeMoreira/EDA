#include "avl.h"
#include "functions.h"
#include "cpf.h"
#include "data.h"
#include "nome.h"
#include "AVLtreeFunctions.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// montar o sistema de busca 
int main()
{
    AVL_tree<CPF>* cpf_tree = build_tree_cpf(string_to_vector("data.csv"));
    AVL_tree<Nome>* nome_tree = build_tree_nome(string_to_vector("data.csv"));
    AVL_tree<Data>* data_tree = build_tree_data(string_to_vector("data.csv"));

    while(true){
        cout << endl << "1 - add person" << endl
            << "2 - remove person" << endl
            << "3 - show cpf_tree" << endl
            << "4 - show nome_tree" << endl
            << "5 - show data_tree" << endl
            << "6 - search cpf" << endl
            << "7 - search nome" << endl
            << "8 - search data" << endl
            << "9 - exit" << endl << endl;

        int num;
        cin >> num;
        cin.ignore();

        if(num == 9) break;

        else if(num == 1){
            //criar uma pessoa
            string cpf, nome, sobrenome, nascimento, endereco;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cout << "Digite o nome: ";
            getline(cin, nome);
            cout << "Digite o sobrenome: ";
            getline(cin, sobrenome);
            cout << "Digite a data de nascimento: ";
            getline(cin, nascimento);
            cout << "Digite o endereco: ";
            getline(cin, endereco);
            Pessoa* pessoa = new Pessoa(cpf, nome, sobrenome, nascimento, endereco);
            //adicionar a pessoa nas 3 arvores
            cpf_tree->add(pessoa->cpf, pessoa);
            nome_tree->add(pessoa->nome, pessoa);
            data_tree->add(pessoa->nascimento, pessoa);
        }

        else if(num == 2){
            string cpf, nome, sobrenome, nascimento;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cout << "Digite o nome: ";
            getline(cin, nome);
            cout << "Digite o sobrenome: ";
            getline(cin, sobrenome);
            cout << "Digite a data de nascimento: ";
            getline(cin, nascimento);
            //remove das arvores
            cpf_tree->remove(CPF(cpf));
            nome_tree->remove(Nome(nome + " " + sobrenome));
            data_tree->remove(Data(nascimento));
        }

        else if(num == 3){
            cpf_tree->bshow();
        }

        else if(num == 4){
            nome_tree->bshow();
        }

        else if(num == 5){
            data_tree->bshow();
        }

        else if(num == 6){
            string cpf;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cpf_tree->search(cpf,'c');
            std::cout << "=======================================" << std::endl;
        }

        else if(num == 7){
            string nomeCompleto;
            cout << "Digite o nome: ";
            getline(cin, nomeCompleto);
            nome_tree->search(nomeCompleto,'n');
            std::cout << "=======================================" << std::endl;
        }

        else if(num == 8){
            string datainicio, datafim;
            cout << "Digite a data de inicio: ";
            getline(cin, datainicio);
            cout << "Digite a data de fim: ";
            getline(cin, datafim);
            data_tree->search(datainicio + " " + datafim, 'd');
            std::cout << "=======================================" << std::endl;
        }

        else cout << "Comando invalido" << endl;

    }
}