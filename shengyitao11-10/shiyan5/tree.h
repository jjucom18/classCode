void main()
{
BiTree T;
char j;
int flag=1;
printf("\n");
printf("建立二叉树。\n");
printf("建立将以三个空格后回车结束。\n");
printf(1 2 3  （回车）\n);Create BiTree(T)

getchar();
while(flag)
{
printf("\n");
printf("请选择：\n");
printf("1.递归先序遍历\n");
printf("2.递归中序遍历\n");
printf("3.递归后序遍历\n");
printf("0.退出程序\n");
scanf("%c",&j);
switch(j)
{
case'1':if(T)
{
printf("递归先序遍历二叉树;");
PreOrder(T);
printf("\n");
}
else printf("二叉树为空!\n");
break;
case '2':if(T)
{
printf("递归中序遍历二叉树：");
InOrder(T);
printf("\n");
}
else printf("二叉树为空！\n");
break;
case '3':if(T)
{
printf("递归后序遍历二叉树：");
PostOrder(T);
printf("\n");
}
else printf("二叉树为空！\n");
break;
