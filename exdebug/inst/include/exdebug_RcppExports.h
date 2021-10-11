// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_exdebug_RCPPEXPORTS_H_GEN_
#define RCPP_exdebug_RCPPEXPORTS_H_GEN_

#include <RcppArmadillo.h>
#include <Rcpp.h>

namespace exdebug {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("exdebug", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("exdebug", "_exdebug_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in exdebug");
            }
        }
    }

    inline void sort_vec_R(int n, arma::vec v) {
        typedef SEXP(*Ptr_sort_vec_R)(SEXP,SEXP);
        static Ptr_sort_vec_R p_sort_vec_R = NULL;
        if (p_sort_vec_R == NULL) {
            validateSignature("void(*sort_vec_R)(int,arma::vec)");
            p_sort_vec_R = (Ptr_sort_vec_R)R_GetCCallable("exdebug", "_exdebug_sort_vec_R");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sort_vec_R(Shield<SEXP>(Rcpp::wrap(n)), Shield<SEXP>(Rcpp::wrap(v)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
    }

    inline arma::vec getEigenValues_R(arma::mat M) {
        typedef SEXP(*Ptr_getEigenValues_R)(SEXP);
        static Ptr_getEigenValues_R p_getEigenValues_R = NULL;
        if (p_getEigenValues_R == NULL) {
            validateSignature("arma::vec(*getEigenValues_R)(arma::mat)");
            p_getEigenValues_R = (Ptr_getEigenValues_R)R_GetCCallable("exdebug", "_exdebug_getEigenValues_R");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getEigenValues_R(Shield<SEXP>(Rcpp::wrap(M)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::vec >(rcpp_result_gen);
    }

    inline arma::vec getEigenValues_arma(arma::mat M) {
        typedef SEXP(*Ptr_getEigenValues_arma)(SEXP);
        static Ptr_getEigenValues_arma p_getEigenValues_arma = NULL;
        if (p_getEigenValues_arma == NULL) {
            validateSignature("arma::vec(*getEigenValues_arma)(arma::mat)");
            p_getEigenValues_arma = (Ptr_getEigenValues_arma)R_GetCCallable("exdebug", "_exdebug_getEigenValues_arma");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getEigenValues_arma(Shield<SEXP>(Rcpp::wrap(M)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::vec >(rcpp_result_gen);
    }

}

#endif // RCPP_exdebug_RCPPEXPORTS_H_GEN_
