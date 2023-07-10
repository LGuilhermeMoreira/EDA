// IDEIA 4 DE IMPLEMENTAR UM GRAFO
// Ideia falha, pois não consegui implementar o grafo com templates
// estava dando erro de compilação

// #include <set>
// #include <iostream>
// #include "Edge.h"
// #include <fstream>
// #include <sstream>
// #include <string>
// #include "ListGraph.h"
// using namespace std;

// //transforma o conteudo de um arquivo txt em uma string
// string fileToString(const string& path) {
//     auto ss = ostringstream{};
//     ifstream input_file(path);
//     if (!input_file.is_open()) {
//         cerr << "Could not open the file - '"
//              << path << "'" << endl;
//         exit(EXIT_FAILURE);
//     }
//     string line;
//     //getline(input_file, line); // pula a primeira linha
//     ss << input_file.rdbuf();
//     return ss.str();
// }



// //divide a string de acordo com o delimitador e retorna uma lista dividida
// vector<string> split(const string& s, char delimiter)
// {
//    vector<string> tokens;
//    string token;
//    istringstream tokenStream(s);
//    while (getline(tokenStream, token, delimiter))
//    {
//       tokens.push_back(token);
//    }
//    return tokens;
// }

// // Função de printar o grafo
// template <typename T, typename U>
// void print(const ListGraph<T,U>& graph) {
//     for(int i = 0; i < graph.get_num_v(); ++i) {
//         cout << i << ": ";
//         for(auto v = graph.begin(i); v != graph.end(i); ++v) {
//             cout << *v << " ";
//         }
//         cout << endl;
//     }
// }

// // retorna o tamanho do grafo apartir do arquivo
// int getNumVertices(string filename){
//     string file = fileToString(filename);
//     vector<string> lines = split(file, '\n');
//     set<string> vertices;
//     for(int i = 0; i < lines.size(); i++){
//         vector<string> line = split(lines[i],';');
//         vertices.insert(line[0]);
//     }
//     return vertices.size();
// }

// //funcao test
// template <typename T, typename U>
// ListGraph<T,U> readString(string filename){
//     ListGraph<T,U> graph(getNumVertices(filename), false);
//     string file = fileToString(filename);
//     vector<string> lines = split(file, '\n');
//     for(int i = 0; i < lines.size(); i++){
//         vector<string> line = split(lines[i],';');
//         graph.insert(Edge<T,U>(line[0],line[2],line[1]));
//     }
//     return graph;
// }



// int main() {
//      ListGraph<int,int> graph(5,false);
//         graph.insert(Edge<int,int>(1,2,3));
//         // graph.insert(Edge<string,string>("A","C","2"));
//         // graph.insert(Edge<string,string>("A","D","3"));
//     //print(graph);
// }



// IDEIA 5 implementar um lista de adjacencias usando 
/*
class ator{
    nome,
    listaFIlmes
    numerodebacon
    filmequeconecta
}

#ERRADA ??
calculateBaconNumbers(unordered_map<string, Actor>& adjacencyList, const string& startActor) {
    // Definir o ator inicial como número de Bacon 0
    adjacencyList[startActor].baconNumber = 0;
    adjacencyList[startActor].baconMovie = "";

    // Utilizar busca em largura para calcular o número de Bacon para cada ator
    queue<string> actorQueue;
    actorQueue.push(startActor);

    while (!actorQueue.empty()) {
        string currentActor = actorQueue.front();
        actorQueue.pop();

        const Actor& actor = adjacencyList[currentActor];
        int currentBaconNumber = actor.baconNumber + 1;

        for (const string& movie : actor.movies) {
            for (const string& coActor : adjacencyList[currentActor].movies) {
                if (coActor != currentActor && adjacencyList[coActor].baconNumber == -1) {
                    adjacencyList[coActor].baconNumber = currentBaconNumber;
                    adjacencyList[coActor].baconMovie = movie;
                    actorQueue.push(coActor);
                }
            }
        }
    }
}


#PROTOTIPO
void calculaNumero(unoredered_map<string,Actor>& list, string& ator){
    list.[ator].baconNumber = 0;
    list.[ator].baconMovie = "";

    queue<string> filaAtores;
    filaAtores.push(ator);

    while(!filaAtores.empty()){
        string atorAtual = filaAtores.front();
        filaAtores.pop();
    
        Actor& ator1 = list[atorAtual];
        int numeroBaconAtual = ator1.baconNumber + 1;

        // precisa do const?
        for(string& film: ator1.movies){
            //TODO
        }
    }
}


#PROTOTIPO

unorder_map<string,Actor>  constroiList(string& file){
    unorder_map<string,Actor> list;
    ifstream input(file);
    string line;

    while(getline(input,line)){
        vector<string> parts = split(line,';');
        if(parts.size() == 3){
            string ator1 = parts[0], film = parts[1], ator2 = parts[2];
            if(list.find(ator1) == list.end()){
                //TODO
            }

            if(list.find(ator2) == list.end()){
                //TODO
            }

            list[ator1].movies.push_back(film);
            list[ator2].movies.push_back(film);
        }
    }
    input.close();
    return list;
}
*/