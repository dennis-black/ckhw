#include <cstdlib>
using namespace std;
int main() {
    system("echo \"Checking of your HW4 is currently in progress, please wait...\"");

    system(
        "cd p1 && c++ -c twoNumbers.cpp && c++ main.cpp twoNumbers.o -o your_twoNumbers && cd .. "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p1/your_twoNumbers\" a.twoNumbers twoNumbers_ > \"hw4_output.txt\" "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/cktf \"p1/your_twoNumbers\" a.twoNumbers twoNumbers_ > \"hw4_inspect.txt\" "
        "&& cd p2 && c++ -c findAMac.cpp && c++ main.cpp findAMac.o -o your_findAMac && cd .. "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p2/your_findAMac\" a.findAMac findAMac_ >> \"hw4_output.txt\" "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/cktf \"p2/your_findAMac\" a.findAMac findAMac_ >> \"hw4_inspect.txt\" "
        "&& cd p3 && c++ -c contact.cpp && c++ main.cpp contact.o -o your_contact && cd .. "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p3/your_contact\" a.contact contact_ > \"hw4_output.txt\" "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/cktf \"p3/your_contact\" a.contact contact_ >> \"hw4_inspect.txt\" "
        "&& cd p4 && c++ -c dynamic2DArray.cpp && c++ main.cpp dynamic2DArray.o -o dynamic2DArray && cd .. "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/ckhw \"p4/your_dynamic2DArray\" a.dynamic2DArray dynamic2DArray_ >> \"hw4_output.txt\" "
        "&& /home/stu/cbb111227/turnin/cpp.hw4/cktf \"p4/your_dynamic2DArray\" a.dynamic2DArray dynamic2DArray_ >> \"hw4_inspect.txt\" "
        "&& cd p1 && rm -f your_twoNumbers a.out *.o *~ *.*~  && cd ../p2 && rm -f your_findAMac a.out *.o *~ *.*~ "
        "&& cd ../p3 && rm -f your_contact a.out *.o *~ *.*~ && cd ../p4 && rm -f your_dynamic2DArray a.out *.o *~ *.*~ "
        "&& cd .. && echo \"=============================================\\n\\nProcess finished. Run [ cat hw4_output.txt ] and [ cat hw4_inspect.txt ] to inspect the result.\""
    );
    return 0;
}
