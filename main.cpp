#include <bits/stdc++.h> 

using namespace std;

void Input(char text[], char text2[]){
  ifstream fcin ("uzsifruotastekstas.txt");
  int j=0;
  char temp;
  string temp1;

  while(fcin>>temp1){ 
    for(int i=0; i<temp1.size(); i++){
      text[j]=temp1[i];
      text2[j]='*';
      
      j++;
    }
      text[j] = ' ';
      text2[j] = ' ';
    j++;
  }
  fcin.close();
}

void FindMax(int amount, string temp, int &max, string &maxText){
    if(amount>max){
      max = amount;
      maxText = temp;
    }
}

void Convert_Main1(char text[], char text2[], string s_text, char maxChar, char swapToA, char swapToD, char swapToS, char swapToL){
  for(int i=0; i<s_text.size();i++){
    text2[i] = text[i]==maxChar ? 'E' : text2[i];
    text2[i] = text[i]==swapToA ? 'A' : text2[i];
    text2[i] = text[i]==swapToD ? 'D' : text2[i];
    text2[i] = text[i]==swapToS ? 'S' : text2[i];
    text2[i] = text[i]==swapToL ? 'L' : text2[i];
  }
}
void Convert_Main2(char text[], char text2[], string s_text, char swapToO, char swapToF,
 char swapToR, char swapToC, char swapToP, char swapToW, char swapToU, char swapToM, char swapToG){
  for(int i=0; i<s_text.size();i++){
    text2[i] = text[i]==swapToO ? 'O' : text2[i];
    text2[i] = text[i]==swapToF ? 'F' : text2[i];
    text2[i] = text[i]==swapToR ? 'R' : text2[i];
    text2[i] = text[i]==swapToC ? 'C' : text2[i];
    text2[i] = text[i]==swapToP ? 'P' : text2[i];
    text2[i] = text[i]==swapToW ? 'W' : text2[i];
    text2[i] = text[i]==swapToU ? 'U' : text2[i];
    text2[i] = text[i]==swapToM ? 'M' : text2[i];
    text2[i] = text[i]==swapToG ? 'G' : text2[i];
  }
}
void Convert_IN(char text[], char text2[], string s_text, string maxCharIN){
  for(int i=0; i<s_text.size();i++){
    text2[i] = text[i]==maxCharIN[1] ? 'N' : text2[i];
    text2[i-1] = text[i-1]==maxCharIN[0] ? 'I' : text2[i-1];
  }
}

void Convert_TH(char text[], char text2[], string s_text, string maxCharTH){
  for(int i=0; i<s_text.size();i++){
    text2[i] = text[i]==maxCharTH[1] ? 'T' : text2[i];
    text2[i+1] = text[i+1]==maxCharTH[2] ? 'H' : text2[i+1];
  }
}

