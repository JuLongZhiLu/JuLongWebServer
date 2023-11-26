#include "webserver.hpp"

int main(int argc,char *argv[])
{ 
    if(argc!=2)
        std::cout<<"Usage : "<<argv[0]<<" <port>\n"<<std::endl;

    int port=atoi(argv[1]);
    JuLong::WebServer server(port);
}