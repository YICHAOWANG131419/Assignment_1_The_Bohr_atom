Assignment 1 - The Bohr atom
Yichao Wang 10455639
Development steps (commit history)

Commit 1: Initial working version and build setup
- Created the repository from the provided Assignment 1 template.
- Set up a Linux build environment in GitHub Codespaces so the project can be compiled using the provided `Makefile` via `make`.
- Installed the required compiler toolchain (`g++-11`), as it was not available by default in the Codespaces image.
- Renamed the source file from `Assignment-1.cpp` to `assignment-1.cpp` (changed the leading `A` to lowercase) to match the `Makefile` target on a case-sensitive system.
- Implemented the first working version of the program:
  - Reads `Z`, `n_i`, and `n_j` from standard input.
  - Computes the transition energy using the Bohr formula in eV, implemented as `136000 * 1e-4` as required.
  - Prints the computed energy in eV with fixed precision output formatting.

