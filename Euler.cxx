/*
 *Euler mathode
 *Theodora + Johannes + Abdul
 *
 */
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;
void euler_vor(double* f_vor, const int n, const double step,const double lambda);//definieren
void euler_back(double* f_back, const int n, const double step,const double lambda);
void euler_mitt(double* f_mitt, const int n, const double step,const double lambda);
void make_file(double* f_vor, const int n, const double step);
void make_file2(double* f_back, const int n, const double step);
void make_file3(double* f_mitt, const int n, const double step);
int main()
{
  
  
  const  double t_beg=0, t_end=5;
  const int n=  50;
  const double step=(t_end-t_beg)/((double)n);
  
  double *f_vor=new double[n];
  double *f_back=new double[n];
  double *f_mitt=new double[n];
  const double lambda=0.5;
  
  euler_vor(f_vor, n, step,lambda); //aufrufen
  make_file(f_vor, n,  step);
  euler_back(f_back, n,  step, lambda);
  make_file2(f_back, n,  step);
  euler_mitt(f_mitt, n,  step, lambda);
  make_file3(f_mitt, n,  step);
  delete[] f_vor;
  delete[] f_back;
  delete[] f_mitt;
  
  return 0;
}
void euler_vor(double* f_vor, const int n, const double step,const double lambda)  // Dateien speichern
{
  f_vor[0]=1;
  for (int i=1; i<n; i++)
  {
    f_vor[i]=f_vor[i-1]+step*lambda*f_vor[i-1]; // Yn+1 = Yn + delt_t*F*(Yn,t)
  }
}

void euler_back(double* f_back, const int n, const double step, const double lambda)
{
  f_back[0]=1;
  for(int i=1; i<n; i++)
  {
    f_back[i]=f_back[i-1]/(1-lambda*step);
  }
}
void euler_mitt(double* f_mitt, const int n, const double step,const double lambda)
{
  f_mitt[0]=1;
   for(int i=1; i<n; i++)
  {
    f_mitt[i]=f_mitt[i-1]*(2+step*lambda)/(2-step*lambda);
  }
  
}

void make_file(double* f_vor, const int n, const double step)
{
  ofstream out("euler_vor.txt");
  for(int i=0; i<n; i++)
    out<<i*step<<"\t"<<f_vor[i]<<endl;
 
  out.close();
}
void make_file2(double* f_back, const int n, const double step)
{
  ofstream out("euler_back.txt");
  for(int i=0; i<n; i++)
    out<<i*step<<"\t"<<f_back[i]<<endl;
 
  out.close();
}
void make_file3(double* f_mitt, const int n, const double step)
{
  ofstream out("euler_mitt.txt");
  for(int i=0; i<n; i++)
    out<<i*step<<"\t"<<f_mitt[i]<<endl;
 
  out.close();
}
// gnuplot> plot "euler_back.txt","euler_vor.txt", exp(0.5*x)
