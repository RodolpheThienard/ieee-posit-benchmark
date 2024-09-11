############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project posit_hls
set_top add
add_files posit_hls/add.c
add_files posit_hls/add.h
add_files -tb posit_hls/test.c -cflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xck26-sfvc784-2LV-c}
create_clock -period 5 -name default
config_export -flow syn -format ip_catalog -output /home/emg2-abtics/Downloads -rtl verilog -vivado_clock 5
config_cosim -tool xsim
source "./posit_hls/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -flow syn -rtl verilog -format ip_catalog -output /home/emg2-abtics/Downloads
