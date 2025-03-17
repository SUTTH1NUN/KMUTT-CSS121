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


int main(){
    struct Student student[10];
    strcpy(student[0].name, "Kira");
    student[0].score = 90;
    strcpy(student[1].name, "Mary");
    student[1].score = 95;    
    strcpy(student[2].name, "Mary12");
    student[2].score = 66;
    MaxStudent(student, 3);
    MinStudent(student, 3);
    AvrScore(student, 3);
    float Medain = MedianScore(student, 3);
    cout << SDScore(student, 3) << endl;
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