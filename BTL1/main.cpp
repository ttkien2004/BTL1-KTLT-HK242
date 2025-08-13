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

void tnc_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("tnc_tc_01_input");
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
  // string encodedTarget1 = "Pl@#68e32I*%80kU";
//   string encodedTarget2 = "Ple9iku5";
//   string encodedTarget3 = "Ple1Ku4Nat9";  
//   string encodedTarget4 = "Buon1Ma3Thuot5-8";
//   string encodedTarget5 = "KonTum";

  // cout << "Decoded Target 1: " << determineRightTarget(encodedTarget1) << endl;
//   // cout << "Decoded Target 2: " << determineRightTarget(encodedTarget2) << endl;
//   // cout << "Decoded Target 3: " << determineRightTarget(encodedTarget3) << endl;
//   // cout << "Decoded Target 4: " << determineRightTarget(encodedTarget4) << endl;
//   // cout << "Decoded Target 5: " << determineRightTarget(encodedTarget5) << endl;

  // string encodedMessage = "41 EtUO%r LANoiTA$N";
//   // int exp1 = 350, exp2 = 400;
  // string decodedTarget = decodeTarget(encodedMessage, EXP1, EXP2);
  // cout << "Decoded Right Target: " << decodedTarget << endl;

//   // encodedMessage = "paL cuD";
//   // decodedTarget = decodeTarget(encodedMessage, 150, 320);
//   // cout << "Decoded Target: " << decodedTarget << endl;

//   // encodedMessage = "Xyz";
//   // decodedTarget = decodeTarget(encodedMessage, exp1, exp2);
//   // cout << "Decoded Target: " << decodedTarget << endl;

//   // encodedMessage = "abc";
//   // decodedTarget = decodeTarget(encodedMessage, exp1, exp2);
//   // cout << "Decoded Target: " << decodedTarget << endl;

// //   // Test task3
    // int LF1_total = 1987, LF2_total = 2968;
//     // for (int i = 0; i < 17; i++) {
//     //     LF1_total += LF1[i];
//     //     LF2_total += LF2[i];
//     // }
//   //   cout << "LF1: " << LF1_total << " LF2: " << LF2_total << endl;
  // manageLogistics(LF1_total, LF2_total, EXP1, EXP2, T1, T2, E);

//   // Print the modified supply values
  // cout << "T1: " << T1 << ", T2: " << T2 << endl;

// //   // Test task4
  // int battleField[10][10] = {
  //   {506, 15, 20, 25, 305, 635, 540, 145, 50, 55},
  //   {325, 18, 24, 330, 36, 442, 48, 54, 660, 665},
  //   {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
  //   {562, 24, 323, 404, 484, 60, 40, 72, 80, 88},
  //   {181, 27, 36, 52, 543, 63, 72, 81, 90, 99},
  //   {505, 30, 40, 501, 602, 70, 80, 90, 100, 110},
  //   {922, 33, 442, 55, 66, 77, 58, 99, 110, 121},
  //   {124, 36, 48, 60, 72, 84, 96, 108, 120, 132},
  //   {264, 39, 525, 65, 78, 91, 104, 170, 130, 143},
  //   {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}};
//   int battleField[10][10] = {
//     {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
//     {15, 25, 35, 45, 55, 65, 75, 85, 95, 105},
//     {5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
//     {12, 22, 32, 42, 52, 62, 72, 82, 92, 102},
//     {8, 18, 28, 38, 48, 58, 68, 78, 88, 98},
//     {20, 40, 60, 80, 100, 120, 140, 160, 180, 200},
//     {25, 50, 75, 100, 125, 150, 175, 200, 225, 250},
//     {30, 60, 90, 120, 150, 180, 210, 240, 270, 300},
//     {35, 70, 105, 140, 175, 210, 245, 280, 315, 350},
//     {40, 80, 120, 160, 200, 240, 280, 320, 360, 400}
// };
    
//     int result4 = planAttack(300, 280, 450, 470, 2500, 2600, battleField);

//     cout << "Result: " << result4 << endl;

// //     // Test task5
//     int shortfall = 0;    
    // int shortfall = 1050;
    // int supply[5][5] = {
    //     {150, 200, 180,  90, 110},
    //     { 70,  80, 120, 140, 160},
    //     {220, 240, 200, 190, 130},
    //     {100, 110, 300, 280, 320},
    //     {170, 210, 260, 230, 290}
    // };
//     shortfall = 250;
// int supply[5][5] = {
//     {50, 50, 50, 50, 50},
//     {50, 50, 50, 50, 50},
//     {50, 50, 50, 50, 50},
//     {50, 50, 50, 50, 50},
//     {50, 50, 50, 50, 50}
// };
int shortfall = 250;
int supply[5][5] = {
    {10, 20, 30, 40, 50},
    {15, 25, 35, 45, 55},
    {12, 22, 32, 42, 52},
    {18, 28, 38, 48, 58},
    {11, 21, 31, 41, 61}};


    int result5 = resupply(shortfall, supply);

    cout << "Result: " << result5 << endl;
}

int main(int argc, const char * argv[]) {  
    tnc_tc_01();
    return 0;
}
