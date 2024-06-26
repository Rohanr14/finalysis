#include "trend_analyzer.h"
#include <dlib/matrix.h>
#include <dlib/optimization.h>
#include <cmath>

using namespace dlib;

double linear_regression(const matrix<double, 0, 1>& w, const std::vector<double>& x, const std::vector<double>& y) {
    double error = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        double prediction = w(0) * x[i] + w(1);
        error += std::pow(prediction - y[i], 2);
    }
    return error / x.size();
}

std::vector<double> analyzeTrends(const std::vector<double>& data) {
    std::vector<double> x(data.size());
    std::iota(x.begin(), x.end(), 0); // Fill with 0, 1, 2, ..., n-1

    matrix<double, 0, 1> w = {0, 0}; // Initial weights

    find_min_using_approximate_derivatives(bfgs_search_strategy(), objective_delta_stop_strategy(1e-7), 
                                           [&](const matrix<double, 0, 1>& w) { return linear_regression(w, x, data); }, 
                                           w, -1);

    std::vector<double> trend;
    for (const auto& xi : x) {
        trend.push_back(w(0) * xi + w(1));
    }
    return trend;
}