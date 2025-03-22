#pragma once
#include "Device.h"
#include "Library.cpp"

class Slave :
	public Device
{	
public:
		virtual void recieve_data_frame();
		virtual void send_address();
		virtual void listen_SDA();
		Slave() {
			this->address = gen_random(6);
		}
private:
	string address;
};

