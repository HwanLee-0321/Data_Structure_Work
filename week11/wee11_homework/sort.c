#include <stdio.h>
#include <stdlib.h> // for malloc and free

// 배열 출력 함수 (정렬 과정 확인용)
void printArray(int arr[], int size, const char* msg) {
    printf("%s: ", msg);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. 선택 정렬 (Selection Sort)
// 가장 작은(또는 큰) 요소를 찾아 정렬되지 않은 부분의 맨 앞으로 옮기는 방식
void selectionSort(int arr[], int n) {
    printf("--- 선택 정렬 시작 ---\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // 정렬되지 않은 부분에서 최솟값 찾기
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 최솟값을 현재 위치(i)와 교환
        // (만약 이미 제자리에 있다면 교환하지 않아도 됨)
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
        printArray(arr, n, "단계별 정렬");
    }
    printf("--- 선택 정렬 완료 ---\n\n");
}

// 2. 삽입 정렬 (Insertion Sort)
// 현재 요소를 이미 정렬된 부분의 적절한 위치에 삽입하는 방식
void insertionSort(int arr[], int n) {
    printf("--- 삽입 정렬 시작 ---\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // 현재 삽입할 요소
        int j = i - 1;

        // key를 정렬된 부분(arr[0...i-1])에 삽입할 위치 찾기
        // key보다 큰 요소들을 한 칸씩 뒤로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // key 삽입
        printArray(arr, n, "단계별 정렬");
    }
    printf("--- 삽입 정렬 완료 ---\n\n");
}

// 3. 버블 정렬 (Bubble Sort)
// 인접한 두 요소를 비교하여 순서가 맞지 않으면 교환하는 과정을 반복
void bubbleSort(int arr[], int n) {
    printf("--- 버블 정렬 시작 ---\n");
    for (int i = 0; i < n - 1; i++) {
        // 각 회전마다 가장 큰 요소가 맨 뒤로 이동
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 인접한 요소 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n, "단계별 정렬");
    }
    printf("--- 버블 정렬 완료 ---\n\n");
}

// 4. 셸 정렬 (Shell Sort)
// 삽입 정렬의 단점을 보완, 불연속적인 부분 리스트에 대해 삽입 정렬 적용
void shellSort(int arr[], int n) {
    printf("--- 셸 정렬 시작 ---\n");
    // 갭(gap) 설정 및 감소
    for (int gap = n / 2; gap > 0; gap /= 2) { // 교수님 지시에 따라 gap을 2로 나눔
        printf("Gap: %d\n", gap);
        // 각 갭에 대해 삽입 정렬 수행
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // 갭만큼 떨어진 요소들과 비교하며 삽입
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printArray(arr, n, "단계별 정렬 (현재 Gap)");
    }
    printf("--- 셸 정렬 완료 ---\n\n");
}

// 5. 병합 정렬 (Merge Sort) - 보조 함수
// 두 개의 정렬된 부분 리스트를 병합
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // 왼쪽 부분 리스트 크기
    int n2 = right - mid;    // 오른쪽 부분 리스트 크기

    // 임시 배열 생성
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 데이터 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 임시 배열들을 병합하여 원본 배열에 저장
    i = 0; // 첫 번째 서브배열 인덱스
    j = 0; // 두 번째 서브배열 인덱스
    k = left; // 병합된 서브배열 인덱스
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남아있는 요소들을 원본 배열에 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 임시 배열 해제
    free(L);
    free(R);
}

