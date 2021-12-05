string Solution::solve(string A) {
  string ans="";
  int freq[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  queue<char> q;
  for(int i=0;i<A.size();i++){
    if(freq[A.front()]==0){
      q.enqueue(A[i]);
      ans+=A[i];
      freq[A[i]-96]++;
    }
    else{
      q.dequeue();
    }
  }

}
