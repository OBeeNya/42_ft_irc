#ifndef MESSAGE_HPP
# define MESSAGE_HPP

class Message {

	public:
	
		/************ Member functions ************/
		Message();
		Message(Client*);
		Message(const std::string);
		Message(const Message&);
		Message &operator=(const Message&);
		~Message();

		void 	createMessage();
		void	tokenizer(std::string);
		
		/************ Getters / Setters ************/
		void setPrefix(std::string);
		void setCmd(std::string);
		void setParams(std::vector<std::string>);

		std::string 				getMessage() const;
		std::string 				getPrefix() const;
		std::string 				getCmd() const;
		std::vector<std::string>&	getParams();

	private:

		/************ Attributes ************/
		Client*						_client;
		std::string					_message;
		std::string 				_prefix;
		std::string					_cmd;
		std::vector<std::string>	_params;

};

std::ostream &operator<<(std::ostream &out, Message &data);

#endif
