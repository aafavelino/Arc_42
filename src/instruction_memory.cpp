#include "instruction_memory.h"

  void instruction_memory::load_reg() {
        int current_line = 0;
        std::string word;
        std::string aux;
        std::ifstream arquivo("regs.txt", std::fstream::in);

        std::vector<Codigo> line;
        while (!arquivo.eof()) {
            current_line++;
            std::getline(arquivo, word);

            if (!word.empty()) {
                for (auto i(0u); i < word.length(); ++i) {
                    if (word[i] == ' ' or word[i] == ',')
                        continue;
                    else {
                        while (word[i] != ' ' and word[i] != ',' and i < word.length()) {
                            aux += word[i++];
                        }
                        regs.push_back(aux);
                        aux = "";
                    }
                }
            } 
            
        }
        arquivo.close();
        for (int i = 0; i < regs.size(); ++i)
        {
       		banco_regs.push_back(stoi(regs.at(i)));
        }
    }

    void instruction_memory::load_instructions() {
        std::string word;
        std::ifstream arquivo("data.txt", std::fstream::in);

        while (!arquivo.eof()) {
            std::getline(arquivo, word);

            if (!word.empty()) {
                Codigo code(word);
                instructions.push_back(code);
            }
        }
        arquivo.close();
    }

    void instruction_memory::write_regs() {
        if (addr.read() >= instructions.size()) {
            enable.write(false);
            return;
        } else enable.write(true);

        Codigo code = instructions.at(addr.read());
        if (code.getOp1() != "" and code.getNome() != "lw") {
            std::string r1 = code.getOp1();
            int index1 = stoi(r1.substr(r1.length() - 1));
            int op1 = banco_regs[index1];//stoi(regs.at(index1));
            regA.write(op1);
        }
        if (code.getOp2() != "") {
            std::string r2 = code.getOp2();
            int index2 = stoi(r2.substr(r2.length() - 1));
            int op2 = banco_regs[index2];//stoi(regs.at(index2));
            regB.write(op2);
        }

        if (code.getNome() == "add") {
            op_code.write(1);
        } else if (code.getNome() == "sub") {
            op_code.write(2);
        } else if (code.getNome() == "and") {
            op_code.write(3);
        } else if (code.getNome() == "or") {
            op_code.write(4);
        } else if (code.getNome() == "xor") {
            op_code.write(5);
        } else if (code.getNome() == "cmp") {
            op_code.write(6);
        } else if (code.getNome() == "not") {
            op_code.write(7);
        } else if (code.getNome() == "j") {
            std::string r1 = code.getDest();
            int index1 = stoi(r1);
            regA.write(index1);
            op_code.write(8);
        } else if (code.getNome() == "jn") {
            std::string r1 = code.getDest();
            int index1 = stoi(r1);
            regA.write(index1);
            op_code.write(9);
        } else if (code.getNome() == "jz") {
            std::string r1 = code.getDest();
            int index1 = stoi(r1);
            regA.write(index1);
            op_code.write(10);
        } else if (code.getNome() == "lw") {
            std::string r1 = code.getOp1();
            regA.write(stoi(r1));

            std::string r2 = code.getDest();
            int index2 = stoi(r2.substr(r2.length() - 1));
            regB.write(index2);
            op_code.write(11);
        } else if (code.getNome() == "sw") {
            std::string r1 = code.getDest();
            regB.write(stoi(r1));
            op_code.write(12);
        }
    }