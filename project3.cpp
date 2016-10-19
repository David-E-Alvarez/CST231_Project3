#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student{
	string name;
	int id;
	double midterm_score1, midterm_score2, final_score;
	double quiz_scores[5];
}; 

double quiz_grade(double passed_array[], int size){
	double weighted_quiz_avgs = 0;
	for (int j = 1; j < size; j++){
		weighted_quiz_avgs += passed_array[j];
		//cout << "WQA's: "<<weighted_quiz_avgs<<" " <<endl;
	}
	//cout <<weighted_quiz_avgs <<endl;
	return 20.0 * (weighted_quiz_avgs / 40.0);
}

double mid_term_grade(double grade1, double grade2){
	double midterm_grade;
	midterm_grade = (grade1 + grade2) / 200.00;
	return  40.0 * midterm_grade;
}

double final_grade(double score){
	double final_grade;
	final_grade = score / 100.00;
	return 40.0 * final_grade;
}

char letter_grade(double grade){
	if (grade <= 100 && grade >= 90){
		return 'A';

	}
	if (grade < 90 && grade >= 80){
		return'B';

	}

	if (grade < 80 && grade >= 70){
		return 'C';

	}
	if (grade < 70 && grade >= 60){
		return 'D';

	}
	if (grade < 60 && grade >= 0){
		return 'F';

	}
}



	


void s_sort(double x[], int n) {
	int m; // keep the index of current smallest value
	double hold;

	for (int k=0; k<=n - 1; k++) {
		m = k;
		for (int j=k+1; j <= n-1; j++) {
			if (x[j] < x[m])
				m = j;
		}

		hold = x[m];
		x[m] = x[k];
		x[k] = hold;
		//cout << "x[" << k <<"]:" <<x[k] <<endl;
	}
}


int main()
{
	Student a;
	int i, j;
	double numeric_average;
	const int SIZE = 5;
	//double numeric_average_array[SIZE];
	string file;
	ifstream in_file;
	in_file.open("C:\\Temp\\cst231_2.txt");
	if(in_file.fail()){
		cout <<"Error: file open failed.\n";
	}
	cout <<"--------------------------------------------------\n";
	cout <<"  Course Report: Numerical Average Order\n";
	cout <<"--------------------------------------------------\n";
	for(i = 0; i < SIZE; i++){
		in_file >> a.name >>a.id;
		/*cout <<"Name: " <<a.name <<endl;
		cout <<"I.D.: " <<a.id <<endl;
		cout <<"Quiz scores: " <<endl;*/
		for(j = 0; j < 5; j++){
			in_file >>a.quiz_scores[j];
			//cout <<a.quiz_scores[j] <<endl;
		}
		//call sort
		s_sort(a.quiz_scores, SIZE);//call to sort quiz scores
		in_file >>a.midterm_score1 >>a.midterm_score2 >>a.final_score;
		/*cout << "Midterm 1: " <<a.midterm_score1 <<endl;
		cout << "Midterm 2: " <<a.midterm_score2 <<endl;
		cout <<"Final: " <<a.final_score <<endl <<endl;*/
		numeric_average = quiz_grade(a.quiz_scores, SIZE) + mid_term_grade(a.midterm_score1, a.midterm_score2) + final_grade(a.final_score);
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << a.name <<" " <<a.id <<" - " <<numeric_average <<" " <<"(" <<letter_grade(numeric_average) <<") " <<endl;
		
	}
	in_file.close(); 
	
	
	
	return 0;
}