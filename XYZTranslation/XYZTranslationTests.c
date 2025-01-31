#include "XYZTranslationTests.h"

// Run tests
void XYZTranslationTests() {
  TestingExpectedPointWithXYZTranslation();
  XYZTranslationLargeValueOutOfBounds();
  XYZTranslationSmallValueOutOfBounds();
  PassingEmptyShapeStruct();

}
//Test ensure proper function of XYZTranslation()
void TestingExpectedPointWithXYZTranslation() {

  float x;
  float y;
  float z;

  struct point expected;

  expected.element[0] = 4;
  expected.element[1] = 6;
  expected.element[2] = 8;
  expected.element[3] = 1;

  // Create Identity Matrix
  resetMatrix();

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();

  setXTranslation(3);
  setYTranslation(4); 
  setZTranslation(5); 

  XYZTranslation();

  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);

  for (int i = 0; i < 3; i++) {
    if (inputShape->points[inputShape->numOfPoints - 1]->element[i] != expected.element[i]) {
      printf("Clean test failed: Expected vector did not match the result\n");
    }
  }
}

// Resulting matrix will be out of bounds unless multiplied by the points and produce logical error caught by the program
void XYZTranslationLargeValueOutOfBounds() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();

  setXTranslation(FLT_MAX * 2);
  setYTranslation(FLT_MAX * 2);
  setZTranslation(FLT_MAX * 2);

  XYZTranslation();
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}

// Resulting matrix will be out of bounds unless multiplied by the points and produce logical error caught by the program
void XYZTranslationSmallValueOutOfBounds() {
  float x;
  float y;
  float z;

  x = getXTranslation();
  y = getYTranslation();
  z = getZTranslation();

  setXTranslation(FLT_MIN * 2);
  setYTranslation(FLT_MIN * 2);
  setZTranslation(FLT_MIN * 2);
  XYZTranslation();
 
  setXTranslation(x);
  setYTranslation(y);
  setZTranslation(z);
}

//Testing an empty shape struct
void PassingEmptyShapeStruct() {
    struct point **originalPoints = malloc(sizeof(struct point *) * inputShape->numOfPoints);

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      originalPoints[i][j] = inputShape->points[i][j];
    }
  }

  inputShape->points = NULL;
  XYZTranslation();

  if(inputShape->points != NULL) {
    printf("Failed Dirty Test. Should not have intialized anything\n");
  }

  for(int i = 0; i < inputShape->numOfPoints; i++) {
    for(int j = 0; j < 4; j++) {
      inputShape->points[i][j] = originalPoints[i][j];
    }
  }
  free(originalPoints);
}
