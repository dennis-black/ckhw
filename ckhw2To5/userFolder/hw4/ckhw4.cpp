#include <cstdlib>
using namespace std;

int main() {
    system("echo \"Checking of your HW4 is currently in progress, please wait...\"");

    // Process for p1
    system("cd p1 && c++ -c twoNumbers.cpp && c++ main.cpp twoNumbers.o -o your_twoNumbers");
    system("/home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p1/your_twoNumbers\" a.twoNumbers twoNumbers_ > \"hw4_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw4/cktf \"p1/your_twoNumbers\" a.twoNumbers twoNumbers_ > \"hw4_inspect.txt\"");
    system("cd ..");

    // Process for p2
    system("cd p2 && c++ -c findAMac.cpp && c++ main.cpp findAMac.o -o your_findAMac");
    system("/home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p2/your_findAMac\" a.findAMac findAMac_ >> \"hw4_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw4/cktf \"p2/your_findAMac\" a.findAMac findAMac_ >> \"hw4_inspect.txt\"");
    system("cd ..");

    // Process for p3
    system("cd p3 && c++ -c contact.cpp && c++ main.cpp contact.o -o your_contact");
    system("/home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p3/your_contact\" a.contact contact_ >> \"hw4_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw4/cktf \"p3/your_contact\" a.contact contact_ >> \"hw4_inspect.txt\"");
    system("cd ..");

    // Process for p4
    system("cd p4 && c++ -c dynamic2DArray.cpp && c++ main.cpp dynamic2DArray.o -o your_dynamic2DArray");
    system("/home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p4/your_dynamic2DArray\" a.dynamic2DArray dynamic2DArray_ >> \"hw4_output.txt\"");
    system("/home/stu/cbb111227/turnin/cpp.hw4/cktf \"p4/your_dynamic2DArray\" a.dynamic2DArray dynamic2DArray_ >> \"hw4_inspect.txt\"");
    system("cd ..");

    // Cleanup
    system("cd p1 && rm -f your_twoNumbers a.out *.o *~ *.*~");
    system("cd p2 && rm -f your_findAMac a.out *.o *~ *.*~");
    system("cd p3 && rm -f your_contact a.out *.o *~ *.*~");
    system("cd p4 && rm -f your_dynamic2DArray a.out *.o *~ *.*~");
    system("cd ..");

    system("echo \"=============================================\"");
    system("echo \"\"");
    system("echo \"Process finished. Run [ cat hw4_output.txt ] and [ cat hw4_inspect.txt ] to inspect the result.\"");

    return 0;
}

