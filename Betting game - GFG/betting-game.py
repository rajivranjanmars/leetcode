#User function Template for python3

class Solution:
   def betBalance(ob, result):
       # code here
       sum = 4
       bet = 1
       for i in result:
           if i== "W" and sum >=bet:
               sum =sum+bet
               bet = 1
               
           elif i=="L" and sum >= bet:
               sum = sum - bet
               bet = 2 * bet
               
           else :
               return -1
               
       return sum 

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        result = input()
        
        ob = Solution()
        print(ob.betBalance(result))
# } Driver Code Ends