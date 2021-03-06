#ifndef __Packet_hpp__
#define __Packet_hpp__

#include <string>
#include "Serializable.hpp"

enum PacketType {
  ACK,
  ANSWER,
  IS_ALIVE,
  SERVER_DOWN,
  NEW_REPLICA,
  REPLICAS,
  NEW_LEADER,
  ELECTION,
  COORDINATOR,
  UPDATE_PROFILE,
  UPDATE_NOTIFICATION,

  DATA,
  SEND,
  LOGIN,
  FOLLOW,
  SUCCESS,
  ERROR,
  CLOSE,
  NO_TYPE,
};

class Packet {
  public:
  int m_length;
  PacketType m_type;
  int m_sequenceNumber;
  long unsigned int m_timestamp;
  const char* m_payload;

  public:
    friend class TCPConnection;

    static const int sizeFieldLength = 10; // Char lenght of uint32 max value

    Packet(PacketType type, Serializable* data);
    Packet(PacketType type, const char* payload);
    ~Packet();

    const char* payload();
    int length();
    PacketType type();
    std::string typeString();

    std::string serialize();
    static Packet* deserialize(const char* rawData);

  private:
    Packet(int length, PacketType type, int sequenceNumber, long unsigned int timestamp, const char* payload);
    static const char* typeToString(PacketType type);
    static PacketType stringToType(const char* buffer);
};

#endif // __Packet_hpp__