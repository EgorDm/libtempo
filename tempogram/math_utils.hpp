//
// Created by egordm on 26-7-2018.
//

#ifndef PROJECT_MATH_UTILS_HPP
#define PROJECT_MATH_UTILS_HPP

#include <cmath>
#include <sigpack.h>

using namespace sp;

namespace tempogram { namespace utils { namespace math {

    inline int fix(double x) {
        return static_cast<int>(x >= 0 ? floor(x) : ceil(x));
    }

    inline vec sinc_fac(const vec &x) {
        vec ret(x.size());
        for(uword i = 0; i < x.size(); ++i) {
            if (fabs(x.at(i) - 0.0) < 0.000001) ret.at(i) = 1;
            else ret.at(i) = sin(M_PI * x.at(i)) / (M_PI * x.at(i));
        }

        return ret;
    }

    inline arma::vec my_hanning( const arma::uword N ) {
        arma::vec h(N);
        for(arma::uword i=0; i<N; i++) {
            h[i] = 0.5-0.5*std::cos(sp::PI_2*(i)/(N-1));
        }
        return h;
    }

    inline mat pad_mat(const mat &data, int pad_size) {
        mat band_krn(data.n_rows, data.n_cols + pad_size * 2);
        for(int k = 0; k < pad_size; ++k) {
            band_krn(span::all, (const uword)k) = data(span::all, 0);
        }
        band_krn(span::all, span((const uword)pad_size, band_krn.n_cols - 1 - pad_size)) = data;
        for(int k = 0; k < pad_size; ++k) {
            band_krn(span::all, band_krn.n_cols - 1 - k) = data(span::all, data.n_cols - 1);
        }

        return band_krn;
    }
}}}

#endif //PROJECT_MATH_UTILS_HPP
