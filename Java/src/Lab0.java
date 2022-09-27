//Lab 0 Fisher Norton CSC240 8/30/22
public class Lab0 {
    public static void main(String[] args) {
        //1 Given a non-negative int n, recursively count the occurrences of 3 as a digit.
        System.out.println("Count # of 3's in 313, 3, and 456");
        System.out.println("There are " + count3(313) + " 3's in 313"); //=2
        System.out.println("There are " + count3(3) + " 3's in 3"); //=1
        System.out.println("There are " + count3(456) + " 3's in 456\n");//=0
        //2 Write a method that accepts two numbers and performs multiplication by recursively adding the same number multiple times. 
        System.out.println("Multiply 0 & 10, 1 & 5, and 18 & 8");
        System.out.println("0 * 10 = " + multiply(0, 10)); //=0
        System.out.println("1 * 5 = " + multiply(1, 5)); //=5
        System.out.println("18 * 8 = " + multiply (18, 8) + "\n"); //=144
        //3 Write a boolean returning recursive method to determine if a number is prime. Recursively determine if the any number less the number are divisible by the number. 
        System.out.println("Check if 919, 50, and 2 are prime");
        System.out.println("Is 919 prime: " + isPrime(919, 2)); //=true
        System.out.println("Is 50 prime: " + isPrime(50, 2)); //=false
        System.out.println("Is 2 prime: " + isPrime(2, 2) + "\n"); //=true
        //4 Given a String, recursively build a new string where the vowels are duplicated. 
        System.out.println("Duplicate the vowels in the strings hello, xxyy, and abc");
        System.out.println(dupVowel("hello")); //="heelloo"
        System.out.println(dupVowel("xxyy")); //="xxyy"
        System.out.println(dupVowel("abc") + "\n"); //="aabc"
        //5 Given an array of ints, recursively compute the number of times that a multiple of 10 appears in the array. index is used to examine a specific element from the array.  
        //  Use a helper function to incorporate an index to count through elements in the array. 
        System.out.println("Count the number of times a multiple of 10 appears in 3 integer arrays [10, 20, 31], [11, 10], and [1, 2, 3, 4]");
        int[] arr1 = {10, 20, 31};
        System.out.println("There are " + array10(arr1) + " multiples of 10 in the array: 10, 20, 31");
        int[] arr2 = {11, 10};
        System.out.println("There are " + array10(arr2) + " multiples of 10 in the array: 11, 10");
        int[] arr3 = {1, 2, 3, 4};
        System.out.println("There are " + array10(arr3) + " multiples of 10 in the array: 1, 2, 3, 4");
    }

    public static int count3(int num) {
        if (num == 0) { //Base case
            return 0;
        } else if (num % 10 == 3) {
            return count3((num - (num % 10)) / 10) + 1;
        } else {
            return count3((num - (num % 10)) / 10);
        }
    }

    public static int multiply(int num, int times) {
        if (times <= 1) { //base case
            return num;
        } else {
            return num + multiply(num, times-1);
        }
    }

    public static boolean isPrime(int numToCheck, int count) {
        if (count >= numToCheck / 2) { //Base case (Finished searching all the numbers)
            return true;
        } else if (numToCheck % count == 0) { //Base case 2 (number is not prime)
            return false;
        } else {
            return isPrime(numToCheck, count+1);
        }
    }

    public static String dupVowel(String str) {
        if(str.length() == 0) {
            return "";
        } else if (str.charAt(0) == 'a' || str.charAt(0) == 'e' || str.charAt(0) == 'i' || str.charAt(0) == 'o' || str.charAt(0) == 'u') {
            return str.charAt(0) + str.charAt(0) + dupVowel(str.substring(1));
        } else {
            return str.charAt(0) + dupVowel(str.substring(1));
        }
    }


    public static int array10(int[] nums) {
        if(nums.length <= 1 && (nums[0] % 10 != 0)) {
            return 0; //No enough data
        } else {
            return array10Helper(nums, 0);
        }
    }

    public static int array10Helper(int[] nums, int index) {
        if (index > nums.length-1) {
            return 0;
        } else if (nums[index] % 10 == 0) {
            return array10Helper(nums, index+1) + 1;
        } else {
            return array10Helper(nums, index+1);
        }
    }
}
