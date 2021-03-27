#ifndef __TCPConnection_hpp__
#define __TCPConnection_hpp__

#include <string>
#include "lib/packet/Packet.hpp"

#define RECV_BUFFER_SIZE 400

class TCPConnection {
  int m_socketDescriptor;
  std::string m_ip;
  int m_port;
  int m_sequenceNumber;
  std::string m_buffer;

  public:
    friend class TCPClient;
    friend class TCPServer;

    std::string getConnectionIp();
    int getConnectionPort();

    ssize_t send(const char* buffer, size_t length);
    ssize_t send(Packet* packet);
    ssize_t receive(char* buffer, size_t length);
    Packet* receive();

    ~TCPConnection();
  
  private:
    TCPConnection(int socket, std::string ipAddress, int portNumber);

    Packet* breakPayload(Packet* packet);
};

#endif //__TCPConnection_hpp__