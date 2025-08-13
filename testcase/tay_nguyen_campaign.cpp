#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;
const string BMT = "Buon Ma Thuot";
const string DL = "Duc Lap";
const string DLK = "Dak Lak";
const string QL_21 = "National Route 21";
const string QL_14 = "National Route 14";
int bestSum = INT_MAX;
int bestSet[5] = {};

// Task 0: Read input file
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // các phần tử trong LF1 và lF2: [0, 1000]
  // EXP1 và EXP2: [0, 600]
  // T1 và T2: [0, 3000]
  // E: [0, 99]

  for (int i = 0; i < MAX_LINES; i++){    
    for (int j = 0; j < MAX_LINE_LENGTH; j++){ 
      if (data[i][j] == '\0' || data[i][j] == '\n') {
        break;
      }
      if (i == 0 || i == 1) {
        // Xử lý LF1, LF2        
        int len = 0;        
        while (j < MAX_LINE_LENGTH) {   
          if (data[i][j] == '[') {
            j += 1;
            continue;
          }          
          int sum = 0;   
          int mem = 1;       
          while (data[i][j] != ',' && j < MAX_LINE_LENGTH) {
            if (data[i][j] == '-') {
              mem = -1;
              continue;
            }
            if ('0' <= data[i][j] && data[i][j] <= '9') {              
              sum = (sum * 10 +  (data[i][j] - '0')) * mem;
              j += 1;              
            }
            if (data[i][j] == ']') {              
              j = MAX_LINE_LENGTH;
              break;
            }
          }
          j += 1;        
          if (i == 0) {
            LF1[len++] = sum;            
          }else if (i == 1) {            
            LF2[len++] = sum;            
          }          
        }        
      } else if (i == 2 || i == 3 || i == 4) {
        // i=2 Xử lý EXP1, EXp2
        int exp1 = true;
        // i=3 Xử lý T1, T2
        int t1 = true;
        // i=4 Xử lý E
        while(j < MAX_LINE_LENGTH) {
          int sum = 0;
          int mem = 1;
          while(data[i][j] != ' '){
            if (data[i][j] == '-') {
              mem = -1;
            }
            sum = (sum * 10 + (data[i][j] - '0')) * mem;
            j += 1;            
            if (data[i][j] == '\0' || data[i][j] == '\n') {
              j = MAX_LINE_LENGTH;
              break;
            }
          }
          j += 1;
          if (i == 2) {
            if (exp1) {
              EXP1 = sum;
              exp1 = false;
            }else {
              EXP2 = sum;
            }
          }else if (i == 3) {
            if (t1) {
              T1 = sum;
              t1 = false;
            }else {
              T2 = sum;
            }
          }else {
            E = sum;
          }
        }
      }
    }    
  }
  // TODO: Extract values from the `data` array and store them in respective variables      
  return true;
}

// Task 1
int getPower(int index) {
  if (index == 0) {
    return 1;
  }else if (index == 1) { 
    return 2;
  }else if (index == 2) {
    return 3;
  }else if (index == 3) {
    return 4;

  }else if (index == 4) {
    return 5;
  }else if (index == 5) {
    return 7;
  }else if (index == 6) {
    return 8;
  }else if (index == 7) {
    return 9;
  }else if (index == 8) {
    return 10;
  }else if (index == 9) {
    return 12;
  }else if (index == 10) {
    return 15;
  }else if (index == 11) {
    return 18;
  }else if (index == 12) {
    return 20;
  }else if(index == 13) {
    return 30;
  }else if(index == 14) {
    return 40;
  }else if (index == 15) {
    return 50;
  }
  return 70;
}

