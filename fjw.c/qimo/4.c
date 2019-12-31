/*   迷宫问题
   走迷宫的过程可以模拟为一个搜索的过程：每到一处，总让它按东、东南、南、西南、西、西北、北、东北个方向顺序试探下一个位置；如果某方向可以通过，并且不曾到达，则前进一步，在新位置上继续进行搜索；如果个方向都走不通或曾经到达过，则退回一步，在原来的位置上继续试探下一位置。每前进或后退一步，都要进行判断：若前进到了出口处，则说明找到了一条通路；若退回到了入口处，则说明不存在通路。用一个字符类型的二维数组表示迷宫，数组中每个元素取值“0”（表示通路）或“1”（表示墙壁）。迷宫的入口点在位置（1，1）处，出口点在位置（m,m）处。这个算法，为其寻找一条从入口点到出口点的通路。*/

 

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

 int main(void)

{
  int m=1;
   while (m!=0)
   {
#if 0

 

      /* 无法实现定义迷宫大小 */
      printf("输入m,使得为m*m的方阵迷宫(m>0 输入0 时退出:）\n");
      scanf ("%d",&m);

 

#endif 
      m = 8;
      printf("迷宫矩阵的大小为:%d * %d\n", m, m);

 

      /*设定n*n的方阵迷宫*/
      /*数组的形式表示八个方向*/
      int move[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1, 0},{-1, 1}};

 
      /*用结构体表示位置*/

       struct position

      {
        int x;
		int y;

      };
 
      /*用于记录和输出迷宫探路中相关符号，包括1 .*/

       char maze[10][10]; 

      /*用栈来存储探路过程中的数据*/

      position stack[64+1];
      int top;/*栈顶*/
      int i,x,y,ok;
      position p;

 

 

 

      /*二维数组的第0行、第m+1行、第0列、第m+1列元素全
      置成"1"，表示迷宫的边界；第1行第1列元素和第m行第m列
      元素置成"0"，表示迷宫的入口和出口；其余元素值用随机
      函数产生。*/

 

      srand(time(0));  /* 产生一个随机种子 */
      for(x=1;x<=m;x++)
         for(y=1;y<=m;y++)
            maze[x][y]=48+rand()%2;
     maze[1][1]='0';maze[m][m]='0';     /* 入口 */
      for(x=0;x<=m+1;x++)

 
      {
         maze[x][0]='1';maze[x][m+1]='1';  /* 边界 */
     }

      for(y=0;y<=m+1;y++)

      {

         maze[0][y]='1';maze[m+1][y]='1';  /* 边界 */

       }

      p.x=1;p.y=1;
      top=1;stack[top]=p;
      maze[1][1]='.';

 
      /*开始探路
         走迷宫的过程可以模拟为一个搜索的过程：每到一
      处，总让它按东、东南、南、西南、西、西北、北、东北
      个方向顺序试探下一个位置；如果某方向可以通过，并且不
      曾到达，则前进一步，在新位置上继续进行搜索；如果个
      方向都走不通或曾经到达过，则退回一步，在原来的位置上
      继续试探下一位置。
         每前进或后退一步，都要进行判断：若前进到了出
      口处，则说明找到了一条通路；若退回到了入口处，则说明
      不存在通路。*/
      do{
         p=stack[top];
         ok=0;i=0;
         while((ok==0)&&(i<8))
         {
            x=p.x+move[i][0];
            y=p.y+move[i][1];
            if(maze[x][y]=='0')

            {
                p.x=x;p.y=y;
				stack[++top]=p;
                maze[x][y]='.';
                ok=1;
           }

            i++;

         }

         if(i==8)

         {
            maze[p.x][p.y]='*';
            top--;

         }

      } while((top>0)&&((p.x!=m)||(p.y!=m)));

      /*输出探路结果*/

      if(top==0) 

      {
         printf("没有路径\n");

      }

 
      else 

      {
         printf("有路径\n");

      }

      /*输出探路迷宫留下的踪迹*/

#if 0

      for(x=1;x<=m;x++)

      {

         printf("\n");
         for(y=1;y<=m;y++) 
            printf("%c ",maze[x][y]);

	  }  

     break; 

 
 #else      /*输出整个迷宫*/
      for(x=0; x <= m + 1; x++)
      {
         printf("\n");
         for(y=0;y<=m+1;y++) 
            printf("%c ",maze[x][y]);

      }

break; 

#endif
      printf("\n");
      system("pause"); 
   }
   return 0;
}