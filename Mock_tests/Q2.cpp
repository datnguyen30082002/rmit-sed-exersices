#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
const int SCORE_SIZE = 3;

class Student
{
private:
    string name;
    int scores[SCORE_SIZE];

public:
    Student() {}

    void copy(int dest[SCORE_SIZE], int src[SCORE_SIZE])
    {
        for (int i = 0; i < SCORE_SIZE; i++)
        {
            dest[i] = src[i];
        }
    }

    Student(string name, int scores[SCORE_SIZE])
    {
        this->name = name;
        copy(this->scores, scores);
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setScores(int scores[SCORE_SIZE])
    {
        copy(this->scores, scores);
    }

    void inputData()
    {
        string name;
        cout << "Enter student's name: ";
        getline(cin, name);

        int scores[SCORE_SIZE];
        cout << "Enter student's scores: " << endl;
        for (int i = 0; i < SCORE_SIZE; i++)
        {
            do
            {
                cout << "Enter scores[" << i + 1 << "] = ";
                cin >> scores[i];
            } while (!(scores[i] >= 0 && scores[i] <= 100));
        }

        setName(name);
        setScores(scores);
    }

    void showInfo()
    {
        cout << "Student's name is: " << name << endl;

        cout << "Student's scores are: ";
        for (int i = 0; i < SCORE_SIZE; i++)
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    double avgScore()
    {
        int sum = 0;

        for (int i = 0; i < SCORE_SIZE; i++)
        {
            sum += scores[i];
        }

        double avg = sum / SCORE_SIZE;

        return avg;
    }

    bool operator>(Student &student2)
    {
        return this->avgScore() > student2.avgScore() ? true : false;
    }

    friend istream &operator>>(istream &input, Student &student)
    {
        student.inputData();
        return input;
    }

    friend ostream &operator<<(ostream &output, Student &student)
    {
        student.showInfo();
        return output;
    }

    friend Student operator+(float n, Student student);
};

Student operator+(float n, Student student)
{
    Student result = student;

    for (int i = 0; i < SCORE_SIZE; i++)
    {
        result.scores[i] += n;
    }

    return result;
}

int main()
{
    Student student1, student2, student3;

    // inputData and showInfo methods
    student1.inputData();
    cout << "Student1's info: " << endl;
    student1.showInfo();
    cout << endl;

    // Overload the >> and << operators
    cin.ignore(1, '\n');
    cin >> student2;
    cout << "Student2's info: " << student2;

    // Overload the > operator and print out true if object1 has higher average score than object2, return false otherwise
    cout << endl
         << "> Student 1 has " << ((student1 > student2) ? "higher " : "lower or equal ")
         << "average score than Student 2 \n";

    // Return a object with same name, but scores increase by n
    student3 = 20 + student2;
    cout << endl
         << "Student3's info: " << student3;

    // Create an array of 10 Student objects and read all information from a file named data.txt (attached) to assign values for them
    Student stuArr[10];
    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);
    if (!myFile)
    {
        cout << "Fail to open/create file \n";
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        string tempStr;
        // Read the name (up to the delimeter ',')
        std::getline(myFile, tempStr, ',');
        stuArr[i].setName(tempStr);

        // Read the scores
        std::getline(myFile, tempStr);

        // Declare a stringstream object with the content of tempStr
        stringstream ss;
        ss << tempStr;
        string word;
        int scores[SCORE_SIZE], index = 0;
        
        // Extract stringstream content and store to scores array
        while (ss >> word)
        {
            scores[index++] = stoi(word);
        }

        stuArr[i].setScores(scores);
    }

    // Close the file
    myFile.close();

    // Print out all information from the file
    cout << endl
         << "> All information read from the file: " << endl;
    for (int i = 0; i < 10; i++)
    {
        stuArr[i].showInfo();
    }

    // Find student with highest average value
    Student bestStu = stuArr[0];
    for (int i = 0; i < 10; i++)
    {
        if (bestStu.avgScore() < stuArr[i].avgScore())
        {
            bestStu = stuArr[i];
        }
    }
    cout << "\n> Student with highest average score: \n";
    bestStu.showInfo();
}