#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    int id;
    char content[100];
    int status;
};

int main() {
    struct Task tasks[MAX_TASKS]; 
    int task_count = 0; 
    int choice;         

    while (1) {
        printf("\n=== 我的待办事项 ===\n");
        printf("1. 查看所有任务\n");
        printf("2. 添加新任务\n");
        printf("0. 退出程序\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("退出程序，再见！\n");
            break;
        } 
        else if (choice == 1) {
            if (task_count == 0) {
                printf("当前没有待办任务，快去添加吧！\n");
            } else {
                printf("\n--- 任务列表 ---\n");
                for (int i = 0; i < task_count; i++) {
                    printf("[%d] %s", tasks[i].id, tasks[i].content);
                    if (tasks[i].status == 0) {
                        printf("  (状态: 未完成)\n");
                    } else {
                        printf("  (状态: 已完成)\n");
                    }
                }
                printf("----------------\n");
            }
        } 
        else if (choice == 2) {
            if (task_count >= MAX_TASKS) {
                printf("任务列表已满！\n");
            } else {
                tasks[task_count].id = task_count + 1; 
                tasks[task_count].status = 0;          
                
                printf("请输入任务内容: ");
                getchar(); 
                fgets(tasks[task_count].content, 100, stdin);
                tasks[task_count].content[strcspn(tasks[task_count].content, "\n")] = 0; 

                task_count++; 
                printf("添加成功！\n");
            }
        } 
        else {
            printf("输入错误，请重新输入！\n");
        }
    }

    return 0;
}