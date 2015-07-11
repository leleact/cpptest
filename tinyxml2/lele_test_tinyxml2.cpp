#include <iostream>
#include <string>
#include <map>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;
struct st_server
{
	std::string m_strip;	
	int m_nport;
};

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "please input the xml file!" << endl;
		return -1;
	}

	map<int, struct st_server> ServerMap;
	XMLDocument doc;
	XMLError nErrId = doc.LoadFile(argv[1]);
	if (nErrId)
	{
		cerr << "LoadFile Error, RetCode: "	 << nErrId;
		return nErrId;
	}

	XMLElement *pRoot = doc.FirstChildElement();
	if (pRoot == nullptr)
	{
		std::cerr << "none RootElement"	 << std::endl;
		return -1;
	}

	int nNumber;
	struct st_server stServer;
	XMLElement *pServer = pRoot->FirstChildElement("number");
	while (pServer != nullptr)
	{
		
		nNumber = atoi( pServer->Attribute("no") );
		stServer.m_strip = pServer->FirstChildElement("IP")->GetText();
		stServer.m_nport = atoi(pServer->FirstChildElement("Port")->GetText());
		ServerMap.insert( std::make_pair(nNumber, stServer) );
		pServer = pServer->NextSiblingElement();
	}

	std::map<int, struct st_server>::iterator it;
	for (it = ServerMap.begin(); it != ServerMap.end(); ++it)
	{
		std::cout << "No: "	 << it->first << ", IP: " << it->second.m_strip << ", Port: " << it->second.m_nport << std::endl;
	}

	return 0;
}
