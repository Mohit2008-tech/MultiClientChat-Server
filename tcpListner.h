#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <sstream>
//using namespace std;

#pragma comment (lib, "ws2_32.lib")

class tcpListner
{
    public:

    tcpListner(const char* ipAddress, int port):
          m_ipAddress(ipAddress),m_port(port){}

    // Initialize the listner
    int init();

    // Run the listner
    int run();


    protected:
     // Handler for client connections 
     virtual void onClientconnected(int clientSocket);
     
     // Handler for client disconnections
     virtual void onClientdisconnected(int clientSocket);
     
     // Handler for when a msg is recieved from the client
     virtual void onMessageRecieved(int clientSocket, const char* msg, int length);
     // Send a message to client
     void sendToClient(int cleintSocket, const char* msg, int length);
     
     // BroadCast a mesaage from client 
     void broadCastToClients(int sendingClient, const char* msg, int length);

    private:
    const char* m_ipAddress; // IpAddress server will run on
    int         m_port;     // port # for the web service
    int         m_socket; // Internal FD for the listening socket
    fd_set      m_master; //Master file descriptor set
};