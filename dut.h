#ifndef _EXT_ARRAY_RW_SRC_DUT_H_
#define _EXT_ARRAY_RW_SRC_DUT_H_

#include "adf.h"
#include "my_defs.h"
#include "kernels.h"

using namespace adf;

class MyGraph: public adf::graph {
   adf::kernel m_k[4];  //There are four kernels created here 
public:
    input_plio m_i[4];  //Four input plios 
    output_plio m_o[4]; //Four output plios

   MyGraph()
      {
          m_i[0] = input_plio::create("In0" , plio_32_bits , "data/i1.txt");
          m_i[1] = input_plio::create("In1" , plio_32_bits , "data/i1.txt");
          m_i[2] = input_plio::create("In2" , plio_32_bits , "data/i1.txt");
          m_i[3] = input_plio::create("In3" , plio_32_bits , "data/i1.txt");

          m_o[0] = output_plio::create("Out0" , plio_32_bits, "data/o1.txt");
          m_o[1] = output_plio::create("Out1" , plio_32_bits, "data/o2.txt");
          m_o[2] = output_plio::create("Out2" , plio_32_bits, "data/o3.txt");
          m_o[3] = output_plio::create("Out3" , plio_32_bits, "data/o4.txt");
          
          int ind = 0;
          m_k[ind] = adf::kernel::create(myFunc_1di);
          adf::runtime<adf::ratio>(m_k[ind]) = 0.8;
          adf::source(m_k[ind]) = "kernels.cpp";
          adf::headers(m_k[ind]) = {"kernels.h"};
          adf::connect(m_i[ind].out[0], m_k[ind].in[0]);
          adf::connect(m_k[ind].out[0], m_o[ind].in[0]);
          adf::dimensions(m_k[ind].in[0]) = { NUM_SAMPLES };
          adf::dimensions(m_k[ind].out[0]) = { NUM_SAMPLES };

          ++ind;
          m_k[ind] = adf::kernel::create(myFunc_1df);
          adf::runtime<adf::ratio>(m_k[ind]) = 0.8;
          adf::source(m_k[ind]) = "kernels.cpp";
          adf::headers(m_k[ind]) = {"kernels.h"};
          adf::connect(m_i[ind].out[0], m_k[ind].in[0]);
          adf::connect(m_k[ind].out[0], m_o[ind].in[0]);

          ++ind;
          m_k[ind] = adf::kernel::create(myFunc_2di);
          adf::runtime<adf::ratio>(m_k[ind]) = 0.8;
          adf::source(m_k[ind]) = "kernels.cpp";
          adf::headers(m_k[ind]) = {"kernels.h"};
          adf::connect(m_i[ind].out[0], m_k[ind].in[0]);
          adf::connect(m_k[ind].out[0], m_o[ind].in[0]);
          adf::dimensions(m_k[ind].in[0]) = { 2, NUM_SAMPLES/2 };
          adf::dimensions(m_k[ind].out[0]) = { 2, NUM_SAMPLES/2 };

          ++ind;
          m_k[ind] = adf::kernel::create(myFunc_2df);
          adf::runtime<adf::ratio>(m_k[ind]) = 0.8;
          adf::source(m_k[ind]) = "kernels.cpp";
          adf::headers(m_k[ind]) = {"kernels.h"};
          adf::connect(m_i[ind].out[0], m_k[ind].in[0]);
          adf::connect(m_k[ind].out[0], m_o[ind].in[0]);
      }
};
#endif // ifndef _EXT_ARRAY_RW_SRC_DUT_H_

