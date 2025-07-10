#include "./includes/Data.hpp"

#include "./includes/Serializer.hpp"

int main(){
    Data user = {1,"odib"};
    Data* ptr = &user;
    uintptr_t serializedValue = Serializer::serialize(ptr);
    std::cout << "serialized value = " << serializedValue << std::endl;
    
    Data* deserializedValue = Serializer::deserialize(serializedValue);
    std::cout << "deserialized value = " << deserializedValue << std::endl;
    return 0;
}
