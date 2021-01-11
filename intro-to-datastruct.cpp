#include <stdio.h> //input output
#include <stdlib.h> //strcpy
#include <string.h> //dynamic memory allocation

struct Course{
    char ID[10]; //10 bytes
    int score; // 4 bytes
};

struct Student {
    char name[255];//255 bytes
    double GPA;//8 bytes
    Course c; //object course
};

int plus(int a, int b){
    return a+b;
}
//tipe data yang di return :int
// nama function : plus
//parameter: a dan b


//Function ini akan mereturn pointer yang mengarah ke student
//const char *name sama dengan char name[], bedanya kalau pakai [] di vscode akan dapat warning
Student *createstudent(const char *name, double gpa, const char *ID, int score){
    //alokasi memori
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name); //strcpy((*newStudent).name, name);

    // hasil = hasil +3 sama dengan hasil +=3
    // (*newStudent).atributnya sama saja dengan newStudent->atributnya

    newStudent->GPA = gpa;
    strcpy(newStudent->c.ID, ID);
    newStudent->c.score = score;


    return newStudent;
}
//tipe data yang di return :Student*
// nama function : createstudent
//parameter: name, gpa, course (id dan score)

void removeStudent(Student *s){
    free(s);
    s = NULL;
}

void printStudent(Student *s){
    printf("Name: %s\n", s->name);
    printf("GPA: %lf\n", s->GPA);
    printf("Course ID: %s\n", s->c.ID);
    printf("Score: %d\n", s->c.score);
}

int main(){

    // Student dummy;
    // isi dummy.name, dummy.gpa;
    // createstudent(dummy);

    //s1 mengarah ke student yang diarahkan oleh createstudent
    Student *s1 = createstudent("Budi", 3.90, "COMP6048", 100);
    Student *s2 = createstudent("Abdul", 4.00, "COMP6049", 85);
    //Student *s3 = createstudent(name, gpa, id, score);
    //Student students[10]; //static memory allocation
    printf("Before Remove : \n");
    printStudent(s1);
    removeStudent(s1);
    printf("After Remove : \n");
    //Student *s3 = createstudent("Bryan", 3.90, "COMP6049", 95);
    //kalau memorimu gede lama ketimpanya, kalau memori kecil cepet ketimpanya
    printStudent(s1);//Print setelah remove termasuk undefined behaviour, mengakses memori ilegal
    //jangan print nilai yang sudah di free
    return 0;
}