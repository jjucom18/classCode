#include"CarQueue.h"

ListQueue *InitQueue()
{
        ListQueue *list;
        CarQueueNode *head;
        list = (ListQueue *)malloc(sizeof(ListQueue));
        head = (CarQueueNode *)malloc(sizeof(CarQueueNode));
        head->next = NULL;
        list->front = head;
        list->rear = head;

        return list;
}

void InQueue(ListQueue *list, Car data)
{
        CarQueueNode *node;
        node = (CarQueueNode *)malloc(sizeof(CarQueueNode));
        node->data = data;
        node->next = NULL;
        list->rear->next = node;
        list->rear = node;

}

int EmptyQueue(ListQueue *list)
{
        return list->front == list->rear;
}

void OutQueue(ListQueue *list, Car *data)
{
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

int PlaceQueue(ListQueue *list)
{
        int num = 0;
        CarQueueNode *tmp = list->front->next;
        while(tmp != list->rear){
                tmp = tmp->next;
                num++;
        }
        return num;
}

void displayQueue(ListQueue *list)
{
        CarQueueNode *tmp = list->front->next;
        timefrom *from;
        int num = 0;
        printf("便道状态\n");
        printf("\n");
        while(tmp != NULL){
                num++;
                from = localtime(&(tmp->data.atime));
                printf("车牌号为%s\t",tmp->data.number );
                printf("停车位置为第%d个\n",num );      //输出队列车信息

                tmp = tmp->next;

        }
        printf("\n");
}