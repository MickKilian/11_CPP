#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	uintptr_t data_intptr;
	Data *data_back;

	data->id = 5;
	data->name = "susan";
	std::cout << "Initial Data* : " << data << std::endl;
	std::cout << "data->id : " << data->id << std::endl;
	std::cout << "data->name : " << data->name << std::endl;
	data_intptr = Serializer::serialize(data);
	data_back = Serializer::deserialize(data_intptr);
	std::cout << "Cast to uintptr_t : " << data_intptr << std::endl;
	std::cout << "Re-cast to Data* : " << data_back << std::endl;
	std::cout << "re-cast data->id : " << data_back->id << std::endl;
	std::cout << "re-cast data->name : " << data_back->name << std::endl;

	delete data;
	return 0;
}
