
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

// Estrutura para representar um ator
struct Actor {
    string name;// Nome do ator
    vector<string> movies; //vetor de filmes que o ator participou
    int baconNumber; // Número de Bacon
    string baconMovie; // Filme que conecta o ator a Kevin Bacon
};

// Função para dividir uma string com base em um delimitador
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

// Função para ler o arquivo de entrada e construir a lista de adjacência (simulando um grafo)
unordered_map<string, Actor> buildList(const string& filename) {
    unordered_map<string, Actor> listAdjacency;
    ifstream inputFile(filename);
    string line;

    while (getline(inputFile, line)) {
        vector<string> parts = split(line, ';');

        if (parts.size() == 3) {
            string ator1 = parts[0];
            string film = parts[1];
            string ator2 = parts[2];

            // Adicionar o ator 1 à lista de adjacência
            if (listAdjacency.find(ator1) == listAdjacency.end()) {
                Actor novoAtor;
                novoAtor.name = ator1;
                // inicialmente, definido como -1 para indicar não visitado
                novoAtor.baconNumber = -1; 
                listAdjacency[ator1] = novoAtor;
            }

            // Adicionar o ator 2 à lista de adjacência
            if (listAdjacency.find(ator2) == listAdjacency.end()) {
                Actor novoAtor;
                novoAtor.name = ator2;
                novoAtor.baconNumber = -1;
                listAdjacency[ator2] = novoAtor;
            }

            // Adicionar o filme à lista de filmes do ator 1
            listAdjacency[ator1].movies.push_back(film);

            // Adicionar o filme à lista de filmes do ator 2
            listAdjacency[ator2].movies.push_back(film);
        }
    }

    inputFile.close();
    return listAdjacency;
}


/*
Essa função utiliza uma busca em largura para calcular o valor de cada ator
*/
void calculaNumeroBacon(unordered_map<string, Actor>& listadjacency, const string& startActor) {
    // Definir o ator inicial como número de Bacon 0
    listadjacency[startActor].baconNumber = 0;
    listadjacency[startActor].baconMovie = "";

    // Utilizar busca em largura para calcular o número de Bacon para cada ator
    queue<string> actorQueue;
    actorQueue.push(startActor);

    while (!actorQueue.empty()) {
        string currentActor = actorQueue.front();
        actorQueue.pop();

        const Actor& actor = listadjacency[currentActor];
        int currentBaconNumber = actor.baconNumber + 1;

        for (const string& movie : actor.movies) {
            for (const auto& pair : listadjacency) {
                const string& coActor = pair.first;
                if (coActor != currentActor && find(listadjacency[coActor].movies.begin(), listadjacency[coActor].movies.end(), movie) != listadjacency[coActor].movies.end()) {
                    // Verificar se o ator já foi visitado ou se é a primeira vez que está sendo visitado
                    if (listadjacency[coActor].baconNumber == -1) {
                        listadjacency[coActor].baconNumber = currentBaconNumber;
                        listadjacency[coActor].baconMovie = movie;
                        actorQueue.push(coActor);
                    }
                }
            }
        }
    }
}


// Função para imprimir a saída
void print(const unordered_map<string, Actor>& adjacencyList) {
    set<string> actors; // Usando um conjunto para manter os nomes dos atores em ordem alfabética

    // Adicionar todos os atores à lista
    for (const auto& pair : adjacencyList) {
        actors.insert(pair.first);
    }

    // Imprimir o número de Bacon para cada ator
    for (const string& actor : actors) {
        const Actor& currentActor = adjacencyList.at(actor);
        cout << "O numero de Bacon de " << currentActor.name << " é " << currentActor.baconNumber;
        cout << " pelo filme " << currentActor.baconMovie << endl;
    }
}

int main() {
    string filename ; // Nome do arquivo de entrada
    cout << "Digite o nome do arquivo de entrada: ";
    getline(cin, filename);
    //filename = "input-output/input.txt";
    // Construir a lista de adjacência
    unordered_map<string, Actor> List = buildList(filename);

    string startActor = "Kevin Bacon"; // Ator a partir do qual será calculado o número de Bacon

    // Calcular o número de Bacon para cada ator
    calculaNumeroBacon(List, startActor);

    // Imprimir a saída
    print(List);

    return 0;
}