void checkEXP(int &EXP1, int &EXP2) {  
  // Kiểm tra giá trị EXP1 và EXP2
  if (EXP1 <= 0) {
    EXP1 = 0;    
  }else if (EXP1 >= 600) {
    EXP1 = 600;
  }

  if (EXP2 <= 0) {
    EXP2 = 0;
  }else if (EXP2 >= 600) {
    EXP2 = 600;
  }
}
void checkT(int &T1, int &T2) {
  // Kiểm tra giá trị T1 và T2
  if (T1 <= 0) {
    T1 = 0;    
  }else if (T1 >= 3000) {
    T1 = 3000;
  }

  if (T2 <= 0) {
    T2 = 0;
  }else if (T2 >= 3000) {
    T2 = 3000;
  }
}
void checkE(int &E){
  // Kiểm tra giá trị E
  if (E <= 0) {
    E = 0;
  }else if (E >= 99) {
    E = 99;
  }
}
void checkArray(int LF1[], int LF2[]){
  // kiểm tra các phần tử trong LF1 và LF2 trước khi thực thi
  for(int i = 0; i < 17; i ++)  {
    // Kiểm tra phần tử trong LF1
    if (LF1[i] <= 0) {
      LF1[i] = 0;
    }else if (LF1[i] >= 1000) {
      LF1[i] = 1000;
    }
    // Kiểm tra phần tử trong LF2
    if (LF2[i] <= 0) {
      LF2[i] = 0;
    }else if (LF2[i] >= 1000) {
      LF2[i] = 1000;
    }
  }
}
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
  checkArray(LF1, LF2);
  // Tính tổng LF1 và LF2
  int total_lf1 = 0;
  int total_lf2 = 0;
  int total = 0;

  for (int i = 0; i < 17; i += 1) {
    total_lf1 += LF1[i] * getPower(i);
    total_lf2 += LF2[i] * getPower(i);
  }
  total = total_lf1 + total_lf2;
  return total;
}

// Task 2
string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  // Kon3 Tum
    int target_len = target.length();
    int number[3] = {0}; // nummber dùng để lưu các phần tử
    int count = 0; // số phần tử trong dãy number
    int ID = 0; // ID cần giải mã

    for (int i = 0; i < target_len; i ++) {
        int sum = 0;    
        if ('0' <= target[i] && target[i] <= '9') {
          count += 1;
          while ('0' <= target[i] && target[i] <= '9' && i < target_len) {
            sum = sum * 10 + (target[i] - '0');
            i += 1;
          }
          i -= 1;
          if (count <= 3) {
            number[count-1] = sum;   
          }
        }
    }
    
    // Nếu như k có số nguyên nào hoặc số số nguyên lớn hơn 3
    if (count <= 0 || count > 3) {
      return "INVALID";
    }
    
    if (count == 1) {
      ID = number[0];
      if (0 <= ID && ID <= 2) {
        return "DECOY";
      }
    }else if (count == 2) {
      ID = ((number[0] + number[1]) % 5) + 3;
    }else if (count == 3) {
      ID = (max(number[0], max(number[1],number[2])) % 5) + 3;
    }
    if (ID == 3) {
      return BMT;
    }else if (ID == 4) {
      return DL;
    }else if (ID == 5) {
      return DLK;
    }else if (ID == 6) {
      return QL_21;
    }else if (ID == 7) {
      return QL_14;
    }
    return "INVALID";
}

