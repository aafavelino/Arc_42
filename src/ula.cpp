#include "ula.h"

void ula::operacao () {
	dataA = regA.read();
	dataB = regB.read();
            switch (op_code.read()) {
                case 1:
                    resultado = dataA + dataB;
                    cout << "@" << sc_time_stamp() << " | Sum >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 2:
                    resultado = dataA - dataB;
                    if (dataA > dataB) {
                        n.write(true);
                    } else {
                        n.write(false);
                        if (resultado == 0) z.write(true);
                    }
                    cout << "@" << sc_time_stamp() << " | Sub >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 3:
                    resultado = dataA && dataB;
                    cout << "@" << sc_time_stamp() << " | AND >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 4:
                    resultado = dataA || dataB;
                    cout << "@" << sc_time_stamp() << " | OR >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 5:
                    resultado = not (dataA || dataB);
                    cout << "@" << sc_time_stamp() << " | XOR >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 6:
                    resultado = 0;
                    if (dataA > dataB) {
                        n.write(true);
                    } else if (dataA < dataB) {
                        n.write(false);
                    } else {
                        z.write(true);;
                        resultado = 1;
                    }
                    cout << "@" << sc_time_stamp() << " | Comp >> (op1: "
                    << dataA << ") (op2: " << dataB << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 7:
                    resultado = not (dataA);
                    cout << "@" << sc_time_stamp() << " | Not >> (op: "
                    << dataA << ") (resultado: " << resultado << ")" << endl;
                    break;
                case 8:
                    cout << "@" << sc_time_stamp() << " | J >> (goto: "
                    << dataA << ")" << endl;
                    break;
                case 9: 
                    if (n == true)
                        cout << "@" << sc_time_stamp() << " | Jn >> (goto: "
                        << dataA << ")" << endl;
                    else
                        cout << "@" << sc_time_stamp() << " | Jn >> FALSE CONDITION" << endl;
                    break;
                case 10:
                    if (z == true)
                        cout << "@" << sc_time_stamp() << " | Jz >> (goto: "
                        << dataA << ")" << endl;
                    else
                        cout << "@" << sc_time_stamp() << " | Jz >> FALSE CONDITION" << endl;
                    break;
                case 11:
                    operation.write(false);
                    addr.write(dataB);
                    //data_mem_out.read();
                    cout << "@" << sc_time_stamp() << " | LW >> (read data: "
                    << dataA << ") reg to write: (" << dataB << ")" << endl;
                    break;
                case 12:
                    operation.write(true);
                    data_mem_in.write(dataA);
                    addr.write(dataB);
                    cout << "@" << sc_time_stamp() << " | SW >> (write data: "
                    << dataA << ") addresultado to write: (" << dataB << ")" << endl;
                    break;
            }
            regDest.write(resultado);
}

