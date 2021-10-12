#include <ex-debug.hpp>

namespace TestNamespace {

    void sort_vec(int n, arma::vec &v) {
        std::cout << "From root-dir/src/ex-debug.cpp" << std::endl;
        std::cout << "n: " << n << std::endl;
        std::cout << "Length of v: " << arma::size(v) << std::endl;
        /// The following print explodes
        std::cout << "Printing v(2): " << v(2) << std::endl;
    }

    arma::vec getEigenValues(arma::mat &M) {
        return arma::eig_sym(M);
    }

}
