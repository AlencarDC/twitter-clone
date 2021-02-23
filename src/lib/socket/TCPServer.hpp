#ifndef __TCPServer_h__
#define __TCPServer_h__

#include <string>
#include "TCPConnection.hpp"

#define CONN_WAIT_LIST_SIZE 10

class TCPServer {

  int listeningSocket;
  bool listening;
  std::string ip;
  int port;
  
  public:
    TCPServer(const std::string serverIp, int portNumber);
    ~TCPServer();

    bool isListening();
    bool start();
    TCPConnection* accept();
  
  private: 
    TCPServer() {}
};

#endif // __TCPServer_h__