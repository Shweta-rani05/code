#include<iostream>
#include<vector>
using namespace std ;

int maxActivities(vector<int> start,vector<int> end){
    //sort on end time 
    //a0 select 
    cout << "selecting a0 \n";
    int count = 1;
    int currEndTime = end[0];

    for(int i=0;i<start.size(); i++){
        if(start[i] >= currEndTime){
            cout << "selecting A" << i <<endl;
            count++;
            currEndTime = end[i];
        }

    }
    return count;
}

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second< p2.second; //ascending order end 
    return p1.first <p2.first ; //ascending -start 
}

int main(){
    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,6,7,9,9};
    vector<int> start ={0,1,2};
    vector<int> end = {9,2,4};
    // cout<< maxActivities(start,end) << endl;

    vector<pair<int,int>> activity(3,make_pair(0,0));
    activity[0] = make_pair(0,9);
    activity[1] = make_pair(1,2);
    activity[2] = make_pair(2,4);

    for(int i=0; i<activity.size(); i++){
        cout<<"A" << i << ":" << activity[i].first << ","<< activity[i].second <<endl;
    }
    
    sort(activity.begin(),activity.end(),compare);
   
    cout << "sorted --";
    for(int i=0; i<activity.size(); i++){
        cout<<"A" << i << ":" << activity[i].first << ","<< activity[i].second <<endl;
    }
    
    return 0 ;
}