// 5. 병합 정렬 (Merge Sort) - 주 함수
// 분할 정복 방식: 리스트를 분할하고 재귀적으로 정렬 후 병합
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 중간 지점

        // 왼쪽 부분 정렬
        mergeSort(arr, left, mid);
        // 오른쪽 부분 정렬
        mergeSort(arr, mid + 1, right);

        // 정렬된 두 부분을 병합
        merge(arr, left, mid, right);
        printf("병합 완료: ");
        for(int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// 6. 퀵 정렬 (Quick Sort) - 보조 함수 (분할)
// 피벗을 기준으로 리스트를 두 부분으로 분할
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 첫 번째 요소를 피벗으로 선택 (강의 지시)
    int i = low;
    int j = high;

    while (i < j) {
        // 피벗보다 작은 값을 찾을 때까지 i 이동 (오른쪽으로)
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        // 피벗보다 큰 값을 찾을 때까지 j 이동 (왼쪽으로)
        while (arr[j] > pivot) {
            j--;
        }
        // i와 j가 교차하지 않았다면 요소 교환
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 피벗을 제자리로 이동 (j 위치)
    arr[low] = arr[j];
    arr[j] = pivot;
    return j; // 피벗의 최종 위치 반환
}

// 6. 퀵 정렬 (Quick Sort) - 주 함수
// 분할 정복 방식: 피벗을 기준으로 분할하고 재귀적으로 정렬
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 분할 (피벗을 기준으로 작은 값/큰 값 나누고 피벗 제자리 찾음)
        int pi = partition(arr, low, high);

        printf("분할 후 (피벗 %d): ", arr[pi]);
        printArray(arr, high - low + 1, "배열 상태"); // 전체 배열 상태 출력
        
        // 왼쪽 부분 재귀적으로 정렬
        quickSort(arr, low, pi - 1);
        // 오른쪽 부분 재귀적으로 정렬
        quickSort(arr, pi + 1, high);
    }
}


// 7. 힙 정렬 (Heap Sort) - 보조 함수 (힙 생성/유지)
// 주어진 서브트리를 힙 속성(최대 힙)을 만족하도록 재구성
void heapify(int arr[], int n, int i) {
    int largest = i;     // 현재 노드를 가장 큰 값으로 가정
    int left = 2 * i + 1;  // 왼쪽 자식 노드 인덱스
    int right = 2 * i + 2; // 오른쪽 자식 노드 인덱스

    // 왼쪽 자식이 현재 가장 큰 값보다 크면 largest 업데이트
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 오른쪽 자식이 현재 가장 큰 값보다 크면 largest 업데이트
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // largest가 현재 노드가 아니면 (자식 중 더 큰 값이 있다면)
    if (largest != i) {
        // 값 교환
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // 재귀적으로 힙 속성을 유지
        heapify(arr, n, largest);
    }
}

// 7. 힙 정렬 (Heap Sort) - 주 함수
// 힙 자료구조를 활용하여 정렬
void heapSort(int arr[], int n) {
    printf("--- 힙 정렬 시작 ---\n");
    // 힙 생성 (최대 힙으로 만듦)
    // 마지막 부모 노드부터 루트 노드까지 heapify 호출
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    printf("최초 힙 구성: ");
    printArray(arr, n, "");

    // 힙에서 요소 추출 및 정렬
    for (int i = n - 1; i > 0; i--) {
        // 루트(가장 큰 값)를 현재 배열의 맨 끝으로 이동
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 힙 크기를 줄이고, 남은 요소에 대해 힙 속성 유지
        heapify(arr, i, 0);
        printArray(arr, n, "단계별 정렬");
    }
    printf("--- 힙 정렬 완료 ---\n\n");
}


// 8. 기수 정렬 (Radix Sort) - 보조 함수 (자릿수별 정렬을 위한 계수 정렬)
// 특정 자릿수(exp)를 기준으로 배열을 정렬
void countSort(int arr[], int n, int exp) {
    int *output = (int*)malloc(n * sizeof(int)); // 정렬된 요소를 저장할 임시 배열
    int count[10] = {0}; // 0부터 9까지의 숫자를 세기 위한 배열

    // 각 숫자의 자릿수 값(0~9)을 카운트
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // count[i]가 현재 자릿수 값 i의 최종 위치를 나타내도록 누적 합 계산
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // output 배열에 정렬된 순서대로 요소 배치
    // 뒤에서부터 채워야 안정성을 유지할 수 있음
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 정렬된 요소를 원본 배열로 복사
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    free(output);
}

