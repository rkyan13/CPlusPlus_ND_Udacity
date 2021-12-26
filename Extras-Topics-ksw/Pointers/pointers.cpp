#include <iostream>
using namespace std;

int main(){

	int a[5]={0,1,2,3,4};
	int *ptr1;
        int (*ptr2)[5];
        int *ptr[5];
	
        
        //Pointer-to-array: Type1
	ptr1 = a;
        cout<<"\na      = "<< a;	
	cout<<"\n&a     = "<< &a;
	cout<<"\nptr1   = "<< ptr1;
	cout<<"\n*ptr1  = "<<*ptr1;
        
        cout<<"\n:Printing *(ptr1+i): ";
	for(int i=0; i<5;i++){
	    cout<<*(ptr1+i)<<" ,";
	}
	cout <<"\n";
        
        //Pointer-to-array: Type2: 
        //(*ptr2) is a pointer to an array with 5 elements
        cout<<"\nNotice the difference in *ptr1 and **ptr2: Notice the double indirection** in ptr2";

       	ptr2 = &a;
        cout<<"\na      = "<< a;	
	cout<<"\n&a     = "<< &a;
	cout<<"\nptr2   = "<< ptr2;
	cout<<"\n*ptr2  = "<<*ptr2;
        cout<<"\n**ptr2 = "<<**ptr2;
        
        cout<<"\n:Printing *(*ptr2+i): ";
	for(int i=0; i<5;i++){
	    cout<<*(*ptr2+i)<<" ,";
	}
	cout <<"\n";

      


	return 0;
}


