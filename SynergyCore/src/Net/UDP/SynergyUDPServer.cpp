#include <Net/UDP/SynergyUDPServer.h>
#include <Net/Payloads/HelloPayload.h>
#include <iostream>

SynergyUDPServer::SynergyUDPServer(asio::io_context& nContext, int nServerPort)
  : Socket(nContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), nServerPort)) {
}

void SynergyUDPServer::StartListening() {
  Socket.async_receive_from(asio::buffer(ReceiveBuffer), RemoteEndpoint,
    [this](const std::error_code& err, std::size_t bytesReceived) {
      HandleReceive(err, bytesReceived);
    });
}

void SynergyUDPServer::HandleReceive(const std::error_code& error, std::size_t bytesReceived) {
  if (!error) {
    std::string receivedMessage(ReceiveBuffer.data(), bytesReceived);
    
    HelloPayload hp;
    hp.Deserialize(receivedMessage);
    

    std::cout << "Received message: " << hp.Message << std::endl;
  }
  else {
    std::cout << "Receive failed: " << error.message() << std::endl;
  }

  StartListening();
}