// Assignment 1 - The Bohr Atom
// Program to calculate transition energy using simple Bohr formula

#include <iostream>
#include <iomanip>
#include <limits>

double transition_energy_eV(int Z, int ni, int nj)
{
    const double BOHR_FACTOR_INT = 136000.0;
    const double BOHR_FACTOR_SCALE = 1.0e-4;

    const double Z2 = static_cast<double>(Z) * static_cast<double>(Z);
    const double term =
        (1.0 / (static_cast<double>(nj) * nj)) - (1.0 / (static_cast<double>(ni) * ni));
    return (BOHR_FACTOR_INT * BOHR_FACTOR_SCALE) * Z2 * term;
}

int main()
{
    const double EV_TO_J = 1.602176634e-19;

    while (true)
    {
        int Z = 0;
        int ni = 0;
        int nj = 0;
        char unit = '\0';

        // ---- Re-enter loop for the four inputs ----
        while (true)
        {
            // --- Atomic number ---
            while (true)
            {
                std::cout << "Enter atomic number Z (positive integer): ";
                if (std::cin >> Z && Z > 0) break;

                std::cout << "Error: Z must be a positive integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // --- Quantum numbers ---
            while (true)
            {
                std::cout << "Enter initial quantum number n_i (positive integer): ";
                if (std::cin >> ni && ni > 0) break;

                std::cout << "Error: n_i must be a positive integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // NOTE: minimal change here: only check nj > 0 now (no nj < ni check here)
            while (true)
            {
                std::cout << "Enter final quantum number n_j (positive integer, and n_j < n_i): ";
                if (std::cin >> nj && nj > 0) break;

                std::cout << "Error: n_j must be a positive integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // --- Units ---
            while (true)
            {
                std::cout << "Display energy in Joules (J) or electron volts (e)? Enter J or e: ";
                if (std::cin >> unit)
                {
                    if (unit == 'J' || unit == 'j' || unit == 'e' || unit == 'E') break;
                }
                std::cout << "Error: please enter 'J' for Joules or 'e' for electron volts.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // ---- After ALL four inputs: validate the physical condition ----
            if (nj < ni)
            {
                break; // valid, proceed to calculation
            }

            std::cout << "Error: physical condition violated (need n_j < n_i).\n";

            // Ask whether to re-enter everything
            char retry = '\0';
            while (true)
            {
                std::cout << "Do you want to re-enter the input? (y/n): ";
                if (std::cin >> retry)
                {
                    if (retry == 'y' || retry == 'Y' || retry == 'n' || retry == 'N') break;
                }
                std::cout << "Error: please enter 'y' or 'n'.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (retry == 'n' || retry == 'N')
            {
                return 0; // exit program
            }

            std::cout << "\n"; // restart input from Z
        }

        // ---- Calculation & output (unchanged) ----
        const double deltaE_eV = transition_energy_eV(Z, ni, nj);

        std::cout << std::setprecision(3);

        if (unit == 'e' || unit == 'E')
        {
            std::cout << "Transition energy: " << deltaE_eV << " eV\n";
        }
        else
        {
            const double deltaE_J = deltaE_eV * EV_TO_J;
            std::cout << "Transition energy: " << deltaE_J << " J\n";
        }

        // Repeat? (unchanged)
        char again = '\0';
        while (true)
        {
            std::cout << "Calculate another transition? (y/n): ";
            if (std::cin >> again)
            {
                if (again == 'y' || again == 'Y' || again == 'n' || again == 'N') break;
            }
            std::cout << "Error: please enter 'y' or 'n'.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (again == 'n' || again == 'N') break;
        std::cout << "\n";
    }

    return 0;
}
