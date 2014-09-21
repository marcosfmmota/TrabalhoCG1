#ifndef ARQ_TRATAMENTO_H
#define ARQ_TRATAMENTO_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

#include "vertice.h"
#include "face.h"
#include "objeto.h"

using namespace std;

float parseFloat (string str);
int parseInt (string str);
vector<string> splitString(string str);
void whichIsTheObject (vector<string> tokens, vector<Vertice> *vertices, vector<Face> *faces);
void fileTreatment(string nome_arquivo_entrada, vector<Vertice> *vertices, vector<Face> *faces);
void toVertice (vector<string> tokens);
void toFace (vector<string>tokens);

#endif // ARQ_TRATAMENTO_H
