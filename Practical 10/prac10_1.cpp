#include<iostream>
using namespace std;

int main(){
int n;
int slots[10];

for(int i=0; i<10; i++){
    slots[i]=-1;
}

cout<<"Enter no of cars you want to register:";
cin>>n;

cout<<"\n Enter registration slot numbers:";
for(int i=0;i<n;i++){
  int reg;

  cin>>reg;

  int index=reg%10;

  int j=0;

  while(slots[index]!=-1){
    j++;

     index = (reg % 10 + j) % 10;
     // index=reg+1)%10 
}

 if(j == 10){
            cout << "Parking lot is full. Cannot insert " << reg << endl;
        }
        else{
            slots[index] = reg;
        }

}

for(int i=0;i<10;i++){
    cout<<endl<<i<<" : "<<slots[i]<<endl;
}

return 0;


}