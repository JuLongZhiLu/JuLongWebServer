#include "webserver.hpp"

JuLong::WebServer::WebServer(int port)
{
    this->port=port;
    initResponse();
    initServerSocket();
    acceptAndProcessConnections();
}

JuLong::WebServer::~WebServer()
{
    close(serv_sock);
}

void JuLong::WebServer::initServerSocket()
{
    serv_sock=socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock==-1)
        std::cout<<"socket() error"<<std::endl;

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(port);

    if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
        std::cout<<"bind() error"<<std::endl;

    if(listen(serv_sock,5)==-1)
        std::cout<<"listen() error"<<std::endl;
}

void JuLong::WebServer::initResponse()
{
    response="HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html; charset=UTF-8\r\n\r\n"
            "<!DOCTYPE html>"
            "<html lang=\"zh-CN\">"
            "<head>"
            "<meta charset=\"utf-8\">"
            "<title>Hello World</title>"
            "</head>"
            "<body>"
            "<p>Hello World<p>"
            "</body></html>\r\n";
}

void JuLong::WebServer::acceptAndProcessConnections()
{
    while(1){
        int numbytes;
        char buff[500];
        clnt_addr_size=sizeof(clnt_addr);
        clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
        std::cout<<"Client connected"<<std::endl;
        if(clnt_sock==-1){
            std::cout<<"accept() error:Client connected error"<<std::endl;
            continue;
        }

        if((numbytes=recv(clnt_sock,buff,99,0))==-1){
            std::cout<<"recv() error";
            exit(1);
        }

        std::cout<<buff<<std::endl;
        
        std::cout<<send(clnt_sock,response.c_str(),response.length(),0)<<"Bytes sent"<<std::endl;
        sleep(1000);

        close(clnt_sock);
    }
}
