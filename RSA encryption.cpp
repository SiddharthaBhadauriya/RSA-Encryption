 //Idea is to generate some encrpted message and then decrypt it,
 // let's say A is sender and B is receiver then A will send message with encrption and for encryption A will use public key e of B,
 // then when the encrpted message will reach to B, B will need to decrypt it using its private key d.
   
#include<bits/stdc++.h>
using namespace std;
string multiply(string x,string y){
        string ans="";
        int n= x.size();
        int m = y.size();
        int x1= n+m;
        int arr[n+m];
        memset(arr,0,sizeof(arr));
        int n1=x1;
        int c=0;
        for(int i=m-1;i>=0;i--)
        {   n1= --x1;
            for(int j=n-1;j>=0;j--)
            {   
                  int s= ((y[i]-'0')*(x[j]-'0'))+arr[n1];
                   c= s/10;
                  int r = s%10;
                //  cout<<n1<<"n";
                  arr[n1]=r;
                  arr[n1-1]+=c;
                //  cout<<c<<" "<<r<<"r";
                  n1--;
            }
        }
        while(c!=0)
        {
            arr[n1--]=c%10;
            c=c/10;
        }
       // cout<<(n+m);// process of converting array of integer to string.
        int p=0;
        for(int i=0;i<(n+m);i++)
        {
            if(arr[i]!=0)
            p=1;
            if(p==1)
            ans += (arr[i]+'0');
        }
        return ans;
}
bool isSmaller(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;
    for (int i=0; i<n1; i++)
    if (s1[i] < s2[i])
        return true;
    else if (s1[i] > s2[i])
        return false;

    return false;
}
string addition(string s1, string s2)
{
     if (isSmaller(s1, s2))
        swap(s1, s2);
    string ans = "";
    int n1 = s1.length();
    int arr[n1+1];
    memset(arr,0,sizeof(arr));
    int a1[n1];
    int a2[n1];
    for(int i=0;i<n1;i++)
    {a1[i]= s1[i]-48; 
  //  cout<<a1[i]<<" "<<endl;
    }
    int m=s2.size();
    for( int i=n1-1;i>=0;i--)
    {  if(m==0)
     a2[i]=0;
     else
        a2[i]= s2[--m]-48;
        //cout<<a2[i]<<" ";
    }
    for(int i=n1-1;i>=0;i--)
    { int s=(a1[i]+a2[i]+arr[i+1]);
        arr[i+1]=  s%10;
        arr[i] +=  s/10;
    }
    // process of converting array of integer to string.
     int p=0;
        for(int i=0;i<=(n1);i++)
        { // cout<<arr[i]<<" ";
            if(arr[i]!=0)
            p=1;
            if(p==1)
            ans += (arr[i]+'0');
        }
        if(ans.size()==0)
        ans="0";
        return ans;
}
bool isSmallerOrEqualTo(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;
    for (int i=0; i<n1; i++)
    if (s1[i] < s2[i])
        return true;
    else if (s1[i] > s2[i])
        return false;

    return true;
}
bool isEqualTo(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if(n1!=n2)
        return false;
    for (int i=0; i<n1; i++)
        if(s1[i]!=s2[i])
            return false;
    return true;
}
string difference(string s1, string s2)
{
    if (isSmaller(s1, s2))
        swap(s1, s2);
    string ans = "";
    int n1 = s1.length();
    int arr[n1];
    int a1[n1];
    int a2[n1];
    for(int i=0;i<n1;i++)
    {a1[i]= s1[i]-48;
  //  cout<<a1[i]<<" "<<endl;
    }
    int m=s2.size();
    for( int i=n1-1;i>=0;i--)
    {  if(m==0)
     a2[i]=0;
     else
        a2[i]= s2[--m]-48;
        //cout<<a2[i]<<" ";
    }
    for(int i=n1-1;i>=0;i--)
    {
        if(a1[i]<a2[i])
        {
            a1[i]= a1[i]+10;
            a1[i-1]= a1[i-1]-1;
            arr[i]= a1[i]-a2[i];
        }
        else
        arr[i]=a1[i]-a2[i];
    } // process of converting array of integer to string.
    int p=0;
        for(int i=0;i<(n1);i++)
        {
            if(arr[i]!=0)
            p=1;
            if(p==1)
            ans += (arr[i]+'0');
        }
        if(ans.size()==0)
        ans="0";
        return ans;
}
// trickiest part of division with basic rules of division when inputs are string.
string division(string num, string div){
    string ans="";
    int pos=0;
    string temp="";
    while(pos<num.size()){
        if( temp[0]=='0')
            temp[0]=num[pos];
        else if(temp.size()==0 || temp.size()>=1)
            temp+=num[pos];
        if(isSmaller(temp,div)){
            if(ans.size()!=0)
                ans+='0';
        }
        else{
            for(int i=9;i>=0;i--){
                string t="";
                t+=i+'0';
                if(isSmallerOrEqualTo(multiply(t,div),temp)){
                    ans+=t;
                    if(isEqualTo(multiply(t,div),temp))
                        temp="";
                    else
                        temp=difference(multiply(t,div),temp);
                    break;
                }
            }
        }
        pos++;
    }
    if(ans.size()==0)
        return "0";
    return ans;
}
// finding out mod using already written function for multiply, division , difference
string mod(string s1,string s2){
    return difference(s1,multiply(division(s1,s2),s2));
} // find power in log(n) using previously defined functions
string power(string x,int n){
    if(n==0)
        return "1";
    if(n==1)
        return x;
    string temp=power(x,n/2);
    if(n%2==0)
        return multiply(temp,temp);
    else
        return multiply(x,multiply(temp,temp));
}
// finding modulus woth basic idea of division
int mod(string num, int a)
{
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}
// finding power (x^n)%N; simple like finding power but taking modulus everytime 
string power(string x,string n,string N){
    if(isEqualTo(n,"0"))
        return "1";
    if(isEqualTo(n,"1"))
        return mod(x,N);
    string temp  =mod(power(x,division(n,"2"),N),N);
    if(isEqualTo(mod(n,"2"),"0"))
        return mod(multiply(temp,temp),N);
    else
        return mod(multiply(x,mod(multiply(temp,temp),N)),N);
}// function to find Greatest common divisor
string gcd(string a, string b)
{
    if (isEqualTo(b,"0"))
        return a;
    return gcd(b, mod(a,b));
}// generating some random prime numbers
string generatePrime(){
    string primes[]={"1772629573679152589335751",
        "9996834795542799325379081",
        "8076737514959871909661591",
        "9184713383182455436877249",
        "5248856571818397095667017",
        "3316361718074381133015827",
        "6612394226173762040335063",
        "4246452375127824091160929",
        "8418082864875619721401463",
        "2875808158322221473148513",
        "61920572513383563943782839",
        "65320483338614522331739967",
        "94473552408568888084488047",
        "82729098578631246331278929",
        "87432804709221392558315267",
        "23302685438930430940182319",
        "51878221179371927720140051",
        "94206560009118564271125241",
        "93038004734008531347720607",
        "10481819821432872613578271",};
        // for testing it with larger primes, it was taking much time approx 24 seconds.
       /* string primes[]={"622288097498926496141095869268883999563096063592498055290461",
"610692533270508750441931226384209856405876657993997547171387",
"668486051696691190102895306426999370394054817506916629001851",
"313539589974026666385010319707341761012894704055733952484113",
"470287785858076441566723507866751092927015824834881906763507",
"361720912810755408215708460645842859722715865206816237944587",
"378348910233465647859184421334615532543749747185321634086219",
"669483106578092405936560831017556154622901950048903016651289",
"351300033958683656629281197430236951045077917074227778834807",
"511704374946917490638851104912462284144240813125071454126151",};*/
    return primes[rand()%10];
}// converting message to integer , we can do it using binary concept, as out data has to be in between 256 bits so rather 2 use 256.
string strToNum(string s){
    string ans="";
    for(int i=s.size()-1,k=0;i>=0;i--,k++){
        int t=s[i]+0;
        string temp;
        while(t!=0){
            temp+=t%10+'0';
            t/=10;
        }
        reverse(temp.begin(),temp.end());
        ans=addition(ans,multiply(power("256",k),temp));
    }
    return ans;
}
string numToStr(string n){
    string ans="";
    while(!isSmaller(n,"256")){
        ans+=mod(n,256);
        n=division(n,"256");
    }
    ans+=mod(n,256);
    reverse(ans.begin(),ans.end());
    return ans;
}// This is the definition of class RSA which will contain the required things for our encryption, we can see d is private.
class RSA{
    string p;
    string q;
    string phiN;
    string d;
    public:
    string N;
    string e;
    void generatePandQ(){
        p=generatePrime();
        q=generatePrime();
    }
    void calculateN(){
        N=multiply(p,q);
    }
    void calculatephiN(){
        phiN=multiply(difference(p,"1"),difference(q,"1"));
    }
    void generateE(){
        e="3";
        while(1){
        if(isEqualTo(gcd(e,phiN),"1"))
            break;
        e=addition(e,"2");
        }
    }
    void generateD(){
        string k="1";
        while(1){
            if(isEqualTo(mod(addition("1",multiply(k,phiN)),e),"0")){
                d=division(addition("1",multiply(k,phiN)),e);
                break;
            }
            k=addition(k,"1");
        }
    }
    // here N is receipients N
    // and message is encrypted in this function using (msg(in numbers)^e)%N;
    // here e is public key of receipient.
    string encryptMessage(string message,RSA recipient){
        string mnum,c,r_e,r_N;
        mnum=strToNum(message);
       // cout<<mnum<<endl;
        r_e=recipient.e;
        r_N=recipient.N;
        if(isSmaller(mnum,r_N)){
            c=mod(power(mnum,r_e,r_N),r_N);
            return c;
       }else{
            return "-1";
        }
    }
    // derypting message using private key of recepient private key  (cT^d)%N;
    // here N is recepients N.
    string decryptMessage(string cypherText){
        string decryptedMsg,decrptedMsgnum;
        decrptedMsgnum=mod(power(cypherText,d,N),N);
        //cout<<decrptedMsgnum<<endl;
        decryptedMsg=numToStr(decrptedMsgnum);
        return decryptedMsg;
    }
};
// main to run things for us
int main()
{
    RSA portalA,portalB;
    portalA.generatePandQ();
    portalA.calculateN();
    portalA.calculatephiN();
    portalA.generateE();
    portalA.generateD();

    portalB.generatePandQ();
    portalB.calculateN();
    portalB.calculatephiN();
    portalB.generateE();
    portalB.generateD();

    string message;
    cout<<"Please enter a message you want to send via portalA : ";

    //NOTE:-
    //Message can not be very large(Not more than 20 characters) because
    //Conversion of message string into number should be less than N.
    //But we can't take very large N as it would take more time so we will stick to messages less than length of 20.
    // we checked it with prime numbers of length of length 60 whhich was obviously taking much longer time.
    getline(cin,message);
    cout<<endl<<endl<<"Message from portal A: "<<message<<endl;

    //Encrypting message using portalB public key(e)
    string cypherText=portalA.encryptMessage(message,portalB);
    if(isEqualTo(cypherText,"-1")){
        cout<<"\nOops! :-( Message is too long.";
        return 0;
    }
    cout<<"Encrypted Message reached to portalB: "<<cypherText<<endl;

    //Now Decrypting message using portalB private key(d)
    string dMessage=portalB.decryptMessage(cypherText);
    cout<<"Decrypted Message decrpted at portal B using its private key(d): "<<dMessage;
	}
