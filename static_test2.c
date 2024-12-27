#include <stdio.h>
static int global_int = 2;
extern int global_a;

#include <stdio.h>  
#include <string.h>  
typedef struct {  
    int id;  
    char name[20];
} Person;  
  
int main() {  
    Person p1 = {1, "Alice"};  
    Person p2 = p1;  
  
    // 使用memcpy进行结构体赋值  
    //memcpy(&p2, &p1, sizeof(Person));  
  
    // 或者逐个成员地进行赋值  
    // p2.id = p1.id;  
    // strcpy(p2.name, p1.name);  
    
    p1.id = 2;
    strcpy(p1.name, "newname");
    printf("p2.id = %d, p2.name = %s\n", p2.id, p2.name);  
  
    // int* p = (int*)(0x67a9);
    // *p = 0x1234;

    printf("%d\n", global_a);

    return 0;  
}
