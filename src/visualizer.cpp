#include "visualizer.h"
#include <matplot/matplot.h>

using namespace matplot;
using namespace std;

void visualizeData(const vector<double>& data) {
    vector<double> x(data.size());
    iota(x.begin(), x.end(), 0); // Fill with 0, 1, 2, ..., n-1

    auto fig = figure(true);
    plot(x, data);
    xlabel("Time");
    ylabel("Stock Price");
    title("Stock Price Over Time");
    show();
}