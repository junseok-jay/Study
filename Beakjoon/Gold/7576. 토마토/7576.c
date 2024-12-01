#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x, y;
} tomato;

typedef struct {
    tomato xy[1000];
    int front, rear;
} queue;

void init_queue(queue* q) {
    q->front = 0;
    q->rear = 0;
}

int empty(queue* q) {
    return q->front == q->rear;
}

void enque(queue* q, int x, int y) {
    q->xy[q->rear].x = x;
    q->xy[q->rear].y = y;
    q->rear++;
}

tomato deque(queue* q) {
    return q->xy[q->front++];
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    int y, x;
    scanf("%d %d", &y, &x);

    int** arr = (int**)malloc(sizeof(int*) * x);
    queue que;
    init_queue(&que);

    for (int i = 0; i < x; i++) {
        arr[i] = (int*)malloc(sizeof(int) * y);
        for (int j = 0; j < y; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                enque(&que, i, j);
            }
        }
    }

    int days = 0;
    while (!empty(&que)) {
        int q_size = que.rear - que.front;

        for (int i = 0; i < q_size; i++) {
            tomato t = deque(&que);
            int _x = t.x;
            int _y = t.y;

            for (int j = 0; j < 4; j++) {
                int nx = _x + dx[j];
                int ny = _y + dy[j];

                if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] == 0) {
                    arr[nx][ny] = 1;
                    enque(&que, nx, ny);
                }
            }
        }

        if (!empty(&que)) {
            days++;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (arr[i][j] == 0) {
                printf("-1\n");
                goto cleanup;
            }
        }
    }

    printf("%d\n", days);

cleanup:
    for (int i = 0; i < x; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
    
