#include"shiyan4.h"

double Price = 0.05;

CarStack *InitCarStack(){
	CarStack *stack;
	stack = (CarStack *)malloc(sizeof(CarStack));
	stack->top = -1;
	return stack;
}
TmpStack *InitTmpStack(){
	TmpStack *stack;
	stack = (TmpStack *)malloc(sizeof(TmpStack));
	stack->top = -1;
	return stack;
}

int EmptyCar(CarStack *stack){
	return stack->top == -1;
}
int EmptyTmp(TmpStack *stack){
	return stack->top == -1;
}

int FullCar(CarStack *stack){
	return stack->top == MaxSize-1;
}
int FullTmp(TmpStack *stack){
	return stack->top == MaxSize-1;
}

void PushCarStack(CarStack *stack, Car data){
	if( !FullCar(stack)){
		stack->top++;
		stack->data[stack->top] = data;
	}
	return; 
}
void PushTmpStack(TmpStack *stack, Car data){
	if( !FullTmp(stack)){
		stack->top++;
		stack->data[stack->top] = data;
	}
	return; 
}

void PopCarStack(CarStack *stack, Car *data){
	if( !EmptyCar(stack)){
		*data = stack->data[stack->top];
		stack->top--;
	}
	return;
}

void PopTmpStack(TmpStack *stack, Car *data){
	if( !EmptyTmp(stack)){
		*data = stack->data[stack->top];
		stack->top--;
	}
	return;
}

void TopCarStack(CarStack *stack, Car *data,int tmp){
	if( !EmptyCar(stack)){
		*data = stack->data[tmp];
	}
	return;
}
void TopTmpStack(TmpStack *stack, Car *data){
	if( !EmptyTmp(stack)){
		*data = stack->data[stack->top];
	}
	return;
}


ListQueue *InitQueue(){
	ListQueue *list;
	CarQueueNode *head;
	list = (ListQueue *)malloc(sizeof(ListQueue));
	head = (CarQueueNode *)malloc(sizeof(CarQueueNode));
	head->next = NULL;
	list->front = head;
	list->rear = head;

	return list;
}

void InQueue(ListQueue *list, Car data){
	CarQueueNode *node;
	node = (CarQueueNode *)malloc(sizeof(CarQueueNode));
	node->data = data;
	node->next = NULL;
	list->rear->next = node;
	list->rear = node;

	return;

}

int EmptyQueue(ListQueue *list){
	return list->front == list->rear;
}

void OutQueue(ListQueue *list, Car *data){
	CarQueueNode *node;
	if( !EmptyQueue(list)){
		node = list->front->next;
		list->front->next = node->next;
		*data = node->data;
		free(node);
		if(list->front->next == NULL)
			list->rear = list->front;
	}
	return;
}

void ChangePrice(){
	
	system("clear");
	printf("当前价格为%lf分/秒\n",Price);
	printf("请输入新的价格\n");
	scanf("%lf",&Price);
	getchar();
	printf("\n");
	printf("请按任意键继续\n");
	getchar();
	system("clear");
	return ;

}//更改价格

int PlaceQueue(ListQueue *list){
	int num = 0;
	CarQueueNode *tmp = list->front->next;
	while(tmp != list->rear){
		tmp = tmp->next;
		num++;
	}
	return num;
}//队列的大小

int PlaceStack(CarStack *stack,char number[]){
	int tmp = stack->top;
	while(tmp != -1 && strcmp(stack->data[tmp].number,number)){
		tmp--;
	}
	return tmp;
}//查找车在栈中的位置

void display(timefrom *from,Car *car){
	printf("进入时间:%04u-%02u-%02u  %02u:%02u:%02u\n",from->tm_year+1900,from->tm_mon+1,from->tm_mday,from->tm_hour,from->tm_min,from->tm_sec );
	printf("车牌号为%s\t",car->number );
	return;
}//输出车的进入时间和车牌号

void displayStack(CarStack *stack){
	timefrom *from;
	printf("停车场状态\n");
	printf("\n");
	for(int i = stack->top; i > -1; i-- ){
		Car *car = (Car *)malloc(sizeof(Car));
		TopCarStack(stack, car, i);
		from = localtime(&(car->atime));
		display(from,car);									//输出车的进入时间和车牌号
		printf("停车位置为第%d个\n", i + 1);
		free(car);
		printf("\n");
	}
	return;					
}//输出停车场状态

void displayQueue(ListQueue *list){
	CarQueueNode *tmp = list->front->next;
	timefrom *from;
	int num = 0;
	printf("便道状态\n");
	printf("\n");
	while(tmp != NULL){
		num++;
		from = localtime(&(tmp->data.atime));
		printf("车牌号为%s\t",tmp->data.number );
		printf("停车位置为第%d个\n",num );	//输出队列车信息

		tmp = tmp->next;

	}
	printf("\n");
	return;
}//输出便道状态

