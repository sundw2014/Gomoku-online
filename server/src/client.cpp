#include "client.hpp"
#include "protocol.hpp"
#include "unistd.h"
#include "stdio.h"

using namespace std;

Client::Client(int fd,struct sockaddr_in &Tclient_addr,unsigned int &Tclient_addr_len):socketFd(fd),protocol(fd)
{
  receivedFrame=(const Frame *)&(protocol.receivedFrame);
  client_addr=Tclient_addr;
  client_addr_len=Tclient_addr_len;
};

Client::~Client()
{
  close(socketFd);
}

bool Client::updateFrame()
{
  bool result=false;
  if(protocol.receiveFrame())
  {
    parseFrame();
    return true;
  }
  for(unsigned i=0;i<2;i++)
  {
    sleep(1);
    if(protocol.receiveFrame())
    {
        return true;
        parseFrame();
    }
  }
  return false;
}

bool Client::parseFrame()
{
  // printf("length = {%d,%d,%d,%d}\r\n",protocol.receivedFrame.length[0],protocol.receivedFrame.length[1],protocol.receivedFrame.length[2],protocol.receivedFrame.length[3]);
  frame.cmd=string(protocol.receivedFrame.cmd,(size_t)protocol.receivedFrame.length[0]);
  frame.value1=string(protocol.receivedFrame.value1,(size_t)protocol.receivedFrame.length[1]);
  frame.value2=string(protocol.receivedFrame.value2,(size_t)protocol.receivedFrame.length[2]);
  frame.value3=string(protocol.receivedFrame.value3,(size_t)protocol.receivedFrame.length[3]);
  return true;//备用返回值
}

bool Client::sendFrame(const unsigned char lengths[],const char *cmd ,const char *value1,const char *value2,const char *value3)
{
  protocol.sendFrame(lengths,cmd,value1,value2,value3);
}
