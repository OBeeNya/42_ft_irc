#include "utils.hpp"

void showConfig() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "********** CONFIGURATION ********" << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Server name   " << "     |     " << NAME << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Version       " << "     |     " << VERSION << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Max Users     " << "     |     " << MAX_USERS << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Oper User     " << "     |     " << OPER_USER << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Oper Password " << "     |     " << OPER_PASSWORD << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << " Timeout       " << "     |     " << TIMEOUT << std::endl;
	std::cout << "---------------------------------" << std::endl;
}
