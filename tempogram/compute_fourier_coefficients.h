//
// Created by egordm on 26-7-2018.
//

#ifndef PROJECT_COMPUTE_FOURIER_COEFFICIENTS_H
#define PROJECT_COMPUTE_FOURIER_COEFFICIENTS_H

#include <armadillo>

namespace tempogram {
    /**
     * @param s time domain signal
     * @param window vector containing window function
     * @param n_overlap overlap given in samples
     * @param f vector of frequencies values of fourier coefficients, in Hz
     * @param sr sampling rate of signal s in Hz
     * @return
     */
    arma::mat compute_fourier_coefficients(const arma::vec &s, const arma::vec &window, int n_overlap, const arma::vec &f, double sr);
}


#endif //PROJECT_COMPUTE_FOURIER_COEFFICIENTS_H