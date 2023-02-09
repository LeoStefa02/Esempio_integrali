#include "FunzioniUtili/funzioni.h"
#include "FunzioniUtili/FunzioneBase.h"
#include "Integrali/Integral.h"
#include <iostream>
#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TF1.h"
#include <vector>
#include <cmath>

using namespace std;

TGraph* make_graph(const char* nome_algoritmo, vector<unsigned int>& n_step) {
    TGraphData data;

    for(int i = 0; i < n_step.size(); i++){
        string filename = to_string(n_step[i]).append("_").append(nome_algoritmo);
        vector<double> v = read_all<double>(filename.c_str());
        data.y.push_back(pow(varianza<double>(v.begin(), v.end()), 0.5));
        data.x.push_back(double(n_step[i]));
    }

    return tgraph_with_data(data);
}

int main() {

    TApplication app("", 0, 0);

    vector<unsigned int> n_step {100, 500, 1000, 5000, 10000, 50000, 100000};

    TGraph* graph_media = make_graph("media", n_step);
    
    TGraph* graph_hom = make_graph("hit_or_miss", n_step);
    

    TF1 f("f", "[0]/sqrt(x)");

    TCanvas canvas;
    canvas.Divide(2);
    canvas.cd(1);
    graph_media->SetMarkerStyle(20);
    graph_media->Draw("AP");
    graph_media->Fit("f");
    
    canvas.cd(2);
    graph_hom->SetMarkerStyle(20);
    graph_hom->Draw("AP");
    graph_hom->Fit("f");

    app.Run();

    return 0;
}