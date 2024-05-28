#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <memory>
#include <array>
#include <string>
using namespace std;

string execute_command(const string& command) {
    array<char, 1001> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <executable1> <executable2> <inputfile>" << endl;
        return 1;
    }
    
    string errorLog;
    string execPath1 = argv[1];
    string execPath2 = argv[2];
    string inputFilePathBase = argv[3];
    string inputFilePath;
    string locationPath = "/home/stu/cbb111227/turnin/cpp.hw3/testfile/";
    string pName;



    cout << "==========" << inputFilePathBase << "Compared Result ==========" << endl;

    for (int i = 0; ; ++i) {
        inputFilePath = inputFilePathBase;
        size_t lastUnderScore = inputFilePath.find_last_of('_');
        if (lastUnderScore != string::npos) {
            inputFilePath = inputFilePath.substr(0, lastUnderScore + 1) + to_string(i) + ".in";
        } else {
            inputFilePath += "_" + to_string(i) + ".in";
        }
        //inputFilePath.insert(inputFilePath.begin(), static_cast<char*>("/home/stu/cbb111227/turnin/cpp.hw1/hw1_testfile"));
        inputFilePath = locationPath + inputFilePath;
        //cout << inputFilePath;
        ifstream file(inputFilePath);
        if(!file) break;
        string command1 = "./" + execPath1 + " < " + inputFilePath;
        string command2 = "/home/stu/cbb111227/turnin/cpp.hw3/testfile/" + execPath2 + " < " + inputFilePath;

        string output1 = execute_command(command1);
        string output2 = execute_command(command2);
        if ((!output1.empty()) || (!output2.empty())) {
            if (output1 == output2) {
                cout << "Testfile ["+ to_string(i) +"] ---------------- [PASSED]" << endl;
            } else {
                cout << "Testfile ["+ to_string(i) +"] ---------------- [FAILED]----------x" << endl;
                errorLog = errorLog + execPath1 + " in testfile ["+ to_string(i) +"]\n";
            }
        }
    }
    return 0;
}