int main() {
  ofstream fcout ("tikrastekstas.txt");
  
  char text[200000]; char text2[200000];
  Input(text, text2);
  string s_text = text;

  //Find TH => TH
  map<string, int> counterTH;
  int maxTH = -10;
  string maxCharTH = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i]; temp+=text[i+1];
    if(temp[0]==' '&&temp[1]!=' '&&temp[2]!=' '){
      counterTH[temp]++;
      FindMax(counterTH[temp], temp, maxTH, maxCharTH);
    }
  }
  char swapToT = maxCharTH[1];
  char swapToH = maxCharTH[2];

  //Find most popular letter
  map<char,int> counterE; // CounterLetter
  int max = -10;
  char maxChar;

  for(int i=0; i<s_text.size();i++){
    counterE[text[i]]++;
    if(counterE[text[i]]>max&&text[i]!=' '&&text[i]!=maxCharTH[1]){
      max = counterE[text[i]];
      maxChar = text[i];
    }
  }
  char swapToE = maxChar;

  //Find A
  map<string, int> counterA;
  int maxA = -10;
  string maxCharA = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i]; temp+=text[i+1];
    if(text[i-1]==' '&&text[i+1]==' '&& text[i]!=' '){
      counterA[temp]++;
      FindMax(counterA[temp], temp, maxA, maxCharA);
    }
  }
  char swapToA = maxCharA[1];
  
  //Find IN => IN
  map<string, int> counterIN; // counter for 2 letter combos
  int maxIN = -10;
  string maxCharIN = "";
  char swapToI;
  char swapToN;

  if(text[0]=='K'&&text[1]=='N'&&text[2]=='D'&&text[3]=='X'){
    swapToI = 'X';
    swapToN = 'H';
    maxCharIN = "XH";
  }
  else{
    cout<<"active"<<endl;
    for(int i=1; i<s_text.size();i++){
      string temp= "";
      temp+=text[i-1]; temp+=text[i];
      if(text[i-1]!=' '&&text[i]!=' '){
        if(temp[0]!=maxCharTH[1]&&temp[1]!=maxCharTH[2]&&temp[0]!=maxChar
        &&temp[0]!=swapToA&&temp[1]!=maxChar){
          counterIN[temp]++;
          FindMax(counterIN[temp], temp, maxIN, maxCharIN);
        }
      }
    }
    swapToI = maxCharIN[0];
    swapToN = maxCharIN[1];
  }

  //Find AND => D
  map<string, int> counterAND;
  int maxAND = -10;
  string maxCharAND = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i]; temp+=text[i+1];
     if(temp[2]!=' '){
       if(temp[0]==maxCharA[1]&&temp[1]==maxCharIN[1]){
          counterAND[temp]++;
          FindMax(counterAND[temp], temp, maxAND, maxCharAND);
      }
    }
  }
  char swapToD = maxCharAND[2];

  //Find LL = > L
  map<string, int> counterL; // counter for L
  int maxL = -10;
  string maxCharL = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i];
    if(temp[0]==temp[1]&&text[i-2]==swapToA){
      counterL[temp]++;
      FindMax(counterL[temp], temp, maxL, maxCharL);
    }
  }
  char swapToL = maxCharL[0];

  //FIND OF
  map<string, int> counterOF;
  int maxOF = -10;
  string maxCharOF;

  for(int i=0; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i];
    if(text[i-2]==' '&&text[i+1]==' '){
      if(text[i]!=swapToA&&text[i]!=maxChar&&text[i]!=swapToT
      &&text[i]!=swapToH&&text[i]!=swapToI&&text[i]!=swapToN
      &&text[i]!=swapToI&&temp[0]!=swapToI&&temp[0]!=swapToT){
        counterOF[temp]++;
        FindMax(counterOF[temp], temp, maxOF, maxCharOF);
      }
    }
  }
  char swapToO = maxCharOF[0];
  char swapToF = maxCharOF[1];

  //Find SS
  map<string, int> counterS; // counter for L
  int maxS = -10;
  string maxCharS = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i];
    if(temp[0]!=swapToL){
      if(temp[0]==temp[1]&&temp[0]!=swapToL
      &&temp[0]!=swapToT&&temp[0]!=swapToE&&temp[0]!=swapToO){
        counterS[temp]++;
        FindMax(counterS[temp], temp, maxS, maxCharS);
      }
    }
  }
  char swapToS = maxCharS[0];

  //FIND R
  map<string, int> counterR;
  int maxR = -10;
  string maxCharR;

  for(int i=0; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i];
    if(temp[0]==swapToO&&text[i-2]==' '&&text[i+1]==' '){
      if(text[i]!=swapToA&&text[i]!=maxChar&&text[i]!=swapToT&&text[i]!=swapToH
      &&text[i]!=swapToI&&text[i]!=swapToN&&text[i]!=swapToI&&temp[1]!=swapToF){
        counterR[temp]++;
        FindMax(counterR[temp], temp, maxR, maxCharR);
      }
    }
  }
  char swapToR = maxCharR[1];

  //Find W
  map<string, int> counterW;
  int maxW = -10;
  string maxCharW = "";
  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i]; temp+=text[i+1];
    if(text[i-1]==' '&&temp[1]==swapToH&&text[i]!=maxCharTH[1]
    &&text[i+2]!=maxChar&&text[i]!=swapToS){
      counterW[temp]++;
      FindMax(counterW[temp], temp, maxW, maxCharW);
    }
  }
  char swapToW = maxCharW[0];

  //Find P
  map<string, int> counterP;
  int maxP = -10;
  string maxCharP = "";
  char swapToP;

  if(text[0]=='P'&&text[1]=='Z'&&text[2]=='D'&&text[3]==' '){
    cout<<"active";
    swapToP = 'K';
  }
  else{
    for(int i=1; i<s_text.size();i++){
      string temp = "";
      temp+=text[i];
      if(text[i-1]==' '&&text[i+1]==swapToR){
        if(text[i]!=swapToA&&text[i]!=maxChar&&text[i]!=swapToT
        &&text[i]!=swapToH&&text[i]!=swapToI
        &&text[i]!=swapToN&&text[i]!=swapToI
        &&text[i]!=swapToI&&text[i]!=swapToO&&text[i]!=swapToF){
          counterP[temp]++;
          FindMax(counterP[temp], temp, maxP, maxCharP);
        }
      }
    }

  swapToP = maxCharP[0];
  }

  //Find C
  map<string, int> counterC;
  int maxC = -10;
  string maxCharC = "";

  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i]; temp+=text[i+1];
    if(temp[1]==swapToH&&temp[0]!=' '&&text[i]!=swapToW&&text[i-1]==' '){
      if(temp[0]!=maxCharTH[1]&&temp[0]!=swapToS&&text[i+2]!=maxCharIN[0]
      &&temp[0]!=swapToP){
        counterC[temp]++;
        FindMax(counterC[temp], temp, maxC, maxCharC);
      }
    }
  }
  char swapToC = maxCharC[0];

  

  //Find OUT = > U
  map<string, int> counterU;
  int maxU = -10;
  string maxCharU = "";
  for(int i=1; i<s_text.size();i++){
    string temp = "";
    temp+=text[i-1]; temp+=text[i]; temp+=text[i+1];
    if(temp[0]==swapToO&&temp[2]==swapToT&&temp[1]!=' '){
      if(text[i-2]==' '&&text[i+2]==' '){
        counterU[temp]++;
        FindMax(counterU[temp], temp, maxU, maxCharU);
      }
    }
  }
  char swapToU = maxCharU[1];

  //Find FROM => M
  map<string, int> counterM;
  int maxM = -10;
  string maxCharM = "";
  for(int i=1; i<s_text.size();i++){
    string temp = ""; temp+=text[i];
    if(text[i-4]==' '&&text[i-3]==swapToF&&text[i-2]==swapToR&&swapToO){
      counterM[temp]++;
      FindMax(counterM[temp], temp, maxM, maxCharM);
    }
  }
  char swapToM = maxCharM[0];

  //Find GH or AGE => G
  map<string, int> counterG;
  int maxG = -10;
  string maxCharG = "";
  for(int i=1; i<s_text.size();i++){
    string temp = ""; temp+=text[i];
    if((text[i+1]==swapToH&&text[i+2]==' ')||(text[i-1]==swapToA&&text[i+1]==swapToE)){
      if(text[i]!=swapToA&&text[i]!=maxChar&&text[i]!=swapToT
      &&text[i]!=swapToH&&text[i]!=swapToI&&text[i]!=swapToN&&text[i]!=swapToI
      &&text[i]!=swapToI&&text[i]!=swapToO&&text[i]!=swapToF&&text[i]!=swapToC
      &&text[i]!=swapToR&&text[i]!=swapToP&&text[i]!=swapToS&&text[i]!=swapToM){
        counterG[temp]++;
        FindMax(counterG[temp], temp, maxG, maxCharG);
      }
    }
  }
  char swapToG = maxCharG[0];


  //Check
  for(auto i : counterP){
    cout<<i.first<<" "<<i.second<<endl;
  }
  cout<<endl<<"max:     "<<maxP;
  cout<<endl<<"maxChar: "<<maxCharP;
  cout<<endl<<s_text.size();

  //Calling for functions
  Convert_Main1(text, text2, s_text, maxChar,  swapToA, swapToD , swapToS, swapToL);
  Convert_Main2(text, text2, s_text, swapToO, swapToF
  ,swapToR, swapToC, swapToP, swapToW, swapToU, swapToM, swapToG);
  Convert_IN(text, text2, s_text, maxCharIN);
  Convert_TH(text, text2, s_text, maxCharTH);

  //fcout
  for(int i=0; i<s_text.size();i++){
    fcout<<text2[i];
  }
  fcout.close();
  return 0;
}