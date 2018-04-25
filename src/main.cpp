//
// Created by Adelino on 16/04/18.
//

#include <systemc.h>
#include <iostream>
#include "controller.h"
#include "data_memory.h"
#include "instruction_memory.h"
#include "ula.h"
#include "teste.h"

int sc_main (int argc, char* argv[]) 
{
   // sc_clock clock("clock", 10, SC_NS, 1, 10, SC_NS);

   //  sc_signal<sc_uint<32> > result, data_out, data_in;
   //  sc_signal<sc_uint<32> > op1, op2;
   //  sc_signal<sc_uint<4>> op_code;
   //  sc_signal<sc_uint<32> > addr, addr_memory;
   //  sc_signal< bool > enable, z, n, operation;

   //  controller ctl("controller");
   //  ctl.clock(clock);
   //  ctl.counter_out(addr);
   //  ctl.enable(enable);
   //  ctl.op(op_code);
   //  ctl.regA(op1);
   //  ctl.z(z);
   //  ctl.n(n);

   //  instruction_memory data("data");
   //  data.regA(op1);
   //  data.regB(op2);
   //  data.op_code(op_code);
   //  data.Clk(clock);
   //  data.addr(addr);
   //  data.enable(enable);

   //  ula ula("ula");
   //  ula.regDest(result);
   //  ula.regA(op1);
   //  ula.regB(op2);
   //  ula.op_code(op_code);
   //  ula.z(z);
   //  ula.n(n);
   //  ula.operation(operation);
   //  ula.data_mem_in(data_in);
   //  ula.data_mem_out(data_out);
   //  ula.addr(addr_memory);

   //  data_memory memory("memory");
   //  memory.addr(addr_memory);
   //  memory.data_in(data_in);
   //  memory.data_out(data_out);
   //  memory.Clk(clock);
   //  memory.operation(operation);
    sc_signal<sc_uint<32> > result, data_out, data_in;
    sc_signal<sc_uint<32> > op1, op2;
    sc_signal<sc_uint<4>> op_code;
    sc_signal<sc_uint<32> > addr, addr_memory;
    sc_signal< bool > enable, z, n, operation;

    sc_signal<sc_uint<32> > result1, data_out1, data_in1;
    sc_signal<sc_uint<32> > op11, op21;
    sc_signal<sc_uint<4>> op_code1;
    sc_signal<sc_uint<32> > addr1, addr_memory1;
    sc_signal< bool > enable1, z1, n1, operation1;



    sc_clock clock("clock", 10, SC_NS, 1, 10, SC_NS);

    // teste teste("teste");
    Processador *teste = new Processador("teste123");

    teste->ctl->clock(clock);
    teste->ctl->counter_out(addr);
    teste->ctl->enable(enable);
    teste->ctl->op(op_code);
    teste->ctl->regA(op1);
    teste->ctl->z(z);
    teste->ctl->n(n);


    teste->data->regA(op1);
    teste->data->regB(op2);
    teste->data->op_code(op_code);
    teste->data->Clk(clock);
    teste->data->addr(addr);
    teste->data->enable(enable);

    
    teste->alu->regDest(result);
    teste->alu->regA(op1);
    teste->alu->regB(op2);
    teste->alu->op_code(op_code);
    teste->alu->z(z);
    teste->alu->n(n);
    teste->alu->operation(operation);
    teste->alu->data_mem_in(data_in);
    teste->alu->data_mem_out(data_out);
    teste->alu->addr(addr_memory);

    
    teste->memory->addr(addr_memory);
    teste->memory->data_in(data_in);
    teste->memory->data_out(data_out);
    teste->memory->Clk(clock);
    teste->memory->operation(operation);





    Processador *ggg = new Processador("teste122333");
    //ggg teste("teste2");

    ggg->ctl->clock(clock);
    ggg->ctl->counter_out(addr1);
    ggg->ctl->enable(enable1);
    ggg->ctl->op(op_code1);
    ggg->ctl->regA(op11);
    ggg->ctl->z(z1);
    ggg->ctl->n(n1);


    ggg->data->regA(op11);
    ggg->data->regB(op21);
    ggg->data->op_code(op_code1);
    ggg->data->Clk(clock);
    ggg->data->addr(addr1);
    ggg->data->enable(enable1);

    
    ggg->alu->regDest(result1);
    ggg->alu->regA(op11);
    ggg->alu->regB(op21);
    ggg->alu->op_code(op_code1);
    ggg->alu->z(z1);
    ggg->alu->n(n1);
    ggg->alu->operation(operation1);
    ggg->alu->data_mem_in(data_in1);
    ggg->alu->data_mem_out(data_out1);
    ggg->alu->addr(addr_memory1);

    
    ggg->memory->addr(addr_memory1);
    ggg->memory->data_in(data_in1);
    ggg->memory->data_out(data_out1);
    ggg->memory->Clk(clock);
    ggg->memory->operation(operation);


    sc_start();  // Run the simulation till sc_stop is encountered


	return 0;
}