#include "kernels.h"

__attribute__((noinline))
void myFunc_1di(adf::input_buffer<int>  & __restrict i1,
                adf::output_buffer<int> & __restrict o1)
{
    int32 *__restrict pi1 = i1.data();
    int32 *__restrict po1 = o1.data();
    
    for (unsigned ind = 0; ind < NUM_SAMPLES; ++ind)
    {
         *po1++ = 1 + *pi1++;
    }
}

__attribute__((noinline))
    void myFunc_1df(adf::input_buffer<int, adf::extents<NUM_SAMPLES>>  & __restrict i1,
                    adf::output_buffer<int, adf::extents<NUM_SAMPLES>> & __restrict o1)
{
    int32 *__restrict pi1 = i1.data();
    int32 *__restrict po1 = o1.data();
    
    for (unsigned ind = 0; ind < o1.dim(0); ++ind)
    {
        *po1++ = 2 + *pi1++;
    }
}

__attribute__((noinline))
void myFunc_2di(adf::input_buffer<int, adf::extents<adf::inherited_extent, adf::inherited_extent>>  & __restrict i1,
                adf::output_buffer<int, adf::extents<adf::inherited_extent, adf::inherited_extent>> & __restrict o1)
{
    int32 *__restrict pi1 = i1.data();
    int32 *__restrict po1 = o1.data();
    
    for (unsigned ind = 0; ind < NUM_SAMPLES; ++ind)
    {
        *po1++ = 3 + *pi1++;
    }
}

__attribute__((noinline))
    void myFunc_2df(adf::input_buffer<int, adf::extents<2, NUM_SAMPLES/2>>  & __restrict i1,
                    adf::output_buffer<int, adf::extents<2, NUM_SAMPLES/2>> & __restrict o1)
{
    int32 *__restrict pi1 = i1.data();
    int32 *__restrict po1 = o1.data();
    
    for (unsigned ind = 0; ind < o1.size(); ++ind)
    {
        *po1++ = 4 + *pi1++;
    }
}
