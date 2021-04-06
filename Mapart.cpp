#include <iostream>
#include "NBTlib.hpp"

int main() {
    try{
        std::vector<char> nbt = nbt::readNbt("Test");
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    long test = 134121;

	return 0;
}