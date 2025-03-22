#pragma once
#include "LineConnector.h"
#include <Memory>

using namespace std;

class Device
{
public:
	virtual void init_device(); //here would be a good idea to load all slave addresses
	virtual void set_connection(LineConnector* c);
	virtual void expect_ack();
protected:
	LineConnector* connection;
	char status_register; //current bus status
	//TODO in MASTER: shared pointer to keep track of all slaves connected, also implement logic to increase ptr counter when object of slave type is connected to the LineConnector
	//TODO in SLAVE: private short address;


};

