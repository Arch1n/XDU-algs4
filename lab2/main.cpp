
#include "arGL.h"
#include "arObserver.h"
#include "arOptions.h"

arObserver ob;

void sort_helper(const std::vector<int>& mess, void (*sort) (std::vector<int>& , bool(*cmp)(const int&, const int&))){
    std::vector<int> A;
    for(const auto& c:mess)
        A.emplace_back(c);
    auto start_time = std::chrono::system_clock::now();
    auto start_mem = ob.get_proc_mem();
    sort(A, [](const int& a, const int& b){ return a < b;});
    auto end_time = std::chrono::system_clock::now();
    auto end_mem = ob.get_proc_mem();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> (end_time - start_time);
    std::cout << "time :" << static_cast<double> (duration.count()) / std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;
    std::cout << "memory :"<< end_mem - start_mem  << std::endl;

}

void test(int size){
    std::vector<int> mess(size);
    std::cout<< "size = " << size << std::endl;
    std::iota(mess.begin(), mess.end(), 1);
    std::cout << "insertion: \t";
    sort_helper(mess, &insertion::sort);
    std::cout <<std::endl;

    std::cout << "quick: \t";
    sort_helper(mess, &quick::sort);
    std::cout <<std::endl;

    std::cout << "merge: \t";
    sort_helper(mess, &merge::sort);
    std::cout <<std::endl;

    std::cout << "quick3way: \t";
    sort_helper(mess, &quick3way::sort);
    std::cout <<std::endl;

    std::cout << "mergeBU: \t";
    sort_helper(mess, &mergeBU::sort);
    std::cout <<std::endl;




}

int main(int argc, char** argv) {
#ifdef DRAW
    arGLmain(argc, argv);
#else //DRAW
    test(1000);
    test(5000);
    test(10000);
    test(1000000);
#endif
    return 0;
}
