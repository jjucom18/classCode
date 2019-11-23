#include"carpark.c"
#include"display.c"

int main()
{
    #if 0
    char *test = (char *)malloc(sizeof(char));
    int hour,min,sec;
    time_t timer = time(NULL);
    strcpy(test,ctime(&timer));
    printf("%s\n",test);
    mytime(test,&hour,&min,&sec);
    printf("now time is:%d:%d:%d\n",hour,min,sec);
    #endif
    display();
    return 0;
}
