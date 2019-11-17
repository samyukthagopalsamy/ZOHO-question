#include<stdio.h>
#include<limits.h>

//this program finds the second largest number in a given window
int main()
{
   int arr[] = {10,19,30,23,14,27,28,33,32,21,45,41,6,3,90};
   int fl,sl,tl, ind,window=6, size, window_begin, window_end;
   /*
   fl- first largest
   sl- second largest
   tl- third largest
   */
   size = sizeof(arr) / sizeof(arr[0]); // calculating size of the array
   fl = sl = tl = INT_MIN;
   for(ind = 0; ind < window; ind++)// updating first, second and third largest values for first window (i.e 0 to window-1)
   {
       if(arr[ind] > fl) 
       {
           tl = sl;
           sl = fl;
           fl = arr[ind];
       }
      else if(arr[ind] > sl)
       {
           tl = sl;
           sl = arr[ind];
       } 
      else if(arr[ind] > tl)
            tl = arr[ind];
   }
printf("%d ", sl);
window_begin = 0;
window_end = window -1;
do
{
   /* For each new window only the element at beginning of last window
   and element at end of new window need to be compared with fl and sl*/
    if(arr[window_begin] == sl)
    {
        sl = tl;
    } 
   else if(arr[window_begin] == fl)
    {
        fl = sl;
        sl = tl;
        tl = INT_MIN;
    }
    window_end++;
       if(arr[window_end] > fl) //the new element included in the window is compared with current fl, sl and tl 
       {
           tl = sl;
           sl = fl;
           fl = arr[window_end];
       }
      else if(arr[window_end] > sl)
       {
           tl = sl;
           sl = arr[window_end];
       } 
      else if(arr[window_end] > tl)
            tl = arr[window_end];
    printf("%d ", sl); // the second largest element of current window is printed
    window_begin++;

}
   while(window_begin < (size-window)); // To prevent overrunning of window size
}
