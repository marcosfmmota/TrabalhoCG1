#include "arq_tratamento.h"

//Transforma um valor contido em string em um valor em float
float parseFloat (string str) {

  stringstream sst;
  float f;
  sst << str << endl;
  sst >> f;

  return f;
}

//Transforma um valor contido em string em um valor em float
int parseInt (string str) {

  stringstream sst;
  int i;
  sst << str << endl;
  sst >> i;

  return i;
}

//Separa a string para constru��o do objeto
vector<string> splitString(string str) {

  istringstream iss(str);
  vector<string> tokens;
  copy(istream_iterator<string>(iss),
       istream_iterator<string>(),
       back_inserter(tokens));

  return tokens;
}

//Analisa a String para saber qual objeto deve ser instanciado
void whichIsTheObject (vector<string> tokens, vector<Vertice> *vertices, vector<Face> *faces) {
  if (tokens[0] == "v") {
      Vertice *v = new Vertice(
            parseFloat(tokens[1]),
          parseFloat(tokens[2]),
          parseFloat(tokens[3]));
      vertices->push_back(*v);
  } else if (tokens[0] == "f") {
      Face *f = new Face(
            vertices->at(parseInt(tokens[1])-1),
          vertices->at(parseInt(tokens[2])-1),
          vertices->at(parseInt(tokens[3])-1));
      faces->push_back(*f);
  }
}


/*
//Instancia o objeto vertice a partir das informa��es tiradas do arquivo
void toVertice (vector<string> tokens) {

}

//Instancia o objeto face a partir das informa��es tiradas do arquivo
void toFace (vector<string>tokens){

}
*/

//Recebe nome do arquivo e transforma cada linha dele em uma string
void fileTreatment(string nome_arquivo_entrada, vector<Vertice> *vertices, vector<Face> *faces){

  ifstream inFile (nome_arquivo_entrada.c_str( ) );

  // Testando se o arquivo existe
  if(!inFile ) {
      cerr << "N�o foi possivel abrir o arquivo de entrada : "
           << nome_arquivo_entrada << " Saindo do programa!\n";
      return;
    }
  //Lendo linha por linha ate o final do arquivo, transformando cada uma em string e chama a funcao para identificar o objeto a ser instanciado
  while (!inFile.eof()) {
      for (std::string line; std::getline(inFile, line); ) {
          vector<string> tokens = splitString(line);
          whichIsTheObject(tokens, vertices, faces);
        }
    }

  inFile.open (nome_arquivo_entrada.c_str( ) );

  inFile.close( );

}
