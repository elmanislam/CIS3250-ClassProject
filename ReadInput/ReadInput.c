#include "ReadInput.h"


void readInput(char *fileName, char *fileName2) {  // readInput manually creates an "expected" file read that would be what we expect from the "real function". Since the TDD is not expected to actually read the real text file, we do not get into file reading here.
    inputShape = malloc(sizeof(struct shape));
    FILE *fp = fopen(fileName, "r");
    FILE *fp2 = fopen(fileName2, "r");

    if (fp == NULL) {
        return;
    }
    if (fp2 == NULL) {
        return;
    }

    inputShape->numOfPoints = 0;
    inputShape->points = NULL;
    char line[40];
    struct point *points;
    int i = 0;
    fgets(line, 40, fp);

    do {
        points = malloc(sizeof(struct point));

        if (sscanf(line, "%f,%f,%f,%f", &(points->element[0]), &(points->element[1]), &(points->element[2]), &(points->element[3])) != 4) {
            free(points);
            continue;
        }

        inputShape->points = realloc(inputShape->points, (sizeof(struct point *) * (i + 1)));

        inputShape->points[i] = points;

        inputShape->numOfPoints += 1;

        i++;
    } while (fgets(line, 40, fp));

    //uncoment for other groups when .h file is included
    
	
	char line2[40];
	const char s[2] = "=";
	char *token;
	
	float functCallNums[17];
	i = 0;
	fgets(line2, 40, fp2);

	do{
		token = strtok(line2, s);
		token = strtok(NULL, s);

		functCallNums[i] = atof(token);

		i++;
	} while(fgets(line2, 40, fp2));
    
	setGlobalScale(functCallNums[0]);
	setXScale(functCallNums[1]);
  	setYScale(functCallNums[2]);
  	setZScale(functCallNums[3]);
  	setXRotation(functCallNums[4]*(M_PI/180));      //Convert degrees to radians
  	setYRotation(functCallNums[5]*(M_PI/180));
  	setZRotation(functCallNums[6]*(M_PI/180));
  	setXTranslation(functCallNums[7]);
  	setYTranslation(functCallNums[8]);
  	setZTranslation(functCallNums[9]);
    setXReflection(functCallNums[10]);
  	setYReflection(functCallNums[11]);
  	setZReflection(functCallNums[12]);
    setXShear(functCallNums[13]);
    setYShear(functCallNums[14]);
    setZShear(functCallNums[15]);
	setOrthographic(functCallNums[16]);

    fclose(fp);
    fclose(fp2);
}
