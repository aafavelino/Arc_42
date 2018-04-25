//
// Created by Adelino on 16/04/18.
//
#ifndef _ULA_H_
#define _ULA_H_ 

#include <systemc.h>
#include <iostream>

SC_MODULE(ula) {
	sc_in<sc_uint<32>> regA, regB;
	sc_uint<32> dataA, dataB, resultado;
    sc_out<sc_uint<32>> regDest;
	sc_in<sc_uint<4>> op_code;
	sc_out<bool> n;
    sc_out<bool> z;
    sc_out<bool> operation;
    sc_out<sc_uint<32>> data_mem_in;
    sc_in<sc_uint<32>> data_mem_out;
    sc_out<sc_uint<32> > addr;    
	void operacao();

	SC_CTOR(ula){
		SC_METHOD(operacao);
			sensitive << regA << regB << op_code;
	}
};
#endif