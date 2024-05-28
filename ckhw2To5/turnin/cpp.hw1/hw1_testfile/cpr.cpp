#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <memory>
#include <array>
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

    string execPath1 = argv[1];
    string execPath2 = argv[2];
    string inputFilePathBase = argv[3];
    string inputFilePath;

    for (int i = 0; ; ++i) {
        inputFilePath = inputFilePathBase;
        size_t lastUnderScore = inputFilePath.find_last_of('_');
        if (lastUnderScore != string::npos) {
            inputFilePath = inputFilePath.substr(0, lastUnderScore + 1) + to_string(i) + ".in";
        } else {
            inputFilePath += "_" + to_string(i) + ".in";
        }
        ifstream file(inputFilePath);
        if(!file) break;
        string command1 = "./" + execPath1 + " < " + inputFilePath;
        string command2 = "./" + execPath2 + " < " + inputFilePath;

        string output1 = execute_command(command1);
        string output2 = execute_command(command2);
        if ((!output1.empty()) || (!output2.empty())) {
            cout << "\n-----------------------In Testfile [" << i << "]--------------------------\n";
            cout << "=========== " << execPath1 << " output ===========\n";
            cout << output1 << endl;
            cout << "=========== " << execPath2 << " output ===========\n";
            cout << output2 << endl;
            cout << "=====================Judgement=====================\n";

            if (output1 == output2) {
                cout << "Outputs are the same :)" << endl;
            } else {
                cout << "x-----------------------------------------------------Outputs differ :(" << endl;
            }
        }
    }
    return 0;
}
