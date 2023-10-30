#pragma once

#include"tcpListner.h"

class MultiClientChat:public tcpListner{
      public:
      MultiClientChat(const char* ipAddress,int port):
           tcpListner(ipAddress, port){}

      protected:
     // Handler for client connections 
     virtual void onClientconnected(int clientSocket);
     
     // Handler for client disconnections
     virtual void onClientdisconnected(int clientSocket);
     
     // Handler for when a msg is recieved from the client
     virtual void onMessageRecieved(int clientSocket, const char* msg, int length);
};