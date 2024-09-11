# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/emg2-abtics/project_2/axis_IO_system/_ide/scripts/systemdebugger_axis_io_system_standalone.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/emg2-abtics/project_2/axis_IO_system/_ide/scripts/systemdebugger_axis_io_system_standalone.tcl
# 
connect -url tcp:127.0.0.1:3121
source /tools/Xilinx/Vitis/2023.2/scripts/vitis/util/zynqmp_utils.tcl
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Xilinx X-MLCC-01 XFL1TQBDF1BXA" && level==0 && jtag_device_ctx=="jsn-X-MLCC-01-XFL1TQBDF1BXA-04724093-0"}
fpga -file /home/emg2-abtics/project_2/axis_IO/_ide/bitstream/design_2_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw /home/emg2-abtics/project_2/design_2_wrapper/export/design_2_wrapper/hw/design_2_wrapper.xsa -mem-ranges [list {0x80000000 0xbfffffff} {0x400000000 0x5ffffffff} {0x1000000000 0x7fffffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source /home/emg2-abtics/project_2/axis_IO/_ide/psinit/psu_init.tcl
psu_init
after 1000
psu_ps_pl_isolation_removal
after 1000
psu_ps_pl_reset_config
catch {psu_protection}
targets -set -nocase -filter {name =~ "*A53*#0"}
rst -processor
dow /home/emg2-abtics/project_2/axis_IO/Release/axis_IO.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A53*#0"}
con
