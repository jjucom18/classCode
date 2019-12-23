#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int board[8][8];		// 棋盘
	struct _node *next;		// 指针域，指向链表中下一个结点
} Node;		// 链表节点数据结构

typedef struct _list {
	Node *head;		// 链表头结点
	int length;		// 链表长度
}List;		// 链表数据结构

void Add(List* list, int board[][8]) {
	int i, j;
	Node *node = (Node*)malloc(sizeof(Node));	// 创建节点
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			node->board[i][j] = board[i][j];	// 将棋盘复制到节点
		}
	}
	node->next = NULL;

	if (list->head == NULL)	// 如果链表为空，则设置该节点为第1个节点
		list->head = node;
	else {					// 否则插入到链表中
		node->next = list->head;
		list->head = node;
	}

	++list->length;		// 长度加1
}

List* EightQueue();
void SubEightQueue(List* list, int board[][8], int i, int n);
int isPeace(int board[][8], int i, int j);
void PrintBoard(int board[][8]);

List* EightQueue() {
	int board[8][8]; // 一个总的棋盘
	List *list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;	// 创建链表并初始化
	int i, j;
	for (i = 0; i < 8; ++i)	// 初始化棋盘，全都设置成0，表示为空
		for (j = 0; j < 8; ++j)
			board[i][j] = 0;
	SubEightQueue(list, board, 0, 8);	// 开始递归求解，递归即是栈的应用
	return list;
}

void SubEightQueue(List *list, int board[][8], int i, int n) {
	int j;

	// 深度搜索，这是树的应用，一层一层往下搜索，树状结构，找到能放着8个皇后的结果即停止往下搜索

	// i == n 表示已经放置完成了8个皇后，即找到了一个接，将其添加到链表中
	if (i == n) {
		Add(list, board);
	}
	else {	// 否则，表示还要继续扩展树，继续往下搜索
		for (j = 0; j < 8; ++j) {
			if (isPeace(board, i, j)) {	// 如果该位置可以放置一个皇后
				board[i][j] = 1;		// 则放置下去
				SubEightQueue(list, board, i + 1, n); // 在当前状态继续下一层搜索，也就是进入下一行进行放置操作
				board[i][j] = 0;		// 完成后取消该位置的放置
			}
		}
	}
}

int isPeace(int board[][8], int i, int j) {
	int k, l;
	for (k = 0; k < i; ++k)	//检查竖线
		if (board[k][j] == 1)
			return 0;
	for (k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l)	// 检查左上斜线
		if (board[k][l] == 1)
			return 0;
	for (k = i - 1, l = j + 1; k >= 0 && l < 8; --k, ++l)	// 检查右上斜线
		if (board[k][l] == 1)
			return 0;
	return 1;
}

void PrintBoard(int board[][8]) {
	int i, j;
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	List *head = EightQueue();
	int i;
	Node *node;
	printf("八皇后解的数量：%d\n", head->length);
	for (i = 0, node = head->head; i < head->length; ++i, node = node->next) {
		printf("第 %d 种解法：\n",i+1);
		PrintBoard(node->board);
	}
	return 0;
}

