#include "ReadInputTests.h"

//shape->points[i]->element[0]
/*
// (CLEAN) Test #1 will compare all the given float values against the expected float values. We expect this test to pass.
char ReadInputTest1(char testFile[20], char answerFile[20], char inputfile2[20]) {
    struct shape *input = readInput(testFile, inputfile2);
    FILE *fp = fopen(answerFile, "r");
    int lines = 0;
    char buf[30];
    float *test;
    float answers[4];
    for (int i = 0; fgets(buf, 30, fp); i++) {
        test = input->points[i]->element;
        sscanf(buf, "%f,%f,%f,%f", &answers[0], &answers[1], &answers[2], &answers[3]);
        lines++;
        for (int j = 0; j < 4; j++) {
            if (test[j] != answers[j]) {
                fclose(fp);
                freeShape(input);
                return '1';
            }
        }
    }
    fclose(fp);
    freeShape(input);
    return '0';
}  // END OF TEST 1

//Dirty test 1 - incorrect input format(characters found in the input file)
int ReadInputTest2(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    //printf("pass readinput1\n");
    struct shape *original = readInput(orgFile, inputfile2);  //Read the "correct" original input file

    struct shape *testInput = readInput(testFile, inputfile2);  //Read the input file containing characters
    //printf("pass readinput2\n");
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = testInput->points[i]->element;
        //printf("pass\n");

        for (int j = 0; j <= 3; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                //printf("pass3\n");
                freeShape(original);
                //printf("pass4\n");
                freeShape(testInput);
                //printf("pass5\n");
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(testInput);
    return 0;
}  // END OF TEST 2

//Dirty test 2 - incorrect inputs format more than 4 values on each line in the input file)
int ReadInputTest3(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    struct shape *original = readInput(orgFile, inputfile2);    //Read the "correct" original input file
    struct shape *testInput = readInput(testFile, inputfile2);  //Read from input file with more than 3 values on each line
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = testInput->points[i]->element;
        for (int j = 0; j <= 4; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                freeShape(original);
                freeShape(testInput);
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(testInput);
    return 0;
}  // END OF TEST 3

//Dirty test 3 - incorrect inputs (incomplete matrix in the input file)
int ReadInputTest4(char *testFile, char *orgFile, char inputfile2[20]) {
    float *test, *answers;
    struct shape *original = readInput(orgFile, inputfile2);    //Read the "correct" original input file
    struct shape *testInput = readInput(testFile, inputfile2);  //Read from "incomplete" input file
    for (int i = 0; i < original->numOfPoints; i++) {
        test = original->points[i]->element;
        answers = testInput->points[i]->element;
        for (int j = 0; j <= 4; j++) {
            if (test[j] != answers[j]) {  //Compare the data between the 2 files
                freeShape(original);
                freeShape(testInput);
                return 1;
            }
        }
    }
    freeShape(original);
    freeShape(testInput);
    return 0;
}  // END OF TEST 4

//Dirty test 4 - Incorrect file name passed, fails to read because filereader == NULL.
int ReadInputTest5(char answerFile[20], char inputfile2[20]) {
    struct shape *original = readInput(answerFile, inputfile2);  //Call the function with an incorrect file name

    if (original == NULL) {
        freeShape(original);
        return 1;  // If file name not found, fail case.
    }
    freeShape(original);
    return 0;  // Else, pass case.
}  // END OF TEST 5

// Dirty Test 5 - Attempts to add all floats contained in both txt files and compare the values. (Index is wrong...)
int ReadInputTest6(char testFile[20], char answerFile[20], char inputfile2[20]) {
    float runningTotalExpected = 0;
    float runningTotalSecond = 0;

    struct shape *passedStruct = readInput(testFile, inputfile2);

    for (int i = 0; i < passedStruct->numOfPoints; i++) {
        for (int j = 0; j <= 5; j++) {
            runningTotalExpected += passedStruct->points[i]->element[j];
        }  // variable j exceeds array index number of points within struct (should be '<5' instead of '<=5') (this is the error)
    }

    FILE *fp = fopen(answerFile, "r");

    int lines = 0;
    char buf[30];
    //float *test = 0;
    float answers[3];
    for (int i = 0; fgets(buf, 30, fp); i++) {
        sscanf(buf, "%f %f %f", &answers[0], &answers[1], &answers[2]);
        runningTotalSecond += answers[0];  //
        runningTotalSecond += answers[1];  // These three lines add all the float values into
        runningTotalSecond += answers[2];  //
        lines++;
    }

    if (runningTotalExpected != runningTotalSecond) {  // Compares totals from addition. (Expected vs fileRead)
        freeShape(passedStruct);
        return 1;  // if not equal, fail case.
    } else {
        freeShape(passedStruct);
        return 0;  // if equal, pass case.
    }

}  // END OF TEST 6

void freeShape(struct shape *test) {
    if (!test) return;
    for (int i = 0; i < test->numOfPoints; i++) {
        free(test->points[i]);
    }
    free(test->points);
    free(test);
}
*/
