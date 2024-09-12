# Posit Validation for RacEr Architecture 

Implementation of a benchmark strategy to be able to measure different metrics on the IEEE-754 floating-point standard and the UNUM 3 Posit standard. Benchmark are carried out on AMD FPGAs provided by AWS. To compare these two representations, we used 3 types of implementation :
- CPU (sequential & parralel with IEEE)
- GPU (CUDA with IEEE)
- FPGA (RacEr with POSIT)

# Tests done
  - Dotprod
  - Memset
  - Add
  - Kmeans
  - Memcpy
  - Inverse

# Documentation / User Guide
- [documentation RacEr](documentation/racer/documentation.pdf)
- [documentation FPGA](documentation/fpga/guide.pdf)
- [documentation AWS](documentation/aws/guide.pdf)
- [Papers](documentation/papers)
- [Internship report](documentation/rapport/Rapport_Rodolphe_THIENARD.pdf)

> [!NOTE]  
> - Posit was implemented on a RacEr architecture. You can find it at `documentation/racer/documentation.pdf`   
> - In this file, you can find API of RacEr with examples.

