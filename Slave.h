#pragma once
#include "Device.h"
#include <algorithm>
#include <random>
#include <string>

class Slave :
	public Device
{	
public:
		//void recieve_data_frame();
		//void send_address();
		//void listen_SDA();
		Slave() {
			std::random_device rd;
			std::mt19937 g(rd());
			this->address = "ASDFGH12345";
			std::shuffle(this->address.begin(), this->address.end(), g);
		}
		string get_address() {
			return this->address;
		}
private:
	string address;
};

