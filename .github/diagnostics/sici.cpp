#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <xsf/sici.h>

void show(const char* label, std::complex<double> value) {
    std::cout << label << '=' << value << " signs=" << std::signbit(value.real())
              << ',' << std::signbit(value.imag()) << '\n';
}

int main(int argc, char** argv) {
    std::cout << std::setprecision(17);
    volatile double input = argc > 1 ? std::stod(argv[1]) : -10.0;
    double y = input;
    std::complex<double> z(0.0, y);
    auto jz = std::complex<double>(0.0, 1.0) * z;
    show("z", z);
    show("jz", jz);
    show("-jz", -jz);
    show("expi(jz)", xsf::expi(jz));
    show("expi(-jz)", xsf::expi(-jz));
    show("exp1(-jz)", xsf::exp1(-jz));
    std::cout << "copysign=" << ::copysign(M_PI, jz.imag())
              << " std=" << std::copysign(M_PI, jz.imag()) << '\n';
    std::complex<double> si, ci;
    xsf::sici(z, si, ci);
    show("si", si);
    show("ci", ci);
}
