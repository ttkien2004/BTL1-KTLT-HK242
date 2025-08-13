#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>  // For creating a directory
#include <sys/types.h> // For mkdir() on Unix-like OS
#include <direct.h>    // For _mkdir() on Windows

using namespace std;

// Constants
const int LF_SIZE = 17;
const int MIN_LF = 0, MAX_LF = 1000;
const int MIN_EXP = 0, MAX_EXP = 600;
const int MIN_T = 0, MAX_T = 3000;
const int MIN_E = 0, MAX_E = 99;



// Function to generate a random number in a range
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate and save a test case
void generateTestCase(const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to create file " << filename << endl;
        return;
    }

    // Generate LF1 array
    outFile << "[";
    for (int i = 0; i < LF_SIZE; i++) {
        outFile << getRandomNumber(MIN_LF, MAX_LF);
        if (i < LF_SIZE - 1) outFile << ",";
    }
    outFile << "]\n";

    // Generate LF2 array
    outFile << "[";
    for (int i = 0; i < LF_SIZE; i++) {
        outFile << getRandomNumber(MIN_LF, MAX_LF);
        if (i < LF_SIZE - 1) outFile << ",";
    }
    outFile << "]\n";

    // Generate EXP1 and EXP2
    outFile << getRandomNumber(MIN_EXP, MAX_EXP) << " " << getRandomNumber(MIN_EXP, MAX_EXP) << "\n";

    // Generate T1 and T2
    outFile << getRandomNumber(MIN_T, MAX_T) << " " << getRandomNumber(MIN_T, MAX_T) << "\n";

    // Generate E
    outFile << getRandomNumber(MIN_E, MAX_E);
    

    outFile.close();
    cout << "Test case saved: " << filename << endl;
}

void generateOutput(const string &filename) {
    ofstream outfile(filename);
    outfile.close();
}

// Function to create a directory (cross-platform)
void createDirectory(const string &folder) {
#if defined(_WIN32)
    _mkdir(folder.c_str()); // Windows
#else
    mkdir(folder.c_str(), 0777); // Linux/macOS
#endif
}

int main() {
    srand(time(0)); // Seed for random numbers

    string folder = "testcases";
    createDirectory(folder);
    string output_folder = "outputs";
    createDirectory(output_folder);

    int numTestCases;
    cout << "Enter number of test cases to generate: ";
    cin >> numTestCases;

    for (int i = 1; i <= numTestCases; i++) {
        string filename = folder + "/tc_" + (i < 10 ? "0" : "") + to_string(i);
        string output_file = output_folder + "/tc_" + (i < 10 ? "0" : "") + to_string(i);
        generateTestCase(filename);
        generateOutput(output_file);
    }

    cout << "All test cases generated in folder: " << folder << endl;
    cout << "All outputs generated in folder: " << output_folder << endl;
    return 0;
}
