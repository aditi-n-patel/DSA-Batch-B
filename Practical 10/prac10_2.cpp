#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<int> slots[10];

int n;
cout<<"Enter no of books:";
cin>>n;

cout<<"\n Enter book code:";

for(int i=0;i<n;i++){
  int code;
  cin>>code;

  int index=code%10;

  slots[index].push_back(code);
}

cout<<"\n Final shelves:\n";

for(int i=0;i<10;i++){

    cout<<i<<":";
    for(int j=0; j<slots[i].size(); j++){
        cout<<slots[i][j]<<" ";
}
cout<<endl;
}


}