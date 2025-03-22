#include "Master.h"
#include "Slave.h"
#include <vector>


void main() {
	//1.Init Master
	//2.Init 4 Slaves
	//3.Init line connectors and load slave addresses
	//4.Send messages to slaves
	LineConnector* line = new LineConnector();

	Master* m = new Master();
	m->set_connection(line);

	vector<Slave*> slaves;
	for (auto& s : slaves) {
		s = new Slave();
		s->set_connection(line);
	}

}
