# Lap4.c Explained

## ✨ 개요
`Lap4.c`는 단순 연결 리스트의 순서를 **역순(Reverse)** 되게 변경하는 것이 해당 파일의 확장점입니다.

---

## ▶️ 실행 순서
1. `head1` 에 값 10, 20, 30 순차적 삽입
2. 그 결과 표시 (`print_list`)
3. `reverse(head1)` 호출, 결과가 `head2`에 등록
4. 결과 표시 (`print_list`)

> ⚠️ `reerse()` 함수명과 `print_lis()` 호출에 오픈이 있으므로, 다음과 같이 수정 필요:
> ```c
> ListNode* reverse(ListNode* head);
> print_list(head2);
> ```

---

## 구조
```c
typedef struct {
    element data;
    struct ListNode *link;
} ListNode;
```

---

## 함수 내용

### 1. `reverse(ListNode *head)` (현재 오타: `reerse`)
- 전형: 다음과 같이 3개 통을 이용
```c
ListNode *p = head, *q = NULL, *r;
while (p != NULL) {
    r = q;
    q = p;
    p = p->link;
    q->link = r;
}
return q;
```
- 순차적인 리스트 경로를 역순로 변경

### 2. `insert_first`, `print_list` 구조 이전 파일과 동일

---

## 예제 실행 결과
```c
head1: 30 -> 20 -> 10 -> NULL
head2: 10 -> 20 -> 30 -> NULL
```

---

## 주의 점
- 함수 명/ 호출 오픈 모든 바위 수정 필요
- 그 이상의 데이터 유지는 각 자리의 `link` 초과 가 여부 결정
- 노드의 회신이 많은 경우 시간 버그와 무효 데이터 처리를 발생시킵니다.

---

## 개인적 평가
- 다른 리스트 파일의 기능을 모은 해당 파일은 "뒤집기"에 중점
- 바로 역순 가능한 데이터 구조와 적절한 호출문으로 구조

