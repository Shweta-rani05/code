/*
program to show multi-level inheritance 
class bank : name,location,accounts;
methods : add, remove,display
class account : account no. ,account holder,balance,transactions.
methods : deposit,withdraw and display account details;
class accountHolder : name,address,phone no.
methods : update;
class transaction :transaction id,date,type,amount.
methods : display ; 
*/

#include<iostream>
using namespace std;

class transaction{
    public:
    int transactionid;
    string date;
    string type;
    int amount;
    transaction(int t_id,string d,string t,int amt){
        transactionid = t_id;
        date = d;
        type = t;
        amount = amt;
    }
    void display(){
        cout<<"transaction details"<<endl;
        cout<<"id :"<<transactionid<<"date: "<<date<<" "<<endl;
        cout<<"type :"<<type<<"Amount : "<<amount<<endl;
    }
};

class accountHolder{
    public:
    string name;
    string address;
    string phoneno ;
    accountHolder(string n,string add,string p_no.){
        name = n;
        address = add;
        phoneno = p_no.;
    }
    void update(){
        cout<<"account holder updated details" <<endl;
    }
};

class Account:public transaction,public accountHolder{
    public :
    int accountno;
    float balance ;
    Account(int acc_no ,float b,int t_id,string d,string t,int amt,string n,string add,int p_no.):transaction(t_id,d,amt),accountHolder(n,add,p_no),accountno(acc_no),balance(b){}
    void deposit(float amount){
        balance+= amount;
        cout<<"Amount deposited.new balance:"<<balance<<endl;
    }
    void withdraw(float amount){
        if(amout>balance){
            cout<<"Insufficient balance"<<endl;
        }else{
            balance-=amount;
            cout<<"Amount withdrawn.New balance:"<<balance<<endl;
        }
    }
    void display(){
        cout << "Account Details:" << endl;
        cout << "Account No: " << accountno << ", Balance: " << balance << endl;
    }
};


class bank {
    public:
    string name;
    string location;
    int accounts;
    bank(string n,string l,int acc):name(n),location(l),accounts(acc){}
    

    void add(){
        cout <<"Add account details"<<endl;
    }
    void remove(){
        cout<<"to removw account details"<<endl;
    }
    void display(){
        cout<<"display accounts details"<<endl;
        cout<<name<<" "<<location<<" "<<accounts<<" "<<endl;
        cout<<"Number of accounts:"<<accounts<<endl;
    }
};

int main() {
    Account acc(101, 5000.0, 1, "2025-04-03", "Credit", 1000, "Shweta", "India", "1234567890");
    acc.display();
    acc.deposit(2000);
    acc.withdraw(3000);

    bank b("MyBank", "Haryana", 100);
    b.display();

    return 0;
}

