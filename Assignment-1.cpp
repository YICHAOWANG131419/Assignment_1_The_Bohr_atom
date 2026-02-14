// Assignment 1 - The Bohr Atom
// Program to calculate transition energy using simple Bohr formula

#include <iostream>
#include <iomanip>

int main()
{
    const double BOHR_FACTOR_INT = 136000.0;  // As requested: use 136000 instead of 13.6
    const double BOHR_FACTOR_SCALE = 1.0e-4;  // 136000 * 1e-4 = 13.6

    int Z = 0;
    int ni = 0;
    int nj = 0;

    // Ask user to enter atomic number
    std::cout << "Enter atomic number Z (positive integer): ";
    std::cin >> Z;

    // Ask user to enter initial and final quantum numbers
    std::cout << "Enter initial quantum number n_i (positive integer): ";
    std::cin >> ni;

    std::cout << "Enter final quantum number n_j (positive integer): ";
    std::cin >> nj;

    // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
    const double Z2 = static_cast<double>(Z) * static_cast<double>(Z);
    const double term =
        (1.0 / (static_cast<double>(nj) * nj)) - (1.0 / (static_cast<double>(ni) * ni));
    const double deltaE_eV = (BOHR_FACTOR_INT * BOHR_FACTOR_SCALE) * Z2 * term;

    // Output answer
    std::cout << std::setprecision(10);
    std::cout << "Here is my answer: " << deltaE_eV << " eV" << std::endl;

    return 0;
}
