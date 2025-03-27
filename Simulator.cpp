#include "Master.h"
#include "Slave.h"
#include <vector>


void main() {
	//1.Init Master
	//2.Init 4 Slaves
	//3.Init line connectors and load slave addresses
	//4.Send messages to slaves
	LineConnector* line = new LineConnector(1000);

	Master m = Master(100);
	m.set_connection(line);

	vector<Slave*> slaves;
	for (auto& s : slaves) {
		s = new Slave();
		s->set_connection(line);
		m.load_slave_address(s->get_address());
	}



	std::thread thread_obj(&Master::start_CLK, &m);

	std::cout << "Main" << endl;

}
