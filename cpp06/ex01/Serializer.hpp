#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

typedef struct s_Data
{
    unsigned char   chr;
    uint8_t         idx;
    uint16_t        info;
} Data;

class Serializer
{

	public:
		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

	private:

};


#endif /* ****************************************************** SERIALIZER_H */