bool compareString (string a, string b) {
  if (a.length() != b.length()) {
      return false;
  }
  for (size_t i = 0; i < a.length(); i++){
      if ('A' <= a[i] && a[i] <= 'Z'){
          a[i] += 32;
      }
      if ('A' <= b[i] && b[i] <= 'Z'){
          b[i] += 32;
      }
      if (a[i] != b[i]) {
          return false;
      }
  }
  return true;
}
string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // Kiểm tra giá trị EXP1 và EXP2
  checkEXP(EXP1, EXP2);
  // TODO: Implement this function
  int mess_len = message.length();
  string new_message = "";
  if (EXP1 >= 300 && EXP2 >= 300){
    // Caesar Cipher
    int shifts = (EXP1 + EXP2) % 26;
    for (int i = 0; i < mess_len; i += 1) {
        char c = message[i];
        char new_char;
        if ('A' <= c && c <= 'Z') {
            // is supercase            
            new_char = (c - 'A' + shifts) % 26 + 'A';
        }else if ('a' <= c && c <= 'z') {
            // is lowercase
            new_char = (c - 'a' - 26 + shifts) % 26 + 'a';
        }else if (c == ' ' || ('0' <= c && c <= '9')) {
            new_message += c;
            continue;
        }else {
          continue;
        }
      new_message += new_char;
    }
  }else if (EXP1 < 300 || EXP2 < 300) {
    // Đảo ngược chuỗi    
    for (int i = mess_len - 1; i > -1; i--) {
      new_message += message[i];
    }
    
  }
  cout << new_message << endl;
  if (compareString(new_message, BMT)) {
    return BMT;
  }else if (compareString(new_message, DL)) {
    return DL;
  }else if (compareString(new_message, DLK)) {
    return DLK;
  }else if (compareString(new_message, QL_21)) {
    return QL_21;
  }else if (compareString(new_message, QL_14)) {
    return QL_14;
  }
  return "INVALID";
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // Kiểm tra giá trị EXP1 và EXP2
  checkEXP(EXP1, EXP2);
  // Kiểm tra giá trị E
  checkE(E);
  // Kiểm tra giá trị T1 và T2
  checkT(T1, T2);
  // TODO: Implement this function
  // T1, T2 là nguồn tiếp tế lương thực, chỉ thuộc [0, 3000]
  // Có vài chỗ chưa đúng  
  float supply1 = 0;
  
  float supply2 = 0;
  
  if (E == 0) {    
    // Tính T1
    supply1 = (((float)LF1 / (LF1 + LF2)) * (T1 + T2)) * (1 + ((float)(EXP1 - EXP2) / 100));    
    // Tính T2
    supply2 = (T1 + T2) - supply1;    
    return;
  }else if (1 <= E && E <= 9) {   
    supply1 = -T1 *(E * 0.01) ; // mất E * 1% tiếp tế
    supply2 = -T2 * (E * 0.005); // mất E * 0.5% tiếp tế      
  }else if (10 <= E && E <= 29) {
    supply1 = E * 50;
    supply2 = E * 50;    
  }else if (30 <= E && E <= 59) {
    supply1 = T1 * E * 0.005;
    supply2 = T2 * E * 0.002;    
  }
  
  T1 += round(supply1) >= supply1 ? round(supply1) : round(supply1) + 1;
  T2 += round(supply2) >= supply2 ? round(supply2) : round(supply2) + 1;
  // kiểm tra T1 có vượt mức hoặc dưới 3000 hay không?
  if (T1 > 0) {
    T1 = min((int)T1, 3000);
  }else {
    T1 = 0;
  }
  // kiểm tra T2 có vượt mức hoặc dưới 3000 hay không?
  if (T2 > 0) {
    T2 = min((int)T2, 3000);
  }else {
    T2 = 0;
  }
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{    
  // Kiểm tra EXP1 và EXP2
  checkEXP(EXP1, EXP2);
  // Kiểm tra T1 và T2
  checkT(T1, T2);
  // TODO: Implement this function
  float total_power = (LF1 + LF2) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++){
      if (i % 2 != 0) {
        total_power -= ((float)battleField[i][j] * 3) / 2;
      }else {
        total_power -= ((float)battleField[i][j] * 2) / 3;
      }
    }
  }
  total_power = (int)(round(total_power) > total_power ? round(total_power) : round(total_power) + 1);

  return total_power;
}

// Task 5
void backtrack(int cells[25], int selected_cells[5], int selected_cells_size, int index, int sum, int shortfall) {
  if (selected_cells_size == 5) {
    if (sum >= shortfall && sum < bestSum) {
      bestSum = sum;
      // Thiết lập bestSet
      for (int i = 0; i < 5; i++){
        bestSet[i] = selected_cells[i];         
      }
    }
    return;
  }

  for (int i = index; i < 25; i++) {
    // Nhánh cận: Nếu tổng 5 ô nhỏ nhất có thể đã vượt bestSum, cắt nhánh
    if (sum + cells[i] * (5 - selected_cells_size) >= bestSum) {
      continue;
    }
    // Thêm vào selected_cells
    selected_cells[selected_cells_size] = cells[i];   
    // Backtrack
    backtrack(cells, selected_cells, selected_cells_size + 1, i + 1, sum + cells[i], shortfall);
    // Quay lui
    
  }
}

void sort(int cells[25]) {
  int selected = 0;  
  while (selected < 25) {
    int min_val = cells[selected];
    int min_i = selected;
    // Tìm số nhỏ nhất từ selected + 1 -> n-1
    for (int i = selected + 1; i < 25; i++) {
      if (cells[i] < min_val) {
        min_val = cells[i];
        min_i = i;
      }
    }
    // Swap hai giá trị lại với nhau
    int swap_val = cells[selected]; // giá trị của matrix tại i,j    

    // Tiến hành hành swap
    cells[selected] = cells[min_i];
        
    // Swap một lần nữa
    cells[min_i] = swap_val;        
    // Tăng tới ô kế tiếp trong cells
    selected += 1;
  }  
}

int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int cells[25] = {};
  int i_cell = 0;
  // Chuyển ma trận thành các ô
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cells[i_cell] = supply[i][j];
      i_cell += 1;
    }
  }
  // Sắp xếp cells
    sort(cells);
  // Dùng backtracking để tìm tổ hợp tốt nhất
    int selected_cells[5] = {};
    backtrack(cells, selected_cells, 0, 0, 0, shortfall);

  // Kết quả tổng  
  int sum = bestSum;
  return sum;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
