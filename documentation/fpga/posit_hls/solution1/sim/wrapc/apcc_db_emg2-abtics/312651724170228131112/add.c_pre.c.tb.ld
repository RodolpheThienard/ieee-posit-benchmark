#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/emg2-abtics/posit_hls/solution1/sim/wrapc/apcc_db_emg2-abtics/312651724170228131112/add.c_pre.c.tb.ld.bc ${1+"$@"}
