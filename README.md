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
- Error accumulation mean
- Root Mean Square
- Forward Error

[comment]: # (TODO)
## Algorithms used
- Reduction 
- Gemm
- Dot product
- Sqrt
- Sum of sqrt
- Inverse matrix 

Posit was implemented on a RacEr architecture  
No library yet

# Compilation & Run
All `main` compilation command will create a shared object lib which will be used for each test  
Then you can run test or use the lib in your own file.

## Lib 
```bash
mkdir build
cd build
cmake ..
make <version>_bench
```
all version available : {x86, omp, cuda}

## Test compilation & run command :
```bash
mkdir build
cd build
cmake ..
make <version>_main
./<version>_main <matrix-size> <meta-repetition> 
```
all version available : {x86, omp, cuda}

#### Example : 
```bash
mkdir build
cd build
cmake ..
make cuda_main
./cuda_main <matrix-size> <meta-repetition>
```

## Troubleshoot

> [!WARNING]
> If error : "cannot find -lcublas" or "cannot find -lcudart"  
> check if LD_LIBRARY_PATH AND LIBRARY_PATH have "/path/to/your/cuda/lib64"  
> if not, 
```sh
export LIBRARY_PATH="/path/to/your/cuda/lib64:${LIBRARY_PATH}"
export LD_LIBRARY_PATH="/path/to/your/cuda/lib64:${LD_LIBRARY_PATH}"
```


## API
> [!WARNING]
> Todo  
