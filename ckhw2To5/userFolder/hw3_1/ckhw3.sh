cd p1
g++ perfect.cpp -o your_perfect
cd ..
/home/stu/cbb111227/turnin/cpp.hw3/ckhw "p1/your_perfect" a.perfect perfect_ > "hw3_output.txt"
/home/stu/cbb111227/turnin/cpp.hw3/cktf "p1/your_perfect" a.perfect perfect_ > "hw3_inspect.txt"
#rm -f your_perfect *~ a.out

cd p2
g++ chaistory.cpp -o your_chaistory
cd ..
/home/stu/cbb111227/turnin/cpp.hw3/ckhw "p2/your_chaistory" a.chaistory chaistory_ >> "hw3_output.txt"
/home/stu/cbb111227/turnin/cpp.hw3/cktf "p2/your_chaistory" a.chaistory chaistory_ >> "hw3_inspect.txt"
#rm -f your_chaistory *~ a.out

cd p3
g++ barchart.cpp -o your_barchart
cd ..
/home/stu/cbb111227/turnin/cpp.hw3/ckhw "p3/your_barchart" a.barchart barchart_ >> "hw3_output.txt"
/home/stu/cbb111227/turnin/cpp.hw3/cktf "p3/your_barchart" a.barchart barchart_ >> "hw3_inspect.txt"
#rm -f your_barchart *~ a.out

cd p4
make
mv a.out your_10andhalf
cd ..
/home/stu/cbb111227/turnin/cpp.hw3/ckhw "p4/your_10andhalf" a.10andhalf 10andhalf_ >> "hw3_output.txt"
/home/stu/cbb111227/turnin/cpp.hw3/cktf "p4/your_10andhalf" a.10andhalf 10andhalf_ >> "hw3_inspect.txt"
#make clean
#rm -f your_10andhalf a.out *.o *~ *.*~

cd p1
rm -f  your_perfect *~ a.out
cd ../p2
rm -f your_chaistory *~ a.out
cd ../p3
rm -f your_barchart *~ a.out
cd ../p4
rm -f your_10andhalf a.out *.o *~ *.*~

cd ..
echo "============================================="
echo "\n\nProcess finished. Run [ cat hw3_output.txt ] and [ cat hw3_inspect.txt ] to inspect the result."
