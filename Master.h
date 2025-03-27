#pragma once
#include "Device.h"
#include <string>
#include <thread>
#include <vector>

class Master :
    public Device
{   public:
		Master(int poll_wait_time) {
			this->poll_waiting_period = poll_wait_time;
			this->number_of_slaves = 0;
		}
		void load_slave_address(string addr) {
			this->slaves.push_back(addr);
			this->number_of_slaves++;
		}
		void send_message(bool *message) {
			bool bit_sent = false;
			while (true) {
				if (this->connection->get_clk() == true) {	//SEND START BIT
					this->connection->master_set_sda(false);
					std::this_thread::sleep_for(std::chrono::milliseconds(this->poll_waiting_period));
				}
			}
		}
		void send_data_frame(char data);
		void start_CLK() {
			this->connection->master_start_simulate_SCL();
		}
	private:
		string id; 
		int poll_waiting_period;
		vector<string> slaves;
		int number_of_slaves;

};

