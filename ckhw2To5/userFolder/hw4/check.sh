#!/bin/bash

echo "Checking of your HW4 is currently in progress, please wait..."

# Process for p1
cd p1
c++ -c twoNumbers.cpp && c++ main.cpp twoNumbers.o -o your_twoNumbers
/home/stu/cbb111227/turnin/cpp.hw4/ckhw "your_twoNumbers" a.twoNumbers twoNumbers_ > "../hw4_output.txt"
/home/stu/cbb111227/turnin/cpp.hw4/cktf "your_twoNumbers" a.twoNumbers twoNumbers_ > "../hw4_inspect.txt"
cd ..

# Process for p2
cd p2
c++ -c findAMac.cpp && c++ main.cpp findAMac.o -o your_findAMac
/home/stu/cbb111227/turnin/cpp.hw4/ckhw "your_findAMac" a.findAMac findAMac_ >> "../hw4_output.txt"
/home/stu/cbb111227/turnin/cpp.hw4/cktf "your_findAMac" a.findAMac findAMac_ >> "../hw4_inspect.txt"
cd ..

# Process for p3
cd p3
c++ -c contact.cpp && c++ main.cpp contact.o -o your_contact
/home/stu/cbb111227/turnin/cpp.hw4/ckhw "your_contact" a.contact contact_ >> "../hw4_output.txt"
/home/stu/cbb111227/turnin/cpp.hw4/cktf "your_contact" a.contact contact_ >> "../hw4_inspect.txt"
cd ..

# Process for p4
cd p4
c++ -c dynamic2DArray.cpp && c++ main.cpp dynamic2DArray.o -o your_dynamic2DArray
/home/stu/cbb111227/turnin/cpp.hw4/ckhw "your_dynamic2DArray" a.dynamic2DArray dynamic2DArray_ >> "../hw4_output.txt"
/home/stu/cbb111227/turnin/cpp.hw4/cktf "your_dynamic2DArray" a.dynamic2DArray dynamic2DArray_ >> "../hw4_inspect.txt"
cd ..

# Clean up
cd p1 && rm -f your_twoNumbers a.out *.o *~ *.*~
cd ../p2 && rm -f your_findAMac a.out *.o *~ *.*~
cd ../p3 && rm -f your_contact a.out *.o *~ *.*~
cd ../p4 && rm -f your_dynamic2DArray a.out *.o *~ *.*~
cd ..

echo "============================================="
echo ""
echo "Process finished. Run [ cat hw4_output.txt ] and [ cat hw4_inspect.txt ] to inspect the result."
