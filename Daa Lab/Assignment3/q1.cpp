#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>  input(){
    int size;
    cout<<"Enter size: "<<endl;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter Elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return arr;
}

void display(const vector<int>& arr){
    cout<<"Elements of array are: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort(vector<int>& arr){
    int i,j;
    for(i=0;i<arr.size()-1;i++){
        for(j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    display(arr);
}
void select_sort(vector<int>& arr){
    int i,j;
    for(i=0;i<arr.size()-1;i++){
        for(j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    display(arr);
}
void insert_sort(vector<int>& arr){
    int key;
    int i,j;
    for(i=1;i<arr.size();i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    display(arr);
}



int main(){
    vector<int> array;
    int ch=1;
    while(ch){
        cout<<"\n1.Input\n2.Display\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n6.Quit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            array=input();
            break;
            case 2:
            display(array);
            break;
            case 3:
            bubble_sort(array);
            break;
            case 4:
            select_sort(array);
            break;
            case 5:
            insert_sort(array);
            break;
            case 6:
            exit(0);
            default:
            cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}