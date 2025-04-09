#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int hakbun; // 학번
} Student;

// 삽입 정렬
void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].hakbun > key.hakbun) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printStudents(Student arr[], int n) {
    printf("\n[정렬된 학생 목록]\n");
    for (int i = 0; i < n; i++) {
        printf("이름: %s, 학번: %d\n", arr[i].name, arr[i].hakbun);
    }
}

int main() {
    Student students[MAX];
    int n;

    printf("학생 수 입력: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n학생 %d 이름: ", i + 1);
        scanf("%s", students[i].name);
        printf("학생 %d 학번: ", i + 1);
        scanf("%d", &students[i].hakbun);
    }

    insertionSort(students, n);
    printStudents(students, n);

    return 0;
}