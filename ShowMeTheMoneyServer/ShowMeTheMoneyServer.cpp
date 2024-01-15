
#include <iostream>

#include "Network/TCPServer.h"

int main()
{
    TcpServer* Server = new TcpServer();
    Server->Initialize();
    Server->Bind(5001);
    Server->Listen();
    const TcpSocket* ClientSocket = Server->Accept();
    ClientSocket->Send("show me the money.");
    const std::string Message = ClientSocket->Receive();
    std::cout << Message << std::endl;

    return 0;
}
