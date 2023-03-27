//
// Created by a1016 on 2023/3/28.
//

#include "SecondChance.h"

namespace Algorithms {
    /*
     * int *pages: 將要運行的全部頁面陣列
     * int pages_requests_length: pages陣列長度
     * int frames_num: 頁框數量
     */
    SecondChance::SecondChance(int *pages, int pages_requests_length, int frames_num) {
        _pages = pages;
        _pages_requests_length = pages_requests_length;
        _frames_num = frames_num;
        _page_fault = 0;
        _pointer = 0;
        _frames = new frame[_frames_num];
    }

    /*
     * 運行該算法
     */
    void SecondChance::run() {
        for (int i = 0; i < _pages_requests_length; i++) {
            find(_pages[i]) ? replace(_pages[i]) : (void) NULL;
            print_process();
        }
        std::cout << "Total page faults: " << _page_fault << std::endl;
        delete[] _frames;
    }

    /*
     * 印出程序
     */
    void SecondChance::print_process() {
        for (int i = 0; i < _frames_num; i++) {
            std::cout << std::setw(5)
                      << _frames[i].stored_page
                      << "("
                      << _frames[i].second_chance
                      << ") ";
        }
        std::cout << ": pointer->" << _pointer << std::endl;
    }

    /*
     * 找尋頁面是否已在頁框裡運行,並給予二次機會
     * int page: 欲進入頁框的頁面
     * return: 是否更換頁框中的頁面
     */
    bool SecondChance::find(int page) {
        for (int i = 0; i < _frames_num; i++) {
            // 如果即將進行的頁面仍存活在頁框裡
            if (_frames[i].stored_page == page) {
                // 給予二次機會
                _frames[i].second_chance = 1;
                return false;
            }
        }
        return true;
    }

    /*
     * 更換頁面
     * 擁有二次機會者無法被替換
     * 需找到已經沒有二次機會者,或者將二次機會歸零
     * 替換頁面後將page fault加1
     * int page: 欲進入頁框的頁面
     */
    void SecondChance::replace(int page) {
        // 擁有二次機會者無法被替換,需找到已經沒有二次機會者,或者將二次機會歸零
        while (_frames[_pointer].second_chance != 0) {
            _frames[_pointer].second_chance = 0;
            pointer_to_next();
        }

        // 當pointer指到要被替換的頁面時,更換頁面
        _frames[_pointer].stored_page = page;
        pointer_to_next();

        // page fault加1
        _page_fault++;
    }

    /*
     * 指標移動至下一格
     */
    void SecondChance::pointer_to_next() {
        _pointer = (_pointer + 1) % _frames_num;
    }


} // Algorithms