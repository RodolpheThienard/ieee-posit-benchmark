# Ieee posit benchmark for RacEr Asics

Implementation of a benchmark strategy to be able to measure different metrics on the IEEE-754 floating-point standard and the UNUM 3 Posit standard. Benchmark are carried out on AMD FPGAs provided by AWS. To compare these two representations, we used 3 types of implementation :
- CPU (sequential & parralel with IEEE)
- GPU (CUDA with IEEE)
- FPGA (RacEr with POSIT)

# Benchmarks
## Performances metrics
- Time elapsed
- Stddev
- Bandwidth

## Accuracy
- Error accumulation 

## Algorithms used
- Reduction 
- Gemm
- Dot product
- Sqrt
- Sum of sqrt

Posit was implemented on a RacEr architecture
No library yet

# Compilation & Run
## IEEE compilation command :
```bash
mkdir build
cd build
cmake ..
make ieee_main
./ieee_main <matrix-size> <meta-repetition> 
```

## CUDA compilation command :
```bash
mkdir build
cd build
nvcc ../tests/cuda/main.cu ../kernels/Cuda/sgemm.cu ../driver/driver_cuda.cu ../utils/utils.c -lm -lcublas -o cuda_main
./cuda_main <matrix-size> <meta-repetition>
```

## RacEr compilation command :
```bash
UNIMPLEMENTED
```
