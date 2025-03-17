#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Student
{
    char name[30];
    int score;
};

void MaxStudent(struct Student student[], int size);
void MinStudent(struct Student student[], int size);
float AvrScore(struct Student student[], int size);
void ModeScore(struct Student student[], int size);
float MedianScore(struct Student student[], int size);
float SDScore(struct Student student[], int size);
void merge(int arr[], int left, int mid, int right);
void mergesort(int arr[], int left, int right);
void getgrade(struct Student student[], int size);

int main(){
    struct Student student[10];
    strcpy(student[0].name, "Kira1");
    student[0].score = 80;
    strcpy(student[1].name, "Mary1");
    student[1].score = 45;    
    strcpy(student[2].name, "chat1");
    student[2].score = 67;
    strcpy(student[3].name, "gpt1");
    student[3].score = 80;
    strcpy(student[4].name, "copi1");
    student[4].score = 95;    
    strcpy(student[5].name, "Kira2");
    student[5].score = 64;
    strcpy(student[6].name, "Mary2");
    student[6].score = 56;    
    strcpy(student[7].name, "chat2");
    student[7].score = 77;
    strcpy(student[8].name, "gpt2");
    student[8].score = 46;
    strcpy(student[9].name, "copi2");
    student[9].score = 50;   

    
    MaxStudent(student, 10);
    MinStudent(student, 10);
    AvrScore(student, 10);
    float Medain = MedianScore(student, 3);
    ModeScore(student, 10);
    getgrade(student, 10);
}

void MaxStudent(struct Student student[], int size){
    int Max = student[0].score;
    int i, j = 0;
    for(i = 1; i < size; i++){
        if(Max < student[i].score){
            j = i;
        }
    }
    cout << "MaxStudent : " << student[j].name << " " << "Score : " << student[j].score << endl;
}

void MinStudent(struct Student student[], int size){
    int Min = student[0].score;
    int i, j = 0;
    for(i = 1; i < size; i++){
        if(Min > student[i].score){
            j = i;
        }
    }
    cout << "MinStudent : " << student[j].name << " " << "Score : " << student[j].score << endl;
}

float AvrScore(struct Student student[], int size){
    int i;
    float sum = 0, avr = 0;
    for(i = 0; i < size; i++){
        sum += student[i].score;
    }
    avr = sum/size;
    return avr;
}

void ModeScore(struct Student student[], int size){
    int score[size];
    int Maxcount = 1, count = 1;
    for(int i = 0; i < size; i++){
        score[i] = student[i].score;
    }
    mergesort(score, 0, size-1);
    int mode = score[0];
    for(int j = 1; j < size; ++j){
        if(score[j] == score[j-1]){
            ++count;
        }else{
            if(count > Maxcount){
                Maxcount = count;
                mode = score[j - 1];
            }
            count = 1;
        }
    }
    if(count > Maxcount){
        mode = score[size -1];
    }
    cout << "Mode is : " << mode << endl;
}

float MedianScore(struct Student student[], int size){
    int score[size];
    for(int i = 0; i < size; i++){
        score[i] = student[i].score;
    }
    mergesort(score, 0, size - 1);
    if(size % 2 == 0){
        return (score[size / 2 - 1] + score[size / 2]) / 2.0;
    }else{
        return score[size / 2];
    }
}

float SDScore(struct Student student[], int size){
    float avr, variance, sd;
    avr = AvrScore(student, size);
    for(int i = 0; i < size; i++){
        variance += pow(student[i].score - avr, 2);
    }
    sd = sqrt(variance / (size - 1));
    return sd;
}

void mergesort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) /2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[left+i]; 
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j <n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void getgrade(struct Student student[], int size){
    float avr, sd;
    char grade;
    avr = AvrScore(student, size);
    sd = SDScore(student, size);
    float A = avr + (2*sd);
    float B = avr + sd;
    float C = avr;
    float D = avr-sd;

    for(int i = 0; i < size; i++){
        int num = student[i].score;
        if(num > A){
            grade = 'A';
        }else if(num <= A && num > B){
            grade = 'B';
        }else if(num <= B && num > C){
            grade = 'C';
        }else if(num <= C && num > D){
            grade = 'D';
        }else{
            grade = 'F';
        }
        cout << "Name : " << student[i].name << " grade : " << grade << endl;
    }
}