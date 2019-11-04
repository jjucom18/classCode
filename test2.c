#include "sampleg.h

 student initstu(){
         student *ptrStu = (student*)malloc(sizeof(student));
	 printf("请输入你的名字: ")
	 scanf("%s", ptrStu->name);
         printf("请输入你的身份: ");
	 scanf("%d", ptrStu->id);
	 printf("请输入你的成绩: ");
	 scanf("%f", ptrStu->record );

	 return *ptrStu;

}

  void  outStu(student stu){
	printf("%s's id: %d and record: %f\n", stu.name, stu.id, stu.record);
	return;

}
 float getRec(student stu){
 	  student stu;
	  if(stu.id ==id){
		  stu.record = record;
	  }


	  return;
 }
	

