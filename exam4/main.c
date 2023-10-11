#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define ECDARGC "error: cd: bad arguments\n"
#define ECDPATH "error: cd: cannot change directory to "
#define EEXCUTE "error: cannot excute "
#define ESYSCAL "error: fatal\n"

int execute(char *args[], int i, char *envp[]);
int execute_cd(char *path, int argc);
int except(char *msg);

int main(int argc, char *argv[], char *envp[]) {
	int i = 0;
	int status = 0;

	if (argc <= 1)
		return status;

	while (argv[i] && argv[++i]) {
		argv += i;
		i = 0;
		while (argv[i] 
			&& strcmp(argv[i], "|") != 0 
			&& strcmp(argv[i], ";") != 0)
			i++;
		if (strcmp(*argv, "cd") == 0)
			status = execute_cd(argv[1], i);
		else if (i)
			status = execute(argv, i, envp);
	}

	return status;
}

int execute(char *args[], int i, char *envp[]) {
	int pid;
	int fd[2];
	int status;
	int has_pipe = args[i] && !strcmp(args[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return except(ESYSCAL);
	pid = fork();
	if (pid == - 1)
		return except(ESYSCAL);
	else if (pid == 0) {
		args[i] = 0;
		if (has_pipe && (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return except(ESYSCAL);
		else if (execve(*args, args, envp) == -1)
			return (except(EEXCUTE), except(*args), except("\n"));
	}
	else {
		if (has_pipe && (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return except(ESYSCAL);
		waitpid(pid, &status, 0);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int execute_cd(char *path, int argc) {
	if (argc != 2)
		return except(ECDARGC);
	else if (chdir(path) == -1)
		return (except(ECDPATH), except(path), except("\n"));
	else
		return 0;
}

int except(char *msg) {
	while (*msg)
		write(2, msg++, 1);
	return (1);
}