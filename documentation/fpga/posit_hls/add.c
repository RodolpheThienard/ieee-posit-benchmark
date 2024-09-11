
#include "stdio.h"
#include "add.h"

void add(data_h in_a, data_h in_b, data_h out_c)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=in_a
#pragma HLS INTERFACE s_axilite port=in_b
#pragma HLS INTERFACE s_axilite port=out_c

    out_c = in_a + in_b;
}
