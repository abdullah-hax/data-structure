// #include <iostream>
// #define max 50
// #include <cstdio>

// using namespace std;

// int top = -1;
// // const int max=50;

// int stack[max];

// void push(int value)
// {
//     if (top == (max - 1))
//     {
//         cout << "Stack is overflow" << endl;
//         return;
//     }
//     else{
//          top++;
//         stack[top] = value;
//     }
       
// }

// void pop()
// {
//     if (top == -1)
//     {
//         cout << "Stack is underflow" << endl;
//         return;
//     }

//     stack[top] = -1;
//     top--;

//     // int value;
//     // value=stack[top];
//     // top--;
// }
// void display()
// {
//     for (int i = top; i >= 0; i--) // i=0;i<=top;i++
//     {
//         cout << stack[i] << endl;
//     }
// }

// int main()
// {
//     printf("For push enter: 1\n");
//     cout << "1. Push\n2. Pop\n3. Display\n0. Exit\n";
//     cout << "***************" << endl;


//     int var;
//     cout << "Select the value(Push/Pop/Display):";
//     cin >> var;

//     while (var != 0)
//     {
       
//         if (var == 1)
//         {
//             cout << "For stop push enter:-1" << endl;
//             cout << "Now enter the value for push: ";
//             int push_val;
//             cin >> push_val;

//             while (push_val != -1)
//             {
//                 push(push_val);
//                 cin >> push_val;
//             }
//         }
//         else if (var == 2) pop();
        
//         else if (var == 3) display();
    
//         cin >> var;
//     }

//     return 0;
// }


#include <iostream>
#define MAX 50   
using namespace std;

int top=-1;         
int stack[MAX]; 

void push(int value) {
    if (top == (MAX - 1)) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;  // first increment then insert
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "Popped: " << stack[top] << endl;
    stack[top] = -1; // reset value and decrease top
    top--;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements (top to bottom):" << endl;
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {
    
    cout << "=== Stack Menu ===" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "0. Exit" << endl;
    cout << "==================" << endl;

    int var;
    cout << "Select an option: ";
    cin >> var;

    while (var != 0) {
        if (var == 1) {
            cout << "Enter values to push (end with -1):" << endl;
            int push_val;
            cin >> push_val;
            while (push_val != -1) {
                push(push_val);
                cin >> push_val;
            }
        }
        else if (var == 2) {
            pop();
        }
        else if (var == 3) {
            display();
        }
        else {
            cout << "Invalid option! Try again." << endl;
        }

        cout << "\nSelect an option: ";
        cin >> var;
    }

    cout << "Program exited." << endl;
}