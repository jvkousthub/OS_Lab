#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork();

    if (child1 < 0) {
        perror("Failed to create child 1");
        return 1;
    } else if (child1 == 0) {
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());

        child2 = fork();

        if (child2 < 0) {
            perror("Failed to create child 2");
            return 1;
        } else if (child2 == 0) {
            printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            printf("Child 1 created Child 2 with PID = %d\n", child2);
        }
    } else {
        printf("Parent: PID = %d, created Child 1 with PID = %d\n", getpid(), child1);
    }

    if (child1 > 0) {
        wait(NULL);
    }
    
    return 0;
}

