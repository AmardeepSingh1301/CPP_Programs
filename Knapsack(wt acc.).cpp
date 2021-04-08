#include <iostream>
#include <string.h>
using namespace std;

char item[50][50], fset1[50][50],fset2[50][50];// 2d arrays to store the item
int arr[50], vl[50], n;   // arr is to store the wt of item and vl for its value      
int mwt = 0, mvl = 0;    // mwt stores the max. wt of sack and mvl the total value         

void sortwt() // function to sort according wt.
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
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
    cout << "Items after sorting as per min. weight" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << item[i] << "  " << arr[i] << "  " << vl[i] << endl;
        
    }
    cout << endl;
}

void calc(int mwt,char fset[][50]) // fun to calculate the sack wt.
{
    int t = n;
    int i = 0;

    while (mwt >= arr[i] && t > 0)
    {
        mwt -= arr[i];
        mvl += vl[i];
        strcpy(fset[i], item[i]);
        i++;
        t--;
    }
    cout << endl
         << "Remaining Weight is: " << mwt << endl;
    cout << "Value of the sack: " << mvl << endl;
}
void disp()
{
    cout << "Items selected in the sack:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << " " << fset1[i] << " ";  // display the content of sack
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
    sortwt();
    calc(mwt,fset1);
    disp();
    cout << endl;
    return 0;
}