#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("sample data.txt",ios::in);
    fout.open("TP_Sort_Result.txt",ios::out);
    if(!fin)
        cout<<"file could not be open"<<endl;

    string str1;
    while(fin>>str1)
    {
        int layer;
        string str2,str3,str4;
        stringstream s;
        s<<str1;
        s>>layer;
        int adj[layer+1][layer+1];
        int arr1[layer];
        int arr2[layer];

        for(int j=0; j<layer+1; j++)
        {
            for(int k=0; k<layer+1; k++)
                adj[j][k]=0;
        }
        adj[0][0]=-1;

        for(int j=1; j<layer+1; j++)
        {
            if(fin>>str2)
            {
                // arr[j-1]=str2;
                stringstream ss;
                int n;
                ss<<str2;
                ss>>n;
                adj[j][0]=n;
                adj[0][j]=n;
                arr1[j-1]=n;
                arr2[j-1]=0;
            }
        }

        int constraint;
        if(fin>>str3)
        {
            stringstream ss;
            ss<<str3;
            ss>>constraint;
        }
        for(int j=0; j<constraint; j++)
        {
            int s1,s2,t1,t2;
            string c;
            for(int k=0; k<3; k++)
            {
                if(fin>>str4)
                {
                    if(k==0)
                    {
                        stringstream ss;
                        ss<<str4;
                        ss>>t1;
                    }
                    if(k==1)
                    {
                        c=str4;
                    }
                    if(k==2)
                    {
                        stringstream ss;
                        ss<<str4;
                        ss>>t2;
                    }
                }

                if(c==">")
                {
                    s1=t1;
                    s2=t2;
                }
                else if(c=="<")
                {
                    s1=t2;
                    s2=t1;
                }
            }
            int m,n;
            for(m=0; m<layer+1; m++)
            {
                if(adj[m][0]==s1)
                    break;
            }

            for(n=0; n<layer+1; n++)
            {
                if(adj[0][n]==s2)
                    break;
            }
            adj[m][n]++;

            for(int t=0; t<layer; t++)
            {
                if(arr1[t]==s2)
                    arr2[t]++;
            }
        }
        for(int k=0; k<layer; k++)
        {
            int s=0;
            while(s<layer&&arr2[s]!=0)
                ++s;

            arr2[s]=-1;
            //cout<<arr1[s]<<" ";
            fout<<arr1[s]<<" ";



            int t;
            for(t=0; t<layer; t++)
            {
                if(adj[t][0]==arr1[s])
                    break;
            }
            for(int x=1; x<layer+1; x++)
            {
                if(adj[t][x])
                    arr2[x-1]--;
            }
        }
        //cout<<endl;
        fout<<endl;


    }
    str1.clear();
    fin.close();
    fout.close();

    return 0;
}
