/**
 * Produced by Bruce from Korea
 * Since 2023.11
*/


#include "utill_sort.h"


int compare_int(const void *selected, const void *target){
    if(*(const int *)target < *(const int *)selected) 
        return HIGH;
    else if(*(const int *)selected < *(const int *)target)
        return LOW;
    else
        return 0;    
}

int compare_str(const void *selected, const void *target){
    // strcmp 함수를 사용하여 두 문자열을 비교
    int result = strcmp((const char *)selected, (const char *)target);

    // 비교 결과에 따라 우선순위를 반환
    if (result < 0) {
        return LOW;  // selected 가 우선순위 높음 -1
    } else if (result > 0) {
        return HIGH;   // target 가 우선순위 높음 1
    } else {
        return EQU;   // 두 문자열이 같은 우선순위 0
    }
}

// Swap two pointers
void swap_pointers(void **selected, void **target) {
    void *temp = *selected;
    *selected = *target;
    *target = temp;
}
