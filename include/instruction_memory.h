//
// Created by Adelino on 16/04/18.
//
#ifndef _INSTRUCTION_MEMORY_
#define _INSTRUCTION_MEMORY_ 

#include <systemc.h>
#include <iostream>
#include <fstream>
#include "codigo.h"


SC_MODULE(instruction_memory) {
    sc_out < sc_uint<32> > regA, regB;
    sc_out < sc_uint<4> > op_code;
    sc_in<sc_uint<32> > addr;
    sc_out<bool> enable;

    sc_in<bool> Clk;

    std::vector<std::string> regs;
    std::vector<int> banco_regs;
    std::vector<Codigo> instructions;
    void load_reg ();
	void load_instructions ();
	void write_regs ();
  

    SC_CTOR(instruction_memory)   {
        SC_METHOD(load_reg);
        SC_METHOD(load_instructions);
        SC_METHOD(write_regs);

        sensitive << addr << Clk;

    }
};

#endif