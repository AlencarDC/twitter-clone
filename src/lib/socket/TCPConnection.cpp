#include <unistd.h> // close()
#include <sys/types.h>
#include <sys/socket.h>
#include "TCPConnection.hpp"

TCPConnection::TCPConnection(int socket, std::string ipAddress, int portNumber) {
  m_socketDescriptor = socket;
  m_ip = ipAddress;
  m_port = portNumber;
}

TCPConnection::~TCPConnection() {
  close(m_socketDescriptor); // Closes socket of the given descriptor
}

std::string TCPConnection::getConnectionIp() {
  return m_ip;
}

int TCPConnection::getConnectionPort() {
  return m_port;
}

ssize_t TCPConnection::send(const char* buffer, size_t length) {
  return ::send(m_socketDescriptor, buffer, length, 0);
}

ssize_t TCPConnection::receive(char* buffer, size_t length) {
  return recv(m_socketDescriptor, buffer, length, 0);
}