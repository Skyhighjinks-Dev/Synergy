#pragma once

/* Types of payload messages */
enum PayloadType {
  NONE = 0,          // These will be ignored
  HELLO = 1,         // Initial handshake message with server 
  DISCONNECT = 2,    // Disconnect from server
  MESSAGE = 4,       // User message
  AUDIO_CONNECT = 8, // Connects to audio channel
  AUDIO = 16         // Transfers audio information
};