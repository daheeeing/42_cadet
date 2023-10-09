#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->content = "dapark";

	std::cout << "before: " << data->content << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	data = Serializer::deserialize(ptr);

	std::cout << "after: " << data->content << std::endl;

	delete data;

	return 0;
}
