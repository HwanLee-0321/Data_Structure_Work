# BankServiceSimulation.c 코드 설명

## ✨ 개요
이 코드는 **은행 고객 서비스 시뮬레이션**을 구현한 예제로, 고객 도착 시간 및 서비스 시간을 기반으로 **대기열(queue)** 을 관리하며 총 대기 시간 및 평균 대기 시간을 계산합니다. 실제 운영 시뮬레이션에 가까운 큐 활용 예입니다.

---

## ✅ 주요 구조 및 기능 설명

### ▶ element 구조체
```c
typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;
```
- 고객 1명을 나타내는 구조체
  - `id`: 고객 번호
  - `arrival_time`: 도착 시간
  - `service_time`: 소요 서비스 시간

### ▶ 큐 정의
```c
#define MAX_QUEUE_SIZE 5

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
```
- 원형 큐 구현
- `front`, `rear` 인덱스를 순환하며 큐 관리

---

### ▶ 큐 관련 함수
- `init_queue()`: front, rear 초기화
- `is_empty() / is_full()`: 상태 확인
- `enqueue() / dequeue()`: 원형 큐 기반 삽입/삭제
- `queue_print()`: 큐 상태 출력 (디버깅용)

```c
enqueue(&q, customer);
customer = dequeue(&q);
```

---

## 학습 예시: 작동 순서

### 고객 예시
```text
고객 ID: 0, 도착: 0, 서비스: 3
고객 ID: 1, 도착: 2, 서비스: 2
고객 ID: 2, 도착: 4, 서비스: 1
```

### 시뮬레이션 로직
```c
while (time < MAX_TIME) {
    if (고객이 도착함)
        enqueue(q, customer);

    if (남은 서비스 없음 && 큐에 대기 고객 있음)
        dequeue(); // 고객 불러오기

    time++;
    service_time--;
    total_wait_time++;
}
```

---

## ⚠ 관찰 함수 & 경고
- `MAX_QUEUE_SIZE` = 5 이므로 6번째 고객은 받지 못할 수 있음
- 평균 대기 시간 = 총 대기 시간 / 고객 수
- 고객 도착 시간 고려 필수: CPU 스케줄링과 유사

---

## 평가
- **실제 업무 시뮬레이션에 활용** 가능
- 단순 큐 구현을 **현실적 문제**에 적용하는 예
- 추후 **우선순위 큐**, **멀티서버** 시뮬레이션으로 확장 가능

---

## 파일 명
**BankServiceSimulation.c**: 고객 응대 시뮬레이션을 통해 큐의 활용성을 학습하는 코드 예제

