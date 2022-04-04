#include <stdio.h>
#include <iostream>
#include <cstring>

class Person
{
   int age = 12;
   string name = "민성";
   
};

int main(void) {

    int a = 100;
    int* a_ptr = &a ;  //int형 포인터
    printf("a: %d \n", a);
    // printf("a_prt : %d", a_ptr);
    printf("*a_prt : %d  \n", *a_ptr);

    Person person1;
    // age = person1.age;

    // printf("person1.age: %d", person1.age);

    return 0;
 
}