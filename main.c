#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 100
int main(int argc, char *argv[])
{

    char buf[250];
    int len = strlen(buf);

    while (1)
    {
        printf(">> ");
        scanf("%100s", &buf[len]);
        if (strncmp(buf, "quit", 4) == 0)
        {
            printf("bye bye\n");
            return 0;
        }
        pid_t cpid = fork();

        pid_t mypid = getpid();
        pid_t myparent = getppid();

        if (cpid == 0)
        {
            printf("mypid=%d......child process!!!......", getpid());

            int new_out = open("file", O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if (new_out == -1)
            {
                perror("cannot open file: ");
                return -1;
            }
            int saved_out = dup(1);
            if (saved_out == -1 || saved_out == 1)
            {
                perror("ERROR");
                return -1;
            }
            close(1);
            dup2(new_out, 1);
            if (new_out == -1)
            {
                perror("ERROR");
                return -1;
            }

            int ret;
            ret = execlp(buf, buf, NULL);
            if (ret == -1)
            {
                int ret1 = execlp(buf, "where", NULL);
                if (ret1 == -1)
                {
                    printf("%s, command not found\n", buf);
                }
                else
                {
                    execlp(buf, "where", NULL);
                }
            }
            else
            {
                execlp(buf, buf, NULL);
            }
            dup2(saved_out, 1);
            close(saved_out);
            close(new_out);
        }
        else if (cpid > 0)
        {
            printf("mypid=%d......parent process!!!......", getpid());
            int f = open("file", O_RDONLY);
            if (f == -1)
            {
                perror("cannot open file: ");
                return -1;
            }
            ssize_t myret;
            char buf[BUFSIZ];
            myret = read(f, buf, BUFSIZ);
            if (myret == -1)
            {
                perror("cannot read");
                close(f);
                return -1;
            }
            buf[myret] = '\0';
            printf("%s", buf);
            close(f);
            int status;
            { // wait(&status);
                int w = waitpid(cpid, &status, WNOHANG);
                if (w == 0)
                {
                    if (WIFEXITED(status))
                    {
                        printf("child process exited with %d\n", WEXITSTATUS(status));
                    }
                    else if (WIFSIGNALED(status))
                    {
                        printf("child process is signaled with %d\n", WTERMSIG(status));
                    }
                    else if (WIFSTOPPED(status))
                    {
                        printf("Stopped by signal=%d\n", WSTOPSIG(status));
                    }

                    if (WIFCONTINUED(status))
                    {
                        printf("Continued\n");
                    }

                    return 0;
                }
                else
                {
                    sleep(10);
                }
            }while (1);
        }
    }

    return 0;
}
