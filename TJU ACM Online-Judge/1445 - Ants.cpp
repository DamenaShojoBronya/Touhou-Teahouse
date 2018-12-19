#include<iostream>
#define min(x,y) x<y?x:y;
#define max(x,y) x>y?x:y;
using namespace std;

int main()
{
    int l, n, loop;
    cin >> loop;

    while(loop-->0) {
        cin >> l >> n;
        if(l==0) { cout<<"0 0"<<endl; continue; }
        int a, min = 0, max = 0;

        for (int i = 0; i < n;i++) {
            cin>>a;
            if(2*a < l) {    //杆的左边
                min = max(min,a);
                max=max(max,l-a);
            }
            if(2*a >=l) {    //杆的右边
                min = max(min,l-a);
                max = max(max,a);
            }
        }
        cout << min << " " << max << endl;
    }

    return 0;
}