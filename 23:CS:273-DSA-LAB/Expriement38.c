#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void leftView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        int size = rear - front;
        printf("%d ", queue[front + 1]->data);

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[++front];
            if (curr->left) queue[++rear] = curr->left;
            if (curr->right) queue[++rear] = curr->right;
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->left->left = createNode(7);
    root->right->left->right = createNode(8);

    printf("Left view of the binary tree: ");
    leftView(root);

    return 0;
}
