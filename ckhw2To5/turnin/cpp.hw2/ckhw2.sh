cd p1
make
cd ..
/home/stu/cbb111227/turnin/cpp.hw2/ckhw "p1/a.out" wu.string string_ > "hw2_output.txt"
/home/stu/cbb111227/turnin/cpp.hw2/cktf "p1/a.out" wu.string string_ > "hw2_inspect.txt"
cd p2
g++ f2c.cpp
cd ..
/home/stu/cbb111227/turnin/cpp.hw2/ckhw "p2/a.out" wu.f2c f2c_ >> "hw2_output.txt"
/home/stu/cbb111227/turnin/cpp.hw2/cktf "p2/a.out" wu.f2c f2c_ >> "hw2_inspect.txt"
cd p3
g++ fare.cpp
cd ..
/home/stu/cbb111227/turnin/cpp.hw2/ckhw "p3/a.out" wu.fare fare_ >> "hw2_output.txt"
/home/stu/cbb111227/turnin/cpp.hw2/cktf "p3/a.out" wu.fare fare_ >> "hw2_inspect.txt"
cd p4
make
cd ..
/home/stu/cbb111227/turnin/cpp.hw2/ckhw "p4/a.out" wu.value value_ >> "hw2_output.txt"
/home/stu/cbb111227/turnin/cpp.hw2/cktf "p4/a.out" wu.value value_ >> "hw2_inspect.txt"
cd p1
make clean
cd ../p2
rm a.out *~
cd ../p3
rm a.out *~
cd ../p4
make clean
cd ..
echo "Process finished. Run [ cat hw2_output.txt ] and [ cat hw2_inspect.txt ] to inspect the result."