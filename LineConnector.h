#pragma once
#include <chrono>
#include <iostream>
#include <thread> 

using namespace std;

class LineConnector
{
	private:
		bool SDA;
		bool SCL;
		int clock_period;
	public:
		LineConnector(int clk_period) {
			this->clock_period = clk_period;
		}
		~LineConnector() {
			delete this;
		}
		bool get_clk() {
			return this->SCL;
		}
		void master_set_sda(bool byte_data) {
			this->SDA = byte_data;
		}
		char slave_get_sda() {
			return this->SDA;
		}
		void master_start_simulate_SCL() {
			auto start = chrono::steady_clock::now();
			cout << "START CLOCK" << endl;
			while (true) {
					cout << this->SCL << endl;
					this->SCL = !this->SCL;
				std::this_thread::sleep_for(std::chrono::milliseconds(this->clock_period));
			}
		}

};

