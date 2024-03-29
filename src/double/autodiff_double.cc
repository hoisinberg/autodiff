#include "src/double/autodiff_double.h"

#include <cmath>

namespace autodiff {
namespace dbl {
namespace {

double (*std_exp)(double) = std::exp;
double (*std_ln)(double) = std::log;

double (*std_sin)(double) = std::sin;
double (*std_cos)(double) = std::cos;

double (*std_sinh)(double) = std::sinh;
double (*std_cosh)(double) = std::cosh;


} // namespace;

const DualFunc<double> exp(dual_func<double>(std_exp, std_exp));
const DualFunc<double> ln(dual_func<double>(std_ln, [](double t) { return 1.0 / t; }));

const DualFunc<double> sin(dual_func<double>(std_sin, std_cos));
const DualFunc<double> cos(dual_func<double>(std_cos, [](double t) { return -std_sin(t); }));

const DualFunc<double> sinh(dual_func<double>(std_sinh, std_cosh));
const DualFunc<double> cosh(dual_func<double>(std_cosh, std_sinh));

} // namespace double
} // namespace autodiff