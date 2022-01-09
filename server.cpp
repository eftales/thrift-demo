// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ConServiceThrift/ConService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace std;

class ConServiceHandler : virtual public ConServiceIf {
 public:
 std::map<std::string, DeviceMSGThrift>  topo;
  ConServiceHandler() {
    // Your initialization goes here
    std::string macStr("11:22:33:44:55:66");
    DeviceMSGThrift deviceMSG;
    deviceMSG.type = 1;
    topo[macStr] = deviceMSG;
  }

  void getTopo(std::map<MACString, DeviceMSGThrift> & _return) {
    // Your implementation goes here
    _return = topo;
    printf("getTopo\n");
  }

  void getSafeParam(std::map<ColonyIDString, SafeParamThrift> & _return) {
    // Your implementation goes here
    printf("getSafeParam\n");
  }

  int8_t getCMode() {
    // Your implementation goes here
    printf("getCMode\n");
  }

  int8_t setCMode(const int8_t mode) {
    // Your implementation goes here
    printf("setCMode\n");
  }

};

int main(int argc, char **argv) {
  int port = 2022;
  shared_ptr<ConServiceHandler> handler(new ConServiceHandler());
  shared_ptr<TProcessor> processor(new ConServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

