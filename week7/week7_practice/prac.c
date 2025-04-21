#include <stdio.h>

// 정렬되지 않은 배열에서 선형 탐색을 수행
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1; // 못 찾은 경우
}

int main() {
    int arr[] = {5, 3, 9, 1, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("찾고자 하는 숫자를 입력하세요: ");
    scanf("%d", &target);

    int index = linear_search(arr, size, target);

    if (index != -1) {
        printf("%d는 배열의 %d번째 인덱스에 있습니다.\n", target, index);
    } else {
        printf("%d는 배열에 존재하지 않습니다.\n", target);
    }

    return 0;
}