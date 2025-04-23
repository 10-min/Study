// udp_server.cpp
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[1024];
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);

    std::cout << "UDP 서버 실행 중...\n";

    while (true) {
        ssize_t received = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                                    (sockaddr*)&client_addr, &client_len);
        if (received > 0) {
            buffer[received] = '\0';
            std::cout << "수신: " << buffer << std::endl;
        }
    }

    close(sock);
    return 0;
}