#include "Serializer.hpp"


int main(void)
{
	Data		*data = new Data;

	data->idx = 2;
	std::cout << Serializer::serialize(data) << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(data)) << std::endl;
	// std::cout << Serializer::deserialize(Serializer::serialize(data))->idx << std::endl;
	delete data;
	return 0;
}