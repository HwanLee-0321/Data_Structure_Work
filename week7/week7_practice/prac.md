# 선형 탐색 (Linear Search) - C언어 코드 상세 설명

이 문서는 정렬되지 않은 배열에서 **선형 탐색(linear search)** 을 수행하는 C 언어 코드에 대한 상세한 설명을 제공합니다.

## 📌 개요
- **문제**: 정렬되지 않은 배열에서 특정 값을 찾는다.
- **해결 방법**: 배열의 처음부터 끝까지 순차적으로 하나씩 비교하여 일치하는 값을 찾는다.

---

## 🔢 전체 코드 구조
```c
#include <stdio.h>

int linear_search(int arr[], int size, int target);

int main();
```

---

## 1. 헤더 포함
```c
#include <stdio.h>
```
- `printf`, `scanf` 같은 입출력 함수를 사용하기 위한 표준 입출력 라이브러리 포함.

---

## 2. 선형 탐색 함수 정의
```c
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```
- `arr[]`: 탐색 대상 배열
- `size`: 배열의 크기
- `target`: 찾고자 하는 값
- **반복문**을 사용해 배열의 모든 요소를 순차적으로 탐색
- 찾으면 해당 인덱스를 즉시 반환
- 끝까지 못 찾으면 `-1` 반환

---

## 3. main 함수 동작
```c
int arr[] = {5, 3, 9, 1, 4, 7, 6};
```
- 테스트용 정수 배열 선언

```c
int size = sizeof(arr) / sizeof(arr[0]);
```
- 배열의 크기를 동적으로 계산
- 전체 바이트 크기를 요소 하나의 크기로 나눈다

```c
int target;
printf("찾고자 하는 숫자를 입력하세요: ");
scanf("%d", &target);
```
- 사용자로부터 찾고자 하는 숫자 입력 받음

```c
int index = linear_search(arr, size, target);
```
- 입력 받은 값을 기반으로 탐색 수행

```c
if (index != -1) {
    printf("%d는 배열의 %d번째 인덱스에 있습니다.\n", target, index);
} else {
    printf("%d는 배열에 존재하지 않습니다.\n", target);
}
```
- 탐색 성공/실패 여부에 따라 결과 출력

---

## ✅ 실행 예시
```
찾고자 하는 숫자를 입력하세요: 4
4는 배열의 4번째 인덱스에 있습니다.
```

---

## 💡 정리
- 선형 탐색은 단순하고 구현이 쉬우며, **정렬되지 않은 데이터**에 적합
- 시간복잡도: **O(n)**
- 배열의 크기가 작을 경우에는 유용하지만, 크면 비효율적

---

## 📚 확장 아이디어
- 탐색 시 비교 횟수 출력
- 사용자 입력 배열로 변경
- 다른 탐색 알고리즘 (이진 탐색 등)과 비교