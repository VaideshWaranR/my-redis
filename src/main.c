#include "../include/server.h"
#include "../include/datastore.h"
int main(){
	load_data("../data/data.db");
	start_server();
	return 0;
}
