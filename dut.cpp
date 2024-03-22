#include "dut.h"
using namespace adf;

MyGraph mygraph;


int main(int argc, char ** argv) {
    mygraph.init();
    mygraph.run( 4 );
    mygraph.end();
   
    return 0;
}
