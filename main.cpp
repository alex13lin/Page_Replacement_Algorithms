#include <iostream>
#include "SecondChance.h"

int main() {
    // 設定頁框數量
    int frames_num = 4;

    // 設定頁面
    int pages_requests[] = {1, 3, 2, 1, 0, 4, 0, 1, 2, 3, 2, 1, 1, 2, 4};
    int pages_requests_length = 15;

    // 指標指向頁面陣列
    int *ptr_pages = pages_requests;

    // 顯示二次機會算法結果
    auto *second_chance = new Algorithms::SecondChance(ptr_pages, pages_requests_length, frames_num);
    second_chance->run();
    delete second_chance;

    return 0;
}
