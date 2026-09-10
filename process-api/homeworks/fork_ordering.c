// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(int argc, char *argv[]) {
//     int pipefd[2];
    
//     // Create a pipe for synchronization
//     if (pipe(pipefd) == -1) {
//         fprintf(stderr, "pipe failed\n");
//         exit(1);
//     }
    
//     int rc = fork();
//     if (rc < 0) {
//         // fork failed
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {
//         // child process
//         close(pipefd[0]);  // close read end
        
//         printf("hello\n");
        
//         // Signal parent that child is done
//         close(pipefd[1]);  // closing write end signals parent
//     } else {
//         // parent process
//         close(pipefd[1]);  // close write end
        
//         // Wait for child to close its end (blocking read)
//         char buf;
//         read(pipefd[0], &buf, 1);  // This will block until child closes write end
        
//         close(pipefd[0]);
        
//         printf("goodbye\n");
//     }
    
//     return 0;
// }


#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]){

  printf("start of the program: question 3\n");
  int rc = fork();
  
  if (rc < 0){
    fprintf(stderr, "failed to fork\n");
  }else if (rc == 0){
    printf("hello (from child)\n");
  }else{
    sleep(3);
    printf("goodbye (from parent)\n");
  }

  return 0;
}