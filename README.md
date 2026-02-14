Assignment 1 - The Bohr atom

Yichao Wang 10455639

Development steps (commit history)

Note: Commit 1 and 2 are initially edited in local V-S Code environment serveral days ago.

Commit 1: Initial working version and build setup
- Created the repository from the provided Assignment 1 template.
- Set up a Linux build environment in GitHub Codespaces so the project can be compiled using the provided `Makefile` via `make`.
- Installed the required compiler toolchain (`g++-11`), as it was not available by default in the Codespaces image.
- Renamed the source file from `Assignment-1.cpp` to `assignment-1.cpp` (changed the leading `A` to lowercase) to match the `Makefile` target on a case-sensitive system.
- Implemented the first working version of the program:
  - Reads `Z`, `n_i`, and `n_j` from standard input.
  - Computes the transition energy using the Bohr formula in eV, implemented as `136000 * 1e-4` as required.
  - Prints the computed energy in eV with fixed precision output formatting.

Commit 2: Add input validation, unit selection, and repeat-run workflow
- Added robust input validation for all user inputs:
  - Ensures `Z > 0`, `n_i > 0`, and enforces the physical condition `n_j < n_i`.
  - Detects non-integer or invalid input and recovers by clearing the input stream and ignoring the remaining line.
- Added output unit selection:
  - Allows the user to choose between electron volts (eV) and Joules (J).
  - Includes an exact conversion constant `1 eV = 1.602176634e-19 J`.
- Added a repeat-run option so multiple transitions can be computed in one program execution (`y/n` loop).
- Improved output formatting using `std::setprecision(10)` for clearer numeric results.
