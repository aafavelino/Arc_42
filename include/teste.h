#ifndef _TESTE_H_
#define _TESTE_H_ 
#include <systemc.h>
#include <iostream>
#include "controller.h"
#include "data_memory.h"
#include "instruction_memory.h"
#include "ula.h"
SC_MODULE (Processador)
{


    controller *ctl;
    instruction_memory *data;
    ula *alu;
    data_memory *memory;


	SC_CTOR(Processador) {


    ctl = new controller("ctl");
    data = new instruction_memory("data");
    alu = new ula("ula");
    memory = new data_memory("mem");

	}
};


#endif