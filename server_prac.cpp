#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256
char msg_buffer[MAX_BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char inet_addr_buf[16];
    socklen_t client_addr_len = sizeof(client_addr);
    int server_port;
    int len, i;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return -1;
    }

    // Get server port number
    server_port = atoi(argv[1]);

    // [TODO: Create server socket]
    

    // Bind an address IP:Port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error: bind" << std::endl;
        return -1;
    }

    inet_ntop(AF_INET, &server_addr.sin_addr, inet_addr_buf, sizeof(inet_addr_buf));
    std::cout << "Addr: " << inet_addr_buf << std::endl;
    std::cout << "Port: " << ntohs(server_addr.sin_port) << std::endl;

    // [TODO: Listen for incoming connections]


    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            std::cerr << "Error: accept" << std::endl;
            return -1;
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, inet_addr_buf, sizeof(inet_addr_buf));
        std::cout << "===== Client Connected =====" << std::endl;
        std::cout << "From " << inet_addr_buf << ":" << ntohs(client_addr.sin_port) << std::endl;

        // [TODO: Receive small letter word from client]
        

        // [TODO: Capitalize small letters]
    
        
        // [TODO: Send the result to client]


        // Connection Close
        close(client_socket);
        std::cout << "===== Client Disconnected =====" << std::endl;
    }

    close(server_socket);
    return 0;
}
