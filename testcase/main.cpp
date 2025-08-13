/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2025
* Date: 07.02.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "tay_nguyen_campaign.h"


using namespace std;

// Hàm tạo mục tiêu ngẫu nhiên
string generateRandomTarget() {
  srand(time(0));  // Seed số ngẫu nhiên
  string targets[5] = {
    "Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21", "National Route 14"
};

  int index = rand() % 5;
  return targets[index];
}

// Hàm mã hóa Caesar Cipher
std::string caesarCipherEncode(const std::string& message, int shift) {
  std::string encodedMessage = message;
  for (char& c : encodedMessage) {
      if (std::isalpha(c)) { // Chỉ mã hóa chữ cái
          char base = std::islower(c) ? 'a' : 'A';
          c = (c - base + shift) % 26 + base;
      }
  }
  return encodedMessage;
}

// Hàm mã hóa thông điệp dựa trên EXP1 và EXP2
std::string encodeMessage(const std::string& target, int EXP1, int EXP2) {
  if (EXP1 >= 300 && EXP2 >= 300) {
      int shift = (EXP1 + EXP2) % 26;
      return caesarCipherEncode(target, shift);
  } else {
      return std::string(target.rbegin(), target.rend()); // Đảo ngược chuỗi
  }
}

// generate message
string createTarget() {
  srand(time(0));
  int index = rand() % 3;
  string name[3] = {"Kon Tum", "Pleuku", "Gia Lai"};
  return name[index];
}
string createDecoySignal(std::string target, int targetID) {    
  srand(time(0));  // Khởi tạo seed cho số ngẫu nhiên
  int numDigits = rand() % 3 + 1;  // Chọn ngẫu nhiên từ 1 đến 3 số nguyên

  int numbers[numDigits] = {};
  for (int i = 0; i < numDigits; i++) {
      int num = rand() % 100;  // Chọn số nguyên từ 0 đến 99
      numbers[i] = num;
  }

  std::string encodedTarget = target;
  int insertIndex = rand() % (encodedTarget.length() + 1);

  for (int num : numbers) {
      encodedTarget.insert(insertIndex, std::to_string(num));
      insertIndex = rand() % (encodedTarget.length() + 1);  // Cập nhật vị trí mới
  }

  return encodedTarget;
}

void tnc_tc_01(string testcase_input, string testcase_output) {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file(testcase_input);
    ofstream outfile(testcase_output);
    if (!outfile) {
      cerr << "Error: Unable to create file " << testcase_output << endl;
      return;
  }
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;    
    if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {        
        return;
    }

    // Print all elements of LF1
  cout << "LF1: ";
  for (int i = 0; i < 17; i++)
    cout << LF1[i] << " ";
  cout << endl;

  // Print all elements of LF2
  cout << "LF2: ";
  for (int i = 0; i < 17; i++)
    cout << LF2[i] << " ";
  cout << endl;

  // Print other values
  cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << endl;
  cout << "T1: " << T1 << ", T2: " << T2 << endl;
  cout << "E: " << E << endl;

//   // Test gatherForces
  int result1 = gatherForces(LF1, LF2);  
  cout << "Result: " << result1 << endl;

//   // Test task2
//     srand(time(0));
//     int targetId = rand() % 5 + 3;
//     string message = createDecoySignal(createTarget(), targetId);
//     cout << "Message: " << message << ", TargetID: " << targetId << endl;
//   string encodedTarget1 = "Kon3 Tum";
// //   string encodedTarget2 = "Ple9iku5";
// //   string encodedTarget3 = "Ple1Ku4Nat9";  
// //   string encodedTarget4 = "Buon1Ma3Thuot5-8";

//   cout << "Decoded Target 1: " << determineRightTarget(message) << endl;
//   outfile << "Decoded Target: " << determineRightTarget(message) << endl;
// //   cout << "Decoded Target 2: " << determineRightTarget(encodedTarget2) << endl;
// //   cout << "Decoded Target 3: " << determineRightTarget(encodedTarget3) << endl;
// //   cout << "Decoded Target 4: " << determineRightTarget(encodedTarget4) << endl;

//   string randomTarget = generateRandomTarget();
//   string encodedMessage = caesarCipherEncode(randomTarget, 10);
//   cout << "Encoded message: " << encodedMessage << endl;
//   string decodedTarget = decodeTarget(encodedMessage, EXP1, EXP2);
//   cout << "Decoded Right Target: " << decodedTarget << endl;
//   outfile << "Decoded Right Target: " << decodedTarget << endl;

//   encodedMessage = "paL cuD";
//   decodedTarget = decodeTarget(encodedMessage, EXP1, EXP2);
//   cout << "Decoded Target: " << decodedTarget << endl;

//   encodedMessage = "Xyz";
//   decodedTarget = decodeTarget(encodedMessage, EXP1, EXP2);
//   cout << "Decoded Target: " << decodedTarget << endl;

//   encodedMessage = "abc";
//   decodedTarget = decodeTarget(encodedMessage, EXP1, EXP2);
//   cout << "Decoded Target: " << decodedTarget << endl;

//   // Test task3
  //   int LF1_total = 1987, LF2_total = 2968;
  //   // for (int i = 0; i < 17; i++) {
  //   //     LF1_total += LF1[i];
  //   //     LF2_total += LF2[i];
  //   // }
  //   cout << "LF1: " << LF1_total << " LF2: " << LF2_total << endl;
  int LF1_total = 0, LF2_total = 0;
  for (int i = 0; i < 17; i++) {
    LF1_total += LF1[i];
    LF2_total += LF2[i];
  }
   manageLogistics(LF1_total, LF2_total, EXP1, EXP2, T1, T2, E);
  outfile << "T1: " << T1 << ", T2: " << T2;

  // // Print the modified supply values
  cout << "T1: " << T1 << ", T2: " << T2 << endl;

//   // Test task4
//   int battleField[10][10] = {
//     {106, 15, 20, 25, 305, 635, 540, 145, 50, 55},
//     {25, 18, 24, 330, 36, 442, 48, 54, 660, 665},
//     {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
//     {162, 24, 323, 404, 484, 60, 40, 72, 80, 88},
//     {181, 27, 36, 52, 543, 63, 72, 81, 90, 99},
//     {5, 30, 40, 501, 602, 70, 80, 90, 100, 110},
//     {22, 33, 442, 55, 66, 77, 58, 99, 10, 121},
//     {24, 36, 48, 60, 72, 84, 96, 108, 20, 132},
//     {264, 39, 525, 65, 78, 91, 104, 70, 130, 143},
//     {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}};

    
//     int result4 = planAttack(LF1_total, LF2_total, EXP1, EXP2, T1, T2, battleField);

//     cout << "Result: " << result4 << endl;

//     // Test task5
//     int shortfall = 1050;
//     int supply[5][5] = {
//         {150, 200, 180,  90, 110},
//         { 70,  80, 120, 140, 160},
//         {220, 240, 200, 190, 130},
//         {100, 110, 300, 280, 320},
//         {170, 210, 260, 230, 290}
//     };

//     int result5 = resupply(shortfall, supply);

//     cout << "Result: " << result5 << endl;    
  
  outfile.close();
    cout << "-------------------------------------------" << endl;

}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
      cerr << "Error: No input file provided!\n";
      return 1;
  }  
  tnc_tc_01(argv[1], argv[2]);
  return 0;
}

