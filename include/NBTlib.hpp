#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace nbt {

    std::vector<int> readNbt(std::string fileName) {
        
        std::ifstream infile(fileName);
        std::vector<int> Hexes;
	    int c = infile.get();

        while (infile.good()) {
            Hexes.push_back(c);
    	    c = infile.get();
        }
        infile.close();
        return Hexes;
    }
}
