#include<stdio.h>

struct Student {
    int roll;
    char name[20];
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    int avgmarks;
};

void sort(struct Student s[], int n ){
    struct Student temp;
    for (int i = 0 ;i<n;i++){
        for (int j = i+1 ;j<n;j++){
            if (s[j].avgmarks > s[j+1].avgmarks ){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main(){
    struct Student students[100];
    int n;
    printf("Enter how many student details you want to add");
    scanf("%d",&n);
    for (int i = 0 ;n>i;i++){
        printf("Enter details of student %d\n",i+1);
        printf("Enter rollno:");
        scanf("%d",&students[i].roll);
        printf("Enter name:");
        scanf("%s",&students[i].name);
        printf("Enter marks in first subject:");
        scanf("%d",&students[i].marks1);
        printf("Enter marks in second subject:");
        scanf("%d",&students[i].marks2);
        printf("Enter marks in third subject:");
        scanf("%d",&students[i].marks3);
        printf("Enter marks in fourth subject:");
        scanf("%d",&students[i].marks4);
        printf("Enter marks in fifth subject:");
        scanf("%d",&students[i].marks5);
        students[i].avgmarks = (students[i].marks1+students[i].marks2+students[i].marks3+students[i].marks4+students[i].marks5)/5;
    }

    sort(students,n);

    printf("The sorted list is:\n");
    for (int i = 0 ;i<n;i++){
        printf("Rollno:%d\n",students[i].roll);
        printf("Name:%s\n",students[i].name);
        printf("Marks in first subject:%d\n",students[i].marks1);
        printf("Marks in second subject:%d\n",students[i].marks2);
        printf("Marks in third subject:%d\n",students[i].marks3);
        printf("Marks in fourth subject:%d\n",students[i].marks4);
        printf("Marks in fifth subject:%d\n",students[i].marks5);
        printf("Average marks:%d\n",students[i].avgmarks);
        printf("\n");
    }


}