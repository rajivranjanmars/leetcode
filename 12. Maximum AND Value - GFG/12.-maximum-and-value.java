// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;


 // } Driver Code Ends
//User function Template for Java

class Solution{
    
 public static int countMatchingElements(int sequence, int[] array) {
        int counter = 0;
        for (int i = 0; i < array.length; i++) {
            if ((sequence & array[i]) == sequence) counter++;
        }
        return counter;
    }
    public static int maxAND (int array[], int n) {
        int result = 0;
        for (int i = 16; i >= 0; i--) {
            int counter = countMatchingElements(result | (1 << i), array);
            if (counter >= 2) result |= (1 << i);
        }
        return result;
    }
    
}

// { Driver Code Starts.

class BitWise {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    
		    //input size of array
		    int n = Integer.parseInt(br.readLine());
		    String inputLine[] = br.readLine().trim().split(" ");
		    int arr[] = new int[n];
		    
		    //inserting elements in the array
		    for(int i=0; i<n; i++){
		        arr[i]=Integer.parseInt(inputLine[i]);
		    }
		    
		    Solution obj = new Solution();
		    
		    //calling maxAND() method of class AND
		    System.out.println(obj.maxAND(arr, n));
		}
	}
}
  // } Driver Code Ends