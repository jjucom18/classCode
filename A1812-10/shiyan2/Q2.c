#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _person{
	char* firstName;
	char* lastName;
	char* title;
	unsigned int age;
}Person;
 void initiaPerson(Person *person, const char* firstName, const char* lastName, const char* title, unsigned int age) {
	 person->firstName = (char*) malloc(strlen(firstName)  + 1);
	 strcpy(person->firstName, firstName);
	 person->lastName = (char*) malloc(strlen(lastName)  + 1);
	 strcpy(person->lastName,lastName);
	 person->title = (char*) malloc(strlen(title)  + 1);
	 strcpy(person->title, title);
	 person->age = age;
	 } 
 void deallocatePerson(Person* person) 
{
         free(person->firstName) ;
		 free(person->lastName) ;
         free(person->title) ;
	     }
void displayPerson(Person *person) 
{
     printf("The name %s %s, and title %s, age is %d\n",personperson->firstName,person->lastName, person->title, person->age) ;
