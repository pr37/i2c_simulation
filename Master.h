#pragma once
#include "Device.h"
#include <string>
#include <thread>

class Master :
    public Device
{   public:
		void start_message();
		void end_message();
		void send_slave_address_W(short address);
		void send_slave_address_R(short address);
		void send_data_frame(char data);
		void start_CLK() {
			this->connection->master_start_simulate_SCL();
		}
	private:
		string id; 

};

