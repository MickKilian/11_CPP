#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <stdint.h>

struct Data
{
	int			id;
	std::string	name;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
