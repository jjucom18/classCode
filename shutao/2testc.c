  #include<stdio.h>
   #include<stdlib.h>
   typedef struct_node{
   void *data;
   struct_node *next;
   } Node;
   typedf struct_listedList{
    Node *head;
    Node *tail;
    Node *current;}
    LinkedList;

    //建立单链表
   void initializelist(Linkedlist *list){

  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;//初始化

   }
   void addHead(LinkedList *list, void* data) {
   Node *node = (Node*) malloc(sizeof(Node));
   node->data = data;
   if (list->head == NULL) {
   list->tail = node;
   node->next = NULL;}
   else{
     node->next = list->head;

  }
   list->head = node;}
   void addTail(LinkedList *list, void* data) {
   Node *node = (Node*) malloc(sizeof(Node));
   node->data = data;
   node->next = NULL;
 if (list->head == NULL) {
   list->head = node;}
   else{
     list->tail->next = node;

  }
   list->tail = node;}  // 头节点与尾节点添加数据
   void delete(LinkedList *list, Node *node) {
   if (node == list->head) {
   if(list->head->next == NULL) {
   list->head = list->tail - NULL;}
   else {
   list->head = list->head->next;

 } else {
   Node *tmp = list ->head;
   while (tmp != NULL && tmp->next != node){
   tmp = tmp->next;}
   if (tmp != NULL) {
   tmp->next = node ->next;}}
   free(node);}     //删除节点
   Node *getNode(LinkedList *list, COMPARE compare , void* data{
   Node *node = list->head;
   while (node != NULL) {
   if (compare (node->data, data) == 0) {
   return node;}
   node = node->next;}
   return NULL;}   //返回包含指定数据的节点指针
   void displayLinkedList(LinkedList *list, DISPLAY display) {
      printf("\nLinked List\n");
 Node  *current = list->head;
      while (current != NULL){
      display(current->data);
      current  = current->next;}}   //打印

