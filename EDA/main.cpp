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
    AVL_tree<CPF>* cpf_tree = build_tree_cpf(string_to_vector("dataPeople.csv"));
    AVL_tree<Nome>* nome_tree = build_tree_nome(string_to_vector("dataPeople.csv"));
    AVL_tree<Data>* data_tree = build_tree_data(string_to_vector("dataPeople.csv"));
    system("cls||clear");
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
            system("cls||clear");
            string cpf, nome, sobrenome, endereco;
            int dia, mes, ano;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cout << "Digite o nome: ";
            getline(cin, nome);
            cout << "Digite o sobrenome: ";
            getline(cin, sobrenome);
            cout << "Digite o dia de nascimento: ";
            cin >> dia;
            cin.ignore();
            cout << "Digite o mes de nascimento: ";
            cin >> mes;
            cin.ignore();
            cout << "Digite o ano de nascimento: ";
            cin >> ano;
            cin.ignore();
            string nascimento = to_string(mes) + "/" + to_string(dia) + "/" + to_string(ano);
            cout << "Digite a cidade: ";
            getline(cin, endereco);
            Pessoa* pessoa = new Pessoa(cpf, nome, sobrenome, nascimento, endereco);
            //adicionar a pessoa nas 3 arvores
            cpf_tree->add(pessoa->cpf, pessoa);
            nome_tree->add(pessoa->nome, pessoa);
            data_tree->add(pessoa->nascimento, pessoa);
        }

        else if(num == 2){
            system("cls||clear");
            string cpf, nome, sobrenome;
            int dia, mes, ano;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cout << "Digite o nome: ";
            getline(cin, nome);
            cout << "Digite o sobrenome: ";
            getline(cin, sobrenome);
             cout << "Digite o dia de nascimento: ";
            cin >> dia;
            cin.ignore();
            cout << "Digite o mes de nascimento: ";
            cin >> mes;
            cin.ignore();
            cout << "Digite o ano de nascimento: ";
            cin >> ano;
            cin.ignore();
            string nascimento = to_string(mes) + "/" + to_string(dia) + "/" + to_string(ano);
            //remove das arvores
            cpf_tree->remove(CPF(cpf));
            nome_tree->remove(Nome(nome + " " + sobrenome));
            data_tree->remove(Data(nascimento));
        }

        else if(num == 3){
            system("cls||clear");
            cpf_tree->bshow();
        }

        else if(num == 4){
            system("cls||clear");
            nome_tree->bshow();
        }

        else if(num == 5){
            system("cls||clear");
            data_tree->bshow();
        }

        else if(num == 6){
            system("cls||clear");
            string cpf;
            cout << "Digite o CPF: ";
            getline(cin, cpf);
            cpf_tree->search(cpf,'c');
            std::cout << "=======================================" << std::endl;
        }

        else if(num == 7){
            system("cls||clear");
            string nomeCompleto;
            cout << "Digite o nome: ";
            getline(cin, nomeCompleto);
            nome_tree->search(nomeCompleto,'n');
            std::cout << "=======================================" << std::endl;
        }

        else if(num == 8){
            system("cls||clear");
            int diaini, mesini, anoini;
            int diafim, mesfim, anofim;
            cout << "Digite o dia inicial: ";
            cin >> diaini;
            cin.ignore();
            cout << "Digite o mes inicial: ";
            cin >> mesini;
            cin.ignore();
            cout << "Digite o ano inicial: ";
            cin >> anoini;
            cin.ignore();
            cout << "Digite o dia final: ";
            cin >> diafim;
            cin.ignore();
            cout << "Digite o mes final: ";
            cin >> mesfim;
            cin.ignore();
            cout << "Digite o ano final: ";
            cin >> anofim;
            cin.ignore();
            string dataini = to_string(mesini) + "/" + to_string(diaini) + "/" + to_string(anoini);
            string datafim = to_string(mesfim) + "/" + to_string(diafim) + "/" + to_string(anofim);
            string stringData = dataini + " " + datafim;
            data_tree->search(stringData,'d');
            std::cout << "=======================================" << std::endl;
        }

        else cout << "Comando invalido" << endl;

    }
}