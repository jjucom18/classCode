#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person{
		char* firstName;
		char* lastName;
		char* title;
		unsigned int age;
	}Person;


void initiaPerson(Person* person,const char* firstName,const char* lastName,    //初始化
		const char* title,unsigned int age){
	person->firstName = (char*)malloc(strlen(firstName)+1);
	strcpy(person->firstName,firstName);
	person->lastName = (char*)malloc(strlen(lastName)+1);
	strcpy(person->lastName,lastName);
	person->title = (char*)malloc(strlen(title)+1);
	strcpy(person->title,title);
	person->age = age;
}

void deallocatePerson(Person* person){        //分配变量
	free(person->firstName);
	free(person->lastName);
	free(person->title);
}


void displayPerson(Person *person){     //打印输出
	printf("The name %s %s,and title %s,age is %d\n",person->firstName,person->lastName,person->title,person->age);
}

int main(int argc,char** argv){
	Person* person;
	person = (Person*)malloc(sizeof(Person));
	initiaPerson(person,"zhang","san","good",20);
	displayPerson(person);
	deallocatePerson(person);
	free(person);

    return 0;
}       //程序功能：输入变量姓名·评价·年龄，然后一句话输出它，形式为：The name xx,  and title xx, age is xx.