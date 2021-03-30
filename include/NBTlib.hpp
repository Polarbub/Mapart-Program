#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace nbt {

    namespace internal {
        std::string getName(std::vector<int> nbt) {
            std::string out = "";
            int repeat = 0;
            
            while (repeat >= nbt[1]) {
                char c = nbt[repeat + 2];
                out.push_back(c);
                repeat++;
            }

            return out;
        }

    }

    std::vector<int> readNbt(std::string fileName) {

        std::ifstream infile(fileName);
        std::vector<int> Hexes;
	    int c = infile.get();

        while (infile.good()) {
            Hexes.push_back(c);
    	    c = infile.get();
        }
        infile.close();

        if(Hexes[0] == 10 && Hexes[1] == 0 && Hexes[2] == 0 && Hexes[Hexes.size() - 1] == 0) {
            int repeat = 0;
            while(repeat <= 3) {
                Hexes.erase(Hexes.begin());
                repeat++;
            }
            Hexes.pop_back();
            return Hexes;
        } else {
            throw "bad nbt file";
        }
    }

    std::string readStringName(std::vector<int> nbt, std::string name) {
        int offset = 0;
        if(nbt[0 + offset] == 8 && nbt[1 + offset] == 0) {
            
        }
    }

}
