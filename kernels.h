#pragma once
#include "my_defs.h"
#include "adf.h"


void myFunc_1di(adf::input_buffer<int>  & __restrict i1,
                adf::output_buffer<int> & __restrict o1);
void myFunc_1df(adf::input_buffer<int, adf::extents<NUM_SAMPLES>>  & __restrict i1,
                adf::output_buffer<int, adf::extents<NUM_SAMPLES>> & __restrict o1);
void myFunc_2di(adf::input_buffer<int, adf::extents<adf::inherited_extent, adf::inherited_extent>>  & __restrict i1,
                adf::output_buffer<int, adf::extents<adf::inherited_extent, adf::inherited_extent>> & __restrict o1);
void myFunc_2df(adf::input_buffer<int, adf::extents<2, NUM_SAMPLES/2>>  & __restrict i1,
                adf::output_buffer<int, adf::extents<2, NUM_SAMPLES/2>> & __restrict o1);