// 8. 기수 정렬 (Radix Sort) - 최대값 찾기 보조 함수
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 8. 기수 정렬 (Radix Sort) - 주 함수
// 비교 연산 없이 자릿수(버킷)를 이용해 정렬
void radixSort(int arr[], int n) {
    printf("--- 기수 정렬 시작 ---\n");
    // 배열에서 가장 큰 값을 찾아 자릿수 개수를 결정
    int m = getMax(arr, n);

    // 각 자릿수(1의 자리, 10의 자리, ...)에 대해 계수 정렬 수행
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        printf("자릿수 %d 기준 정렬: ", exp);
        printArray(arr, n, "");
    }
    printf("--- 기수 정렬 완료 ---\n\n");
}


int main() {
    // 테스트 배열들 (각 정렬마다 원본 배열 복사해서 사용)
    int arr_selection[] = {64, 25, 12, 22, 11};
    int n_selection = sizeof(arr_selection) / sizeof(arr_selection[0]);
    printArray(arr_selection, n_selection, "원본 배열 (선택 정렬)");
    selectionSort(arr_selection, n_selection);
    printArray(arr_selection, n_selection, "최종 정렬 결과 (선택 정렬)");

    int arr_insertion[] = {12, 11, 13, 5, 6};
    int n_insertion = sizeof(arr_insertion) / sizeof(arr_insertion[0]);
    printArray(arr_insertion, n_insertion, "원본 배열 (삽입 정렬)");
    insertionSort(arr_insertion, n_insertion);
    printArray(arr_insertion, n_insertion, "최종 정렬 결과 (삽입 정렬)");

    int arr_bubble[] = {5, 1, 4, 2, 8};
    int n_bubble = sizeof(arr_bubble) / sizeof(arr_bubble[0]);
    printArray(arr_bubble, n_bubble, "원본 배열 (버블 정렬)");
    bubbleSort(arr_bubble, n_bubble);
    printArray(arr_bubble, n_bubble, "최종 정렬 결과 (버블 정렬)");

    int arr_shell[] = {10, 3, 8, 22, 6, 1, 20, 0, 4, 15, 16};
    int n_shell = sizeof(arr_shell) / sizeof(arr_shell[0]);
    printArray(arr_shell, n_shell, "원본 배열 (셸 정렬)");
    shellSort(arr_shell, n_shell);
    printArray(arr_shell, n_shell, "최종 정렬 결과 (셸 정렬)");

    int arr_merge[] = {26, 5, 37, 1, 61, 11, 59, 15};
    int n_merge = sizeof(arr_merge) / sizeof(arr_merge[0]);
    printf("--- 병합 정렬 시작 ---\n");
    printArray(arr_merge, n_merge, "원본 배열 (병합 정렬)");
    mergeSort(arr_merge, 0, n_merge - 1);
    printf("--- 병합 정렬 완료 ---\n");
    printArray(arr_merge, n_merge, "최종 정렬 결과 (병합 정렬)");

    int arr_quick[] = {5, 3, 7, 8, 2, 6, 9, 4, 1};
    int n_quick = sizeof(arr_quick) / sizeof(arr_quick[0]);
    printf("--- 퀵 정렬 시작 ---\n");
    printArray(arr_quick, n_quick, "원본 배열 (퀵 정렬)");
    quickSort(arr_quick, 0, n_quick - 1);
    printf("--- 퀵 정렬 완료 ---\n");
    printArray(arr_quick, n_quick, "최종 정렬 결과 (퀵 정렬)");

    int arr_heap[] = {12, 11, 13, 5, 6, 7};
    int n_heap = sizeof(arr_heap) / sizeof(arr_heap[0]);
    printArray(arr_heap, n_heap, "원본 배열 (힙 정렬)");
    heapSort(arr_heap, n_heap);
    printArray(arr_heap, n_heap, "최종 정렬 결과 (힙 정렬)");

    int arr_radix[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n_radix = sizeof(arr_radix) / sizeof(arr_radix[0]);
    printArray(arr_radix, n_radix, "원본 배열 (기수 정렬)");
    radixSort(arr_radix, n_radix);
    printArray(arr_radix, n_radix, "최종 정렬 결과 (기수 정렬)");

    return 0;
}
