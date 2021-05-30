#include <iostream>
#include <string.h>
using namespace std;

char item[50][50], fset1[50][50];
int arr[50], vl[50], n;   
float ratio[50];     
float mwt = 0, mvl = 0;    
void sort() 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                float te = ratio[j];
				ratio[j] = ratio[j + 1];
				ratio[j + 1] = te ;
				 
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                temp = vl[j];
                vl[j] = vl[j + 1];
                vl[j + 1] = temp;

                char it[50];
                strcpy(it, item[j]);
                strcpy(item[j], item[j + 1]);
                strcpy(item[j + 1], it);
            }
        }
    }
    cout << "Items after sorting as per max. ratio" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << item[i] << "  " << arr[i] << "  " << vl[i] <<"  "<< ratio[i]<<"  "<< endl;
        
    }
    cout << endl;
}

void calc(int mwt,char fset[][50])
{
    int t = n;
    int i = 0;
	for(int i=0;i<n;i++)
	{
		ratio[i]= (float)vl[i]/arr[i];
	}
	sort();
    while (mwt >= arr[i] && t > 0)
    {
        mwt -= arr[i];
        mvl += vl[i];
        strcpy(fset[i], item[i]);
        i++;
        t--;
    }
    
    if(mwt < arr[i])
    {
    	float temp = ratio[i]*mwt;
		mvl += temp;
		strcpy(fset[i],item[i]);
		mwt=0;		
	}
	
    cout << endl << "Remaining Weight is: " << mwt << endl;
    cout << "Value of the sack: " << mvl << endl;
}
void disp()
{
    cout << "Items selected in the sack:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << " " << fset1[i] << " ";  
    }
}

int main()
{
    cout << "Enter the total number of items:" << endl;
    cin >> n;
    cout << "Enter the max weight:" << endl;
    cin >> mwt;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter an item name,weight and value:" << endl;
        cin >> ws;
        cin.getline(item[i], 49);
        cin >> arr[i];
        cin >> vl[i];
    }
    calc(mwt,fset1);
    disp();
    cout << endl;
    return 0;
}
