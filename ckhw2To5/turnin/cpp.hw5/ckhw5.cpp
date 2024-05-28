#include <cstdlib>
using namespace std;

int main() {
    system("echo \"Checking of your HW5 is currently in progress, please wait...\"");

    // Process for p1
    system("cd p1 && c++ -c date.cpp && c++ /home/stu/cbb111227/turnin/cpp.hw5/testfile/Template_hw5/p1/main.cpp date.o -o your_date");
    system("/home/stu/cbb111227/turnin/cpp.hw5/ckhw \"p1/your_date\" A.date date_ > \"hw5_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw5/cktf \"p1/your_date\" A.date date_ > \"hw5_inspect.txt\"");

    // Process for p2
    system("cd p2 && c++ -c star.cpp && c++ -c date.cpp && c++ /home/stu/cbb111227/turnin/cpp.hw5/testfile/Template_hw5/p2/main.cpp star.o date.o -o your_star");
    system("/home/stu/cbb111227/turnin/cpp.hw5/ckhw \"p2/your_star\" A.star star_ >> \"hw5_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw5/cktf \"p2/your_star\" A.star star_ >> \"hw5_inspect.txt\"");

    // Process for p3
    system("cd p3 && c++ -c star.cpp && c++ -c date.cpp && c++ main.cpp star.o date.o -o your_main");
    system("/home/stu/cbb111227/turnin/cpp.hw5/ckhw \"p3/your_main\" A.main main_ >> \"hw5_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw5/cktf \"p3/your_main\" A.main main_ >> \"hw5_inspect.txt\"");

    // Cleanup
    system("cd p1 && rm -f your_date a.out *.o *~ *.*~");
    system("cd p2 && rm -f your_star a.out *.o *~ *.*~");
    system("cd p3 && rm -f your_main a.out *.o *~ *.*~");

    system("echo \"=============================================\"");
    system("echo \"\"");
    system("echo \"Process finished. Run [ cat hw5_output.txt ] and [ cat hw5_inspect.txt ] to inspect the result.\"");

    return 0;
}
