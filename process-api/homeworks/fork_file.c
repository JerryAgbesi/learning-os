// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <sys/wait.h>
#include <string.h>

// int main(int argc, char *argv[])
// {
//   // Open file before fork
//   fprintf(stdout, "I am opening the file before fork\n");
//   int fd = open("./shared_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
//   if (fd < 0)
//   {
//     fprintf(stderr, "Failed to open file\n");
//     exit(1);
//   }

//   printf("File opened with fd = %d (pid:%d)\n", fd, (int)getpid());

//   int rc = fork();
//   if (rc < 0)
//   {
//     // fork failed
//     fprintf(stderr, "fork failed\n");
//     exit(1);
//   }
//   else if (rc == 0)
//   {
//     // child process
//     printf("Child process: fd = %d (pid:%d)\n", fd, (int)getpid());

//     char child_msg[] = "Child writing to the file yadiyadiyada blablablabla\n";
//     write(fd, child_msg, strlen(child_msg));

//     printf("Child finished writing\n");
//   }
//   else
//   {
//     // parent process
//     printf("Parent process: fd = %d (pid:%d)\n", fd, (int)getpid());

//     // wait(NULL); // Wait for child to finish

//     char parent_msg[] = "Parent writing to the file yadiyadiyada blablablabla\n";
//     write(fd, parent_msg, 128);

//     printf("Parent finished writing\n");
//     close(fd);

   
//   }
//   return 0;
// }

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0744);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    int rc = fork();

    if (rc < 0){
        printf("fork failed\n");
    }else if(rc == 0){
        /// can child access file descriptor returned by open
        write(fd, "child\n", strlen("child\n"));
        printf("wrote to child %d\n", fd);
        close(fd);
    }else{
        /// can parent also do same
        write(fd, "parent\n", strlen("parent"));
        printf("wrote to parent %d\n", fd);
        close(fd);
    }

    /// how do i check what happens concurrently?

    return 0;
}