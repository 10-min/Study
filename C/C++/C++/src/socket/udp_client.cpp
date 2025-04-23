// udp_client.cpp
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);  // 로컬 호스트로 전송

    std::string message = "Hello, UDP!";
    sendto(sock, message.c_str(), message.size(), 0,
           (sockaddr*)&server_addr, sizeof(server_addr));

    std::cout << "메시지 전송 완료\n";

    close(sock);
    return 0;
}
