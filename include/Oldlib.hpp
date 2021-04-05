#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace nbt {

    namespace internal {
        std::vector<std::string> getName(std::vector<int> nbt, int offset) {
            std::vector<std::string> out;
            int repeat = 0;

            while (repeat >= nbt[offset]) {
                char c = nbt[repeat + 1 + offset];
                out[1].push_back(c);
                repeat++;
            }

            out[0] = std::to_string(repeat + 3);
            return out;
        }

        int getNextTag(std::vector<int> nbt, int filter) {
            int check = 0;
            while(nbt.size() >= check) {
                if(nbt[check] == filter && nbt[check + 1] == 0) {
                    return check;
                }
                check++;
            }
            return 0;
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

    std::string readStringByName(std::vector<int> nbt, std::string filterName) {

        int offset = 0;

        while(nbt.size() >= offset) {

            if(nbt[0 + offset] == 8 && nbt[1 + offset] == 0) {

                std::string tagName = internal::getName(nbt, )[1];

                if(tagName == filterName) {
                    int repeat = 0;
                    //offset = offset +
                    std::string out;
                    while (repeat + offset >= nbt[1 + offset]) {
                        char c = nbt[1 + offset];
                        out.push_back(c);
                        repeat++;
                    }

                    return out;
                }

            } else {
                offset = internal::getNextTag(nbt, 8);
                if(offset == 0) {
                    return "";
                }
            }
        }
        return "";
    }
}
