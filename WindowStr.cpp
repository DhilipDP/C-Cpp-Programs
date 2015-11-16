#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std ;



int longestConsecutive( vector<int> &A) {
    map<int , int> hash;
    int n = A.size() ;
    if(n==0)
        return 0;
    int mini = A[0];
    int maxi = A[0];
    hash[mini]++;
    for(int  i=1 ; i<n ; i++){
    	if(A[i]==101)
    		cout<<"g"<<i<<endl;
        hash[A[i]]++;
        mini = min(mini,A[i]);
        maxi = max(maxi,A[i]);
        
    }
    cout<<endl<<mini<<" "<<maxi<<endl;
    int c = 0,maxi_len = 0;
    for(int i=mini ; i<=maxi ; i++)
    {
    	cout<<i<<" ";
        if(hash[i]==0 )
        {
            maxi_len = max(maxi_len,c);
            c = 0;
        }
        else
            c++;
        cout<<c<<endl;
    }
    maxi_len = max(maxi_len,c);
    return maxi_len ;
}


bool isSub(string s,string t)
{
	int hash[256] = {0} ;
	int n1 = s.length() ;
	int n2 = t.length() ;
	for(int i=0 ; i<n2 ; i++)
		hash[t[i]]++ ;
	for(int i=0 ;i<n1 ; i++)
		hash[s[i]]--;
	for(int i=0 ; i<256 ; i++)
		if(hash[i]!=0)
			return false ;
	return true;
}

string window(string s,string t)
{
	int hash[256] = {0} ;
	int n1 = s.length() ;
	int n2 = t.length() ;
	for(int i=0 ; i<n2 ; i++)
		hash[t[i]]++ ;
	int min_length = -1 ;
	int c=0;
	int start;
	char ch ;
	for(int i=0 ; i<n1 ; i++)
	{
		if(hash[s[i]]!=0)
		{
			c++;
			if(c==1)
				ch = s[i] ,start = i;
			if(c==n2)
			{
				min_length  = i-start+1;
				break;
			}
		}
	}
	if(min_length==-1)
		return "";
	int i=min_length;
 	int left = start+1,right = start+min_length-1;

 	int temp[256] = {0};
 	int j=0;
	while(i < n1 && j<3)
	{
		while(i<n1 && s[i]  != ch)
		{
			if(hash[s[i]]!=0)
				temp[s[i]]++;
			i++;
		}
	
		if(s[i]==ch)
		{
			//cout<<"hoi"<<left<<" "<<right;
			while(left <= right)
			{
			//	cout<<left<<endl;
				if(hash[s[left]]==0)
				left++;
				else if(temp[s[left]] != 0)
				left++,temp[s[left]]--;
				else
				{
				
					right = i;
					ch = s[left] ;
					left++;
					i++;
				//		cout<<left<<" "<<right<<endl;
						if(i==12)
							break;
					memset(temp,0,sizeof(temp)) ;
					break;
				}
				
			}
		//	break;
		}
		j++;
		
	}
	return s.substr(left-1,right-left+2);
}


int main()
{
	string s ="xiEjBOGeHIMIlslpQIZ6jERaAVoHUc9Hrjlv7pQpUSY8oHqXoQYWWll8Pumov89wXDe0Qx6bEjsNJQAQ0A6K21Z0BrmM96FWEdRG69M9CYtdBOrDjzVGPf83UdP3kc4gK0uHVKcPN4HPdccm9Qd2VfmmOwYCYeva6BSG6NGqTt1aQw9BbkNsgAjvYzkVJPOYCnz7U4hBeGpcJkrnlTgNIGnluj6L6zPqKo5Ui75tC0jMojhEAlyFqDs7WMCG3dmSyVoan5tXI5uq1IxhAYZvRQVHtuHae0xxwCbRh6S7fCLKfXeSFITfKHnLdT65K36vGC7qOEyyT0Sm3Gwl2iXYSN2ELIoITfGW888GXaUNebAr3fnkuR6VwjcsPTldQSiohMkkps0MH1cBedtaKNoFm5HbH15kKok6aYEVsb6wOH2w096OwEyvtDBTQwoLN87JriLwgCBBavbOAiLwkGGySk8nO8dLHuUhk9q7f0rIjXCsQeAZ1dfFHvVLupPYekXzxtWHd84dARvv4Z5L1Z6j8ur2IXWWbum8lCi7aErEcq41WTo8dRlRykyLRSQxVH70rUTz81oJS3OuZwpI1ifBAmNXoTfznG2MXkLtFu4SMYC0bPHNctW7g5kZRwjSBKnGihTY6BQYItRwLUINApd1qZ8W4yVG9tnjx4WyKcDhK7Ieih7yNl68Qb4nXoQl079Vza3SZoKeWphKef1PedfQ6Hw2rv3DpfmtSkulxpSkd9ee8uTyTvyFlh9G1Xh8tNF8viKgsiuCZgLKva32fNfkvW7TJC654Wmz7tPMIske3RXgBdpPJd5BPpMpPGymdfIw53hnYBNg8NdWAImY3otYHjbl1rqiNQSHVPMbDDvDpwy01sKpEkcZ7R4SLCazPClvrx5oDyYolubdYKcvqtlcyks3UWm2z7kh4SHeiCPKerh83bX0m5xevbTqM2cXC9WxJLrS8q7XF1nh"; ;
	string t = "dO4BRDaT1wd0YBhH88Afu7CI4fwAyXM8pGoGNsO1n8MFMRB7qugS9EPhCauVzj7h" ;
int arr[] = {	97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81, 7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11, 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95, 94, 56, 28, 55, 66, 92, 79, 27, 42, 70 };
	
	int n = sizeof(arr)/sizeof(arr[0]) ;
	sort(arr,arr+n) ;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	vector<int> v(arr,arr+n);
	cout<<longestConsecutive(v);
	cout<<endl;
	//cout<<window(s,t) ;
}
