#include <Net/TCP/SynergyTCPServer.h>

#include <iostream>

void SynergyTCPServer::Start() {
  StartAcceptingTCPMessagesAsync();
}


void SynergyTCPServer::StartAcceptingTCPMessagesAsync() {
  if (Acceptor.is_open()) {
    Acceptor.async_accept(Socket, [this](const std::error_code& err) {
      if (!err) {
        std::cout << "Client has connected (" << Socket.remote_endpoint() << ")" << std::endl;

        StartReadingAsync();

        // Continue accepting new connections
        StartAcceptingTCPMessagesAsync();
      }
      else {
        std::cout << "Accept error: " << err.message() << " (" << err.value() << ")" << std::endl;
      }
      });
  }
  else {
    std::cout << "Acceptor is not open. Unable to accept new connections." << std::endl;
  }
}

void SynergyTCPServer::StartReadingAsync() {
  if (Socket.is_open()) {
    asio::async_read_until(Socket, asio::dynamic_buffer(ReceiveBuffer), '\0',
      [this](const std::error_code& err, std::size_t bytesReceived) {
        if (!err) {
          std::string receivedMessage(ReceiveBuffer.data(), bytesReceived);

          PayloadBase* p = nullptr;
          p->Deserialize(receivedMessage);

          std::cout << "Received message from (" << Socket.remote_endpoint() << "): " << receivedMessage << std::endl;

          // Handle message

          // Continue reading for more data
          StartReadingAsync();
        }
        else {
          std::cout << "Read error: " << err.message() << std::endl;
        }
      });
  }
  else {
    std::cout << "Socket is not open. Unable to perform read operation." << std::endl;
  }
}