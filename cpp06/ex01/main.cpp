#include "Serializer.hpp"
#include <iostream>

int main() {
    
    Data data;
    data.number = 42;
    data.text = "Hello, World!";

    
    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << "Original Data: " << data.number << ", " << data.text << std::endl;

  
    uintptr_t raw = Serializer::serialize(&data);

   
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

 
    Data* deserializedData = Serializer::deserialize(raw);

    
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->number << ", " << deserializedData->text << std::endl;

  
    if (&data == deserializedData) {
        std::cout << "Success: The deserialized pointer is equal to the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer is not equal to the original pointer." << std::endl;
    }

    return 0;
}
