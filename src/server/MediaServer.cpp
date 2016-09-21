
#include <jsonrpccpp/server.h>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>
#include "MediaLibrary.hpp"
#include "MediaDescription.hpp"
#include "mediaserverstub.h"

using namespace jsonrpc;
using namespace std;

class MediaServer : public mediaserverstub{
  
  public:MediaServer(AbstractServerConnector &connector, int port);

  virtual void notifyServer();
  virtual std::string serviceInfo();
  virtual bool add(const Json::Value& param1);
  virtual bool remove(const string& param1);
  virtual Json::Value get(const string& param1);
  virtual Json::Value getTitles();
  virtual Json::Value getMusicTitles();
  virtual Json::Value getVideoTitles();

private:
  int portNum;
  MediaLibrary library;
};
MediaServer::MediaServer(AbstractServerConnector &connector,int port) : mediaserverstub(connector)
{
  library.initialize("media.json");
  portNum = port;
  cout << "server up and listening on port " << port << endl;
}

void MediaServer::notifyServer()
{
  cout << "Media server notified" << endl;
}

string MediaServer::serviceInfo()
{
   std::string msg ="Media Library";
   stringstream ss;
   ss << portNum;
   return  msg.append(ss.str());
}

bool MediaServer::add(const Json::Value& param1)
{ 
  Json::Value isolate = param1;
  cout << "Request to add " << isolate.get("title", "").asString() << " received"  << endl;
  MediaDescription md(isolate);
  return library.add(md);
}

bool MediaServer::remove(const string& param1)
{ 
  cout << "Request to remove " << param1 << " received"  << endl;
  return library.remove(param1);
}

Json::Value MediaServer::get(const string& param1)
{
  cout << "Media Description requested for " << param1 << endl;
  Json::Value temp = library.get(param1);
  return temp;
}

Json::Value MediaServer::getTitles()
{
  cout << "List of titles requested" << endl;
  return library.getTitles();
}

Json::Value MediaServer::getMusicTitles()
{
  cout << "List of music titles requested" << endl;
  return library.getMusicTitles();
}

Json::Value MediaServer::getVideoTitles()
{
  cout << "List of video titles requested" << endl;
  return library.getVideoTitles();
}

int main(int argc, char * argv[]) {
   int port = 8080;
   vector<string> temp;
   if(argc > 1){
      port = atoi(argv[1]);
   }
   //cout << port << endl;
   HttpServer httpserver(port);
   MediaServer cs(httpserver, port);
   cs.StartListening();
   int c = getchar();
   cs.StopListening();
   return 0;
}
