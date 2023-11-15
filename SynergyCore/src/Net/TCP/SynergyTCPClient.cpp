#include <Net/TCP/SynergyTCPClient.h>
#include <iostream>


void SynergyTCPClient::Start() {
  Socket.connect(Endpoint);
  std::cout << "Connected" << std::endl;
}


void SynergyTCPClient::SendMsg(PayloadBase* nPayload) {
  std::string json = nPayload->Serialize();
  std::cout << "Send json: " << json << std::endl;

  asio::write(Socket, asio::buffer(json));
}


void SynergyTCPClient::SendMsgAsync(PayloadBase* nPayload) {
  std::string json = nPayload->Serialize();

  std::cout << "Send json: " << json << std::endl;

  // Capture payloadJson by value to ensure it's valid during the asynchronous operation
  auto payloadData = std::make_shared<std::string>(std::move(json));

  asio::async_write(Socket, asio::buffer(*payloadData),
  [payloadData](const std::error_code& err, std::size_t) {
    if(err) {
      std::cout << "Message failed to send: " << err.message() << std::endl;
    }

    else {
      std::cout << "Message send successfully" << std::endl;
    }
  });
}