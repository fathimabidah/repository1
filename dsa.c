#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct Stack {
int items[MAX];
int top;
};

void initStack(struct Stack *s) {

s->top = -1;
}

int isEmpty(struct Stack *s) {
return s->top == -1;

}

void push(struct Stack *s, int value) {

if (s->top == MAX - 1) {
printf("Stack Overflow!\n");

} else {

s->items[++s->top] = value;

}
}

int pop(struct Stack *s) {
if (isEmpty(s)) {

printf("Stack Underflow!\n");

return -1;
} else {

return s->items[s->top--];

}
}

int graph[MAX][MAX];
int visited[MAX];

int n;

void addEdge(int u, int v) {

graph[u][v] = 1;
graph[v][u] = 1;

}

void displayTopology() {

printf("\nNetwork Topology (Adjacency Matrix):\n");

for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%d "

, graph[i][j]);
}
printf("\n");
}
}

int dfs(int src, int dest, struct Stack *path) {

visited[src] = 1;
push(path, src);
if (src == dest) {
return 1;
}

for (int i = 0; i < n; i++) {
if (graph[src][i] && !visited[i]) {
if (dfs(i, dest, path)) {

return 1;
}
}
}
pop(path);
return 0;
}

void sendPacket(int src, int dest) {

struct Stack path;
initStack(&path);

memset(visited, 0, sizeof(visited));

printf("\nSimulating packet transmission from Node %d to Node %d...\n"

, src, dest);

if (dfs(src, dest, &path)) {
printf("Packet path (push order): ");
for (int i = 0; i <= path.top; i++) {
printf("%d "

, path.items[i]);
}

printf("\nPacket reception (pop order): ");

while (!isEmpty(&path)) {
printf("%d "

, pop(&path));
}

printf("\nPacket successfully delivered!\n");

} else {

printf("No path exists between Node %d and Node %d.\n"

, src, dest);

}
}
int main() {

int choice, u, v, src, dest;

printf("Enter number of nodes in the network: ");

scanf("%d"
, &n);

memset(graph, 0, sizeof(graph));

while (1) {

printf("\n--- Computer Network Simulation ---\n");

printf("1. Add Connection\n");
printf("2. View Network Topology\n");
printf("3. Send Packet\n");
Aaron Loeb
CEO & Founder

printf("4. Exit\n
");
printf("Enter your choice:
");

scanf("%d"

, &choice);
switch (choice) {
case 1:

printf("Enter two nodes to connect (u v):
");

scanf("%d %d"

, &u, &v);
if (u < n && v < n) {
addEdge(u, v);

printf("Connection added between Node %d and Node %d.\n
"
, u, v);

} else {

printf("Invalid nodes!\n
");

}
break;
case 2:
displayTopology();
break;
case 3:

printf("Enter source node:
");

scanf("%d"

, &src);
printf("Enter destination node:
");

scanf("%d"

, &dest);
if (src < n && dest < n) {
sendPacket(src, dest);

} else {

printf("Invalid nodes!\n
");

}
break;
case 4:

printf("Exiting simulation...\n
");

exit(0);
default:

printf("Invalid choice! Try again.\n
");

}
}
return 0;
}
