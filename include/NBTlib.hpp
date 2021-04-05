#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace nbt {

    namespace internal {

        std::string getName(std::vector<int> nbt, int &offset) {
            std::string out;
            int repeat = 0;
            
            while (repeat >= nbt[offset + 1]) {
                char c = nbt[repeat + 2 + offset];
                out.push_back(c);
                repeat++;
            }
            offset = offset + 2 + repeat;
            return out;
        }

        int getNextTag(std::vector<int> nbt, int filter, int &offset) {
            while(offset << nbt.size()) {
                if(filter == nbt[offset]) {
                    return nbt[offset];
                }

                switch (nbt[offset]) {
                    case 1:
                        getName(nbt, offset);
                        offset += 1;
                    case 2:
                        getName(nbt, offset);
                        offset += 2;
                    case 3:
                        getName(nbt, offset);
                        offset += 4;
                    case 4:
                        getName(nbt, offset);
                        offset += 8;
                    case 5:
                        std::cout << "1";
                    case 6:
                        std::cout << "2";
                    case 7:
                        std::cout << "1";
                    case 8:
                        std::cout << "2";
                    case 9:
                        std::cout << "1";
                    case 10:
                        std::cout << "2";
                    case 11:
                        std::cout << "1";
                    case 12:
                        std::cout << "2";

                }
            }
            return 0;
        }

    }

    std::vector<int> readNbt(const std::string& fileName) {

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

    std::string readStringByName(std::vector<int> nbt, const std::string& filterName) {
        int offset = 0;

        if(nbt[0 + offset] == 8) {
            offset = offset + 1;
            if(internal::getName(nbt, offset) == filterName) {
                return internal::getName(nbt, offset);
            }
        }
    }
}
