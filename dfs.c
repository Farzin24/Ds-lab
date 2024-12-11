#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

int vertex_count = 0;

struct vertex {
	char data;
	bool visited;
};

struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];

int stack[MAX];
int top = -1;

void push(int data) {
	stack[++top] = data;
}

int pop() {
	return stack[top--];
}

bool is_stack_empty() {
	return top == -1;
}

void add_vertex(char data) {
	struct vertex *new = (struct vertex*)malloc(sizeof(struct vertex));
	new->data = data;
	new->visited = false;
	graph[vertex_count] = new;
	vertex_count++;
}

void add_edge(int start, int end) {
	adj_matrix[start][end] = 1;
	adj_matrix[end][start] = 1;
}

int adj_vertex(int vertex_get) {
	for (int i = 0; i < vertex_count; i++) {
		if (adj_matrix[vertex_get][i] == 1 && graph[i]->visited == false) {
			return i;
		}
	}
	return -1;
}

void display_vertex(int pos) {
	printf("%c -> ", graph[pos]->data);
}

void dfs(struct vertex *start_vertex, int start) {
	if (!start_vertex) {
		printf("\nNothing to display\n");
		return;
	}
	
	int unvisited;
	printf("\n|||||||||||||||||||||||||||||||\n");
	start_vertex->visited = true;
	display_vertex(start);
	push(start);
	
	while (!is_stack_empty()) {
		int current_vertex = stack[top];
		unvisited = adj_vertex(current_vertex);
		if (unvisited == -1) {
			pop();
		} else {
			graph[unvisited]->visited = true;
			display_vertex(unvisited);
			push(unvisited);
		}
	}
	printf("\n|||||||||||||||||||||||||||||||\n");
	
	for (int i = 0; i < vertex_count; i++) {
		graph[i]->visited = false;
	}
}

void show() {
	printf("\n.................................\n");
	for (int i = 0; i < vertex_count; i++) {
		printf("Edge position of '%c' is %d\n", graph[i]->data, i);
	}
	printf(".................................\n");
}

int main() {
	int opt;
	char data;
	int edge_1, edge_2;
	int start;

	for (int i = 0; i < MAX; i++) 
		for (int j = 0; j < MAX; j++) 
			adj_matrix[i][j] = 0;
	
	do {
		printf("\n1)Add vertex \n2)Create edge \n3)DFS Traversal \n0)Exit \nChoose option :: ");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				printf("\nEnter data to be added to vertex : ");
				scanf(" %c", &data);
				add_vertex(data);
				break;
			case 2:
	         	show();
				printf("\nEnter edge starting : ");
				scanf("%d", &edge_1);
				printf("\nEnter edge ending : ");
				scanf("%d", &edge_2);
				if (vertex_count - 1 < edge_1 || vertex_count - 1 < edge_2) {
					printf("\nThere is no vertex !!\n");
				} else {
					add_edge(edge_1, edge_2);
				}
				break;
			case 3:
				printf("\nEnter starting vertex position : ");
				scanf("%d", &start);
				dfs(graph[start], start);
				break;
			default:
				printf("\nInvalid option try again !! ...");
		}
	} while (opt != 0);
	
	return 0;
}

