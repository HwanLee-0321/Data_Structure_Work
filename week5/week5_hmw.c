#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* create_node(int data, Node* link) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = link;
    return new_node;
}

void insert_node(Node** head, Node* pre, Node* new_node) {
    if (*head == NULL) {
        new_node->link = NULL;
        *head = new_node;
    } else if (pre == NULL) {
        new_node->link = *head;
        *head = new_node;
    } else {
        new_node->link = pre->link;
        pre->link = new_node;
    }
}

void remove_node(Node** head, Node* pre, Node* removed) {
    if (pre == NULL)
        *head = removed->link;
    else
        pre->link = removed->link;
    free(removed);
}

void display(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

Node* concat(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    Node* p = head1;
    while (p->link != NULL)
        p = p->link;
    p->link = head2;
    return head1;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* search(Node* head, int x) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *p;

    // list1 = 30 -> 20 -> 10
    insert_node(&list1, NULL, create_node(10, NULL));
    insert_node(&list1, NULL, create_node(20, NULL));
    insert_node(&list1, NULL, create_node(30, NULL));
    display(list1);

    // list1 = 20 -> 10
    remove_node(&list1, NULL, list1);
    display(list1);

    // list2 = 80 -> 70 -> 60
    insert_node(&list2, NULL, create_node(60, NULL));
    insert_node(&list2, NULL, create_node(70, NULL));
    insert_node(&list2, NULL, create_node(80, NULL));
    display(list2);

    // list1 = list1 + list2
    list1 = concat(list1, list2);
    display(list1);

    // list1 역순
    list1 = reverse(list1);
    display(list1);

    // list1에서 20 탐색
    p = search(list1, 20);
    if (p != NULL)
        printf("탐색성공: %d\n", p->data);
    else
        printf("탐색실패\n");

    return 0;
}