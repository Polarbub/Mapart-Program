#include <iostream>
#include "NBTlib.hpp"

int main() {
    try{
        std::vector<int> nbt = nbt::readNbt("Test");
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    

	return 0;
}