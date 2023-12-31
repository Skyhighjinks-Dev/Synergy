#include <Net/UDP/SynergyUDPClient.h>


/// <summary>
/// Constructor
/// </summary>
/// <param name="nContext">IO Context</param>
/// <param name="nServerIP">Server IP address to connect to</param>
/// <param name="nServerPort">Server port</param>
SynergyUDPClient::SynergyUDPClient(asio::io_context& nContext, const std::string& nServerIP, int nServerPort)
  : Socket(nContext),
    ServerEndpoint(asio::ip::make_address(nServerIP), nServerPort)
{
  Socket.open(asio::ip::udp::v4());
}


/// <summary>
/// Sends a message to the server
/// </summary>
/// <param name="nPayload">Payload pointer to send</param>
void SynergyUDPClient::SendMsg(PayloadBase* nPayload)
{
  std::string payloadJson = nPayload->Serialize();
  std::cout << payloadJson << std::endl;

  Socket.async_send_to(asio::buffer(payloadJson), ServerEndpoint,
    [this, payloadJson](const std::error_code& err, std::size_t bytesSent) {
      if(!err) {
        std::cout << "Message sent: " << payloadJson << std::endl;
      }
      else {
        std::cerr << "Message failed to send: " << err.message() << std::endl;
      }
    });
}