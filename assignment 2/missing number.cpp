#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" sorted elements (with one missing number): ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int missing=-1;
    for(int i=0;i<n;i++) {
        if(arr[i] != arr[0] + i) {
            missing = arr[0] + i;
            break;
        }
    }
    if(missing==-1) missing = arr[n-1] + 1;

    cout<<"Missing number is: "<<missing;
    return 0;
}
