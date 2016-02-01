//Programming Assingment 1
//Gradebook

//Imports
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Returns the lowest score of an array of 5.
int getLowest(int examScores[]){
    int lowest = 101;
    for (int i = 0; i < 5; i++){
        if (examScores[i] < lowest) lowest = examScores[i];
    }
    return lowest;
}

//Converts a number grade to a letter grade.
char convertToLetter (int grade){
    if (grade >= 448 && grade <= 500){
        return 'A';
    }
    else if (grade >= 398 && grade <= 447){
        return 'B';
    }
    else if (grade >= 348 && grade <= 397){
        return 'C';
    }
    else if (grade >= 298 && grade <= 347){
        return 'D';
    }
    else if (grade >= 0 && grade <= 297){
        return 'F';
    }
}

//Returns the percentage of points earned / 600 (the percentage for the score)
float getPercent (int score){
    return (float)(score / 500.0 * 100.0);
}

//Main function
int main(){
    //Loads the file.
    ifstream fin;
    //File error handling.
    fin.open("class_scores.txt");
    if (!fin){
        fin.close();
        cout << "ERROR: Unable to read class_scores.txt" << endl;
        exit(1);
    }

    ofstream fout;
    fout.open("final_grades.txt");

    //Write file header.
    fout << "StudentID\tPoints\tPercent\tGrade" << endl;
    fout << "-------------------------------------" << endl;

    //Parse the file.
    string id;
    while (fin >> id){ //If ID cannot be loaded, we have reached EOF (or have a faulty file)
        //Objects to store the scores.
        int examScores[5];
        int participationScore = 0;
        int assignmentScores[4];
        int total = 0;
        //Loading in the scores.
        for (int x = 0; x < 5; x++){
            fin >> examScores[x];
            total += examScores[x];
        }

        fin >> participationScore;

        for (int x = 0; x < 4; x++){
            fin >> assignmentScores[x];
            total += assignmentScores[x];
        }

        //Normalize the participationScore to 60 if greater then 60.
        if (participationScore>60) participationScore = 60;
        total += participationScore;

        //Subtract the lowest value of the exam scores from the total.
        total -= getLowest(examScores);

        fout << setprecision(1) << left << fixed;

        //Write data to the file.
        fout << id << "\t" << total << "\t" << getPercent(total) << "\t" << convertToLetter(total) << endl;
    }
    fin.close();
    fout.close();
}
