#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
  double age = 10.38;
  int odoo_nas = floor(age);
cout<<"odoo "<<odoo_nas<<"\n";
  int hii_nas = ceil(age);
  cout<<"hii "<<hii_nas<<"\n";
cout<<"sqrt "<<sqrt(age)<<"\n";
cout<<"pow 2 of age "<<pow(age,2)<<"\n";
cout<<"log "<<log(age)<<"\n";
cout<<"log10 "<<log10(age)<<"\n";
cout<<"fabs "<<fabs(age)<<"\n";
cout<<"fmod "<<fmod(age,2.0)<<"\n";

cout<<"cos "<<cos(age)<<"\n";
cout<<"sin"<<sin(age)<<"\n";
}
