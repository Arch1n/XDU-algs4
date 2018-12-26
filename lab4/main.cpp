#include <iostream>
#include <string>
#include <fstream>

std::string wang9897isMySon(const std::string& filename){
    std::ifstream fin(filename);
    std::string line, T;
    while(getline(fin, line)) {
        for (const auto &c: line) {
            if(islower(c))
                T += c;
            else if(!T.empty() && T.back() != ' ')
                T += ' ';
        }
        if(!T.empty() && T.back() != ' ')
            T += ' ';
    }
    fin.close();
    return T;
}

int main() {
    std::cout << wang9897isMySon("corpus.txt") << std::endl;
    return 0;
}



