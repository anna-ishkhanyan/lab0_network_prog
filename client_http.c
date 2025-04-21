#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_IP "147.182.222.214"
#define SERVER_PORT 80
#define BUFFER_SIZE 4096
#define SERVER_NAME "parliament.am"

int main() {
    int sock;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: Cannot create socket");
        exit(1);
    }

    server = gethostbyname(SERVER_NAME);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Cannot connect to server");
        exit(1);
    }
    printf("Connected to server\n");

    strcpy(buffer, "GET / HTTP/1.1\r\nHost: aua.am\r\n\r\n");
    send(sock, buffer, strlen(buffer), 0);
    printf("Sent: %s\n", buffer);

    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}
