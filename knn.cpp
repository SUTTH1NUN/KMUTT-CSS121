#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Mbtitype {
    string ID, Name, sex, type, nick;
    double Ne, Ni, Te, Ti, Se, Si, Fe, Fi;
    int enagram;
};

vector<Mbtitype> readCSV(const string& filename) {
    ifstream infile(filename);
    vector<Mbtitype> types;
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        Mbtitype temp;
        string item;

        getline(ss, temp.ID, ',');
        getline(ss, temp.Name, ',');
        getline(ss, temp.sex, ',');
        getline(ss, item, ','); temp.Ne = stod(item);
        getline(ss, item, ','); temp.Ni = stod(item);
        getline(ss, item, ','); temp.Te = stod(item);
        getline(ss, item, ','); temp.Ti = stod(item);
        getline(ss, item, ','); temp.Se = stod(item);
        getline(ss, item, ','); temp.Si = stod(item);
        getline(ss, item, ','); temp.Fe = stod(item);
        getline(ss, item, ','); temp.Fi = stod(item);
        getline(ss, temp.type, ',');
        getline(ss, item, ','); temp.enagram = stoi(item);
        getline(ss, temp.nick, ',');

        types.push_back(temp);
    }
    infile.close();
    return types;
}

double calculateDistance(const Mbtitype& a, const Mbtitype& b) {
    return sqrt(
        pow(a.Ne - b.Ne, 2) + pow(a.Ni - b.Ni, 2) + pow(a.Te - b.Te, 2) +
        pow(a.Ti - b.Ti, 2) + pow(a.Se - b.Se, 2) + pow(a.Si - b.Si, 2) +
        pow(a.Fe - b.Fe, 2) + pow(a.Fi - b.Fi, 2)
    );
}

int partition(vector<pair<double, int>>& distances, int low, int high) {
    double pivot = distances[high].first;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (distances[j].first < pivot) {
            i++;
            swap(distances[i], distances[j]);
        }
    }
    swap(distances[i + 1], distances[high]);
    return i + 1;
}

void quickSort(vector<pair<double, int>>& distances, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(distances, low, high);
        quickSort(distances, low, pivotIndex - 1);
        quickSort(distances, pivotIndex + 1, high);
    }
}

void findTopMatches(const Mbtitype& mytype, const vector<Mbtitype>& types, int k = 3) {
    vector<pair<double, int>> distances;
    for (int i = 0; i < types.size(); i++) {
        double dist = calculateDistance(mytype, types[i]);
        distances.push_back(make_pair(dist, i));
    }

    quickSort(distances, 0, distances.size() - 1);

    string Typeout[3];
    for (int i = 0; i < k; i++) {
        int index = distances[i].second;
        cout << types[index].Name << " is a " << types[index].type << endl;
        Typeout[i] = types[index].type;
    }

    string myType = "";
    for (int i = 0; i < 8; i++) {
        if (Typeout[0][i] == Typeout[1][i] && Typeout[0][i] == Typeout[2][i]) {
            myType += Typeout[0][i];
        }
        else if (Typeout[0][i] == Typeout[1][i]) {
            myType += Typeout[0][i];
        }
        else if (Typeout[0][i] == Typeout[2][i]) {
            myType += Typeout[0][i];
        }
        else if (Typeout[1][i] == Typeout[2][i]) {
            myType += Typeout[1][i];
        }
        else {
            myType += "x";
        }
    }

    cout << "Hi, your type is " << myType << endl;
}

int main() {
    vector<Mbtitype> types = readCSV("Copy of CSS121 MBTI 2025 - 67.csv");

    Mbtitype mytype;
    cout << "Input your value: " << endl;
    cout << "Name: "; cin >> mytype.Name;
    cout << "Sex: "; cin >> mytype.sex;
    cout << "Ne: "; cin >> mytype.Ne;
    cout << "Ni: "; cin >> mytype.Ni;
    cout << "Te: "; cin >> mytype.Te;
    cout << "Ti: "; cin >> mytype.Ti;
    cout << "Se: "; cin >> mytype.Se;
    cout << "Si: "; cin >> mytype.Si;
    cout << "Fe: "; cin >> mytype.Fe;
    cout << "Fi: "; cin >> mytype.Fi;

    findTopMatches(mytype, types);

    return 0;
}
