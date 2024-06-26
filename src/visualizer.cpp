#include "visualizer.h"
#include <matplot/matplot.h>
#include <iostream>

using namespace matplot;
using namespace std;

void visualizeData(const vector<double>& data) {
    vector<double> x(data.size());
    iota(x.begin(), x.end(), 0);

    auto fig = figure(true);
    auto ax = fig->add_axes();
    ax->plot(x, data);
    ax->xlabel("Time");
    ax->ylabel("Stock Price");
    ax->title("Stock Price Over Time");

    string file_name = "plot.png";
    fig->save(file_name);
    cout << "Plot saved as " << file_name << endl;
}