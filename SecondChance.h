//
// Created by a1016 on 2023/3/28.
//

#ifndef PAGEREPLACEMENTALGORITHMS_SECONDCHANCE_H
#define PAGEREPLACEMENTALGORITHMS_SECONDCHANCE_H

#include <iostream>
#include <iomanip>

namespace Algorithms {

    class SecondChance {

    public:
        explicit SecondChance(int *, int, int);

        void run();

    private:
        bool find(int);

        void replace(int);

        void print_process();

        void pointer_to_next();

        int _page_fault;
        int _frames_num;
        int _pointer;
        int *_pages;
        int _pages_requests_length;
        struct frame {
            int stored_page = -1;
            int second_chance = 0;
        };
        frame *_frames;
    };

} // Algorithms

#endif //PAGEREPLACEMENTALGORITHMS_SECONDCHANCE_H
