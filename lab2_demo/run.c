#include <stdlib.h>
int main(int argc, char **argv){
    if(argc == 1){
        system("./insertion &");
        system("./merge &");
        system("./mergeBU &");
        system("./quick &");
        system("./quick3way &");
        system("./bubble &");
    }
    else {
        system("./std &");
        system("./merge &");
        system("./mergeBU &");
        system("./quick &");
        system("./quick3way &");
        system("./stdstable &");
    }
    return 0;
}
