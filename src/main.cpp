#include "../inc/utils.hpp"

int  serv_run = 0;

void ft_handler(int smth) {
	(void) smth;
	serv_run = 1;
}

int	main (int ac, char** av) {
	signal(SIGINT, ft_handler);
	if (ac != 3 || checkPort(av[1])) {
		std::cerr << "Error " << std::endl << "Syntax: ./IRC PORT PASSWORD" << std::endl ;
		return (1);
	}
	Server	server(av[1], av[2]);
	server.usePoll();
	return (0);
}
