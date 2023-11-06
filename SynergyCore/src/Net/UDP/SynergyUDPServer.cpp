#include <Net/UDP/SynergyUDPServer.h>
#include <Net/Payloads/HelloPayload.h>
#include <iostream>


/// <summary>
/// Constructor 
/// </summary>
/// <param name="nContext">IO Context</param>
/// <param name="nServerPort">Port to host server on</param>
SynergyUDPServer::SynergyUDPServer(asio::io_context& nContext, int nServerPort)
  : Socket(nContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), nServerPort)) {
}


/// <summary>
/// Begin listening for connections
/// </summary>
void SynergyUDPServer::StartListening() {
  Socket.async_receive_from(asio::buffer(ReceiveBuffer), RemoteEndpoint,
    [this](const std::error_code& err, std::size_t bytesReceived) {
      HandleReceive(err, bytesReceived);
    });
}


/// <summary>
/// Handle message/connections
/// </summary>
/// <param name="nError">Errors</param>
/// <param name="nBytesReceived">Number of bytes received</param>
void SynergyUDPServer::HandleReceive(const std::error_code& nError, std::size_t nBytesReceived) {
  if (!nError) {
    std::string receivedMessage(ReceiveBuffer.data(), nBytesReceived);
    
    HelloPayload hp;
    hp.Deserialize(receivedMessage);
    
    std::cout << "Received message: " << hp.Message << " and type: " << hp.Type << std::endl;
  }
  else {
    std::cout << "Receive failed: " << nError.message() << std::endl;
  }

  StartListening();
}