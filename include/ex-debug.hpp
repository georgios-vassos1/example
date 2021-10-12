#pragma once

#ifndef ARMA_R
#include <armadillo>
#endif
#if defined(ARMA_R)
#include <RcppArmadillo.h>
#endif
#include <cmath>

namespace TestNamespace {

    void sort_vec(int, arma::vec &);

    arma::vec getEigenValues(arma::mat &);

}

