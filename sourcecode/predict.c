#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void (*activationfunction)(float *,float *,int);
void (*dActivationFunction)(float *,float *,int);
#define inputDimension 784
#define outputDimension 10
#define numberofHiddenUnits 700
double hiddenWeights[numberofHiddenUnits][inputDimension];
double outputWeights[outputDimension][numberofHiddenUnits];

double inputVector[inputDimension];
double hiddenActualInput[numberofHiddenUnits];
double outputVector[outputDimension];

void logisticSigmoid(double *x,double *y,int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		y[i] = 1/(1 + exp(-x[i]));
	}
}

void dLogisticSigmoid(double *x,double *y,int n)
{
	int i;
	double inter;
	for (i=0;i<n;i++)
	{
		inter = 1/(1 + exp(-x[i]));
		y[i] = inter*(1-inter);
	}
}

void matrixmul(double *x,double *y,double *z,int a, int b, int c)
{
	int i,j,k;

	for (i=0;i<a;i++)
	{	
	  for (j=0;j<c;j++)
	  {
	    
	    z[i*c+j]=0;
	    for (k=0;k<b;k++)
	    {
		z[i*c+j]=z[i*c+j]+x[i*b+k]*y[k*c+j];
	    }
	  }
	}
}

void evaluateTwoLayerPerceptron(void)
{
  double hiddenInput[numberofHiddenUnits];
  double hiddenOutput[numberofHiddenUnits];
  double finalInput[outputDimension];

  matrixmul(hiddenWeights,inputVector,hiddenInput,numberofHiddenUnits,inputDimension,1);
  activationfunction(hiddenInput,hiddenOutput,numberofHiddenUnits);
  matrixmul(outputWeights,hiddenOutput,finalInput,outputDimension,numberofHiddenUnits,1);
  activationfunction(finalInput,outputVector,outputDimension);
}

void decisionRule(void)
{
  int i;int digit;
  float max=0;
  for (i=0;i<outputDimension;i++)
  {
    if (outputVector[i]>max)
    {
        
	max=outputVector[i];
        digit=i;
    }
  }
  printf("digit is %d\n",digit);
}

void main(void)
{
  FILE*fid1;
  FILE*fid2;
  FILE*fid3;
  fid1=fopen("hiddenweights","r");
  fid2=fopen("outputweights","r");
  fid3=fopen("inputvalues","r");
  double *ptrhid=&hiddenWeights;
  double *ptrout=&outputWeights;
  double *ptrin=&inputVector;
  fread(ptrhid,sizeof(double),numberofHiddenUnits*inputDimension,fid1);
  fread(ptrout,sizeof(double),numberofHiddenUnits*outputDimension,fid2);
  fread(ptrin,sizeof(double),inputDimension,fid3);
  fclose(fid1);
  fclose(fid2);
  fclose(fid3);
  activationfunction=logisticSigmoid;
  dActivationFunction=dLogisticSigmoid;
  evaluateTwoLayerPerceptron();
  decisionRule();
}

