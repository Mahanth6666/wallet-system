// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class user{
    public:
        string name;
        int age;  
        int wallet_balance;
        int bank_bal;
        int pho;
        vector<int> walv;
        vector<string> walv2;
        vector<int> banv;
        vector<string>banv2;
        vector<string>bd;
        vector<string>wd;
        int points;
        user() {}
        user(string na,int ag,int ph){
            name=na;
            age=ag;
            points=0;
            wallet_balance=5000;
            bank_bal=0;
            pho=ph;
        }
        void disp(){
            cout<<"Name: "<<name<<" Age: "<<age<<endl<<"Bank_bal= "<<bank_bal<<"  Wallet Bal= "<<wallet_balance<<endl<<endl;
        }
        void dispban()
        {
            int si=banv.size();
            cout<<"BANK LOG:\n";
            for(int i=0;i<si;i++){
                cout<<banv2[i]<<"-"<<banv[i]<<" "<<bd[i]<<endl;
            }
            cout<<endl;
        }
        void dispwal(){
            int si=walv.size();
            cout<<"WALLET LOG:\n";
            for(int i=0;i<si;i++){
                cout<<walv2[i]<<"-"<<walv[i]<<" "<<wd[i]<<endl;
            }
            cout<<endl;
            
        }
    
};
class wallet{
    public: 
        map<int,user> user_list;
        void adduser(string na,int ag,int pho){
            int id=user_list.size();
            user u(na,ag,pho);
            user_list[id]=u;
            cout<<"ID= "<<id<<endl;
            cout<<endl;
            user_list[id].disp();
            return;
        }
        bool login(int id,string na){
            if(user_list[id].name==na){
                return true;
            }
            else{
                return false;
            }
        }
        void spend(int id,int tof,int wb,int rup){
            user &uu=user_list[id];
            if(wb==1){
                if(uu.wallet_balance>=rup){
                    uu.wallet_balance-=rup;
                    uu.walv.push_back(rup);
                    uu.wd.push_back("DEBIT");
                    int uiu=rup*0.05;
                    uu.points+=uiu;
                    switch(tof){
                        case 1:
                            uu.walv2.push_back("SUBSCRIPTION");
                            break;
                        case 2:
                            uu.walv2.push_back("TRAVEL");
                            break;
                        case 3:
                            uu.walv2.push_back("FOOD");
                            break;
                        case 4:
                            uu.walv2.push_back("BOOKS");
                            break;
                        case 5:
                            uu.walv2.push_back("OTHERS");
                            break;
                    }
                }
                else{
                    cout<<"Insufficient Wallet balance\n"<<endl;
                }
            }
            else{
                if(uu.bank_bal>=rup){
                    uu.bank_bal-=rup;
                    uu.banv.push_back(rup);
                    uu.bd.push_back("DEBIT");
                    switch(tof){
                        case 1:
                            uu.banv2.push_back("SUBSCRIPTION");
                            break;
                        case 2:
                            uu.banv2.push_back("TRAVEL");
                        case 3:
                            uu.banv2.push_back("FOOD");
                        case 4:
                            uu.banv2.push_back("BOOKS");
                        case 5:
                            uu.banv2.push_back("OTHERS");
                    }
                }
                else{
                    cout<<"Insufficient Bank balance\n";
                    cout<<endl;
                }
            }
            
        }
        void displog(int id){
            user_list[id].dispban();
            user_list[id].dispwal();
        }
        void addbankabal(int id,int cas){
            user &uu=user_list[id];
            uu.bank_bal=uu.bank_bal+cas;
            uu.banv.push_back(cas);
            uu.banv2.push_back("BANK");
            uu.bd.push_back("CREDIT");
            user_list[id].disp();
            return;
        }
        void claimpoints(int id){
            user &uu=user_list[id];
            cout<<"YOUR POINTS:"<<uu.points<<endl;
            int up=uu.points;
            if(uu.points>=100){
                uu.points-=up;
                uu.wallet_balance+=up;
                cout<<"POINTS CLAINMED:\n";
                cout<<endl;
            }
            else{
                cout<<"LOW POINTS"<<endl;
                cout<<endl;
            }
            
        }
        void subbankabal(int id,int cas){
            user &uu=user_list[id];
            if(uu.bank_bal>=cas){
                uu.bank_bal=uu.bank_bal-cas;
                user_list[id].disp();
                uu.walv.push_back(cas);
                uu.walv2.push_back("BANK");
                uu.wd.push_back("DEBIT");
            }
            else{
                cout<<"Insufficient Balance\n";
                cout<<endl;
            }
            
            return;
        }
};
int main() {
    wallet wal;
    int c1,tof,ag,ph,id,c2,cc,wb,c3,rup;
    string na;
    bool x;
    while(true){
        cout<<"ENTER 1 FOR REGISTER, ENTER 2 FOR LOGIN"<<endl;
    
        cin>>c1;
        switch(c1){
            case 1:
                cout<<"Enter name,age,pho"<<endl;
                
                cin>>na;
                cin>>ag;
                cin>>ph;
                wal.adduser(na,ag,ph);
                break;
            case 2:
                cout<<"ENTER ID,Name"<<endl;
                
                cin>>id;
                cin>>na;
                if(wal.login(id,na))
                {
                    cout<<"LOGINED"<<endl;
                    cout<<endl;
                    x=true;
                    while(x)
                    {
                        cout<<"ENTER 1 TO MANAGE BANK,2 TO LOGOUT,3 TO SPEND,4 TO VIEW LOG,5 FOR ADD POINTS\n";
                        
                        cin>>c2;
                        switch(c2)
                        {
                            case 1:
                                cout<<"ENTER 1 TO ADD BALANCE,2 TO TAKE CASE\n";
                                cout<<endl;
                                cin>>c3;
                                switch(c3)
                                {
                                    case 1:
                                        cout<<"Enter cash to deposit: \n";
                                        cout<<endl;
                                        cin>>cc;
                                        wal.addbankabal(id,cc);
                                        break;
                                    case 2:
                                        cout<<"Enter cash to take: \n";
                                        cout<<endl;
                                        cin>>cc;
                                        wal.subbankabal(id,cc);
                                        break;
                                }
                                break;
                            case 2:
                                x=false;
                                break;
                            case 3:
                                cout<<"ENTER 1 FOR SUBSCRIPTION,2 FOR TRAVEL,3 FOR FOOD,4 FOR BOOKS,5 FOR OTHERS\n";
                                cout<<endl;
                                cin>>tof;
                                cout<<"USE WALLET(1) OR BANK(2): \n";
                                cin>>wb;
                                cout<<"ENTER RUPEES";
                                cin>>rup;
                                wal.spend(id,tof,wb,rup);
                                break;
                            case 4:
                                wal.displog(id);
                                break;
                            case 5:
                                wal.claimpoints(id);
                                break;
                        }
                    }
                    
                }
                else{
                    cout<<"LOGIN FAILED"<<endl;
                    cout<<endl;
                }
                break;
        }
        
    }
    

    return 0;
}
Added wallet management system code
