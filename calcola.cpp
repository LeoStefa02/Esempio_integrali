#include "FunzioniUtili/FunzioneBase.h"
#include "FunzioniUtili/funzioni.h"
#include "Integrali/Integral.h"
#include <iostream>
#include <vector>

using namespace std;

void integra(Integral* integratore, const char* nome_algoritmo, const vector<unsigned int>& n_step, FunzioneBase& f);

int main() {

    Seno seno;
    Media integratore(0, M_PI);
    HitOrMiss integratore2(0, M_PI);

    vector<unsigned int> n_step {100, 500, 1000, 5000, 10000, 50000, 100000};

    integra(&integratore, "media", n_step, seno);

    integra(&integratore2, "hit_or_miss", n_step, seno);

    return 0;
}

void integra(Integral* integratore, const char* nome_algoritmo, const vector<unsigned int>& n_step, FunzioneBase& f) {
    cout << "inizio calcolo con " << nome_algoritmo << endl;

    for(int k = 0; k < n_step.size(); k++) {
        vector<double> v;
        for(int i = 0; i < 10000; i++)
            v.push_back(integratore->integra_step(n_step[k], f));
        string filename = "./Valori/" + to_string(n_step[k]).append("_").append(nome_algoritmo);
        print<double>(v.begin(), v.end(), filename.c_str());
    }

    cout << "fine calcolo con " << nome_algoritmo << endl;
}