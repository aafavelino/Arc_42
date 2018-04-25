//
// Created by Adelino on 16/04/18.
//
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_ 

#include "systemc.h"



SC_MODULE (controller) {
    sc_in_clk     clock ;
    sc_out<sc_uint<32> > counter_out;
    sc_in<bool> enable;

    sc_in < sc_uint<32> > regA;
    sc_in <sc_uint<4>> op;
    sc_uint<32>	count;

    sc_in<bool> n;
    sc_in<bool> z;

    void incr_count ();
    void print_count ();

    SC_CTOR(controller) {
        std::cout << "starting processor..." << std::endl;
        cout << "@" << sc_time_stamp() << " :: Counter Value 0" << endl;


        SC_CTHREAD(incr_count, clock.pos());
        SC_THREAD(print_count);

        sensitive << counter_out;
    }
};
#endif