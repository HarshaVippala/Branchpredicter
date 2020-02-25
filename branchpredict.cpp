#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include<bitset>

using namespace std;
 
unsigned long shiftbits(bitset<32> inst, int start)
{
    unsigned long ulonginst;
    return ((inst.to_ulong())>>start); //getting m bits 
    
}
long extract_address(int m, long pc){   // extracting address 
  bitset<32> b(pc);
  long answer = pc & ((1<<m)-1);
  return answer;

}
auto convert_int(vector<bool> v){
  auto p = v.begin()._M_p;     
  return p;
}
// Calculate the size using pow function
long sizeOFaddress(int b, int e){
  long result = pow(b,e);
  return result;                    
}


int main (int argc, char** argv) {
  
  ifstream config;
  config.open(argv[1]);

  int m, k;
  config >> m >> k;
  config.close();

  // Define size of the table and initialize values
  long tablesize = sizeOFaddress(2,k)*sizeOFaddress(2,m);
  cout<<tablesize<<endl;
  int branchtable [tablesize];
  for(long i=0;i<tablesize;i++){
    branchtable[i] = 3;
  } 


  ofstream out;
  string out_file_name = string(argv[2]) + ".out";
  out.open(out_file_name.c_str());
  

  ifstream trace;
  trace.open(argv[2]);
  unsigned long pc; bool taken;
  trace >> std::hex >> pc >> taken;
  

  vector<bool> v (k);
  for(int i=0;i<k;i++) v[i] = true;
  auto history = v.begin()._M_p;
  
  cout<<*history<<endl;
  long add = extract_address(m, pc);
  long test_address = ((*history)*add);
  cout<<"Address is "<<endl;
  cout<<test_address<<endl;

  while (!trace.eof()) {
    int a = branchtable[test_address];
    bool pre;
    pre = true?(a==2 || a==3):false;
    out << pre<<endl;
    if(taken){
      if(a==0){
        branchtable[test_address] = 1;
      }
      else if(a==1){
        branchtable[test_address] = 3;
      }
      else if(a==2){
        branchtable[test_address] = 3;
      }
      bool insert = true;
      for(int i=0;i<k;i++){
        bool temp = v[i];
        v[i] = insert;
        insert = temp;
      }
      history = v.begin()._M_p;
  
    }
    else{
      if(a==1){
        branchtable[test_address] = 0;
      }
      else if(a==2){
        branchtable[test_address] = 0;
      }
      else if(a==3){
        branchtable[test_address] = 2;
      }
      bool insert = false;
      for(int i=0;i<k;i++){
        bool temp = v[i];
        v[i] = insert;
        insert = temp;
      }
      history = v.begin()._M_p;
  
    }
    trace >> std::hex >> pc >> taken;
    add = extract_address(m,pc);
    test_address =  ((*history)*add);
  }
   
  trace.close();  
  out.close();
}