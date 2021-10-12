# Clear environment 
rm(list=ls())

setwd("/Users/gva/example")
# options(buildtools.check = function(action) TRUE )

# RcppArmadillo::RcppArmadillo.package.skeleton(name = "exdebug")
# Rcpp::compileAttributes("exdebug")
devtools::load_all("exdebug")

## Test
n = 9
v = c(1:5)

# Shows the correct dimensions
# but try to uncomment line 10 in /root-dir/src/ex-debug.cpp
# and then it will explode
sort_vec_R(n, v)


## Generate 5x5 matrix
M = matrix(rnorm(25), 5)
M[lower.tri(M)] = t(M)[lower.tri(M)]
diag(M) = diag(M) + sample.int(10, 5)

## Works with arma::mat arguments
eigen(M)$values # R version
getEigenValues_arma(M) # direct armadillo call
getEigenValues_R(M) # armadillo call through wrapper script
