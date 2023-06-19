#include<bits/stdc++.h>
using namespace std;

struct state{
   public:
    state *p;
    
    vector<vector<int> > a;
    int priority=0;
     state(){
        a.resize(3,vector<int>(3));
       
        p=NULL;}
     state(vector<vector<int> > v,vector<vector<int> > b){
       a.resize(3,vector<int>(3));
        for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
            a[i][j]=v[i][j]; }}
             for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
            if(a[i][j]==b[i][j])priority++; }}
        
         
      p=NULL;
    }};
    struct compare_priority{
        bool operator()(state * const &p1, state * const &p2)
      { return  p1->priority <p2->priority;}
    };
    
   

 int x[4]={-1,0,1,0};
 int y[4]={0,1,0,-1};  
void  display(vector<vector<int> > v){
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){cout<<v[i][j]<<" ";}}
        cout<<endl;
    }
    bool isvalid(int a,int b){
    if((a>=0&&a<3)&&(b>=0&&b<3)) return true;
       
        else return false;
    
 }
void check(vector<vector<int> > v,state * root,vector<vector<int> >   b,priority_queue <state *,vector<state *>,compare_priority> &q){
     
       
      int i,j,m,n,k=0;
       for(i=0;i<3;i++){for(j=0;j<3;j++){
        if(v[i][j]==0){m=i;n=j;break;}}}
       
      for(i=0;i<=3;i++){
      if (isvalid(m+x[i],n+y[i]))
      {swap(v[m][n],v[m+x[i]][n+y[i]]);
       state *ptr=new state(v,b);
       if(ptr->a==root->a)delete ptr;
       if(ptr->a!=root->a){
       if(ptr->a==b){cout<<"match found"<<endl; display(ptr->a);exit(1);}
       ptr->p=root;
       display(ptr->a);cout<<endl;
      
          q.push(ptr);swap(v[m][n],v[m+x[i]][n+y[i]]);}}}
          root=q.top();//while(!q.empty())
          q.pop();check(root->a,root,b,q);
 }
 
 

int main(){
    
     vector<vector<int> > c(3,vector<int>(3));
    vector<vector<int> > b(3,vector<int>(3));
    
    int i,j;
    cout<<"insert initial array:"<<endl;
     for(i=0;i<3;i++){for(j=0;j<3;j++){cin>>c[i][j];}}
        cout<<"insert final array:"<<endl;
       for(i=0;i<3;i++){for(j=0;j<3;j++){cin>>b[i][j];}}
     
         state *root=new state(c,b);
   
     
   
   display(root->a);cout<<endl;
   //void  display(vector<vector<int>> v);
   //bool isvalid(int a,int b);
  priority_queue <state *,vector<state *>,compare_priority> q;
   check(root->a,root,b,q);
  
   
    }