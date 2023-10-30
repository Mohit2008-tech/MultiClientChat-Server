#include"tcpListner.h"
#include<string>


void tcpListner::onClientconnected(int clientSocket){
    // Send a welcome message to the connected client
     std::string welcomeMsg = "Welcome to the Awesome Chat Server!\r\n";
     sendToClient(clientSocket, welcomeMsg.c_str(), welcomeMsg.size()+1);
}

void tcpListner::onClientdisconnected(int clientSocket){
       
}


void tcpListner::onMessageRecieved(int clientSocket, const char* msg, int length){
      broadCastToClients(clientSocket, msg, length);
}