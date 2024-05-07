# Ieee posit benchmark for RacEr Architecture 

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
## Tests done
- Vector operation :
  - Add
  - Sqrt
  - Div
- Matrix operation :
  - Mul
  - Inverse
- Monte-Carlo
  - Pi approximation

> [!NOTE]
> Posit was implemented on a RacEr architecture. You can find some documentation in doc/documentation.pdf

# Compilation & Run
All `main` compilation command will create a shared object lib which will be used for each test  
Then you can run test or use the lib in your own file.

You require to add an agrument for cmake to precise which version you want.
all version available : {racer, omp, cuda}

## Lib 
```bash
mkdir build
cd build
cmake -DENABLE_<VERSION>_COMPILE=on ..
make <version>_bench
```

## Test compilation & run command :
```bash
mkdir build
cd build
cmake -DENABLE_<VERSION>_COMPILE=on ..
make <version>_main
./<version>_main <matrix-size> <meta-repetition> 
```
all version available : {racer, omp, cuda}

#### Example : 
```bash
mkdir build
cd build
cmake -DENABLE_<VERSION>_COMPILE=on ..
make cuda_main
./<version>_bin/<test> <matrix-size> <meta-repetition>
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
