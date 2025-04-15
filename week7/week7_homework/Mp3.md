# 🎵 Mp3.c

> 이중 연결 리스트(Doubly Linked List)를 사용하여 MP3 재생기와 유사한 곡 탐색 기능을 구현한 C 프로그램입니다.

---

## 📌 개요

- 곡 이름을 문자열(`char[]`)로 받아서 이중 연결 리스트 노드로 저장
- 현재 재생 중인 노드를 `current` 포인터로 추적
- 사용자 입력을 통해 곡을 추가하거나, 좌우 방향(←, →)으로 이동

---

## 📚 주요 기능

### 🔹 리스트 초기화

```c
void init(DListNode* phead);
```
- 헤드 노드를 자기 자신과 양방향으로 연결하여 초기화

---

### 🔹 곡 삽입

```c
void dinsert(DListNode *before, element data);
```
- `before` 노드 다음에 새로운 곡 노드 추가  
- 문자열(`char[]`) 데이터를 `strcpy`로 복사

---

### 🔹 곡 삭제

```c
void ddelete(DListNode* head, DListNode* removed);
```
- 현재 노드를 삭제하고 양쪽 노드를 다시 연결  
- 헤드 노드는 삭제하지 않음

---

### 🔹 리스트 출력

```c
void print_dlist(DListNode* phead);
```
- 리스트의 노드를 순회하며 출력  
- `current` 노드일 경우 `#곡명#` 형태로 강조 출력

---

## 🧠 구조체 정의

```c
typedef char element[100];

typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

DListNode* current;
```

- `element`: 최대 100자의 곡 이름을 저장하는 문자열 배열
- `current`: 현재 재생 중인 노드를 가리키는 전역 포인터

---

## 🛠️ 컴파일 & 실행

```bash
# 컴파일
gcc -o Mp3 Mp3.c

# 실행
./Mp3
```

---

## 💡 학습 포인트

- ✅ 이중 연결 리스트 구조 활용
- ✅ 문자열 데이터 삽입 (`strcpy`)
- ✅ 현재 위치를 기준으로 순회하며 상태 추적
- ✅ 동적 메모리 관리 (`malloc`, `free`)

---

## 🔍 예시 출력

```
<-| song1 |-> <-| #song2# |-> <-| song3 |-> 
```

- `#song2#`는 현재 재생 중인 노드
- 좌/우 이동 명령으로 `current`를 변경하며 탐색

---

## ⚠️ 개선 포인트

- 입력 오류에 대한 예외 처리(예: 비어 있는 리스트에서 삭제 시)
- 사용자 인터페이스 기능 보완 가능 (메뉴 선택 등)
