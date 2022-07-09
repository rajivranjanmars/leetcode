#User function Template for python3
import statistics
class Solution:
    
    #Function to find the median of the two arrays when they get merged.
    def findMedianSortedArrays(self,arr1, n, arr2, n2):
        arr1[:]=arr1+arr2
        return int(statistics.median(arr1))
       
        #code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n1,n2=list(map(int,(input().split())))
        arr1=list(map(int,(input().split())))
        arr2=list(map(int,(input().split())))
        
        if n1<n2:
            print(Solution().findMedianSortedArrays(arr1,n1, arr2,n2))
        else:
            print(Solution().findMedianSortedArrays(arr2,n2, arr1,n1))
# } Driver Code Ends