#include "controller.h"

    void controller::incr_count () {
        while (true) {
            wait();

            if (enable.read() == true) {
                if (op.read() == 8 or op.read() == 9 or op.read() == 10) {
                    if (op.read() == 9 and n.read() == true)
                        count = regA.read();
                    else if (op.read() == 9)
                        count += 1;
                    else if (op.read() == 10 and z.read() == true)
                        count = regA.read();
                    else if (op.read() == 10)
                        count += 1;
                    else
                        count = regA.read();
                } else {
                    count += 1;
                }
                counter_out.write(count);
            } //else sc_stop();
        }

    }
    void controller::print_count () {
        while (true) {
            wait();
            cout << "@" << sc_time_stamp() << " :: Counter Value " << counter_out.read() <<endl;
        }
    }