void QueueToStack(ListQueue *list,CarStack *stack){

	if (list->front->next != NULL){
		Car *car = (Car *)malloc(sizeof(Car));
		printf("进入便道\n");
		printf("车牌号为%s\n",list->front->next->data.number );

		OutQueue(list, car);
		car->atime = time(0);
		PushCarStack(stack,*car);
		printf("成功进入 !\n");
	}else{
		printf("查找失败 !\n");
	}
	return;
}

void displayLeave(Car *leaveCar){

	timefrom *from;									 			//timefrom为 struct tm类型将时间格式化输出
	leaveCar->ltime = time(0);									//记录离开的时间
	from = localtime(&(leaveCar->ltime));
	printf("已离开 !\n");
	printf("离开时间:%04u-%02u-%02u  %02u:%02u:%02u\n",
		from->tm_year+1900,from->tm_mon+1,from->tm_mday,from->tm_hour,from->tm_min,from->tm_sec );
	printf("车牌号为%s\n",leaveCar->number );
	printf("经历时间为:%lu秒\n",leaveCar->ltime - leaveCar->atime);
	leaveCar->price = Price*(leaveCar->ltime - leaveCar->atime);
	printf("价格为: %lf分/秒\n",Price);
	printf("本次费用为:%lf分\n",leaveCar->price );
	free(leaveCar);
	printf("\n");
}


void Inparking(CarStack *stack,ListQueue *list){
	system("clear");
	char judge = 'y';
	timefrom *from;										
	while(judge != 'n'){
		Car *car = (Car *)malloc(sizeof(Car));
		car->arrive = 1;										//bool类型赋值为1表示到达
		car->leave = 0;											//bool类型赋值为0表示未离开
		printf("请输入汽车牌号\n");
		scanf("%s",car->number);
		
		int flat = 0;
		if( !FullCar(stack)){
			car->atime = time(0);								//获取当前时间
			from = localtime(&(car->atime));					//时间按格式输出	
			PushCarStack(stack,*car);							//如果(栈)停车场未满则进入
			flat = 1;
		}else{
			InQueue(list, *car);								//如果停车场已满则进入便道(队列)
		}
		
		if (flat == 1){
			display(from,car);
			printf("车进入停车场\t");
			printf("停车位置为第%d个\n", (stack->top) + 1);		//输出入栈车信息
		}
		else{
			printf("车牌号为%s\t",car->number );
			printf("车进入便道\t");
			printf("停车位置为第%d个\n",PlaceQueue(list) + 1 );	//输出入队列车信息

		}
		printf("\n");
		printf("是否继续 ?(y or n)\n");
		getchar();
		scanf("%c",&judge );
	}
	system("clear");
	getchar();
	
	return;
}//进入停车场




void Outparking(CarStack *stack,ListQueue *list){

	system("clear");
	int placetmp;
	Car *car;
	
	TmpStack *stack_tmp;										//辅助栈
	stack_tmp = InitTmpStack();									//初始化辅助栈
	char number[30];

	displayStack(stack);										//输出停车场信息
	printf("\n");
	printf("请输入你要离开车俩的车牌号\n");
	scanf("%s",number);											//获取车牌号
	placetmp = PlaceStack(stack,number);						//获取车在栈中的位置

	while(stack->top > placetmp){

		car = (Car *)malloc(sizeof(Car));
		PopCarStack(stack, car);
		PushTmpStack(stack_tmp, *car);
		free(car);
	}															//车退出到辅助栈
	system("clear");											//清屏
	Car *leaveCar = (Car *)malloc(sizeof(Car));
	PopCarStack(stack, leaveCar);								//离开的车俩

	displayLeave(leaveCar);										//输出离开车的信息

	while( !EmptyTmp(stack_tmp)){
		Car *car = (Car *)malloc(sizeof(Car));
		PopTmpStack(stack_tmp,car);
		PushCarStack(stack,*car);
		free(car);
	}															//从辅助栈进入到停车场
	displayStack(stack);										//输出停车场信息
	displayQueue(list);											//输出便道信息
	getchar();
	printf("\n");
	printf("请按任意键继续\n");
	getchar();
	system("clear");

	QueueToStack(list,stack);									//便道到停车场
	displayStack(stack);
	printf("\n");
	displayQueue(list);

	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	system("clear");
	
	return;
	

}//离开停车场



int PromptInput(CarStack *stack,ListQueue *list){

	char flat;
	printf("请选择你要进行的操作\n");
	printf("1.进入停车场\n");
	printf("2.离开停车场\n");
	printf("0.退出\n");
	flat = getchar();
	switch(flat){
		case '1': Inparking(stack,list);
					break;
		case '2': Outparking(stack,list);
					break;
		case '0': return 1;
	}
	return 0;
}//用户界面

