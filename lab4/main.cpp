#include <iostream>
#include <string>
#include <fstream>

std::string processInput(const std::string& filename){
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

    return 0;
}



