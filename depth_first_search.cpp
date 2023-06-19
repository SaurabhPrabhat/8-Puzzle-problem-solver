#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};

int i=0;
struct state{
  state * parent;
  vector<vector<int>> a;
  state(){
    a.resize(3,vector<int>(3));
  }     
};

void printv(vector<vector<int>> & vv){
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<vv[i][j]<<" ";
    }cout<<"\n";
   }
}
void getpath(state * *st){
  if(((*st)->parent)==NULL) {
    vector<vector<int>> vvv=(*st)->a;
    cout<<"step "<<i<<"\n"; i++;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout<<vvv[i][j]<<" ";
      } cout<<endl;
    } return;
  } else {
    getpath(&((*st)->parent));
  } cout<<endl;
  vector<vector<int>> tt=(*st)->a;
  cout<<"step "<<i<<"\n"; i++;
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout<<tt[i][j]<<" ";
      } cout<<endl;
    } cout<<endl; 
    
    return;

}
bool cheak( vector<vector<int>>& s1, vector<vector<int>>&s2){
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
      if(s1[i][j]!=s2[i][j]) return false;
     }
   } return true;
}
bool isvalid(int x,int y){
  if(x>2 || x<0||y>2 || y<0) return false ;
  else return true;
}

void dfs_for_puzzle(state ** st,map<vector<vector<int>>,bool> &vis,
 vector<vector<int>> &final){

       vis[(*st)->a]=true;
       vector<vector<int>> vv(3,vector<int>(3));
       vv=(*st)->a;
       state * par=(*st)->parent;
       pair<int,int> co;
       for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(vv[i][j]==0){
                co.first=i; co.second=j;
                break;
            }}}
        for(int i=0;i<4;i++){
           int x=co.first+dx[i],y=co.second+dy[i];
           if(isvalid(x,y)){
             state * temp=(*st);
             vector<vector<int>> vtemp(3,vector<int>(3));
             vtemp=temp->a;
             swap(vtemp[co.first][co.second],vtemp[x][y]);
             if(cheak(vtemp,final)){
                state * tt=new state();
                tt->a=vtemp;
                tt->parent=(*st);
                getpath(&tt); return;
             }
             else{
                if(vis[vtemp]==false){
                    state * tt=new state();
                    tt->a=vtemp;
                    tt->parent=(*st);
                    dfs_for_puzzle(&tt,vis,final);
                } else{}
             }
           }

        }}
int main(){

   vector<vector<int>> ini(3,vector<int>(3));
   vector<vector<int>> final(3,vector<int>(3));
   state * s1=new state();
   for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
       cin>>ini[i][j];
     }
   } s1->a=ini;
     s1->parent=NULL;
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
       cin>>final[i][j];
     }
   }
   cout<<endl;
   map<vector<vector<int>>,bool> vis;
   dfs_for_puzzle(&s1,vis,final);
}