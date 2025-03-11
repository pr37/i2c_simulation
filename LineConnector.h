#pragma once
#include <chrono>

using namespace std;

class LineConnector
{
	private:
		bool SDA;
		bool SCL;
		int clock_period;
	public:
		LineConnector() {
		}
		void master_set_sda(bool byte_data) {
			this->SDA = byte_data;
		}
		char slave_get_sda() {
			return this->SDA;
		}
		void master_start_simulate_SCL() {
			auto start = chrono::steady_clock::now();
			while (true) {
				auto now = chrono::steady_clock::now();
				auto duration = chrono::duration_cast<chrono::milliseconds>(now - start);
				if (duration.count() >= clock_period) {	//we have surpassed clock period - change signal
					this->SCL = !this->SCL;
				}
			}
		}

};

