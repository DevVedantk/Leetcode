class Solution {
    public void mergeTwoSortedArray(int[] arr,int[] a,int[] b){
        int i=0;
        int j=0;
        int k=0;
        while(i<a.length && j<b.length){
            if(a[i]<b[j]){
                arr[k]=a[i];
                i++;
                k++;
            }
            else{
                arr[k]=b[j];
                j++;
                k++;
            }
        }
        if(a.length==i){
            while(j<b.length){
                arr[k]=b[j];
                j++;
                k++;
            }
        }

          if(b.length==j){
            while(i<a.length){
                arr[k]=a[i];
                i++;
                k++;
            }
        }



    }
    public void mergeSort(int[] arr){
        int n=arr.length;
        if(n==1) return;
        int[] a=new int[n/2];
        int[] b=new int[n-n/2];
        for(int i=0;i<a.length;i++){
            a[i]=arr[i];
        }
         for(int i=0;i<b.length;i++){
            b[i]=arr[i+n/2];
        }
        mergeSort(a);
        mergeSort(b);
        mergeTwoSortedArray(arr,a,b);
            // a=null;
            // b=null;
    }
 
    public int[] sortArray(int[] arr) {
        mergeSort(arr);
        return arr;
    }
}