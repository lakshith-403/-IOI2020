#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

/*these variables are used to store number of occurunces of each letter.
  Note that only neccessary letters are Counted.
  i.e only the no of 'o' letters after 'l' are counted. (If there is a letter 'o' before 'l' it doesn't matter because we can't use it to make a word)
  Letter 'l' is common for both 'love' and  'like'. Therefore 'l' is counted twice.
*/

int l,o,v,k,i,e,li;

void solve(int t){
  int n;
  cin >> n;
  string s;
  cin >> s;
  /*
  Iterate through the string doing the following
  If the letter is 'l' increment the both l counts (l and li)
  If the letter is 'o' and l!=0 (there is a 'l' before 0) increment 'o' Count and decrement 'l' Count.(We used this 'l' to make 'lo')
  If the letter is 'v' and o!=0 increment v and decrement o (same as above)
  Do the same thing for the letters 'i' and 'k' but starting from variable li instead of l
  Occurunce of e is the tricky part. If we find 'e' and v!=0 that means we can create a ful word. So we can decrement v and increment e as before.
  But there is a problem. We counted l twice for two words. If we finish a word now it means that we completely used up a 'l'. So we have to 
  remove it from the counts of the other word.
  So we can simply decrement li variable. But it could be also used for other letters 'i' and 'k'. So what we have to do is if(li!=0) decrement it. If it's zero proceed to the next letter 
  and decrement it. If it's also zero proceed to the next and decrement it. 
  Doing the same for the word 'like' will complete the solution.
  e count after the loop is the answer.
  
  If it's not clear to you about the need to manage two 'l' counts, think about this example
                                  'loike'
  */
  for(char c:s){
    if(c=='l')l++,li++;
    else if(c=='o'&&l!=0)l--,o++;
    else if(c=='v'&&o!=0)o--,v++;
    else if(c=='e'&&v!=0){
      v--,e++;
      if(li!=0)li--;
      else if(i!=0)i--;
      else if(k!=0)k--;
    }
    else if(c=='i'&&li!=0)li--,i++;
    else if(c=='k'&&i!=0)i--,k++;
    else if(c=='e'&&k!=0){
      k--,e++;
      if(l!=0)l--;
      else if(o!=0)o--;
      else if(v!=0)v--;
    }
  }
  cout << e << "\n";
}

int main(){
  io_setup();
  int t = 1;
  while(t--)solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
