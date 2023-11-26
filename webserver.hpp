#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <arpa/inet.h>
#include <sys/socket.h>

namespace JuLong
{
    class WebServer
    {
    public:
        WebServer(int port);
        ~WebServer();
        
    private:
        void initServerSocket();
        void initResponse();
        void acceptAndProcessConnections();

    private:
        std::string response;
        int serv_sock;
        int clnt_sock;
        int port;
        struct sockaddr_in serv_addr;
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size;
    };
} // namespace JuLong
