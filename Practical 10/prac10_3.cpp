#include<iostream>
using namespace std;
int main(){
int slots[10];

for(int i=0;i<10;i++){

  slots[i]=-1;
}

int n;
cout<<"\n Enter no of students ID:";
cin>>n;

cout<<"\n Enter ID's:\n";
for(int i=0;i<n;i++){
int id;
cin>>id;

int h1=id % 10;
int h2=7-(id % 7);

int index=h1;

int j=0;

while(slots[index]!= -1){

    j++;
    index=(h1 + j * h2)%10;
}

slots[index]=id;

}

cout<<"\n Final table:\n";
for(int i=0;i<10;i++){

    cout<<i<<":"<<slots[i]<<endl;
}

}