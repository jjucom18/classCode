#include"main.h"
double Price = 0.05;

void ViewStack(CarStack *stack,ListQueue *list){

        system("clear");
        displayStack(stack);
        printf("\n");
        displayQueue(list);
        getchar();
        printf("请按任意键返回\n");
        getchar();
        system("clear");

        return;
}//输出停车场状态

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

int PromptInput(CarStack *stack,ListQueue *list){

        char flat;
        printf("请选择你要进行的操作\n");
        printf("1.进入停车场\n");
        printf("2.离开停车场\n");
        printf("3.查看停车场状态\n");
        printf("4.更改价格\n");
        printf("0.退出\n");
        flat = getchar();
        switch(flat){
                case '1': Inparking(stack,list);
                                        break;
                case '2': Outparking(stack,list);
                                        break;
                case '3': ViewStack(stack,list);
                                        break;
                case '4': ChangePrice();
                                        break;
                case '0': return 1;
        }
        return 0;
}//用户界面

void Inparking(CarStack *stack,ListQueue *list){
        system("clear");
        char judge = 'y';
        timefrom *from;                                                                       
        while(judge != 'n'){
                Car *car = (Car *)malloc(sizeof(Car));
                car->arrive = 1;                                                                                //bool类型赋值为1表示到达
                car->leave = 0;                                                                                 //bool类型赋值为0表示未离开

                printf("请输入汽车牌号\n");
                scanf("%s",car->number);

                int flat = 0;
                if( !FullCar(stack)){
                        car->atime = time(0);                                                           //获取当前时间
                        from = localtime(&(car->atime));                                        //时间按格式输出        
                        PushCarStack(stack,*car);                                                       //如果(栈)停车场未满则进入
                        flat = 1;
                }else{
                        InQueue(list, *car);                                                            //如果停车场已满则进入便道(队列)
                }

                if (flat == 1){
                        display(from,car);
                        printf("车进入停车场\t");
                        printf("停车位置为第%d个\n", (stack->top) + 1);         //输出入栈车>信息            
                }
                else{
                        printf("车牌号为%s\t",car->number );
                        printf("车进入便道\t");
                        printf("停车位置为第%d个\n",PlaceQueue(list) + 1 );     //输出入队列>车信息

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

        TmpStack *stack_tmp;                                                                            //辅助栈
        stack_tmp = InitTmpStack();                                                                     //初始化辅助栈
        char number[30];

        displayStack(stack);                                                                            //输出停车场信息
        printf("\n");
        printf("请输入你要离开车俩的车牌号\n");
        scanf("%s",number);                                                                                     //获取车牌号
        placetmp = PlaceStack(stack,number);                                            //获>取车在栈中的位置

        while(stack->top > placetmp){

                car = (Car *)malloc(sizeof(Car));
                PopCarStack(stack, car);
                PushTmpStack(stack_tmp, *car);
                free(car);
        }                                                                                                                       //车退出到辅助栈
        system("clear");                                                                                        //清屏
        Car *leaveCar = (Car *)malloc(sizeof(Car));
        PopCarStack(stack, leaveCar);                                                           //离开的车俩

        printf("正在驶出....\n");
        sleep(2);
        displayLeave(leaveCar);                                                                         //输出离开车的信息

        while( !EmptyTmp(stack_tmp)){
                Car *car = (Car *)malloc(sizeof(Car));
                PopTmpStack(stack_tmp,car);
                PushCarStack(stack,*car);
                free(car);
        }                                                                                                                       //从辅助栈进入到停车场
        displayStack(stack);                                                                            //输出停车场信息
        displayQueue(list);                                                                                     //输出便道信息
        getchar();
        printf("\n");
        printf("请按任意键继续\n");
        getchar();
        system("clear");

        QueueToStack(list,stack);                                                                       //便道到停车场

        displayStack(stack);
        printf("\n");
        displayQueue(list);

        printf("\n");
        printf("请按任意键返回\n");
        getchar();
        system("clear");

        return;


}//离开停车场

void QueueToStack(ListQueue *list,CarStack *stack){

        printf("查找是否有车在便道中....\n");
        sleep(2);                                                                                                       //暂停俩秒
        if (list->front->next != NULL){
                Car *car = (Car *)malloc(sizeof(Car));
                printf("查找成功 !\n");
                printf("车牌号为%s\n",list->front->next->data.number );
                printf("正在从便道驶入停车场....\n");
                sleep(3);

                OutQueue(list, car);
                car->atime = time(0);
                PushCarStack(stack,*car);
                printf("成功进入 !\n");
        }else{
                printf("查找失败 !\n");
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


int main(int argc, char **argv){
	CarStack *stack = InitCarStack();
	ListQueue *list = InitQueue();
	while(1){
		int flat;
		if(PromptInput(stack,list)) break;
	}
	return 0;
}
