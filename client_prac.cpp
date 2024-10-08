#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256
char msg_buffer[MAX_BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int s;
    struct sockaddr_in server_addr;
    char inet_addr_buf[16];
    int len;

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <IP address> <port>" << std::endl;
        return -1;
    }

    server_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        std::cerr << "Error: invalid IP address " << argv[1] << std::endl;
        return -1;
    }
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create a socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        std::cerr << "Error: socket creation" << std::endl;
        return -1;
    }
    inet_ntop(AF_INET, &server_addr.sin_addr, inet_addr_buf, sizeof(inet_addr_buf));
    std::cout << "Trying " << inet_addr_buf << ":" << ntohs(server_addr.sin_port) << std::endl;

    // [TODO: Connect to the server]
    
    
    std::cout << "===== Server Connected =====" << std::endl;

    int x, y;

    // [TODO: Get small letter word as an input]


    // [TODO: Send small letter word to Server]


    // [TODO: Receive capitalized word from Server and print it]



    close(s);
    return 0;
}
