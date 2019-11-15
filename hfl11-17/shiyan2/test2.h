1 #include <stdio.h>
 2 #include <stdlib.h>
 3 #include <string.h>
 4 
 5     typedef struct _person{
 6         char* firstName;
 7         char* lastName;
 8         char* title;
 9         unsigned int age;
10     } Person;
11 
12     
13     void initiaPerson(Person *person, const char* firstName, const char* lastName, const char* title, unsigned int age){
14         person->firstName = (char*)malloc(strlen(firstName) + 1);
15         strcpy(person->firstName, firstName);
16         person->lastName = (char*)malloc(strlen(lastName) + 1);
17         strcpy(person->lastName, lastName);
18         person->title = (char*)malloc(strlen(title) + 1);
19         strcpy(person->title, title);
20         person->age = age;
21     }
22 
23   
24     void deallocatePerson(Person* person){
25         free(person->firstName);
26         free(person->lastName);
27         free(person->title);
28     }
29 
30    
31     void displayPerson(Person *person){
32         printf("The name %s %s, and title %s, age is %d\n", person->firstName, person->lastName, person->title, person->a   ge);
33     }
34 
35 int main(int argc, char** argv)
36 {
37     Person* person;
38     person = (Person*)malloc(sizeof(Person));
39     initiaPerson(person, "zhang", "san", "good", 20);
