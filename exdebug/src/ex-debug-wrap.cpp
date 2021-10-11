// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::plugins(cpp11)]]

#include <RcppArmadillo.h>
#include <ex-debug.hpp>

// [[Rcpp::export]]
void sort_vec_R(int n, arma::vec v) {
    std::cout << "From root-dir/exdebug/src/ex-debug-wrap.cpp" << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "Length of v: " << arma::size(v) << std::endl;
    std::cout << "Printng v[2]: " << v[2] << std::endl;
    TestNamespace::sort_vec(n, v);
}

// [[Rcpp::export]]
arma::vec getEigenValues_R(arma::mat M) {
    return TestNamespace::getEigenValues(M);
}

// [[Rcpp::export]]
arma::vec getEigenValues_arma(arma::mat M) {
    return arma::eig_sym(M);
}

