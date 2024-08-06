#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>

#define LF "\n"
#define ARGC_ERROR_MESSAGE "Wrong number of arguments"
#define FATAL_ERROR_MESSAGE "Fatal error"

typedef struct server_socket {
	int fd;
	struct sockaddr_in addr;
} SERVER_SOCKET;

typedef struct client {
	int id;
	char* message;
} CLIENT;

void init_server_socket(SERVER_SOCKET* server_socket, int server_port);
void process_socket_event(SERVER_SOCKET server_socket);
void register_client(int fd);
void remove_client(int fd);
void send_message(int fd);
void notify_others(int author_fd, const char* buffer);
int extract_message(char** buffer, char** message);
char* str_join(char* str, const char* add);

void handle_argc_error();
void handle_fatal_error();

int max_fd = 0,
	client_count = 0;

CLIENT clients[256];

fd_set all_fd_set,
		read_fd_set,
		write_fd_set;

int main(int argc, char** argv) {
	if (argc != 2) {
		handle_argc_error();
	}

	int server_port = atoi(argv[1]);

	FD_ZERO(&all_fd_set);

	SERVER_SOCKET server_socket;
	init_server_socket(&server_socket, server_port);
	
	max_fd = server_socket.fd;
	FD_SET(server_socket.fd, &all_fd_set);

	if (bind(server_socket.fd, (const struct sockaddr*)&server_socket.addr, sizeof(server_socket.addr)) == -1
		|| listen(server_socket.fd, SOMAXCONN) == -1
	) {
		handle_fatal_error();
	}

	while (1) {
		process_socket_event(server_socket);
	}

	return 0;
}

void init_server_socket(SERVER_SOCKET* server_socket, int server_port) {
	server_socket->fd = socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket->fd < 0) { handle_fatal_error(); }

	bzero(&server_socket->addr, sizeof(server_socket->addr));

	server_socket->addr.sin_family = AF_INET;
	server_socket->addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server_socket->addr.sin_port = htons(server_port);
}

void process_socket_event(SERVER_SOCKET server_socket) {
	read_fd_set = write_fd_set = all_fd_set;

	if (select(max_fd + 1, &read_fd_set, &write_fd_set, 0, 0) == -1) {
		handle_fatal_error();
	}

	for (int fd = 0; fd <= max_fd; fd++) {
		if (!FD_ISSET(fd, &read_fd_set)) {
			continue;
		}

		if (fd == server_socket.fd) {
			socklen_t addr_len = sizeof(server_socket.addr);
			int client_fd = accept(server_socket.fd, (struct sockaddr*)&server_socket.addr, &addr_len);
			if (client_fd >= 0) {
				register_client(client_fd);
				break;
			}
		} else {
			CLIENT* client = &clients[fd];
			char buffer[BUFSIZ];
			
			int recv_byte = recv(fd, buffer, BUFSIZ - 1, 0);
			if (recv_byte <= 0) {
				remove_client(fd);
				break;
			}

			buffer[recv_byte] = '\0';
			client->message = str_join(client->message, buffer);
			if (client->message == 0) {
				handle_fatal_error();
			}
			send_message(fd);
		}
	}
}

void register_client(int fd) {
	if (fd > max_fd) { max_fd = fd; }

	clients[fd].id = client_count++;
	clients[fd].message = 0;
	FD_SET(fd, &all_fd_set);

	char buffer[BUFSIZ];
	sprintf(buffer, "server: client %d just arrived\n", clients[fd].id);
	notify_others(fd, buffer);
}

void remove_client(int fd) {
	free(clients[fd].message);
	FD_CLR(fd, &all_fd_set);
	close(fd);

	char buffer[BUFSIZ];
	sprintf(buffer, "server: client %d just left\n", clients[fd].id);
	notify_others(fd, buffer);
}

void send_message(int fd) {
	char *message = 0;

	int rtn_extract_message;
	while ((rtn_extract_message = extract_message(&clients[fd].message, &message))) {
		char buffer[BUFSIZ];
		sprintf(buffer, "client %d: %s", clients[fd].id, message);
		notify_others(fd, buffer);
		free(message);
	}

	if (rtn_extract_message == -1) {
		handle_fatal_error();
	}
}

void notify_others(int author_fd, const char* buffer) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_fd_set) && fd != author_fd) {
			send(fd, buffer, strlen(buffer), 0);
		}
	}
}

int extract_message(char** buffer, char** message) {
	char* new_buffer;

	if (*buffer == 0) {
		return 0;
	}

	int i = 0;
	while ((*buffer)[i]) {
		if ((*buffer)[i] == '\n') {
			new_buffer = calloc(strlen(*buffer + i + 1) + 1, sizeof(*new_buffer));
			if (new_buffer == 0) {
				return -1;
			}
			strcpy(new_buffer, *buffer + i + 1);
			*message = *buffer;
			(*message)[i + 1] = '\0';
			*buffer = new_buffer;

			return 1;
		}
		i++;
	}

	return 0;
}

char* str_join(char* str, const char* add) {
	char* new_str;
	size_t new_len;

	new_len = (str ? strlen(str) : 0) + strlen(add) + 1;
	new_str = calloc(new_len, sizeof(*new_str));
	if (new_str == 0) {
		return 0;
	}
	new_str[0] = '\0';

	if (str) {
		strcpy(new_str, str);
		free(str);
	}

	if (add) {
		strcat(new_str, add);
	}

	return new_str;
}

void handle_argc_error() {
	write(2, ARGC_ERROR_MESSAGE LF, strlen(ARGC_ERROR_MESSAGE LF));
	exit(1);
}

void handle_fatal_error() {
	write(2, FATAL_ERROR_MESSAGE LF, strlen(FATAL_ERROR_MESSAGE LF));
	exit(1);
}
